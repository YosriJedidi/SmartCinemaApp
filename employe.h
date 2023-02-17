#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Employe
{
public:
    Employe();
    Employe(int,QString,QString,int);
    int getID(){return id;}
    void setNom(QString);
    void setPrenom(QString);
    void setNum(int);
    QString getNom(){return nom;}
    QString getPreNom(){return prenom;}
    int getNumtel(){return numTel;}
    bool ajouter();
    bool modifier(int);
    bool supprimer(int);
    QSqlQueryModel * afficherEmploye();
    QSqlQueryModel * affichageTrier();
private:
    int id,numTel;
    QString nom,prenom;
};

#endif // EMPLOYE_H
