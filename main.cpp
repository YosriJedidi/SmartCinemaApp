#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QTranslator>
#include <QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t;
    QStringList languages;
    languages <<"French"<<"English";
    QString lang = QInputDialog::getItem(NULL,"Select Language","Language",languages);
    if (lang == "English")
    {
        t.load(":/english.qm");
    }
    if (lang != "French")
    {
        a.installTranslator(&t);
    }
    Connexion C;
    bool test=C.ouvrirConnexion();
    MainWindow w;
    if (test)
    { w.show();
        QMessageBox::information(nullptr,QObject::tr("database is not open"),QObject::tr("connection succesful \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
              else
                  QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("connection failed \n click cancel to exit")
                          ,QMessageBox::Cancel);
 return a.exec();
}
