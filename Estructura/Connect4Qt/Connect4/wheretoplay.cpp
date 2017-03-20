#include "wheretoplay.h"

WhereToPlay::WhereToPlay():QObject(),QGraphicsRectItem()
{
    valor=0;
}

void WhereToPlay::Movement(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Right)
    {
     setPos(x()-100,y());
    movimiento++;
    }

    if(e->key()==Qt::Key_Left)
    {
    setPos(x()+100,y());
    movimiento--;
    }
}
