#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpServer>
#include<QTcpSocket>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mServer=new QTcpServer(this);
    mServer->listen(QHostAddress::Any,2000);
    mSocket=new QTcpSocket(this);

    connect(mServer,SIGNAL(newConnection()),this,SLOT(connexion_nueva()));

}

void MainWindow::connexion_nueva()
{
    mSocket=mServer->nextPendingConnection();
    connect(mSocket,SIGNAL(readyRead()),this,SLOT(leer_socket()));
}
void MainWindow:: leer_socket()
{
    QByteArray buffer;
    buffer.resize(mSocket->bytesAvailable());
    mSocket->read(buffer.data(),buffer.size());
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->appendPlainText(QString(buffer));
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    mSocket->write(ui->lineEdit->text().toLatin1().data(),ui->lineEdit->text().size());
    ui->plainTextEdit->appendPlainText(ui->lineEdit->text());
    ui->lineEdit->clear();
}
