#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Produit
{ private:
     int identifiant,quantite,prix;
     QString nom,categorie;

public:
    Produit();
    Produit(int,QString,QString ,int,int);
    int getIdentifiant();
    QString getNom();
    QString getCategorie();
    int getQuantite();
    int getPrix();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int  );
    bool modifier(int);//**//
   // QSqlQueryModel *rechercher(QString);
    QSqlQueryModel * rechercher_nom(QString );
     QSqlQueryModel * rechercher_categorie(QString  );
     QSqlQueryModel * rechercher_quantite(int );
     QSqlQueryModel * rechercher_nomcategorie(QString, QString);
      QSqlQueryModel * rechercher_nomQuantite(QString , int );
       QSqlQueryModel * rechercher_quantitecategorie(int , QString );
       QSqlQueryModel * rechercher_tous( QString ,  QString,int );
    void statistique(QVector<double>* ticks,QVector<QString> *labels);
    QSqlQueryModel * trie_produitQ();
    QSqlQueryModel * trie_produitN();

};

#endif // PRODUIT_H
