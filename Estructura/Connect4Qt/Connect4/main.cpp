
#include <QApplication>
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QObject>
#include <QDebug>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <wheretoplay.h>
using namespace std;
void Menu()
    {


    QDesktopWidget widget;
    QRect rec = widget.availableGeometry(widget.primaryScreen());
    int height = rec.height();
    int width = rec.width();
    QGraphicsScene *Background=new QGraphicsScene();

    QGraphicsView *Window=new QGraphicsView(Background);

    WhereToPlay *donde= new WhereToPlay();

    donde->setRect(0,0,100,100);
    donde->setFlag(QGraphicsItem::ItemIsFocusable);
    donde->setFocus();
    Background->addItem(donde);
    /*
    Window->setAlignment(Qt::AlignBaseline);
    Window->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Window->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Window->setBaseSize(width,height-30);
    Window->resize(width,height-30);
    */
    Window->show();
    //Background->setSceneRect(0,0,Window->width(),Window->height());

    }

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu();
    return a.exec();
}
