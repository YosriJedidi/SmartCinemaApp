#include "ClientF.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


clientF::clientF()
{
id=0;
nom="";
prenom="";
adresse="";
}
clientF::clientF(int i,QString n,QString p,QString a){
    id=i;
    nom=n;
    prenom=p;
    adresse=a;
}
bool clientF::ajouterClient(){
    QSqlQuery query;
    QString ids=QString::number(id);
    query.prepare("INSERT INTO CLIENT (ID,NOM,PRENOM,ADRESSE)"
                  "VALUES(:id, :nom, :prenom, :adresse)");
    query.bindValue(":id",ids);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
return query.exec();
}
QSqlQueryModel * clientF:: afficher(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from client");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    return model ;


}
QSqlQueryModel *clientF::rechercher_id(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from CLIENT where ID LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));


      return model;
  }
QSqlQueryModel *clientF::rechercher_nom(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from CLIENT where NOM LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));


      return model;
  }

QSqlQueryModel *clientF::rechercher_adresse(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from CLIENT where ADRESSE LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));


      return model;
  }
QSqlQueryModel *clientF::trierclient()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from CLIENT  order by ID" );
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
       return model;


 }
QString test_tri1(int c)
{
    if (c==0)
    {
        return "identifiant" ;
    }
    else if (c==1)
    {
        return "nom";
    }
    else if (c==2)
    {
     return "prenom" ;
    }
    else if (c==3)
    {
     return "adresse" ;
    }
    return "NULL";
}
QSqlQueryModel* clientF::triclient(int i)
{
    QString col = test_tri1(i);
    QSqlQueryModel *model = new QSqlQueryModel() ;
    QString header = "SELECT * FROM client ORDER BY "+col;
    model->setQuery(header);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));


    return model ;
}
