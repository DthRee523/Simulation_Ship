#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>

#include "network.h"
#include "serialporttool.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateData();

private:
    Ui::MainWindow *ui;
    Network *network;
    SerialPortTool *serialportTool;
    QTimer *timer;

    //data
    double lat = 60.5;
    double lon = -120.5;
    int speed = 60;
    int sx = 120;//艏向
    //hx data
    double power_left_gk = 0.0;
    double power_right_gk = 0.0;
    int ym_value = 0;//主油门指令
    int ym_value_1 = 0;//副油门指令
    int ry_value = 100;//剩余燃油
    int power_left_dw = 0;
    int power_right_dw = 0;
    double ele1_V = 0;//1号电机电压
    double ele2_V = 0;//2号电机电压
    double ele1_A = 0;//2号电机电流
    double ele2_A = 0;//2号电机电流
    int ele1_state = 0;//1#电机状态
    int ele2_state = 0;//2#电机状态
    int ele_an_state = 0;//岸电状态
    double ele_an_V = 0;//岸电电压
    double ele_an_A = 0;//岸电电流
    int duo_value = 90;//主舵角指令
    int duo_value_1 = 90;//副舵角指令
    int power_left_state = 0;//主机报警状态
    int power_right_state = 0;
    int ele1_state_1 = 0;//报警状态
    int ele2_state_2 = 0;

signals:
    void sendHxData(QByteArray data);
    void sendBaseData(QByteArray data);
    void sendData1(QByteArray data);

protected:
    void paintEvent(QPaintEvent *event) override;
};
#endif // MAINWINDOW_H
