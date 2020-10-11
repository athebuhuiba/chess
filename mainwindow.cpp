#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //绘制棋盘
    int x=0,y=0,temp=0;
    QPainter painter;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(temp==0){
                painter.setBrush(Qt::black);
                temp++;
            }
            else{
                painter.setBrush(Qt::white);
                temp--;
            }
        }
        QRect r(x,y,100,100);
        painter.drawRect(r);
        x+=100;
    }
    x=0;
    y+=100;
    if(temp==0){
        temp=1;
    }
    else{
        temp=0;
    }
}


