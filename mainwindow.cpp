#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "servicetech.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSound>
#include "login.h"
#include<QSqlQueryModel>
#include "clientetfinance.h"
#include "kiosque.h"
#include "Programmation.h"
#include "client.h"
#include "ClientF.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ID->setValidator(new QIntValidator(0,999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setid(QString s){id=s;}
void MainWindow::setmdp(QString s){mdp=s;}
QString MainWindow::getid(){return id;}
QString MainWindow::getmdp(){return mdp;}




    /*void MainWindow::on_Connect_clicked()
    {
        serviceTech d;
            d.setModal(true);
            d.exec();
        ui->stackedWidget->setCurrentIndex(2);
    }*/


void MainWindow::on_connect_clicked()
{

    QSqlQuery query;
    int id=ui->ID->text().toInt();
    QString mdp=ui->PWD->text();
    ui->ID->clear();
    ui->PWD->clear();
    if (templog.connect(id,mdp)==1)
    {
        if (id==123456)
        {
        QMessageBox::information(this,"connecter","Welcome to CinemApp :D");
        clientetfinance c;
             c.setModal(true);
             c.exec();
        }
        else
            if (id==654321)
            {
            QMessageBox::information(this,"connecter","Welcome to CinemApp :D");
            serviceTech d;
                d.setModal(true);
                d.exec();
            }
            else
                if (id==1234)
                {
                QMessageBox::information(this,"connecter","Welcome to CinemApp :D");
                kiosque k;
                      k.setModal(true);
                      k.exec();
                }
                else
                    if (id==12345)
                    {
                    QMessageBox::information(this,"connecter","Welcome to CinemApp :D");
                    Programmation p;
                        p.setModal(true);
                    p.exec();
                    }
    }
    else
    {
     QMessageBox::critical(this,"Login failed","incorrect id or pwd :(");
    }
}

/*

void MainWindow::on_connect_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_hama_clicked()
{
    serviceTech d;
        d.setModal(true);
        d.exec();
}

void MainWindow::on_wiem_clicked()
{
   clientetfinance c;
        c.setModal(true);
        c.exec();
}

void MainWindow::on_farah_clicked()
{
   kiosque k;
         k.setModal(true);
         k.exec();
}

void MainWindow::on_prog_clicked()
{ Programmation p;
    p.setModal(true);
p.exec();
}







void MainWindow::on_pushButton_clicked()
{

    clientetfinance c;
         c.setModal(true);
         c.exec();
}
*/
