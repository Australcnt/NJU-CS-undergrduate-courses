#include "mainwindow.h"

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        qDebug() << e->x() << " "<< e->y();
    }
}

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    //设置窗口
    setWindowTitle("植物大战僵尸 - Plants vs. Zombies by Australcnt");
    setWindowIcon(QPixmap(":/images/Interface/SmallLogo.png"));
    setFixedSize(2150, 1402);

    //设置背景图片
    QPixmap pix;
    pix.load(":/images/Interface/background.jpg");
    pix = pix.scaled(1400 * 7 / 3, 1400);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(350, 0, 2100, 1400);
    scene->setBackgroundBrush(pix);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    //设置背景音乐
    sound = new QSound(":/audios/bgm.wav");
    sound->setLoops(QSound::Infinite);
    sound->play();

    //设置计时器
    timer = new QTimer;
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &MainWindow::Create_Zombie);
    connect(timer, &QTimer::timeout, this, &MainWindow::Gameover_Check);
    timer->start(10); //设置时钟周期10ms

    //创建商店
    Store *store = new Store;
    store->setPos(350, 0);
    scene->addItem(store);

    //创建铲子
    Shovel *shovel = new Shovel;
    shovel->setPos(1830, 70);
    scene->addItem(shovel);

    //创建暂停/继续按钮
    Button *button = new Button(sound, timer);
    button->setPos(2360, 30);
    scene->addItem(button);

    //创建花园
    Garden *garden = new Garden;
    garden->setPos(350, 0);
    scene->addItem(garden);

    view = new QGraphicsView(this);
    view->setScene(scene);
    view->resize(2150, 1402);
    view->show();
}

MainWindow::~MainWindow()
{
    delete sound;
    delete timer;
    delete scene;
    delete view;
}

void MainWindow::Create_Zombie() //产生僵尸
{
    static int interval = 1000;
    static int timer = 0;

    if (timer + 1 == interval)
    {
        timer = 0;
        Zombie *zombie = nullptr;
        int type = qrand() % ZOMBIE_TYPE_MAX;
        switch(type)
        {
        case 0: zombie = new Zombie; break;
        case 1: zombie = new Coneheadzombie; break;
        case 2: zombie = new Newspaperzombie; break;
        case 3: zombie = new Polevaultingzombie; break;
        case 4: zombie = new Jackintheboxzombie; break;
        case 5: zombie = new Catapultzombie; break;
        default: zombie = new Zombie; break;
        }

        int i = qrand() % 5;
        zombie->setPos(350 + 1960 + 200, 175 + 233 * i + 110);
        scene->addItem(zombie);
    }
    else
    {
        timer++;
    }
}

void MainWindow::Gameover_Check() //判断游戏结束
{
    static int interval = 100;
    static int timer = 0;

    if (timer + 1 >= interval)
    {
        timer = 0;
        const QList<QGraphicsItem *> items = scene->items();
        foreach (QGraphicsItem *item, items)
        {
            if (item->type() == Zombie::Type && item->x() < 400)
            {
                QPixmap pix;
                pix.load(":/images/Interface/gameover.png");
                pix = pix.scaled(pix.width() * 2, pix.height() * 2);
                scene->addPixmap(pix)->setPos(900, 250);
                scene->advance();
                this->timer->stop();
                return;
            }
        }
    }
    else
    {
        timer++;
    }
}
