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
    int timer; //�������ʱ�������
    int timeout; //����������ʱ��
    int produce; //������������
    qreal speed; //�����ƶ��ٶ�
    qreal pos_y_max; //�������������
    QMovie *movie; //sunshine.gif

public:
    Sunshine();//��Ȼ��������
    Sunshine(QPointF pos);//���տ���������
    ~Sunshine() override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

class PlantCard: public QGraphicsItem
{
private:
	int index; // ��Ʒ���
    QString name; // ��Ʒ����
	int price; // ��Ʒ�۸�
	int cd; // ��Ʒ��ȴʱ��
	int timer; // ��ʱ��
    bool cooldown_flag; // �Ƿ�������ȴ
public:
    void Set(int _index, QString _name, int _price, int _cd); // ������Ʒ��ز���

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
    void Remove_Plant(QPointF pos); //�Ƴ�ֲ��

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};

class Button: public QGraphicsItem
{
private:
    QSound *sound; //��������
    QTimer *timer; //������
public:
    Button(QSound *_sound, QTimer *_timer); //��ͣ/����

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

class Store: public QGraphicsItem
{
private:
    int sunshine; //������
    int interval; //��Ȼ��������ʱ����
    int timer; //��ʱ��
    PlantCard plant_card[10]; // ֲ�￨Ƭ����
public:
	Store();
    void Add_Plant(QString s, QPointF pos); //������ֲֲ��

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;

    friend class Sunshine;
    friend class PlantCard;
};

#endif
