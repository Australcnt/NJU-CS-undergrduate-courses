#include "Plant.h"
#include "Zombie.h"

Plant::Plant(QString _name)
{
    name = _name;
    hp = 0;
    hp_left = 0;
    hp_flag[0] = true;
    hp_flag[1] = false;
    hp_flag[2] = false;
    state = 0;

    movie = new QMovie(":/images/Plants/" + name + "/1.gif");
    movie->start();
}

Plant::~Plant()
{
    if (movie)
        delete movie;
}

int Plant::type() const
{
    return Type;
}

QRectF Plant::boundingRect() const
{
    return QRectF(-70, -70, 140, 140);
}

void Plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawImage(boundingRect(), movie->currentImage());
}

bool Plant::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)

    return other->type() == Zombie::Type && qAbs(other->y()-y()) < 50 && qAbs(other->x() - x()) < 60 && other->x() > x();
}


/*class Sunflower*/

Sunflower::Sunflower(): Plant("sunflower")
{
    hp = 300;
    hp_left = 300;
    interval = 1000;
    timer = 0;
}

void Sunflower::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        delete this;
        return;
    }

    if(timer + 1 >= interval)//产生阳光
    {
        timer = 0;
        scene()->addItem(new Sunshine(pos()));
    }
    else
    {
        timer++;
    }
}


/*class Peashooter*/

Peashooter::Peashooter(): Plant("peashooter")
{
    hp = 300;
    hp_left = 300;
    interval = 140;
    timer = 0;
}

bool Peashooter::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)

    return other->type() == Zombie::Type && qAbs(other->y()-y()) < 50 && other->x() - x() > 35;
}

void Peashooter::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        delete this;
        return;
    }

    if(timer + 1 >= interval)
    {
        timer = 0;
        QList<QGraphicsItem *> items = collidingItems();
        if(!items.isEmpty()) //所在行有僵尸，则发射豌豆
        {
            Pea *pea = new Pea();
            pea->setX(x() + 35);
            pea->setY(y());
            scene()->addItem(pea);
        }
    }
    else
    {
        timer++;
    }
}


/*class Repeater*/

Repeater::Repeater(): Plant("repeater")
{
    hp = 300;
    hp_left = 300;
    interval = 140;
    timer = 0;
}

bool Repeater::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)

    return other->type() == Zombie::Type && qAbs(other->y() - y()) < 50 && other->x() - x() > 35;
}

void Repeater::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        delete this;
        return;
    }

    if(timer + 21 == interval)
    {
        QList<QGraphicsItem *> items = collidingItems();
        if(!items.isEmpty()) //所在行有僵尸，则发射第一颗豌豆
        {
            Pea *pea = new Pea();
            pea->setX(x() + 35);
            pea->setY(y());
            scene()->addItem(pea);
        }
        timer++;
    }
    else if(timer + 1 >= interval)
    {
        timer = 0;
        QList<QGraphicsItem *> items = collidingItems();
        if(!items.isEmpty()) //所在行有僵尸，则发送第二颗豌豆
        {
            Pea *pea = new Pea();
            pea->setX(x() + 35);
            pea->setY(y());
            scene()->addItem(pea);
        }
    }
    else
    {
        timer++;
    }
}


/*class Snowpea*/

Snowpea::Snowpea(): Plant("snowpea")
{
    hp = 300;
    hp_left = 300;
    interval = 140;
    timer = 0;
}

bool Snowpea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)

    return other->type() == Zombie::Type && qAbs(other->y() - y()) < 50 && other->x() - x() > 35;
}

void Snowpea::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        delete this;
        return;
    }

    if(timer + 1 >= interval)
    {
        timer = 0;
        QList<QGraphicsItem *> items = collidingItems();
        if(!items.isEmpty()) //所在行有僵尸，则发射豌豆
        {
            Peaice *peaice = new Peaice();
            peaice->setX(x() + 35);
            peaice->setY(y());
            scene()->addItem(peaice);
        }
    }
    else
    {
        timer++;
    }
}


/*class Wallnut*/

Wallnut::Wallnut(): Plant("wallnut")
{
    hp = 4000;
    hp_left = 4000;
}

void Wallnut::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        delete this;
        return;
    }

    if (hp / 3 < hp_left && hp_left <= hp * 2 / 3 && hp_flag[1] == false)
    {
        hp_flag[0] = false;
        hp_flag[1] = true;
        if (movie)
            delete movie;
        movie = new QMovie(":/images/Plants/wallnut/2.gif");
        movie->start();
    }
    else if (0 < hp_left && hp_left <= hp / 3 && hp_flag[2] == false)
    {
        hp_flag[1] = false;
        hp_flag[2] = true;
        if (movie)
            delete movie;
        movie = new QMovie(":/images/Plants/wallnut/3.gif");
        movie->start();
    }
}


/*class Tallnut*/

Tallnut::Tallnut(): Plant("tallnut")
{
    hp = 8000;
    hp_left = 8000;
}

QRectF Tallnut::boundingRect() const
{
    return QRectF(-70, -100, 140, 200);
}

void Tallnut::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        delete this;
        return;
    }

    if (hp / 3 < hp_left && hp_left <= hp * 2 / 3 && hp_flag[1] == false)
    {
        hp_flag[0] = false;
        hp_flag[1] = true;
        if (movie)
            delete movie;
        movie = new QMovie(":/images/Plants/tallnut/2.gif");
        movie->start();
    }
    else if (0 < hp_left && hp_left <= hp / 3 && hp_flag[2] == false)
    {
        hp_flag[1] = false;
        hp_flag[2] = true;
        if (movie)
            delete movie;
        movie = new QMovie(":/images/Plants/tallnut/3.gif");
        movie->start();
    }
}


/*class Squash*/

Squash::Squash(): Plant("squash")
{
    hp = 300;
    hp_left = 300;
}

QRectF Squash::boundingRect() const
{
    if (state == 0)
        return QRectF(-80, -80, 160, 160);
    else
        return QRectF(-100, -280, 200, 400);
}

bool Squash::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{

    Q_UNUSED(mode)

    return other->type() == Zombie::Type && qAbs(other->y() - y()) < 50 && qAbs(other->x() - x()) < 200 && other->x() > x  ();
}

//state: 0:初始状态 1:跳起状态
void Squash::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        delete this;
        return;
    }

    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty()) //检测到右方有僵尸，转为跳起状态
    {
        if (state == 0)
        {
            state = 1;
            Zombie *zombie = qgraphicsitem_cast<Zombie *>(items[0]);
            setX(zombie->x());
            foreach (QGraphicsItem *item, items) //压死所有僵尸
            {
                zombie = qgraphicsitem_cast<Zombie *>(item);
                zombie->hp_left = 0;
            }
            if (movie)
                delete movie;
            movie = new QMovie(":/images/Plants/squash/2.gif");
            movie->setSpeed(50);
            movie->start();
            return;
        }
    }

    if (state == 1)
    {
        if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
    }
}


/*class Cherrybomb*/

Cherrybomb::Cherrybomb(): Plant("cherrybomb")
{
    hp = 300;
    hp_left = 300;
    movie->setSpeed(50);
}

QRectF Cherrybomb::boundingRect() const
{
    if (state == 0)
        return QRectF(-85, -60, 170, 120);
    else
        return QRectF(-300, -300, 600, 600);
}

bool Cherrybomb::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)

    return other->type() == Zombie::Type && qAbs(other->y() - y()) < 350 && qAbs(other->x() - x()) < 255;
}

//state: 0:初始状态 1:爆炸状态
void Cherrybomb::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        delete this;
        return;
    }

    if (state == 0)
    {
        if (movie->currentFrameNumber() == movie->frameCount() - 1)
        {
            state = 1;
            if(movie)
                delete movie;
            movie = new QMovie(":/images/Plants/cherrybomb/2.gif");
            movie->start();

            QList<QGraphicsItem *> items = collidingItems();
            foreach (QGraphicsItem *item, items)
            {
                Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
                zombie->hp_left = 0;
                zombie->state = 6;
                if (zombie->name == "catapultzombie")
                    zombie->Set_Body(":/images/Zombies/"+ zombie->name + "/bombdie.gif", 50);
                else
                    zombie->Set_Body(":/images/Zombies/"+ zombie->name + "/bombdie.gif");
            }
        }
    }
    else if (state == 1)
    {
        if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
    }
}


/*class Garlic*/

Garlic::Garlic(): Plant("garlic")
{
    hp = 400;
    hp_left = 400;
}

bool Garlic::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)

    return other->type() == Zombie::Type && qAbs(other->y()-y()) < 50 && qAbs(other->x() - x()) < 60 && other->x() > x();
}

void Garlic::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        delete this;
        return;
    }

    if (hp / 3 < hp_left && hp_left <= hp * 2 / 3 && hp_flag[1] == false)
    {
        hp_flag[0] = false;
        hp_flag[1] = true;
        if (movie)
            delete movie;
        movie = new QMovie(":/images/Plants/garlic/2.gif");
        movie->start();
    }
    else if (0 < hp_left && hp_left <= hp / 3 && hp_flag[2] == false)
    {
        hp_flag[1] = false;
        hp_flag[2] = true;
        if (movie)
            delete movie;
        movie = new QMovie(":/images/Plants/garlic/3.gif");
        movie->start();
    }

    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty()) //检测到右方有僵尸，则将该僵尸移至上下邻近任意一行
    {
        Zombie *zombie = qgraphicsitem_cast<Zombie *>(items[0]);
        if(qrand() % 2 == 1 || (int(zombie->y()) - 175) / 233 == 0)
            zombie->setY(zombie->y() + 233);
        else
            zombie->setY(zombie->y() - 233);
    }
}


/*class Pumpkin*/

Pumpkin::Pumpkin(): Plant("pumpkin")
{
    hp = 4000;
    hp_left = 4000;
}

QRectF Pumpkin::boundingRect() const
{
    return QRectF(-95, -20, 190, 140);
}

void Pumpkin::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (hp_left <= 0)
    {
        delete this;
        return;
    }

    if (hp / 3 < hp_left && hp_left <= hp * 2 / 3 && hp_flag[1] == false)
    {
        hp_flag[0] = false;
        hp_flag[1] = true;
        if (movie)
            delete movie;
        movie = new QMovie(":/images/Plants/pumpkin/2.gif");
        movie->start();
    }
    else if (0 < hp_left && hp_left <= hp / 3 && hp_flag[2] == false)
    {
        hp_flag[1] = false;
        hp_flag[2] = true;
        if (movie)
            delete movie;
        movie = new QMovie(":/images/Plants/pumpkin/3.gif");
        movie->start();
    }
}
