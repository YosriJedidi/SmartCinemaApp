#include "salle.h"

Salle::Salle()
{
num=0;
capacite=0;
etat="";
}
Salle::Salle(int num, int capacite, QString etat)
{
 this->num=num;
 this->capacite=capacite;
 this->etat=etat;
}
bool Salle::ajouterSalle()
{
  QSqlQuery query;
  QString ide=QString::number(num);
  QString capacites=QString::number(capacite);
  query.prepare("INSERT INTO SALLES(CAPACITESALLE,ETATSALLE,NUMSALLE)""VALUES(:capacite,:etat,:num)");
  query.bindValue(":num",ide);
  query.bindValue(":capacite",capacites);
  query.bindValue(":etat",etat);
  return query.exec();
}
bool  Salle:: modifSalle(int num)
{
    QSqlQuery query;
    QString ns=QString::number(num);
    QString c=QString::number(capacite);
    query.prepare("update Salles set ETATSALLE=:etat,CAPACITESALLE=:capacite where NUMSALLE=:num");
    query.bindValue(":num",ns);
    query.bindValue(":etat",etat);
    query.bindValue(":capacite",c);

    return    query.exec();
}
void Salle::setCapacite(int capacite)
{
    this->capacite=capacite;
}
void Salle::setEtat(QString etat)
{
  this->etat=etat;
}
QSqlQueryModel * Salle::afficherSalle()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from salles");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("num"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("capacité"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("état"));
    return model;
}
bool Salle::supprimerSalle(int num)
{
    QSqlQuery query;
    QString ide=QString::number(num);
    query.prepare("Delete from salles where NUMSALLE=:num");
    query.bindValue(":num",ide);
    return query.exec();
}
