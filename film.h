#ifndef FILM_H
#define FILM_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Film
{
public:
    Film();
    Film(int,QString,QString,int);
    int getIDF(){return id;}
    QString getNom(){return nom;}
    QString getCategorie(){return categorie;}
    int getDuree(){return duree;}
    bool ajouterFilm();
    bool supprimerFilm(int);
    bool modifFilm(int);
    void CREATION_PDF();
    QSqlQueryModel* recherche(QString);

    QSqlQueryModel * afficherFilm();
    QSqlQueryModel * trier();
private:
    int id,duree;
    QString nom,categorie;
};


#endif // FILM_H
