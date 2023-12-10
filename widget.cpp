#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);//начало

    QPen pen;
    pen.setColor(Qt::black);//контур
    pen.setWidth(5);// толщина ручки

    QBrush brush;// заливка

    brush.setColor(Qt::white);//цвет заливки
    painter.setPen(pen);// включаем ручку все что связано с ручкой
    brush.setStyle(Qt::SolidPattern);//вид заливки
    painter.setBrush(brush);//включаем заливку

    painter.drawEllipse(10,10,300,300);//включаем рисование
if(ui->horizontalSlider->value()>66)
{
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(10,10,300,300);
    update();
}
if(ui->horizontalSlider->value()<33)
{
    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    painter.drawEllipse(10,10,300,300);
    update();
}
if(ui->horizontalSlider->value()>33 && ui->horizontalSlider->value()<66)
{
    painter.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    painter.drawEllipse(10,10,300,300);
    update();
}





    painter.end();//конец


}
Widget::~Widget()
{
    delete ui;
}

