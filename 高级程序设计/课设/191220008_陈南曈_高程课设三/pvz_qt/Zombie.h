#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsItem>
#include <QMovie>
#include <QDebug>
#include <QPainter>
#include <QGraphicsScene>

const int ZOMBIE_TYPE_MAX = 6; // ��ʬ������

class Zombie: public QGraphicsItem
{
protected:
    QString name; //��ʬ����
    int hp; //��ʬѪ��
    int hp_left; //��ʬʣ��Ѫ��
    bool hp_flag[3]; //��ʬѪ���׶�
    int attack; //��ʬ������
    qreal speed; //��ʬ�ƶ��ٶ�
    int state; // ��ʬ״̬
    bool freezing_flag; //��ʬ�Ƿ񱻱���

    QMovie *head; //xxx.gif
    QMovie *body; //xxx.gif
public:
    enum {Type = UserType + 2};
    int type() const override;

    Zombie(QString _name = "zombie");
    ~Zombie() override;
    void Set_Body(QString path, int percent_speed = 100);
    void Set_Head(QString path, int percent_speed = 100);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;

    friend class Plant;
    friend class Squash;
    friend class Cherrybomb;
    friend class Bullet;
    friend class Pea;
    friend class Peaice;
};

class Coneheadzombie: public Zombie
{
public:
    Coneheadzombie();

    QRectF boundingRect() const override;
    void advance(int phase) override;
};

class Newspaperzombie: public Zombie
{
public:
    Newspaperzombie();

    QRectF boundingRect() const override;
    void advance(int phase) override;
};

class Polevaultingzombie: public Zombie
{
private:
    bool pole_flag; //�Ƿ��гŸ�
public:
    Polevaultingzombie();

    QRectF boundingRect() const override;
    void advance(int phase) override;
};

class Jackintheboxzombie: public Zombie
{
public:
    Jackintheboxzombie();

    QRectF boundingRect() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

class Catapultzombie: public Zombie
{
private:
    int interval; //Ͷ��ʱ����
    int timer; //��ʱ��
    int basketball_left; //ʣ����������
public:
    Catapultzombie();

    QRectF boundingRect() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

#endif // ZOMBIE_H
