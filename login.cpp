#include "login.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

Login::Login()
{
id=0;
mdp="";
}
Login::Login (int id, QString mdp)
{
    this->id=id;
    this ->mdp=mdp;
}
int Login::connect(int id, QString mdp)
{
    QSqlQuery query;
    QString ide=QString::number(id);
    query.prepare("SELECT ID,PWD from USERS WHERE ID= :id AND PWD = :mdp");
    query.bindValue(":id",ide);
    query.bindValue(":mdp",mdp);
    if (query.exec())
    {

       if (query.next())
       {
           return 1;
       }

    }
   return 0;
}
