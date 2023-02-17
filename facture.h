#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class facture
{ private:
    int numfacture,prixachat,prixvente,gain;
    QString datefacture;


public:
    facture();
    facture(int,QString,int,int);
    int getNum();
    int getPrixAchat();
    int getPrixVente();
    QString getDate();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int id );
    bool modifier(int);
    QSqlQueryModel * trie_facture();
    QSqlQueryModel * trie_facturep();
    int calcul(int,int);
    QSqlQueryModel *rechercher(QString);
    QSqlQueryModel * trie_factureid();
};

#endif // FACTURE_H
