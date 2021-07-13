#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsItem>
#include <QMovie>
#include <QPainter>
#include <QGraphicsScene>

#include "Store.h"
#include "Bullet.h"

const int PLANT_TYPE_MAX = 10; // 植物种类数

class Plant: public QGraphicsItem
{
protected:
    QString name; // 植物名字
    int hp; // 植物血量
    int hp_left; // 植物剩余血量
    int hp_flag[3]; //植物血量阶段
    int state; //植物状态

    QMovie *movie; //xxx.gif
public:
    enum { Type = UserType + 1};
    int type() const override;

    Plant(QString _name);
    ~Plant() override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;

    friend class Store;
    friend class Basketball;
    friend class Zombie;
    friend class Coneheadzombie;
    friend class Newspaperzombie;
    friend class Polevaultingzombie;
    friend class Jackintheboxzombie;
    friend class Catapultzombie;
};


class Sunflower: public Plant
{
private:
    int interval; //产生阳光时间间隔
    int timer; //计时器
public:
    Sunflower();

    void advance(int phase) override;
};

class Peashooter: public Plant
{
private:
    int interval; //发射豌豆时间间隔
    int timer; //计时器
public:
    Peashooter();

    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

class Repeater: public Plant
{
private:
    int interval; //发射豌豆时间间隔
    int timer; //计时器
public:
    Repeater();

    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

class Snowpea: public Plant
{
private:
    int interval; //发射豌豆时间间隔
    int timer; //计时器
public:
    Snowpea();

    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

class Wallnut: public Plant
{
public:
    Wallnut();

    void advance(int phase) override;
};

class Tallnut: public Plant
{
public:
    Tallnut();

    QRectF boundingRect() const override;
    void advance(int phase) override;
};

class Squash: public Plant
{
public:
    Squash();

    QRectF boundingRect() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

class Cherrybomb: public Plant
{
public:
    Cherrybomb();

    QRectF boundingRect() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

class Garlic: public Plant
{
public:
    Garlic();

    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

class Pumpkin: public Plant
{
public:
    Pumpkin();

    QRectF boundingRect() const override;
    void advance(int phase) override;
};

#endif // PLANT_H
