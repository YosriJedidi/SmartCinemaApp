#include "Programmation.h"
#include "ui_Programmation.h"
#include "film.h"
#include "ticket.h"
#include "server.h"
#include "client.h"
#include "notificationP.h"
#include "excel.h"

#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QMainWindow>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>
#include <QPainter>
#include <QPdfWriter>
 QSound *sonClick;

Programmation::Programmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Programmation)
{
    ui->setupUi(this);
    ui->tableView_Film->setModel(tempFilm.afficherFilm());
    ui->tableView_Ticket->setModel(tempTicket.afficherTicket());
    sonClick=new QSound(":/new/son/Click.wav");
}

Programmation::~Programmation()
{
    delete ui;
}

void Programmation::on_pushButton_Chat_clicked() //chat
{
     notification n;
     n.notificationChat();
    sonClick->play();
    serverdialog = new Server(this);
    serverdialog->show();
    clientdialog = new Client(this);
    clientdialog->show();

}
void Programmation::on_pushButton_ajoutTicket_clicked()
{
    sonClick->play();
  notification n;
   int ID=ui->lineEdit_IDE->text().toInt();
   int NbPlaces=ui->lineEdit_NbPlaces->text().toInt();
   QString NomC=ui->lineEdit_nomC->text();
   QString DateF=ui->dateEdit->date().toString();
   QString HeureF=ui->timeEdit->time().toString();
   Ticket t(ID, NomC, NbPlaces, DateF, HeureF);
   ui->lineEdit_IDE->clear();
   ui->lineEdit_NbPlaces->clear();
   ui->lineEdit_nomC->clear();
   ui->dateEdit->clear();
   ui->timeEdit->clear();
   bool test=t.ajouterTicket();
   if (test)
   {
        n.notificationAT();
       ui->tableView_Ticket->setModel(tempTicket.afficherTicket());
       QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout avec succès \n click cancel to exit")
               ,QMessageBox::Cancel);
   }
   else
   {
       QMessageBox::critical(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout échoué \n click cancel to exit")
               ,QMessageBox::Cancel);
   }
}

void Programmation::on_pushButton_supprimerTicket_clicked()
{
    sonClick->play();
    notification n;
int id=ui->lineEdit_supprimerTicket->text().toInt();
ui->lineEdit_supprimerTicket->clear();
bool test = tempTicket.supprimerTicket(id);
if (test)
{
  n.notificationST();
    ui->tableView_Ticket->setModel(tempTicket.afficherTicket());
    QMessageBox::information(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression avec succès \n click cancel to exit")
            ,QMessageBox::Cancel);
}
else
{
    QMessageBox::critical(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression échouée \n click cancel to exit")
            ,QMessageBox::Cancel);
}
}


void Programmation::on_pushButton_ajoutFilm_clicked()
{
    sonClick->play();
    notification n;
    int ID=ui->lineEdit_ID->text().toInt();
    QString nom=ui->lineEdit_Nom->text();
    int duree=ui->lineEdit_duree->text().toInt();
    QString categorie=ui->lineEdit_categorie->text();
    Film f(ID ,nom , categorie, duree);
    ui->lineEdit_ID->clear();
    ui->lineEdit_Nom->clear();
    ui->lineEdit_duree->clear();
    ui->lineEdit_categorie->clear();
    bool test=f.ajouterFilm();
    if (test)
    {
        n.notificationAF();

         ui->tableView_Film->setModel(tempFilm.afficherFilm());
        QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout avec succés \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout échoué \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
}

void Programmation::on_pushButton_suppFilm_clicked()
{
    sonClick->play();
    notification n;
    int ID=ui->lineEdit_suppFilm->text().toInt();
    ui->lineEdit_suppFilm->clear();
    bool test = tempFilm.supprimerFilm(ID);
    if (test)
    {
    n.notificationSF();
        ui->tableView_Film->setModel(tempFilm.afficherFilm());
        QMessageBox::information(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression avec succés \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression échouée \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
}

void Programmation::on_pushButton_modifTicket_clicked()
{
    sonClick->play();
    notification n;
    int ID=ui->lineEdit_IDE->text().toInt();
    QString NomC=ui->lineEdit_nomC->text();
    QString DateF=ui->dateEdit->date().toString();
    QString HeureF=ui->timeEdit->time().toString();
    int NbPlaces=ui->lineEdit_NbPlaces->text().toInt();

Ticket t(ID,NomC,NbPlaces,DateF,HeureF);
bool test=t.modifTicket(ID);
        if(test)
        {
       n.notificationMT();
           ui->tableView_Ticket->setModel(tempTicket.afficherTicket());
                    QMessageBox::information(nullptr,QObject::tr("modification"),QObject::tr("modification avec succés \n click ok to exit")
                            ,QMessageBox::Ok);
                                           }
                else
                    QMessageBox::critical(nullptr,QObject::tr("modification"),QObject::tr("modification failed \n click cancel to exit")
                            ,QMessageBox::Ok);
}

void Programmation::on_pushButton_modifFilm_clicked()
{
    sonClick->play();
    notification n;
    int ID=ui->lineEdit_ID->text().toInt();
    QString nom=ui->lineEdit_Nom->text();
    int duree=ui->lineEdit_duree->text().toInt();
    QString categorie=ui->lineEdit_categorie->text();
    Film f(ID,nom,categorie,duree);
    ui->lineEdit_ID->clear();
    ui->lineEdit_Nom->clear();
    ui->lineEdit_duree->clear();
    ui->lineEdit_categorie->clear();
bool test=f.modifFilm(ID);
        if(test)
        {
      n.notificationMF();
           ui->tableView_Film->setModel(tempFilm.afficherFilm());
                    QMessageBox::information(nullptr,QObject::tr("modification"),QObject::tr("modification avec succés \n click ok to exit")
                            ,QMessageBox::Ok);
                                           }
                else
                    QMessageBox::critical(nullptr,QObject::tr("modification"),QObject::tr("modification failed \n click cancel to exit")
                            ,QMessageBox::Ok);
}


void Programmation::on_pushButton_clicked() //pdf
{
    sonClick->play();
Programmation w ;
    QPdfWriter pdf("C:/Users/Yosri Jedidi/Desktop/Cours 2A ESPRIT/QT/Export PDF/Liste Films.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::red);
                          painter.setFont(QFont("Arial", 25));
                          painter.drawText(950,1100,"Liste des Films");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 15));

                          painter.drawRect(100,100,7300,2600);
                          painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Yosri Jedidi/Desktop/Cours 2A ESPRIT/QT/cinemapp.png"));
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial", 9));
                          painter.drawText(200,3300,"ID Film");
                          painter.drawText(1300,3300,"Nom");
                          painter.drawText(2800,3300,"Catégorie");
                          painter.drawText(4000,3300,"Durée (min)");



                          QSqlQuery query;
                          query.prepare("select * from FILM");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1300,i,query.value(1).toString());
                              painter.drawText(2800,i,query.value(2).toString());
                              painter.drawText(4000,i,query.value(3).toString());



                             i = i + 500;
                          }
                          w.show();
                                  QMessageBox::information(nullptr,QObject::tr("Export PDF"),QObject::tr("Export effectué avec succès \n click cancel to exit")
                                          ,QMessageBox::Cancel);
    }



void Programmation::on_pushButton_2_clicked() //imprimer
{
    sonClick->play();
    QPrinter rd;
            QPrintDialog d(&rd,this);
            d.setWindowTitle("Print Liste Films");
            d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
            if (d.exec() != QDialog::Accepted)
                return ;
}


void Programmation::on_radioButton_clicked()
{
    sonClick->play();
     ui->tableView_Film->setModel(tempFilm.trier());
}

void Programmation::on_tableView_Film_activated(const QModelIndex &index)
{
    sonClick->play();
    QString ID=ui->tableView_Film->model()->data(index).toString();
          QSqlQuery query;
          query.prepare("select * from film where IDF LIKE '"+ID+"%' or NOM LIKE '"+ID+"%' or CATEGORIE LIKE '"+ID+"%' or DUREEF LIKE '"+ID+"%'");
          if(query.exec())
          {
            while(query.next())
            {
                ui->lineEdit_ID->setText(query.value(0).toString());
                ui->lineEdit_Nom->setText(query.value(1).toString());
                ui->lineEdit_categorie->setText(query.value(2).toString());
                ui->lineEdit_duree->setText(query.value(3).toString());
            }
          }
            else
            {

                //QMessageBox::critical(this,tr("error::"),query.lastError().text());
              QMessageBox::critical(nullptr, QObject::tr("error"),
                          QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
          }
}

void Programmation::on_pushButton_rechercheF_clicked()
{
    sonClick->play();
    QString id =ui->lineEdit_rechercheF->text();
       ui->tableView_Film->setModel(tempFilm.recherche(id));
}

void Programmation::on_pushButton_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                               tr("Excel Files (*.xls)"));
               if (fileName.isEmpty())
                   return;

               ExportExcelObject obj(fileName, "mydata", ui->tableView_Ticket);

               obj.addField(0, "Num_Ticket", "char(20)");
               obj.addField(1, "Nom", "char(20)");
               obj.addField(2, "Nb_Places", "char(20)");
               obj.addField(3, "Date_Ticket", "char(20)");
               obj.addField(4, "Heure_Ticket", "char(20)");

               int retVal = obj.export2Excel();

               if( retVal > 0)
               {
                   QMessageBox::information(this, tr("Done"),
                                            QString(tr("%1 records exported!")).arg(retVal)
                                            );
               }
}
