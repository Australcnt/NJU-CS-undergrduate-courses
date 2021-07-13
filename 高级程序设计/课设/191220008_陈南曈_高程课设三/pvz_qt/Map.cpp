#include "Map.h"

Garden::Garden()
{
    setAcceptDrops(true);
}

QRectF Garden::boundingRect() const
{
    return QRectF(250, 175, 1710, 1165);
}

void Garden::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Garden::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasText())
    {
        event->setAccepted(true);

        update();
    }
    else
        event->setAccepted(false);
}

void Garden::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event)

    update();
}

void Garden::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasText())
    {
        QString str = event->mimeData()->text();
        QPointF pos = mapToScene(event->pos());
        pos.setX((int(pos.x()) - 210) / 190 * 190 + 250 + 50);
        pos.setY((int(pos.y()) - 175) / 233 * 233 + 175 + 116);
        if (str == "shovel")
        {
            Shovel *shovel = qgraphicsitem_cast<Shovel *>(scene()->items(QPointF(1700, 80))[0]);
            shovel->Remove_Plant(pos);
        }
        else
        {
            Store *store = qgraphicsitem_cast<Store *>(scene()->items(QPointF(350, 0))[0]);
            store->Add_Plant(str, pos);
        }
    }

    update();
}
