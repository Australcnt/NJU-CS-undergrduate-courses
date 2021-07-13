#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSound>
#include <QTimer>

#include "Store.h"
#include "Map.h"
#include "Zombie.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT
private:
    QSound *sound; //背景音乐
    QTimer *timer; //计时器
    QGraphicsScene *scene; //场景
    QGraphicsView *view; //视图
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Create_Zombie(); //产生僵尸
    void Gameover_Check(); //判断游戏结束

    void mousePressEvent(QMouseEvent *e);
};

#endif // MAINWINDOW_H
