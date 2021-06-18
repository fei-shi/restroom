#ifndef PERSON_H
#define PERSON_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QDebug>

class person : public QWidget
{
    Q_OBJECT
public:
    explicit person(QWidget *parent = nullptr);
    QPixmap person1;
signals:

};

#endif // PERSON_H
