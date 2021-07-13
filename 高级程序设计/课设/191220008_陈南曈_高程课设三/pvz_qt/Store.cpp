#include "Store.h"
#include "Plant.h"

/*class Sunshine*/

Sunshine::Sunshine() //��Ȼ��������
{
    timer = 0;
    timeout = 1000;
    produce = 25;
    speed = 1;

    pos_y_max = 300 + qrand() % (1400 - 300 - 100);
    movie = new QMovie(":/images/Interface/Sunshine.gif");
    movie->start();

    setPos(QPointF(350 + 250 + qrand() % (1710 - 100), 0));
}

Sunshine::Sunshine(QPointF pos) //���տ���������
{
    timer = 0;
    timeout = 1000;
    produce = 25;
    speed = 1;

    pos_y_max = pos.y() - 100;
    movie = new QMovie(":/images/Interface/Sunshine.gif");
    movie->start();

    setPos(QPointF(pos.x() + qrand() % 60 - 30, pos.y()));
}

Sunshine::~Sunshine()
{
    if(movie != nullptr)
        delete movie;
}

QRectF Sunshine::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void Sunshine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawImage(boundingRect(), movie->currentImage());
}

void Sunshine::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (timer + 1 >= timeout)
        delete this;
    else
    {
        if (y() < pos_y_max)
            setY(y() + speed);
        timer++;
    }
}

void Sunshine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Store *store = qgraphicsitem_cast<Store *>(scene()->items(QPointF(350, 0))[0]);
    store->sunshine += produce;
    timer = timeout - 1;
    event->setAccepted(true);
}


/*class PlantCard*/

void PlantCard::Set(int _index, QString _name, int _price, int _cd)
{
	index = _index;
	name = _name;
	price = _price;
	cd = _cd;
	timer = 0;
	cooldown_flag = false;

    setPos(165 + 120 * index, 15);
}

QRectF PlantCard::boundingRect() const
{
    return QRectF(0, 0, 120, 140);
}

void PlantCard::paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawPixmap(QRect(0, 0, 120, 140), QPixmap(":/images/Cards/" + name + ".png"));

    if (cooldown_flag) //��ȴ��Ӱ
    {
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRect(0, 0, 120, 140 * (1 - qreal(timer) / cd)));
    }
}

void PlantCard::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (cooldown_flag) //��ȴ
    {
        if (timer + 1 >= cd)
        {
            cooldown_flag = false;
            timer = 0;
        }
        else
        {
            timer++;
        }
    }
}

void PlantCard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (cooldown_flag) //��ȴ״̬�޷�����
        event->setAccepted(false);

    Store *store = qgraphicsitem_cast<Store *>(parentItem());
    if (price > store->sunshine) //���ⲻ���޷�����
        event->setAccepted(false);
}

void PlantCard::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()< QApplication::startDragDistance())
        return;

    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    QImage image(":/images/Plants/" + name + "/0.gif");
    image = image.scaled(image.width() * 2, image.height() * 2);

    mime->setText(name);
    mime->setImageData(image);

    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image));
    drag->setHotSpot(QPoint(image.width() / 2, image.height() / 2));
    drag->exec();
}


/*class Shovel*/

Shovel::Shovel()
{
    ;
}

void Shovel::Remove_Plant(QPointF pos) //�Ƴ�ֲ��
{
    QList<QGraphicsItem *> items = scene()->items(pos);
    foreach (QGraphicsItem *item, items) //�����Ϲ�ͷ��Ҳһ���Ƴ�
    {
        if (item->type() == Plant::Type)
        {
            delete item;
        }
    }
}

QRectF Shovel::boundingRect() const
{
    return QRectF(-80, -80, 160, 160);
}

void Shovel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawPixmap(QRect(-80, -80, 160, 160), QPixmap(":/images/Interface/shovelslot.png"));
    painter->drawPixmap(QRect(-70, -70, 140, 140), QPixmap(":/images/Interface/shovel.png"));
}

void Shovel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)

    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length() < QApplication::startDragDistance())
        return;

    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    QImage image(":/images/Interface/shovel.png");

    mime->setText("shovel");
    mime->setImageData(image);

    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image).scaled(140, 140));
    drag->setHotSpot(QPoint(70, 70));
    drag->exec();

    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)

    setCursor(Qt::ArrowCursor);
}


/*class Button*/

Button::Button(QSound *_sound, QTimer *_timer)
{
    sound = _sound;
    timer = _timer;
}

QRectF Button::boundingRect() const
{
    return QRectF(-120, -30, 240, 60);
}

void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawPixmap(QRect(-120, -30, 240, 60), QPixmap(":/images/Interface/button.png"));
    painter->setPen(Qt::green);
    QFont font("Calibri", 15, QFont::Bold, true);
    painter->setFont(font);
    if (timer->isActive()) //���Ѿ�����ͣ
        painter->drawText(boundingRect(), Qt::AlignCenter, "PAUSE"); //������ͣ��ť
    else
        painter->drawText(boundingRect(), Qt::AlignCenter, "CONTINUE"); //���Ƽ�����ť
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (timer->isActive())
        {
            sound->stop(); //��ͣ��������
            timer->stop(); //��ͣ������
        }
        else
        {
            sound->play(); //������������
            timer->start(); //����������
        }
    }

    update();
}


/*class Store*/

Store::Store()
{
    plant_card[0].Set(0, "sunflower", 50, 500); plant_card[0].setParentItem(this);
    plant_card[1].Set(1, "peashooter", 100, 750); plant_card[1].setParentItem(this);
    plant_card[2].Set(2, "repeater", 200, 750); plant_card[2].setParentItem(this);
    plant_card[3].Set(3, "snowpea", 175, 750); plant_card[3].setParentItem(this);
    plant_card[4].Set(4, "wallnut", 50, 1000); plant_card[4].setParentItem(this);
    plant_card[5].Set(5, "tallnut", 125, 1250); plant_card[5].setParentItem(this);
    plant_card[6].Set(6, "squash", 50, 1250); plant_card[6].setParentItem(this);
    plant_card[7].Set(7, "cherrybomb", 150, 1250); plant_card[7].setParentItem(this);
    plant_card[8].Set(8, "garlic", 50, 750); plant_card[8].setParentItem(this);
    plant_card[9].Set(9, "pumpkin", 125, 1250); plant_card[9].setParentItem(this);

    sunshine = 1000;
    interval = 1000;
	timer = 0;
}

void Store::Add_Plant(QString _name, QPointF pos) //������ֲֲ��
{
    QList<QGraphicsItem *> items = scene()->items(pos);
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i]->type()==Plant::Type)//���õؿ���ֲ����޷���ֲ
        {
            qDebug() << "This sward has already been planted";
            Plant *plant = qgraphicsitem_cast<Plant *>(items[i]);
            if((plant->name == "pumpkin") == (_name =="pumpkin")) //�����߶����Ϲ�ͷ���߶������Ϲ�ͷ�����޷���ֲ
                return;
        }
    }

    int index = -1;
    for(int i = 0; i < PLANT_TYPE_MAX; i++)
    {
        if(plant_card[i].name == _name)//�ҵ�
        {
            index = i;
            break;
        }
    }

    sunshine -= plant_card[index].price;//��������

    Plant *plant = nullptr;
    switch (index)
    {
    case 0: plant = new Sunflower; break;
    case 1: plant = new Peashooter; break;
    case 2: plant = new Repeater; break;
    case 3: plant = new Snowpea; break;
    case 4: plant = new Wallnut; break;
    case 5: plant = new Tallnut; break;
    case 6: plant = new Squash; break;
    case 7: plant = new Cherrybomb; break;
    case 8: plant = new Garlic; break;
    case 9: plant = new Pumpkin; break;
    default:break;
    }
    plant->setPos(pos);
    scene()->addItem(plant);

    QList<QGraphicsItem *> tempcards = childItems();
    for(int i = 0; i < tempcards.size(); i++)
    {
        PlantCard *plantcard = qgraphicsitem_cast<PlantCard *>(tempcards[i]);
        if (plantcard->index == index)
        {
            plantcard->timer = 0;
            plantcard->cooldown_flag = true; //תΪ��ȴ״̬
        }
    }
}

QRectF Store::boundingRect() const
{
    return QRectF(0, 0, 1400, 172);
}

void Store::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawPixmap(QRect(0, 0, 1400, 172), QPixmap(":/images/Interface/Store.png")); //�����̵�

    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(QRectF(4, 120, 140, 44), Qt::AlignCenter, QString::number(sunshine)); //����������
}

void Store::advance(int phase)
{
    if (!phase)
        return;

    update();

    if (timer + 1 >= interval)
    {
        scene()->addItem(new Sunshine); //��Ȼ��������
        timer = 0;
    }
    else
    {
        timer++;
    }
}
