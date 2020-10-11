#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include <QTime>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int map[8][8];
    bool state;
    void paintEvent(QPaintEvent*);
    QPushButton *button;
    QPushButton *button1;
    QPushButton *button2;
//public slots:
    //void slotStart();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
