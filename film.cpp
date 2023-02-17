#include "film.h"
#include "Programmation.h"
#include "client.h"
Film::Film()
{
    id=0;
    nom="";
    categorie="";
    duree=0;
}
Film::Film(int id, QString nom, QString categorie, int duree)
{
    this->id=id;
    this->nom=nom;
    this->categorie=categorie;
    this->duree=duree;
}
bool Film::ajouterFilm()
{
  QSqlQuery query;
  QString idf=QString::number(id);
  QString dureef=QString::number(duree);
  query.prepare("INSERT INTO FILM(IDF,NOM,CATEGORIE,DUREEF)""VALUES(:id, :nom, :categorie, :duree)");
  query.bindValue(":id",idf);
  query.bindValue(":duree",dureef);
  query.bindValue(":nom",nom);
  query.bindValue(":categorie",categorie);
  return query.exec();
}
 QSqlQueryModel * Film::afficherFilm()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from film");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Categorie"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("Duree"));
     return model;
 }
 bool  Film:: modifFilm(int IDt)
 {
     QSqlQuery query;
     QString idt=QString::number(id);
     QString dureef=QString::number(duree);

    // QString NbPlacesf=QString::number(NbPlaces);
     query.prepare("update Film set IDF = :id , NOM = :nom , CATEGORIE = :categorie , DUREEF = :duree where IDF = :id");
     query.bindValue(":id",idt);
     query.bindValue(":id",id);
     query.bindValue(":nom",nom);
     query.bindValue(":categorie",categorie);
     query.bindValue(":duree",dureef);

     return    query.exec();
 }
 bool Film::supprimerFilm(int id)
 {
     QSqlQuery query;
     QString idf=QString::number(id);
     query.prepare("Delete from film where IDF=:id");
     query.bindValue(":id",idf);
     return query.exec();
 }
 QSqlQueryModel *Film::trier() // m sghir lel kbir
 {
     QSqlQuery * q = new  QSqlQuery ();
            QSqlQueryModel * model = new  QSqlQueryModel ();
            q->prepare("SELECT * FROM FILM order by DUREEF ASC");
            q->exec();
            model->setQuery(*q);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("Catégorie"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("Durée"));
            return model;
      //ml kbir l sghir
           /* QSqlQuery * q = new  QSqlQuery ();
                   QSqlQueryModel * model = new  QSqlQueryModel ();
                   q->prepare("SELECT * FROM permisconstruction order by codepostale ASC");
                   q->exec();
                   model->setQuery(*q);
                   return model;*/
 }
 QSqlQueryModel *Film::recherche(QString id)
  {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from FILM where IDF LIKE '"+id+"%' or NOM LIKE '"+id+"%' or CATEGORIE LIKE '"+id+"%' or DUREEF LIKE '"+id+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Catégorie"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Durée"));


 return model;
 }



