#ifndef STORE_H
#define STORE_H

#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include <QWidget>
#include <QTime>
#include <QSound>

class Sunshine: public QGraphicsItem
{
private:
    int timer; //阳光存在时间计数器
    int timeout; //阳光最大存在时间
    int produce; //单个阳光数量
    qreal speed; //阳光移动速度
    qreal pos_y_max; //阳光最大纵坐标
    QMovie *movie; //sunshine.gif

public:
    Sunshine();//自然产生阳光
    Sunshine(QPointF pos);//向日葵产生阳光
    ~Sunshine() override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

class PlantCard: public QGraphicsItem
{
private:
	int index; // 商品序号
    QString name; // 商品名字
	int price; // 商品价格
	int cd; // 商品冷却时间
	int timer; // 计时器
    bool cooldown_flag; // 是否正在冷却
public:
    void Set(int _index, QString _name, int _price, int _cd); // 设置商品相关参数

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

	friend class Store;
};

class Shovel: public QGraphicsItem
{
public:
    Shovel();
    void Remove_Plant(QPointF pos); //移除植物

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};

class Button: public QGraphicsItem
{
private:
    QSound *sound; //背景音乐
    QTimer *timer; //计数器
public:
    Button(QSound *_sound, QTimer *_timer); //暂停/继续

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

class Store: public QGraphicsItem
{
private:
    int sunshine; //阳光数
    int interval; //自然产生阳光时间间隔
    int timer; //计时器
    PlantCard plant_card[10]; // 植物卡片序列
public:
	Store();
    void Add_Plant(QString s, QPointF pos); //购买并种植植物

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;

    friend class Sunshine;
    friend class PlantCard;
};

#endif
