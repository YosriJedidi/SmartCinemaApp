#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Salle
{
public:
    Salle();
    Salle(int,int,QString);
    int getNum(){return num;}
    int getCapacite(){return capacite;}
    QString getEtat(){return etat;}
    void setCapacite(int);
    void setEtat(QString);
    bool ajouterSalle();
    bool modifSalle(int);
    bool supprimerSalle(int);
    QSqlQueryModel * afficherSalle();
    void statistique(QVector<double>* ticks,QVector<QString> *labels);
private:
    int num,capacite;
    QString etat;
};

#endif // SALLE_H
