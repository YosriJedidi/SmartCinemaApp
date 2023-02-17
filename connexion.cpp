#include "connexion.h"
#include "QSqlDatabase"
#include <QString>
Connexion::Connexion()
{

}
bool Connexion::ouvrirConnexion()
{
    bool test=false;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ProjetQt");
    db.setUserName("wiem");
    db.setPassword("pwd");
    if (db.open())
        test=true;
    else throw QString ("Erreur Parametres"+test);
    return test;
}
void Connexion::fermerConnexion()
{
    db.close();
}
