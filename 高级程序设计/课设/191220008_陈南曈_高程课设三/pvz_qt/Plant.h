#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsItem>
#include <QMovie>
#include <QPainter>
#include <QGraphicsScene>

#include "Store.h"
#include "Bullet.h"

const int PLANT_TYPE_MAX = 10; // ֲ��������

class Plant: public QGraphicsItem
{
protected:
    QString name; // ֲ������
    int hp; // ֲ��Ѫ��
    int hp_left; // ֲ��ʣ��Ѫ��
    int hp_flag[3]; //ֲ��Ѫ���׶�
    int state; //ֲ��״̬

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
    int interval; //��������ʱ����
    int timer; //��ʱ��
public:
    Sunflower();

    void advance(int phase) override;
};

class Peashooter: public Plant
{
private:
    int interval; //�����㶹ʱ����
    int timer; //��ʱ��
public:
    Peashooter();

    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

class Repeater: public Plant
{
private:
    int interval; //�����㶹ʱ����
    int timer; //��ʱ��
public:
    Repeater();

    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

class Snowpea: public Plant
{
private:
    int interval; //�����㶹ʱ����
    int timer; //��ʱ��
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
