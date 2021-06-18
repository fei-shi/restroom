#include "test.h"
#include "ui_test.h"

test::test(QWidget *parent)
    : QMainWindow(parent)
{
    test1.load(":/backg.jpg");
    setFixedSize(test1.size());
    test2.load(":/1.png");
    doori.load(":/8.png");
    bed.load(":/7.png");
    enteract=false;
    x=new QTimer(this);
    y=new QTimer(this);
    tmd.setX(-60);tmd.setY(45);
    connect(y,&QTimer::timeout,[=](){
        tmd.setX(tmd.x()+10);
        if(tmd.x()==-20){y->stop();x->start(200);}
        update();
    });
    doorp.setX(0);doorp.setY(41);
    connect(x,&QTimer::timeout,[=](){
        doorp.setY(doorp.y()-10);
        if(doorp.y()==1){x->stop();enteract=true;}
        qDebug()<<doorp.y();
        update();
    });
    y->start(200);
    setWindowTitle(QString::fromLocal8Bit("补给点"));
}

test::~test()
{
    delete ui;
}

void test::paintEvent(QPaintEvent *)
{
    QPainter pa(this);
    pa.drawPixmap(0,0,test1.width(),test1.height(),test1);
    pa.drawImage(0,0,bed);
    pa.drawImage(tmd.x(),tmd.y(),test2);

    qDebug()<<tmd.x()<<"  "<<tmd.y();
    pa.drawImage(doorp.x(),doorp.y(),doori);


}

void test::keyReleaseEvent(QKeyEvent *e)
{

}

void test::keyPressEvent(QKeyEvent *e)
{
    if(enteract)
    {
        qDebug()<<"jljl";
        if(QChar(e->key())==Qt::Key_W)
        {
            qDebug()<<"w";
            if((tmd.y()+25)>10)tmd.setY(tmd.y()-10);
            else    tmd.setY(-25);
                update();
            qDebug()<<tmd.y()<<"is y";
        }
        if(e->key()==Qt::Key_A)
        {
            qDebug()<<"a";
            if((tmd.x()+30)<10)tmd.setX(-30);
            else   tmd.setX(tmd.x()-10);
            update();
        }
        if(e->key()==Qt::Key_S)
        {
            qDebug()<<"s";
            if((115-tmd.y())>10)tmd.setY(tmd.y()+10);
            else    tmd.setY(115);
            update();
        }
        if(e->key()==Qt::Key_D)
        {
            qDebug()<<"d";
            if((230-tmd.x())<10)tmd.setX(230);
            else    tmd.setX(tmd.x()+10);
            update();
        }
    }
}
