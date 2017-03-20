
#include <QApplication>
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QObject>

using namespace std;
class Jugador
{
    private:
    char *nombre;
    int juego;
    public :
        Jugador(){nombre=NULL;juego=1;}
        void set_Nombre(char* a){nombre=a;}
        void set_jugando(int a){juego=a;}
        int get_jugando(){return juego;}
        char* get_Nombre(){return nombre;}
        void Imprimir(){cout<<"Jugador :"<<nombre<<endl;}
};
class Ficha : public QObject , public QGraphicsRectItem
{
Q_OBJECT
private:
    int valor;
 public:
        Ficha(){
            valor=0;
               }
        int get_Valor(){return valor;}//Ayudan al manejo de las fichas su
        void set_Valor(int a){valor=a;}
        void Imprimir(){cout<<"| "<<valor<<" |";}
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);




    QGraphicsScene *Background=new QGraphicsScene();

    QGraphicsRectItem *Item=new QGraphicsRectItem();

    Item->setRect(0,0,100,100);

    Background->addItem(Item);

    QGraphicsView *Window=new QGraphicsView(Background);


    Window->show();

    return a.exec();
}
