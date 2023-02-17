#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Ticket
{
public:
    Ticket();
    Ticket(int,QString,int,QString,QString);
    int getID(){return ID;}
    int getNbPlaces(){return NbPlaces;}
    QString getNomC(){return NomC;}
    QString getDate(){return DateF;}
    QString getHeure(){return HeureF;}
    void setNbPlaces(int);
    void setDate(QString);
    void setHeure(QString);
    void setNomC(QString);
    bool ajouterTicket();
    bool modifTicket(int);
    bool supprimerTicket(int);
    QSqlQueryModel * afficherTicket();

private:
    int ID,NbPlaces;
    QString NomC,DateF,HeureF;
};

#endif // TICKET_H
