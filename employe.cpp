#include "employe.h"

Employe::Employe()
{
    id=0;
    nom="";
    prenom="";
    numTel=0;
}
Employe::Employe(int id, QString nom, QString prenom, int numTel)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->numTel=numTel;
}
bool Employe::ajouter()
{
  QSqlQuery query;
  QString ids=QString::number(id);
  QString nums=QString::number(numTel);
  query.prepare("INSERT INTO EMPLOYES(ID,NOM,PRENOM,NUMTEL)""VALUES(:id, :nom, :prenom, :numTel)");
  query.bindValue(":id",ids);
  query.bindValue(":numTel",nums);
  query.bindValue(":nom",nom);
  query.bindValue(":prenom",prenom);
  return query.exec();
}
void Employe::setNom(QString nom)
{
this->nom=nom;
}
void Employe::setPrenom(QString prenom)
{
    this->prenom=prenom;
}
void Employe::setNum(int numTel)
{
   this->numTel=numTel;
}
bool  Employe:: modifier(int id)
{
    QSqlQuery query;
    QString ide=QString::number(id);
    QString nums=QString::number(numTel);
    query.prepare("update EMPLOYES set NOM=:nom,PRENOM=:prenom,NUMTEL=:numTel where ID=:id");
    query.bindValue(":id",ide);
    query.bindValue(":numTel",nums);
    query.bindValue(":prenom",prenom);
    query.bindValue(":nom",nom);

    return    query.exec();
}
 QSqlQueryModel * Employe::afficherEmploye()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from employes");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("NumTel"));
     return model;
 }
 bool Employe::supprimer(int id)
 {
     QSqlQuery query;
     QString ids=QString::number(id);
     query.prepare("Delete from employes where ID=:id");
     query.bindValue(":id",ids);
     return query.exec();
 }
 QSqlQueryModel * Employe:: affichageTrier()
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("select *from EMPLOYES ORDER BY NOM");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("NumTel"));
     return model;
 }
