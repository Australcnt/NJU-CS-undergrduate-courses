#include "Bullet.h"
#include "Zombie.h"
#include "Plant.h"


/*class Bullet*/

Bullet::Bullet(QString _name)
{
    name = _name;
    speed = 0;
    attack = 0;
}

int Bullet::type() const
{
    return Type;
}

QRectF Bullet::boundingRect() const
{
    return QRectF(-30, -56, 60, 60);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawPixmap(QRect(-24, -56, 48, 48), QPixmap(":/images/Bullets/" + name + "/0.png"));
}


/*class Pea*/

Pea::Pea(): Bullet("pea")
{
    attack = 25;
    speed = 4;
}

bool Pea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)

    return other->type() == Zombie::Type && qAbs(other->y() - y()) < 10 && qAbs(other->x() - x()) < 40 && other->x() > x();
}

void Pea::advance(int phase)
{
    if (!phase)
        return;

    update();

    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty()) //击中僵尸
    {
        Zombie *zombie = qgraphicsitem_cast<Zombie *>(items[0]);
        zombie->hp_left -= attack;
        delete this;
        return;
    }

    setX(x() + speed);

    if (x() > 2500)
        delete this;
}


/*class Peaice*/

Peaice::Peaice(): Bullet("peaice")
{
    attack = 25;
    speed = 4;
}

bool Peaice::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)

    return other->type() == Zombie::Type && qAbs(other->y()-y()) < 10 && qAbs(other->x() - x()) < 40 && other->x() > x();
}

void Peaice::advance(int phase)
{
    if (!phase)
        return;

    update();

    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty()) //击中僵尸
    {
        Zombie *zombie = qgraphicsitem_cast<Zombie *>(items[0]);
        zombie->hp_left -= attack;
        if(!zombie->freezing_flag)
        {
            zombie->speed /= 2;
            zombie->freezing_flag = true;
        }
        delete this;
        return;
    }

    setX(x() + speed);

    if (x() > 2500)
        delete this;
}


/*class Basketball*/

Basketball::Basketball(int _target_x, int _target_y): Bullet("basketball")
{
    attack = 20;
    speed = 6;
    target_x = _target_x;
    target_y = _target_y;
}

bool Basketball::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)

    //同一行，x距离小于30、y距离小于30且在篮球左侧的植物
    return other->type() == Plant::Type && qAbs(other->y() - y()) < 80 && other->y() - y() == 0 && qAbs(other->x() - x()) < 30 && other->x() - x() <= 0;
}

void Basketball::advance(int phase)
{
    if (!phase)
        return;

    update();

    if(qAbs(x() - target_x) < 50 && y() != target_y) //篮球下落
    {
        setPos(target_x, target_y);
        return;
    }

    if(x() == target_x && y() == target_y)
    {
        QList<QGraphicsItem *> items = collidingItems();
        if (!items.isEmpty())
        {
            Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
            foreach (QGraphicsItem *item, items)
            {
                if (qgraphicsitem_cast<Plant *>(item)->name == "pumpkin")
                    plant = qgraphicsitem_cast<Plant *>(item);
            }
            plant->hp_left -= attack;
        }
        delete this;
        return;
    }

    setX(x() - speed);

    if (x() < 0)
        delete this;
}
