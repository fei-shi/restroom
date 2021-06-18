#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QImage>
#include <QKeyEvent>
#include <QDebug>

#include "person.h"
QT_BEGIN_NAMESPACE
namespace Ui { class test; }
QT_END_NAMESPACE

class test : public QMainWindow
{
    Q_OBJECT

public:
    test(QWidget *parent = nullptr);
    ~test();

    void paintEvent(QPaintEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void keyPressEvent(QKeyEvent *e);
    QPixmap test1;
    QImage test2;
    QImage doori;
    QImage bed;
    person *a;
    QTimer *x,*y;
    QPoint tmd,doorp;
    bool enteract;
private:
    Ui::test *ui;
};
#endif // TEST_H
