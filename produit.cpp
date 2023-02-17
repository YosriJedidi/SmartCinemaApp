#include "produit.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include "qcustomplot.h"

Produit::Produit()
{
    this->identifiant=0;
    this->nom="";
    this->categorie="";
    this->quantite=0;
    this->prix=0;
}

Produit::Produit(int identifiant,QString nom,QString categorie,int quantite,int prix)
{
    this->identifiant=identifiant;
    this->nom=nom;
    this->categorie=categorie;
    this->quantite=quantite;
    this->prix=prix;
}

int Produit:: getIdentifiant()
{
   return this->identifiant;
}
QString Produit:: getNom()
{
   return this->nom;
}
QString Produit:: getCategorie()
{
return this->categorie;
}
int Produit:: getQuantite()
{
  return this->quantite;
}

int Produit:: getPrix()
{
    return this->prix;
}
bool Produit:: ajouter()
{
    QSqlQuery query;
    QString res=QString ::number(identifiant);//res=sid//
    QString resQ=QString ::number(quantite);
    QString resP=QString ::number(prix);
    query.prepare("INSERT INTO  PRODUIT(IDENTIFIANT,NOM,CATEGORIE,QUANTITE,PRIX)"
                  "VALUES(:identifiant,:nom ,:categorie,:quantite, :prix)");

 query.bindValue(":identifiant",res);
 query.bindValue(":nom",nom);
 query.bindValue(":categorie",categorie);
 query.bindValue(":quantite",resQ);
 query.bindValue(":prix",resP);


    return query.exec();

}

QSqlQueryModel * Produit:: afficher()
{

QSqlQueryModel * model =new QSqlQueryModel();
model->setQuery ("select * from produit");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDENTIFIANT"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("CATEGORIE"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));

return model;

}


bool  Produit::supprimer(int ide)
{
  QSqlQuery query;
  QString res=QString::number(ide);
  query.prepare("Delete from produit where IDENTIFIANT= :identifiant");
  query.bindValue(":identifiant",res);

    return query.exec();

}

bool Produit::modifier(int idd)
{
QSqlQuery query,rech;
QString res= QString::number(idd);
query.prepare("Update produit set  NOM = :nom , CATEGORIE = :categorie , QUANTITE = :quantite ,PRIX= :prix where IDENTIFIANT = :idd ");
query.bindValue(":idd",res);
query.bindValue(":nom",nom);
query.bindValue(":categorie",categorie);
query.bindValue(":quantite",quantite);
query.bindValue(":prix",prix);
return    query.exec();
}


/*QSqlQueryModel *Produit::rechercher(QString q)
{
     QString res= QString::number(identifiant);
     QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("SELECT * FROM PRODUIT  WHERE NOM like '%"+q+"%'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDENTIFIANT"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("CATEGORIE"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));

      return model;

}*/

QSqlQueryModel *  Produit::rechercher_nom(QString nom)
 {
     QSqlQuery qry;
     qry.prepare("select * from produit where nom=:nom");
     qry.bindValue(":nom",nom);
     qry.exec();

     QSqlQueryModel *model= new QSqlQueryModel;
     model->setQuery(qry);


    return model;


 }

QSqlQueryModel *  Produit::rechercher_categorie(QString categorie)
 {
     QSqlQuery qry;
     qry.prepare("select * from produit where categorie =:categorie");
     qry.bindValue(":categorie",categorie);
     qry.exec();

     QSqlQueryModel *model= new QSqlQueryModel;
     model->setQuery(qry);


    return model;


 }

QSqlQueryModel * Produit::rechercher_quantite(int quantite)
 {
     QSqlQuery qry;
     qry.prepare("select * from produit where quantite=:quantite");
     qry.bindValue(":quantite",quantite);
     qry.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
     model->setQuery(qry);


    return model;


}

QSqlQueryModel * Produit::rechercher_nomcategorie(QString nom, QString categorie)
{
    QSqlQuery *qry= new QSqlQuery();
    qry->prepare("select * from produit where categorie=:categorie and nom=:nom");
    qry->bindValue(":categorie",categorie);
    qry->bindValue(":nom",nom);
    qry->exec();


       QSqlQueryModel *model = new QSqlQueryModel();
       model->setQuery(*qry);
        return model;


}
QSqlQueryModel *Produit:: rechercher_nomQuantite(QString nom, int quantite)
{QSqlQuery *qry= new QSqlQuery();
    qry->prepare("select * from produit where nom=:nom and quantite=:quantite ");
    qry->bindValue(":quantite",quantite);
    qry->bindValue(":nom",nom);
    qry->exec();


       QSqlQueryModel *model = new QSqlQueryModel();
       model->setQuery(*qry);
        return model;
}

 QSqlQueryModel *Produit:: rechercher_quantitecategorie(int quantite, QString categorie)
 {
     QSqlQuery *qry= new QSqlQuery();
         qry->prepare("select * from produit where categorie=:categorie and quantite=:quantite");
         qry->bindValue(":quantite",quantite);
         qry->bindValue(":categorie",categorie);
         qry->exec();


            QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery(*qry);
             return model;
 }

 QSqlQueryModel *Produit:: rechercher_tous( QString nom,QString categorie, int quantite)
 {
     QSqlQuery *qry= new QSqlQuery();
         qry->prepare("select * from produit where nom=:nom and categorie=:categorie and quantite=:quantite  ");
         qry->bindValue(":quantite",quantite);
         qry->bindValue(":categorie",categorie);
         qry->bindValue(":nom",nom);
         qry->exec();


            QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery(*qry);
             return model;
 }






void Produit::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery q;
    int i=0;
    q.exec("select QUANTITE from produit");
    while (q.next())
    {
        QString identifiant = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<identifiant;
    }
}

QSqlQueryModel *Produit:: trie_produitQ()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from produit order by QUANTITE" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDENTIFIANT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("CATEGORIE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));

 return model;

}
QSqlQueryModel *Produit:: trie_produitN()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from produit order by NOM" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDENTIFIANT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("CATEGORIE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));


 return model;

}
