#include "caisse.h"

Caisse::Caisse()
{
    /*numS=0;
    montant=0.0;
    type="";
*/
}
Caisse::Caisse(int n,float m,QString t)
{
    num=n;
    montant=m;
    type=t;

}
void Caisse:: setmontant(float r)
{
 montant=r;
}
void Caisse:: settype(QString a)
{
 type=a;
}
bool Caisse::ajouterBudget(){
    QSqlQuery query;
    QString ns=QString::number(num);
    QString m=QString::number(montant);
    query.prepare("INSERT INTO CAISSE (NUM,TYPE,MONTANT)"
                  "VALUES(:num, :type, :montant)");
    query.bindValue(":num",ns);
    query.bindValue(":type",type);
    query.bindValue(":montant",m);

return query.exec();
}
QSqlQueryModel * Caisse:: afficher1(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from caisse");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("num"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("montant"));

    return model ;
}
bool Caisse::supprimerBudget(int ne){
    QSqlQuery query;
    QString ns=QString::number(ne);
    query.prepare("Delete from caisse where NUM= :num");
    query.bindValue(":num",ns);
    return query.exec();
}
bool  Caisse:: modifiersalaire(QString num)
{
    QSqlQuery query;
    //QString ns=QString::number(num);
    QString m=QString::number(montant);
    query.prepare("update caisse set MONTANT=:montant,TYPE=:type where NUM=:num");
    query.bindValue(":num",num);
    query.bindValue(":type",type);
    query.bindValue(":montant",m);

    return    query.exec();
}

QSqlQueryModel *Caisse::rechercher(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from caisse where num LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("num"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("montant"));


      return model;
  }
QSqlQueryModel *Caisse::rechercher1(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from caisse where type LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("num"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("montant"));


      return model;
  }
QSqlQueryModel *Caisse::rechercher2(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from caisse where montant LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("num"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("montant"));


      return model;
  }
QSqlQueryModel *Caisse::triercaisse()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from caisse  order by NUM" );
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("num"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("montant"));
       return model;


 }
void Caisse::statistique(QVector<double>* ticks,QVector<QString> *labels)
{   QSqlQuery q;
    int i=0;
    q.exec("select NUM from caisse");
    while (q.next()) {
        QString refer = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<refer;
}
}
QString test_tri(int c)
{
    if (c==0)
    {
        return "num" ;
    }
    else if (c==1)
    {
        return "type";
    }
    else if (c==2)
    {
     return "montant" ;
    }
    return "NULL";
}
QSqlQueryModel* Caisse::tricaisse(int i)
{
    QString col = test_tri(i);
    QSqlQueryModel *model = new QSqlQueryModel() ;
    QString header = "SELECT * FROM caisse ORDER BY "+col;
    model->setQuery(header);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT"));


    return model ;
}
