#ifndef CAISSE_H
#define CAISSE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Caisse
{
public:
    Caisse();
   Caisse(int ,float ,QString );
    QString gettype(){return type;}
   int getnum(){return num;}
   void setmontant(float r);
   void settype(QString a);
    int getmontant(){return montant;}
    bool ajouterBudget();
    QSqlQueryModel * afficher1();
    bool supprimerBudget(int n);
    bool   modifiersalaire(QString id);
    QSqlQueryModel* rechercher1(QString txt);
     QSqlQueryModel* rechercher2(QString txt);
    QSqlQueryModel *rechercher(QString txt);
    QSqlQueryModel *triercaisse();
    void statistique(QVector<double>* ticks,QVector<QString> *labels);
    QSqlQueryModel*tricaisse(int i);
private :
    int num;
    QString type;
    float montant;
};

#endif // CAISSE_H
