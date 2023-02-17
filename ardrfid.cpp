#include "ardrfid.h"
#include "ui_ardrfid.h"
#include "arduino.h"
ardrfid::ardrfid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ardrfid)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
       switch(ret){
       case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
           break;
       case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
          break;
       case(-1):qDebug() << "arduino is not available";
       }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
        //le slot update_label suite à la reception du signal readyRead (reception des données).
}

ardrfid::~ardrfid()
{
    delete ui;
}
void ardrfid::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")
        ui->label_msg->setText("Yosri (PROGRAMMATION) est entré"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher msg

    else if (data=="2")

        ui->label_msg->setText("Mohamed (SERVCE TECHNIQUE) est entré");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher msg



}
void ardrfid::on_ouvrir_clicked()
{
  A.write_to_arduino("3"); //envoyer 1 à arduino
}

void ardrfid::on_fermer_clicked()
{
   A.write_to_arduino("4"); //envoyer 0 à arduino
}
