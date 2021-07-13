#include "Zombie.h"
#include "Plant.h"

/*class Zombie*/

Zombie::Zombie(QString _name)
{
    name = _name;

    hp = 270;
    hp_left = 270;
    hp_flag[0] = true;
    hp_flag[1] = false;
    hp_flag[2] = false;
    attack = 1;
    speed = 0.15;
    state = 0;
    freezing_flag = false;

    head = nullptr;
    body = new QMovie(":/images/Zombies/" + name + "/1.gif");
    body->start();
    // Zombie 5:7
    // Coneheadzombie 2:3
    // Newspaperzombie 54:41
    // Polevaultingzombie 174:109
    // Jackintheboxzombie 11:15 1:1
    // Catapultzombie 9:8 9:7
}

Zombie::~Zombie()
{
    delete head;
    delete body;
}

int Zombie::type() const
{
    return Type;
}

void Zombie::Set_Body(QString path, int percent_speed)
{
    if (body)
        delete body;
    body = new QMovie(path);
    body->setSpeed(percent_speed);
    body->start();
}

void Zombie::Set_Head(QString path, int percent_speed)
{
    if (head)
        delete head;
    head = new QMovie(path);
    head->setSpeed(percent_speed);
    head->start();
}

QRectF Zombie::boundingRect() const
{
    if (state == 6)
        return QRectF(-210, -160, 330, 280);
    else if (state == 2)
        return QRectF(-150, -130, 300, 260);
    else if (state == 3)
        return QRectF(-80, -100, 200, 240);
    else
        return QRectF(-85, -119, 170, 238);
}

void Zombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QImage image = body->currentImage();
    if (freezing_flag) //���Ʊ�����Ч
    {
        int width = image.width();
        int height = image.height();
        for (int i = 0; i < height; i++)
        {
            uchar *line = image.scanLine(i);
            for (int j = 5; j < width - 5; ++j)
                line[j << 2] = 200; //Ϳ����ɫ
        }
    }
    painter->drawImage(boundingRect(), image);

    if (head)
    {
        image = head->currentImage();
        if (freezing_flag) //���Ʊ�����Ч
        {
            int width = image.width();
            int height = image.height();
            for (int i = 0; i < height; ++i)
            {
                uchar *line = image.scanLine(i);
                for (int j = 5; j < width - 5; ++j)
                    line[j << 2] = 200; //Ϳ����ɫ
            }
        }
        painter->drawImage(boundingRect(), image);
    }
}

bool Zombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)

    return other->type() == Plant::Type && qAbs(other->y() - y()) < 50 && qAbs(other->x() - x()) < 70 && other->x() - x() < 0;
}

//state: 0:��ʼ״̬ 1:��ʳ״̬ 2/3:����״̬ 6:ը��״̬
void Zombie::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        if(state == 6) //��ӣ��ը��ը��
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 2) //תΪ����״̬
        {
            state = 2;
            Set_Body(":/images/Zombies/" + name + "/bodydie.gif", 50);
            state = 3;
            Set_Head(":/images/Zombies/" + name + "/headdie.gif", 30);
            state = 2;
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1 && head->currentFrameNumber() == head->frameCount() - 1)//Ŀǰ����Ϊstate2�Ҷ������ŵ������
            delete this;
        return;
    }

    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty()) //��⵽����ֲ���ʼ��ʳ
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        foreach (QGraphicsItem *item, items)
        {
            plant = qgraphicsitem_cast<Plant *>(item);
            if (plant->name == "pumpkin") //���Ƚ�ʳ�Ϲ�ͷ
                break;
        }

        if (state == 0 && plant->state == 0) //תΪ��ʳ״̬
        {
            plant->hp_left -= attack; //��ʳ
            state = 1;
            //hp_flag[2 - hp_left / (hp / 3)] = false;
            if(hp * 2 / 3 <= hp_left)
                hp_flag[0] = false;
            else if(hp / 3 <= hp_left && hp_left < hp * 2 / 3)
                hp_flag[1] = false;
            else if(0 < hp_left && hp_left <= hp / 3)
                hp_flag[2] = false;
            Set_Body(":/images/Zombies/" + name + "/4.gif");
        }
        else if (plant->state != 0) //��ֲ�ﴦ�ڲ��ɱ���ʳ״̬�������ǰ��
            setX(x() - speed);

        return;
    }

    if (state == 1) //תΪ��ʼ״̬
    {
        state = 0;
    }

    /*if(hp_flag[2 - hp_left / (hp / 3)] == false)
    {
        hp_flag[2 - hp_left / (hp / 3)] = true;
        Set_Body(":/images/Zombies/" + name + "/" + QString(3 - hp_left / (hp / 3)) + ".gif");
    }*/
    if (hp * 2 / 3 <= hp_left && hp_flag[0] == false)
    {
        Set_Body(":/images/Zombies/" + name + "/1.gif");
        hp_flag[0] = true;
    }
    else if (hp / 3 <= hp_left && hp_left < hp * 2 / 3 && hp_flag[1] == false)
    {
        Set_Body(":/images/Zombies/" + name + "/2.gif");
        hp_flag[1] = true;
    }
    else if (0 < hp_left && hp_left <= hp / 3 && hp_flag[2] == false)
    {
        Set_Body(":/images/Zombies/" + name + "/3.gif");
        hp_flag[2] = true;
    }

    setX(x() - speed);
}


/*class Coneheadzombie*/

Coneheadzombie::Coneheadzombie(): Zombie("coneheadzombie")
{
    hp = 640;
    hp_left = 640;
}

QRectF Coneheadzombie::boundingRect() const
{
    if (state == 6)
        return QRectF(-210, -160, 330, 280);
    else if (state == 2)
        return QRectF(-170, -130, 300, 260);
    else if (state == 3)
        return QRectF(-50, -100, 200, 240);
    else
        return QRectF(-90, -150, 180, 270);
}

//state: 0:��ʼ״̬ 1:��ʳ״̬ 2/3:����״̬ 6:ը��״̬
void Coneheadzombie::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        if(state == 6) //��ӣ��ը��ը��
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 2) //תΪ����״̬
        {
            state = 2;
            Set_Body(":/images/Zombies/" + name + "/bodydie.gif", 50);
            state = 3;
            Set_Head(":/images/Zombies/" + name + "/headdie.gif", 30);
            state = 2;
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1 && head->currentFrameNumber() == head->frameCount() - 1)//Ŀǰ����Ϊstate2�Ҷ������ŵ������
            delete this;
        return;
    }

    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty()) //����⵽����ֲ���ʼ��ʳ
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        foreach (QGraphicsItem *item, items)
        {
            plant = qgraphicsitem_cast<Plant *>(item);
            if (plant->name == "pumpkin") //���Ƚ�ʳ�Ϲ�ͷ
                break;
        }

        if (state == 0 && plant->state == 0) //תΪ��ʳ״̬
        {
            plant->hp_left -= attack; //��ʳ
            state = 1;
            Set_Body(":/images/Zombies/" + name + "/2.gif");
        }
        else if(plant->state != 0) //��ֲ�ﴦ�ڲ��ɱ���ʳ״̬�������ǰ��
            setX(x() - speed);
        return;
    }

    if(state == 1) //תΪ��ʼ״̬
    {
        state = 0;
        Set_Body(":/images/Zombies/" + name + "/1.gif");
    }

    setX(x() - speed);
}


/*class Newspaperzombie*/

Newspaperzombie::Newspaperzombie(): Zombie("newspaperzombie")
{
    hp = 420;
    hp_left = 420;
}

QRectF Newspaperzombie::boundingRect() const
{
    if (state == 6)
        return QRectF(-210, -160, 330, 280);
    else if (state == 2)
        return QRectF(-170, -130, 300, 260);
    else if (state == 3)
        return QRectF(-50, -100, 200, 240);
    else
        return QRectF(-162, -167, 378, 287);
}

//state: 0:��ʼ״̬ 1:��ʳ״̬ 2/3:����״̬ 6:ը��״̬
void Newspaperzombie::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        if(state == 6) //��ӣ��ը��ը��
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 2) //תΪ����״̬
        {
            state = 2;
            Set_Body(":/images/Zombies/" + name + "/bodydie.gif", 50);
            state = 3;
            Set_Head(":/images/Zombies/" + name + "/headdie.gif", 30);
            state = 2;
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1 && head->currentFrameNumber() == head->frameCount() - 1)//Ŀǰ����Ϊstate3�Ҷ������ŵ������
            delete this;
        return;
    }

    QList<QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty()) //����⵽����ֲ���ʼ��ʳ
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        foreach (QGraphicsItem *item, items)
        {
            plant = qgraphicsitem_cast<Plant *>(item);
            if (plant->name == "pumpkin") //���Ƚ�ʳ�Ϲ�ͷ
                break;
        }

        if (state == 0 && plant->state == 0) //תΪ��ʳ״̬
        {
            plant->hp_left -= attack; //��ʳ
            state = 1;
            Set_Body(":/images/Zombies/" + name + "/" + QString(2 + hp_flag[1] * 3) + ".gif");
        }
        else if(plant->state != 0) //��ֲ�ﴦ�ڲ��ɽ�ʳ״̬�������ǰ��
            setX(x() - speed);
        return;
    }

    if(state == 0)
    {
        if(hp_left <= hp * 2 / 3 && hp_flag[1] == false) //������ֽ��תΪ��ŭ״̬
        {
            hp_flag[0] = false;
            hp_flag[1] = true;
            Set_Body(":/images/Zombies/" + name + "/5.gif");
            speed = 0.3;
        }
    }
    else if(state == 1) //תΪ��ʼ״̬
    {
        state = 0;
        if(hp_left > hp * 2 / 3)
        {
            Set_Body(":/images/Zombies/" + name + "/1.gif");
            speed = 0.15;
        }
        else
        {
            Set_Body(":/images/Zombies/" + name + "/4.gif");
            speed = 0.3;
        }
    }

    setX(x() - speed);
}


/*class Polevaultingzombie*/

Polevaultingzombie::Polevaultingzombie(): Zombie("polevaultingzombie")
{
    speed = 0.25;
    hp = 500;
    hp_left = 500;
    pole_flag = true;
}

QRectF Polevaultingzombie::boundingRect() const
{
    if (state == 6)
        return QRectF(-210, -160, 330, 280);
    else if (state == 4)
        return QRectF(-304, -240, 609, 382);
    else if (state == 5)
        return QRectF(-304, -240, 609, 382);
    else
        return QRectF(-304, -240, 609, 382);
}

//state: 0:��ʼ״̬ 1����Ծ״̬ 2���޸�״̬ 3:��ʳ״̬ 4/5:����״̬ 6:ը��״̬
void Polevaultingzombie::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        if(state == 6) //��ӣ��ը��ը��
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 4) //תΪ����״̬
        {
            state = 4;
            Set_Body(":/images/Zombies/" + name + "/bodydie.gif", 60);
            state = 5;
            Set_Head(":/images/Zombies/" + name + "/headdie.gif", 60);
            state = 4;
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1 && head->currentFrameNumber() == head->frameCount() - 1)//Ŀǰ����Ϊstate3�Ҷ������ŵ������
            delete this;
        return;
    }

    QList<QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty() && state != 1) //����⵽����ֲ��Ҳ�������Ծ״̬����ʼ��Ծ/��ʳ
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        foreach (QGraphicsItem *item, items)
        {
            plant = qgraphicsitem_cast<Plant *>(item);
            if (plant->name != "pumpkin") //���Ƚ�ʳ�Ϲ�ͷ
                break;
        }

        if(!pole_flag) //û�гŸ�
        {
            if (state != 3 && plant->state == 0) //תΪ��ʳ״̬
            {
                plant->hp_left -= attack; //��ʳ
                state = 3;
                Set_Body(":/images/Zombies/" + name + "/5.gif");
            }
            else if(plant->state != 0) //��ֲ�ﴦ�ڲ��ɽ�ʳ״̬�������ǰ��
                setX(x() - speed);
            return;
        }
        else if(state == 0) //תΪ��Ծ״̬
        {
            pole_flag = false;
            if(plant->name != "tallnut") //���󷽲��Ǹ߼��������ǰ��Ծ������ԭ����Ծ
                setX(x() - 200);
            state = 1;
            speed = 0.15;
            Set_Body(":/images/Zombies/" + name + "/3.gif", 30);
            return;
        }
    }

    if(state == 1) //תΪ�޸�״̬
    {
        if(body->currentFrameNumber() == body->frameCount() - 1)
        {
            state = 2;
            Set_Body(":/images/Zombies/" + name + "/4.gif");
        }
    }
    else if(state == 3) //תΪ�޸�״̬
    {
        state = 2;
        Set_Body(":/images/Zombies/" + name + "/4.gif");
    }

    setX(x() - speed);

    return;
}


/*class Jackintheboxzombie*/

Jackintheboxzombie::Jackintheboxzombie(): Zombie("jackintheboxzombie")
{
    speed = 0.2;
    hp = 500;
    hp_left = 500;
}

QRectF Jackintheboxzombie::boundingRect() const
{
    if (state == 6)
        return QRectF(-210, -160, 330, 280);
    else if (state == 3)
        return QRectF(-170, -130, 300, 260);
    else if (state == 4)
        return QRectF(-50, -100, 200, 240);
    else if(state != 1)
        return QRectF(-93, -127, 187, 255);
    else
        return QRectF(-300, -300, 600, 600);
}

bool Jackintheboxzombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)

    return other->type() == Plant::Type && qAbs(other->y() - y()) < 350 && qAbs(other->x() - x()) < 255;
}

//state: 0:��ʼ״̬ 1����ը״̬ 2:��ʳ״̬ 3/4:����״̬ 6:ը��״̬
void Jackintheboxzombie::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        if(state == 6) //��ӣ��ը��ը��
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 3) //תΪ����״̬
        {
            state = 3;
            Set_Body(":/images/Zombies/" + name + "/bodydie.gif", 50);
            state = 4;
            Set_Head(":/images/Zombies/" + name + "/headdie.gif", 30);
            state = 3;
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1 && head->currentFrameNumber() == head->frameCount() - 1)//Ŀǰ����Ϊstate3�Ҷ������ŵ������
            delete this;
        return;
    }

    if (state == 1) //���ڱ�ը״̬
    {
        if (body->currentFrameNumber() == 1)
        {
            QList<QGraphicsItem *> items = collidingItems();
            if(!items.isEmpty()) //ը����Χ3��3�ݵ��ڵ�����ֲ��
            {
                foreach (QGraphicsItem *item, items)
                {
                    delete item;
                }
            }
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1)//Ŀǰ����Ϊstate1�Ҷ������ŵ������
        {
            delete this;
        }
        return;
    }
    else if((2500 - x()) / 190 >= qrand() % 30000) //תΪ��ը״̬
    {
        state = 1;
        Set_Body(":/images/Zombies/" + name + "/4.gif");
        return;
    }

    QList<QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty()) //����⵽����ֲ���ʼ��ʳ
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        foreach (QGraphicsItem *item, items)
        {
            plant = qgraphicsitem_cast<Plant *>(item);
            if (plant->name != "pumpkin") //���Ƚ�ʳ�Ϲ�ͷ
                break;
        }

        if (state != 2 && plant->state == 0) //תΪ��ʳ״̬
        {
            plant->hp_left -= attack; //��ʳ
            state = 2;
            Set_Body(":/images/Zombies/" + name + "/2.gif");
        }
        else if(plant->state != 0) //��ֲ�ﴦ�ڲ��ɱ���ʳ״̬�������ǰ��
            setX(x() - speed);
        return;
    }

    if(state != 0) //תΪ��ʼ״̬
    {
        state = 0;
        Set_Body(":/images/Zombies/" + name + "/1.gif");
    }

    setX(x() - speed);
}


/*class Catapultzombie*/

Catapultzombie::Catapultzombie(): Zombie("catapultzombie")
{
    speed = 0.2;
    hp = 850;
    hp_left = 850;
    basketball_left = 10;
    interval = 300;
    timer = 0;
}

QRectF Catapultzombie::boundingRect() const
{
    if (state == 6)
        return QRectF(-157, -110, 315, 220);
    else if (state == 2)
        return QRectF(-170, -130, 300, 260);
    else if (state == 3)
        return QRectF(-50, -100, 200, 240);
    else
        return QRectF(-157, -140, 315, 280);
}

bool Catapultzombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)

    return other->type() == Plant::Type && qAbs(other->y() - y()) < 10 && other->x() < x();
}

//state: 0:��ʼ״̬ 1��Ͷ��״̬ 2/3:����״̬ 6:ը��״̬
void Catapultzombie::advance(int phase)
{
    if (!phase)
        return;

    update();

    QList<QGraphicsItem *> items = collidingItems();
    if (hp_left <= 0)
    {
        if(state == 6) //��ӣ��ը��ը��
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 2) //תΪ����״̬
        {
            state = 2;
            Set_Body(":/images/Zombies/" + name + "/bodydie.gif", 50);
            state = 3;
            Set_Head(":/images/Zombies/" + name + "/headdie.gif", 30);
            state = 2;
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1 && head->currentFrameNumber() == head->frameCount() - 1)//Ŀǰ����Ϊstate2�Ҷ������ŵ������
            delete this;
        return;
    }


    if (state == 0) //���ڳ�ʼ״̬
    {
        if(!items.isEmpty()) //����⵽������ֲ���ʼͶ��
        {
            if (basketball_left > 0 && x() < 2000) //����������ʣ�࣬��תΪͶ��״̬
            {
                state = 1;
                Set_Body(":/images/Zombies/" + name + "/2.gif");
            }
            else //��û��ʣ�����������ǰ��
            {
                /*QList<QGraphicsItem *> items2 = Zombie::collidingItems();
                if(!items2.empty()) //����⵽����ֲ���ֱ����ѹֲ��
                {
                    Plant *plant = qgraphicsitem_cast<Plant *>(items2[0]);
                    foreach (QGraphicsItem *item2, items2)
                    {
                        plant = qgraphicsitem_cast<Plant *>(item2);
                        plant->hp_left = 0;
                    }
                }*/
                setX(x() - speed);
            }
            return;
        }

        setX(x() - speed);//ǰ��
    }
    else if(state == 1) //����Ͷ��״̬
    {
        if(!items.isEmpty()) //����⵽������ֲ��������󷽵�ֲ��Ͷ��
        {
            if(timer + 1 >= interval)
            {
                timer = 0;
                Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
                foreach (QGraphicsItem *item, items)
                {
                    if (qgraphicsitem_cast<Plant *>(item)->x() < plant->x())
                        plant = qgraphicsitem_cast<Plant *>(item);
                    else if (qgraphicsitem_cast<Plant *>(item)->x() == plant->x())
                    {
                        if (plant->name != "pumpkin")
                            plant = qgraphicsitem_cast<Plant *>(item);
                    }
                }
                Basketball *basketball = new Basketball(plant->x(), plant->y());
                basketball->setX(x() - 50);
                basketball->setY(y() - 50);
                scene()->addItem(basketball); //Ͷ��
                basketball_left--;
                if(basketball_left == 0) //������Ͷ�꣬��תΪ��ʼ״̬
                {
                    state = 0;
                    Set_Body(":/images/Zombies/" + name + "/1.gif");
                }
            }
            else
            {
                timer++;
            }
            return;
        }

        state = 0; //תΪ��ʼ״̬
        Set_Body(":/images/Zombies/" + name + "/1.gif");
    }
}
