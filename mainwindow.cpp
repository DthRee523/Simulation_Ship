#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    network = new Network(this);
    serialportTool = new SerialPortTool(this);
    this->setMaximumSize(1024, 600);
    this->setMinimumSize(1024, 600);
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    timer = new QTimer(this);
    timer->setInterval(500);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateData);
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateData()
{

    QByteArray baseData;
    baseData.resize(19);
    QByteArray hxData;
    hxData.resize(29);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::yellow);
    painter.drawLine(0, 100, 1024, 100);
}

