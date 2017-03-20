#ifndef WHERETOPLAY_H
#define WHERETOPLAY_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QKeyEvent>
class WhereToPlay:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
private:
    int valor;

public:
int movimiento;
    WhereToPlay();
            int get_Valor() {
                return valor;   //Ayudan al manejo de las fichas para las graficas y calculos
            }
            void set_Valor(int a) {
                valor=a;
            }
    void Movement(QKeyEvent *e);
};

#endif // WHERETOPLAY_H
