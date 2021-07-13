#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <QMovie>
#include <QPainter>
#include <QGraphicsScene>
#include <QString>


class Bullet: public QGraphicsItem
{
protected:
    QString name; //名字
    qreal speed; //移动速度
    int attack; //攻击力
public:
    enum {Type = UserType + 3};
    int type() const override;

    Bullet(QString _name);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

class Pea: public Bullet
{
public:
    Pea();

    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

class Peaice: public Bullet
{
public:
    Peaice();

    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

class Basketball: public Bullet
{
private:
    int target_x;
    int target_y;
public:
    Basketball(int _target_x, int _target_y);

    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // BULLET_H
