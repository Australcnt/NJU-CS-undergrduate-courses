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
    if (freezing_flag) //绘制冰冻特效
    {
        int width = image.width();
        int height = image.height();
        for (int i = 0; i < height; i++)
        {
            uchar *line = image.scanLine(i);
            for (int j = 5; j < width - 5; ++j)
                line[j << 2] = 200; //涂成蓝色
        }
    }
    painter->drawImage(boundingRect(), image);

    if (head)
    {
        image = head->currentImage();
        if (freezing_flag) //绘制冰冻特效
        {
            int width = image.width();
            int height = image.height();
            for (int i = 0; i < height; ++i)
            {
                uchar *line = image.scanLine(i);
                for (int j = 5; j < width - 5; ++j)
                    line[j << 2] = 200; //涂成蓝色
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

//state: 0:初始状态 1:进食状态 2/3:死亡状态 6:炸毁状态
void Zombie::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        if(state == 6) //被樱桃炸弹炸毁
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 2) //转为死亡状态
        {
            state = 2;
            Set_Body(":/images/Zombies/" + name + "/bodydie.gif", 50);
            state = 3;
            Set_Head(":/images/Zombies/" + name + "/headdie.gif", 30);
            state = 2;
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1 && head->currentFrameNumber() == head->frameCount() - 1)//目前动画为state2且动画播放到了最后
            delete this;
        return;
    }

    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty()) //检测到左方有植物，开始进食
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        foreach (QGraphicsItem *item, items)
        {
            plant = qgraphicsitem_cast<Plant *>(item);
            if (plant->name == "pumpkin") //优先进食南瓜头
                break;
        }

        if (state == 0 && plant->state == 0) //转为进食状态
        {
            plant->hp_left -= attack; //进食
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
        else if (plant->state != 0) //若植物处于不可被进食状态，则继续前进
            setX(x() - speed);

        return;
    }

    if (state == 1) //转为初始状态
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

//state: 0:初始状态 1:进食状态 2/3:死亡状态 6:炸毁状态
void Coneheadzombie::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        if(state == 6) //被樱桃炸弹炸毁
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 2) //转为死亡状态
        {
            state = 2;
            Set_Body(":/images/Zombies/" + name + "/bodydie.gif", 50);
            state = 3;
            Set_Head(":/images/Zombies/" + name + "/headdie.gif", 30);
            state = 2;
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1 && head->currentFrameNumber() == head->frameCount() - 1)//目前动画为state2且动画播放到了最后
            delete this;
        return;
    }

    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty()) //若检测到左方有植物，则开始进食
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        foreach (QGraphicsItem *item, items)
        {
            plant = qgraphicsitem_cast<Plant *>(item);
            if (plant->name == "pumpkin") //优先进食南瓜头
                break;
        }

        if (state == 0 && plant->state == 0) //转为进食状态
        {
            plant->hp_left -= attack; //进食
            state = 1;
            Set_Body(":/images/Zombies/" + name + "/2.gif");
        }
        else if(plant->state != 0) //若植物处于不可被进食状态，则继续前进
            setX(x() - speed);
        return;
    }

    if(state == 1) //转为初始状态
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

//state: 0:初始状态 1:进食状态 2/3:死亡状态 6:炸毁状态
void Newspaperzombie::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        if(state == 6) //被樱桃炸弹炸毁
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 2) //转为死亡状态
        {
            state = 2;
            Set_Body(":/images/Zombies/" + name + "/bodydie.gif", 50);
            state = 3;
            Set_Head(":/images/Zombies/" + name + "/headdie.gif", 30);
            state = 2;
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1 && head->currentFrameNumber() == head->frameCount() - 1)//目前动画为state3且动画播放到了最后
            delete this;
        return;
    }

    QList<QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty()) //若检测到左方有植物，则开始进食
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        foreach (QGraphicsItem *item, items)
        {
            plant = qgraphicsitem_cast<Plant *>(item);
            if (plant->name == "pumpkin") //优先进食南瓜头
                break;
        }

        if (state == 0 && plant->state == 0) //转为进食状态
        {
            plant->hp_left -= attack; //进食
            state = 1;
            Set_Body(":/images/Zombies/" + name + "/" + QString(2 + hp_flag[1] * 3) + ".gif");
        }
        else if(plant->state != 0) //若植物处于不可进食状态，则继续前进
            setX(x() - speed);
        return;
    }

    if(state == 0)
    {
        if(hp_left <= hp * 2 / 3 && hp_flag[1] == false) //丢掉报纸，转为愤怒状态
        {
            hp_flag[0] = false;
            hp_flag[1] = true;
            Set_Body(":/images/Zombies/" + name + "/5.gif");
            speed = 0.3;
        }
    }
    else if(state == 1) //转为初始状态
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

//state: 0:初始状态 1：跳跃状态 2：无杆状态 3:进食状态 4/5:死亡状态 6:炸毁状态
void Polevaultingzombie::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        if(state == 6) //被樱桃炸弹炸毁
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 4) //转为死亡状态
        {
            state = 4;
            Set_Body(":/images/Zombies/" + name + "/bodydie.gif", 60);
            state = 5;
            Set_Head(":/images/Zombies/" + name + "/headdie.gif", 60);
            state = 4;
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1 && head->currentFrameNumber() == head->frameCount() - 1)//目前动画为state3且动画播放到了最后
            delete this;
        return;
    }

    QList<QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty() && state != 1) //若检测到左方有植物，且不处于跳跃状态，则开始跳跃/进食
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        foreach (QGraphicsItem *item, items)
        {
            plant = qgraphicsitem_cast<Plant *>(item);
            if (plant->name != "pumpkin") //优先进食南瓜头
                break;
        }

        if(!pole_flag) //没有撑杆
        {
            if (state != 3 && plant->state == 0) //转为进食状态
            {
                plant->hp_left -= attack; //进食
                state = 3;
                Set_Body(":/images/Zombies/" + name + "/5.gif");
            }
            else if(plant->state != 0) //若植物处于不可进食状态，则继续前进
                setX(x() - speed);
            return;
        }
        else if(state == 0) //转为跳跃状态
        {
            pole_flag = false;
            if(plant->name != "tallnut") //若左方不是高坚果，则向前跳跃；否则原地跳跃
                setX(x() - 200);
            state = 1;
            speed = 0.15;
            Set_Body(":/images/Zombies/" + name + "/3.gif", 30);
            return;
        }
    }

    if(state == 1) //转为无杆状态
    {
        if(body->currentFrameNumber() == body->frameCount() - 1)
        {
            state = 2;
            Set_Body(":/images/Zombies/" + name + "/4.gif");
        }
    }
    else if(state == 3) //转为无杆状态
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

//state: 0:初始状态 1：爆炸状态 2:进食状态 3/4:死亡状态 6:炸毁状态
void Jackintheboxzombie::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        if(state == 6) //被樱桃炸弹炸毁
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 3) //转为死亡状态
        {
            state = 3;
            Set_Body(":/images/Zombies/" + name + "/bodydie.gif", 50);
            state = 4;
            Set_Head(":/images/Zombies/" + name + "/headdie.gif", 30);
            state = 3;
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1 && head->currentFrameNumber() == head->frameCount() - 1)//目前动画为state3且动画播放到了最后
            delete this;
        return;
    }

    if (state == 1) //处于爆炸状态
    {
        if (body->currentFrameNumber() == 1)
        {
            QList<QGraphicsItem *> items = collidingItems();
            if(!items.isEmpty()) //炸毁周围3×3草地内的所有植物
            {
                foreach (QGraphicsItem *item, items)
                {
                    delete item;
                }
            }
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1)//目前动画为state1且动画播放到了最后
        {
            delete this;
        }
        return;
    }
    else if((2500 - x()) / 190 >= qrand() % 30000) //转为爆炸状态
    {
        state = 1;
        Set_Body(":/images/Zombies/" + name + "/4.gif");
        return;
    }

    QList<QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty()) //若检测到左方有植物，则开始进食
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        foreach (QGraphicsItem *item, items)
        {
            plant = qgraphicsitem_cast<Plant *>(item);
            if (plant->name != "pumpkin") //优先进食南瓜头
                break;
        }

        if (state != 2 && plant->state == 0) //转为进食状态
        {
            plant->hp_left -= attack; //进食
            state = 2;
            Set_Body(":/images/Zombies/" + name + "/2.gif");
        }
        else if(plant->state != 0) //若植物处于不可被进食状态，则继续前进
            setX(x() - speed);
        return;
    }

    if(state != 0) //转为初始状态
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

//state: 0:初始状态 1：投篮状态 2/3:死亡状态 6:炸毁状态
void Catapultzombie::advance(int phase)
{
    if (!phase)
        return;

    update();

    QList<QGraphicsItem *> items = collidingItems();
    if (hp_left <= 0)
    {
        if(state == 6) //被樱桃炸弹炸毁
        {
            if(body->currentFrameNumber() == body->frameCount() - 1)
                delete this;
        }
        else if (state != 2) //转为死亡状态
        {
            state = 2;
            Set_Body(":/images/Zombies/" + name + "/bodydie.gif", 50);
            state = 3;
            Set_Head(":/images/Zombies/" + name + "/headdie.gif", 30);
            state = 2;
        }
        else if (body->currentFrameNumber() == body->frameCount() - 1 && head->currentFrameNumber() == head->frameCount() - 1)//目前动画为state2且动画播放到了最后
            delete this;
        return;
    }


    if (state == 0) //处于初始状态
    {
        if(!items.isEmpty()) //若检测到该行有植物，则开始投篮
        {
            if (basketball_left > 0 && x() < 2000) //若还有篮球剩余，则转为投篮状态
            {
                state = 1;
                Set_Body(":/images/Zombies/" + name + "/2.gif");
            }
            else //若没有剩余篮球，则继续前进
            {
                /*QList<QGraphicsItem *> items2 = Zombie::collidingItems();
                if(!items2.empty()) //若检测到左方有植物，则直接碾压植物
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

        setX(x() - speed);//前进
    }
    else if(state == 1) //处于投篮状态
    {
        if(!items.isEmpty()) //若检测到该行有植物，则向最左方的植物投篮
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
                scene()->addItem(basketball); //投篮
                basketball_left--;
                if(basketball_left == 0) //若篮球被投完，则转为初始状态
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

        state = 0; //转为初始状态
        Set_Body(":/images/Zombies/" + name + "/1.gif");
    }
}
