#include "ticket.h"

Ticket::Ticket()
{
ID=0;
NbPlaces=0;
NomC="";
DateF="";
HeureF="";
}
Ticket::Ticket(int ID, QString NomC, int NbPlaces, QString DateF, QString HeureF)
{
 this->ID=ID;
 this->NbPlaces=NbPlaces;
 this->NomC=NomC;
 this->DateF=DateF;
 this->HeureF=HeureF;
}
bool Ticket::ajouterTicket()
{
  QSqlQuery query;
  QString idt=QString::number(ID);
  QString NbPlacesf=QString::number(NbPlaces);
  query.prepare("INSERT INTO TICKET(IDT,NOMC,NBPLACESF,DATEF,HEUREF)""VALUES(:ID,:NomC,:NbPlaces,:DateF,:HeureF)");
  query.bindValue(":ID",idt);
  query.bindValue(":NomC",NomC);
  query.bindValue(":NbPlaces",NbPlacesf);
  query.bindValue(":DateF",DateF);
  query.bindValue(":HeureF",HeureF);
  return query.exec();
}
bool  Ticket:: modifTicket(int IDt)
{
    QSqlQuery query;
    QString idt=QString::number(IDt);
    QString NbPlacesf=QString::number(NbPlaces);
    query.prepare("update ticket set IDT = :Id , NOMC = :NomC , NBPLACESF = :NbPlaces , DATEF = :DateF , HEUREF = :HeureF where IDT = :Id");
    query.bindValue(":ID",idt);
    query.bindValue(":Id",ID);
    query.bindValue(":NomC",NomC);
    query.bindValue(":NbPlaces",NbPlaces);
    query.bindValue(":DateF",DateF);
    query.bindValue(":HeureF",HeureF);

    return    query.exec();
}
void Ticket::setNbPlaces(int NbPlaces)
{
    this->NbPlaces=NbPlaces;
}
void Ticket::setDate(QString DateF)
{
  this->DateF=DateF;

}
void Ticket::setNomC(QString NomC)
{
  this->NomC=NomC;

}
void Ticket::setHeure(QString HeureF)
{
  this->HeureF=HeureF;
}
QSqlQueryModel * Ticket::afficherTicket()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Ticket");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom Client"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nombre Places"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Heure"));
    return model;
}
bool Ticket::supprimerTicket(int ID)
{
    QSqlQuery query;
    QString idf=QString::number(ID);
    query.prepare("Delete from Ticket where IDT=:ID");
    query.bindValue(":ID",idf);
    return query.exec();
}

