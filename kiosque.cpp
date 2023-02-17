#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kiosque.h"
#include "ui_kiosque.h"
#include "produit.h"
#include "facture.h"
#include <QMessageBox>
#include "QIntValidator"
#include <QDateEdit>
#include <QPlainTextEdit>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include "qcustomplot.h"
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QMediaPlayer>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
kiosque::kiosque(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kiosque)
{   son=new QSound(":/son/ss.wav");
    ui->setupUi(this);

    mSystemTrayIcon= new QSystemTrayIcon(this);
    mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
    mSystemTrayIcon->setVisible(true);
    mMediaPlayer = new QMediaPlayer(this);
       connect(mMediaPlayer,& QMediaPlayer::positionChanged,[&](qint64 pos){
           ui->avance->setValue(pos);
       });
       connect(mMediaPlayer,& QMediaPlayer::durationChanged,[&] (quint64 dur)
       {
           ui->avance->setMaximum(dur);
       });
       #define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
       QRegExp rxNom(NOM_RX);
       QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
    ui->LineEditnom_produit->setValidator(valiNom);//nomajoutproduit//
    ui->NomModifPr->setValidator(valiNom);//nommodifproduit//
    ui->LineEditid_prod->setValidator(new QIntValidator(0,99999,this));//idajout_produit//
    ui->NumFacAj->setValidator(new QIntValidator(0,99999,this));//numfactureproduit//
    ui->PrixachatAj->setValidator(new QIntValidator(0,99999,this));
    ui->PrixVenteFacAj->setValidator(new QIntValidator(0,99999,this));
    ui->PrixachatModpr->setValidator(new QIntValidator(0,99999,this));
    ui->PrixventeModfac->setValidator(new QIntValidator(0,99999,this));
    ui->LineEditQuantiteajoutP->setValidator(new QIntValidator(0,999,this));//prixajout produit//
    ui->LineEditPrAjoutPr->setValidator(new QIntValidator(0,999,this));
    ui->PrixModPr->setValidator(new QIntValidator(0,999,this));
    ui->quantieModPr->setValidator(new QIntValidator(0,999,this));
    Produit tempProduit;
    facture temFacture;

     ui->comboBox->setModel(tempProduit.afficher());
     ui->comboBox_3->setModel(tempProduit.afficher());
     ui->comboBox_2->setModel(temFacture.afficher());
     ui->comboBox_4->setModel(temFacture.afficher());
     ui->tableView->setModel(tempProduit.afficher());
     ui->tableView_2->setModel(temFacture.afficher());
     //CHAT//
     mSocket=new QTcpSocket(this);
     mSocket->connectToHost("localhost",2000);
     if (mSocket->waitForConnected(3000))
     {
         ui->plainTextEdit->appendPlainText("se connecter correctement");
     }
     else
     {
         ui->plainTextEdit->appendPlainText("pas de connexion");
     }
     connect(mSocket,SIGNAL(readyRead()),this,SLOT(leer()));
}
void kiosque::leer()
{
    QByteArray buffer;
    buffer.resize(mSocket->bytesAvailable());
    mSocket->read(buffer.data(),buffer.size());
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->appendPlainText(QString(buffer));
}

kiosque::~kiosque()
{
    delete ui;
}
//-------------------------CRUD 1: Produit--------------//
void kiosque::on_pushButton_AjoutProdui_clicked()
{
        son->play();
        int identifiant=ui->LineEditid_prod->text().toInt();
        QString nom=ui->LineEditnom_produit->text();
        QString categorie;
        bool C=ui->radioButton->isChecked();
        if (C)
        { categorie="local";
        }
        else categorie="importe";
        int quantite=ui->LineEditQuantiteajoutP->text().toInt();
        int prix=ui->LineEditPrAjoutPr->text().toInt();
         histo.save("id:"+ui->LineEditid_prod->text(),"quantite :"+ui->LineEditQuantiteajoutP->text());
        Produit P( identifiant,nom, categorie,quantite,prix);
        bool test=P.ajouter();
        if(ui->LineEditnom_produit->text().isEmpty()||ui->LineEditQuantiteajoutP->text().isEmpty()||ui->LineEditPrAjoutPr->text().isEmpty()||ui->LineEditid_prod->text().contains(QRegExp("^[1-9]"))==0){
           { mSystemTrayIcon->showMessage(tr("Notification"),tr("ajout echoué"));
            QMessageBox::information(nullptr, QObject::tr("ERREUR"),
                                   QObject::tr("ERREUR.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
        else{
        if (test)
        {   mSystemTrayIcon->showMessage(tr("Notification"),tr("produit ajouté"));
            ui->comboBox->setModel(P.afficher());
            ui->tableView->setModel(tempProduit.afficher());

            QMessageBox::information(nullptr, QObject::tr("Ajout produit"),
                        QObject::tr("produit ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

             ui->comboBox_3->setModel(P.afficher());

        }

        else
        {  mSystemTrayIcon->showMessage(tr("Notification"),tr("ajout echoue"));
            QMessageBox::critical(nullptr, QObject::tr("Ajout produit"),
                        QObject::tr("ajout echoué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

 }
}

void kiosque::on_suppProduit_clicked()
{
    son->play();
    int identifiant=ui->comboBox_3->currentText().toInt();
    bool test=tempProduit.supprimer(identifiant);
    Produit P;
    if(ui->comboBox_3->currentText().contains(QRegExp("^[1-9]"))==0){
     mSystemTrayIcon->showMessage(tr("Notification"),tr(" liste vide"));
        QMessageBox::information(nullptr, QObject::tr("ERREUR"),
                               QObject::tr("ERREUR.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else {

    if (test)
    {  mSystemTrayIcon->showMessage(tr("Notification"),tr("produit supprimé"));
        ui->comboBox_3->setModel(tempProduit.afficher());
        ui->tableView->setModel(tempProduit.afficher());
        QMessageBox::information(nullptr, QObject::tr("suppression produit"),
                    QObject::tr("produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
       ui->comboBox->setModel(P.afficher());
       ui->comboBox_3->setModel(P.afficher());

    }
    }
}

void kiosque::on_ModifProduit_clicked()
{
     son->play();
        int identifiant=ui->comboBox->currentText().toInt();
        QString nom= ui->NomModifPr->text();
        QString categorie;
        bool Ca=ui->radioButton_5->isChecked();
        if (Ca)
        { categorie="local";
        }
        else   {categorie="importe";}
       int quantite = ui->quantieModPr->text().toInt();
       int prix = ui->PrixModPr->text().toInt();

        Produit P(identifiant,nom,categorie,quantite,prix);

      bool test=P.modifier(identifiant);
      if(ui->comboBox_3->currentText().contains(QRegExp("^[1-9]"))==0){
       mSystemTrayIcon->showMessage(tr("Notification"),tr(" liste vide"));
          QMessageBox::information(nullptr, QObject::tr("ERREUR"),
                                 QObject::tr("ERREUR.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else {
      if(test)
    {     mSystemTrayIcon->showMessage(tr("Notification"),tr(" Modification validée"));
          ui->comboBox->setModel(P.afficher());
          ui->tableView->setModel(P.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("modifier un produit"),
                      QObject::tr("Produit modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      }

}

//----------------------Statistiques produit-----------------//
void kiosque::on_tabWidget_currentChanged(int index)
{
    // background //
              QLinearGradient gradient(0, 0, 0, 400);
              gradient.setColorAt(0, QColor(90, 90, 90));
              gradient.setColorAt(0.38, QColor(105, 105, 105));
              gradient.setColorAt(1, QColor(70, 70, 70));
              ui->plot->setBackground(QBrush(gradient));

              QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
              amande->setAntialiased(false);
              amande->setStackingGap(1);
               //couleurs
              amande->setName("Repartition des produit selon quantite ");
              amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
              amande->setBrush(QColor(0, 168, 140));

               //axe des abscisses
              QVector<double> ticks;
              QVector<QString> labels;
              tempProduit.statistique(&ticks,&labels);

              QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
              textTicker->addTicks(ticks, labels);
              ui->plot->xAxis->setTicker(textTicker);
              ui->plot->xAxis->setTickLabelRotation(60);
              ui->plot->xAxis->setSubTicks(false);
              ui->plot->xAxis->setTickLength(0, 4);
              ui->plot->xAxis->setRange(0, 8);
              ui->plot->xAxis->setBasePen(QPen(Qt::white));
              ui->plot->xAxis->setTickPen(QPen(Qt::white));
              ui->plot->xAxis->grid()->setVisible(true);
              ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
              ui->plot->xAxis->setTickLabelColor(Qt::white);
              ui->plot->xAxis->setLabelColor(Qt::white);

              // axe des ordonnées
              ui->plot->yAxis->setRange(0,10);
              ui->plot->yAxis->setPadding(5);
              ui->plot->yAxis->setLabel("Statistiques");
              ui->plot->yAxis->setBasePen(QPen(Qt::white));
              ui->plot->yAxis->setTickPen(QPen(Qt::white));
              ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
              ui->plot->yAxis->grid()->setSubGridVisible(true);
              ui->plot->yAxis->setTickLabelColor(Qt::white);
              ui->plot->yAxis->setLabelColor(Qt::white);
              ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
              ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

              // ajout des données  (statistiques de la quantité)//

              QVector<double> PlaceData;
              QSqlQuery q1("select QUANTITE from produit");
              while (q1.next()) {
                            int  nbr_fautee = q1.value(0).toInt();
                            PlaceData<< nbr_fautee;
                              }
              amande->setData(ticks, PlaceData);

              ui->plot->legend->setVisible(true);
              ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
              ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
              ui->plot->legend->setBorderPen(Qt::NoPen);
              QFont legendFont = font();
              legendFont.setPointSize(5);
              ui->plot->legend->setFont(legendFont);
              ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}
void kiosque::on_radioButton_TRInProd_clicked()//tri des nom des produits//
{   son->play();
    ui->tableView->setModel(tempProduit.trie_produitN());
}
void kiosque::on_radioButton_TRIqProd_clicked()//tri des quantités des produits//
{
     son->play();
     ui->tableView->setModel(tempProduit.trie_produitQ());
}

//----------------------PDF PRODUIT--------------------------------------------
void kiosque::on_pushButton_PDFProd_clicked()

{   son->play();
    QSqlDatabase db;
                QTableView table_produit;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM PRODUIT ");
                 qry.exec();
                 Modal->setQuery(qry);
                 table_produit.setModel(Modal);


                 db.close();

                 QString strStream;
                 QTextStream out(&strStream);


                 const int rowCount = table_produit.model()->rowCount();
                 const int columnCount =  table_produit.model()->columnCount();

                 const QString strTitle ="Document";


                 out <<  "<html>\n"
                         "<img src='C:/Users/ASUS/Documents/kiosqueK/logocin.png' height='120' width='120'/>"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des produits")
                    <<"<br>"

                    <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                 out << "<thead><tr bgcolor=#f0f0f0>";
                 for (int column = 0; column < columnCount; column++)
                     if (!table_produit.isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(table_produit.model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!table_produit.isColumnHidden(column)) {
                             QString data = table_produit.model()->data(table_produit.model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"
                         <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                     out << "<thead><tr bgcolor=#f0f0f0>";

                         out <<  "</table>\n"

                     "</body>\n"
                     "</html>\n";

                 QTextDocument *document = new QTextDocument();
                 document->setHtml(strStream);

                 QPrinter printer;
                 QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                 if (dialog->exec() == QDialog::Accepted) {

                     document->print(&printer);
                 }

                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName("/tmp/produit.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));

                 delete document;
}
/*void kiosque::on_lineEdit_rechercheP_textChanged(const QString &arg1)//recherche produit//
{
    QString ch = arg1;

                if (ch=="")
                {
                    ui->tableView->setModel(tempProduit.afficher());
                }
                else {
                  ui->tableView->setModel(tempProduit.rechercher(ch)) ;
                }
}*/
void kiosque::on_EXCELPr_clicked()
{
    son->play();
    QTableView *table;
               table = ui->tableView;

               QString filters("CSV files (.csv);;All files (.*)");
               QString defaultFilter("CSV files (*.csv)");
               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                  filters, &defaultFilter);
               QFile file(fileName);

               QAbstractItemModel *model =  table->model();
               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                   QTextStream data(&file);
                   QStringList strList;
                   for (int i = 0; i < model->columnCount(); i++) {
                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") << "\n";
                   for (int i = 0; i < model->rowCount(); i++) {
                       strList.clear();
                       for (int j = 0; j < model->columnCount(); j++) {

                           if (model->data(model->index(i, j)).toString().length() > 0)
                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") + "\n";
                   }
                   file.close();
                   QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                             QObject::tr("Export avec succes .\n"
                                                         "Click OK to exit."), QMessageBox::Ok);
               }
}

void kiosque::on_comboBox_currentTextChanged(const QString &arg1)
{
    QSqlQuery query;
    QString ch=arg1;
    query.prepare("select* from PRODUIT where IDENTIFIANT ='"+ch+"'");
if (query.exec())
{
  while (query.next())
  {
       ui->NomModifPr->setText(query.value(1).toString());
       QString categorie;
       bool C=ui->radioButton->isChecked();
       if (C)
       { categorie="local";
       }
       else categorie="importe";
       ui->quantieModPr->setText(query.value(3).toString());
       ui->PrixModPr->setText(query.value(4).toString());
  }
}
}

//---------------------------------CRUD2: FACTURE----------------------------------------------//
void kiosque::on_ajoutFacture_clicked()
{
   son->play();

    int numfacture=ui->NumFacAj->text().toInt();
    QString datefacture=ui->dateEdit->text();
    int prixachat=ui->PrixachatAj->text().toInt();
    int prixvente=ui->PrixVenteFacAj->text().toInt();
    facture F(numfacture,datefacture,prixachat,prixvente);
    bool test=F.ajouter();
    if(ui->NumFacAj->text().isEmpty()||ui->PrixachatAj->text().isEmpty()||ui->PrixVenteFacAj->text().isEmpty()||ui->NumFacAj->text().contains(QRegExp("^[1-9]"))==0){
       { mSystemTrayIcon->showMessage(tr("Notification"),tr("ajout echoue"));
        QMessageBox::information(nullptr, QObject::tr("ERREUR"),
                               QObject::tr("ERREUR.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else {
    if (test)
    {    mSystemTrayIcon->showMessage(tr("Notification"),tr(" Ajout validé"));
        ui->tableView_2->setModel(temFacture.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajout facture"),
                    QObject::tr("facture  ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->comboBox_2->setModel(F.afficher());
        ui->comboBox_4->setModel(F.afficher());

    }
    }

}

void kiosque::on_SuppFacture_clicked()
{
    son->play();
    int numfacture=ui->comboBox_4->currentText().toInt();
    facture F;
    bool test=temFacture.supprimer(numfacture);
    if(ui->comboBox_4->currentText().contains(QRegExp("^[1-9]"))==0){
     mSystemTrayIcon->showMessage(tr("Notification"),tr(" liste vide"));
        QMessageBox::information(nullptr, QObject::tr("ERREUR"),
                               QObject::tr("ERREUR.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else {
    if (test)
    {    mSystemTrayIcon->showMessage(tr("Notification"),tr("Facture supprimée"));
        ui->tableView_2->setModel(F.afficher());
        QMessageBox::information(nullptr, QObject::tr("suppression facture"),
                    QObject::tr("facture supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->comboBox_2->setModel(F.afficher());
        ui->comboBox_4->setModel(F.afficher());


    }

    }
}

void kiosque::on_ModiFacture_clicked()

{   son->play();
    int numfacture =ui->comboBox_2->currentText().toInt();
    QString date=ui->dateEdit_5->text();
    int prixachat=ui->PrixachatModpr->text().toInt();
    int prixvente=ui->PrixventeModfac->text().toInt();

      facture F( numfacture,date,prixachat,prixvente);
      bool test=F.modifier(numfacture);
      if(ui->comboBox_2->currentText().contains(QRegExp("^[1-9]"))==0){
       mSystemTrayIcon->showMessage(tr("Notification"),tr(" liste vide"));
          QMessageBox::information(nullptr, QObject::tr("ERREUR"),
                                 QObject::tr("ERREUR.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else{
      if(test)
    { mSystemTrayIcon->showMessage(tr("Notification"),tr(" Modification validée"));
          ui->comboBox_2->setModel(F.afficher());
          ui->tableView_2->setModel(F.afficher());
          ui->comboBox_4->setModel(F.afficher());

    QMessageBox::information(nullptr, QObject::tr("modifier une facture"),
                      QObject::tr("Facture modifiée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
ui->comboBox_2->setModel(F.afficher());
    }
}
}

//------------------TRIFACTURE----------------//
void kiosque::on_TriDateFacture_clicked()//tri date//
{
    son->play();
    ui->tableView_2->setModel(temFacture.trie_facture());
}
void kiosque::on_TriidFacture_clicked()//tri id des factures//
{
    son->play();
    ui->tableView_2->setModel(temFacture.trie_factureid());
}

void kiosque::on_rehercheFacture_textChanged(const QString &arg1)//recherchefacture//
{
   QString ch = arg1;

                if (ch=="")
                {
                    ui->tableView_2->setModel(temFacture.afficher());
                }
                else {
                  ui->tableView_2->setModel(temFacture.rechercher(ch)) ;

                }
}
//-----son-------//
void kiosque::on_pushButton_apport_clicked()
{
    son->play();
        QString filename=QFileDialog::getOpenFileName(this,"pushButton_apport");
        if(filename.isEmpty()){
            return;
        }
        mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
        mMediaPlayer->setVolume(ui->volume->value());
               on_play_clicked();
}

void kiosque::on_pushButton_5_clicked()
{
   son->play();
   mMediaPlayer->pause();
}

void kiosque::on_pushButton_stop_clicked()
{
    son->play();
    mMediaPlayer->stop();
}

void kiosque::on_play_clicked()
{
    son->play();
    mMediaPlayer->play();
}

void kiosque::on_avance_valueChanged(int value)
{
    mMediaPlayer->setVolume(value);
}

void kiosque::on_volume_valueChanged(int value)
{
    mMediaPlayer->setVolume(value);
}

void kiosque::on_mute_clicked()
{
    if(ui->mute->text()=="Mute")
    {
        mMediaPlayer->setMuted(true);
        ui->mute->setText("Unmute");
    }
    else {mMediaPlayer->setMuted(false);
    ui->mute->setText("Mute");}
}

//-------------------PDF_Facture-------------------------//
void kiosque::on_pushButton_PDFFac_clicked()
{
    son->play();
    QSqlDatabase db;
                QTableView table_facture;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM FACTURE ");
                 qry.exec();
                 Modal->setQuery(qry);
                 table_facture.setModel(Modal);

                 db.close();

                 QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = table_facture.model()->rowCount();
                 const int columnCount =  table_facture.model()->columnCount();

                 const QString strTitle ="Document";


                 out <<  "<html>\n"
                         "<img src='C:/Users/ASUS/Documents/kiosqueK/logocin.png' height='120' width='120'/>"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des factutres")
                    <<"<br>"

                    <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                 out << "<thead><tr bgcolor=#f0f0f0>";
                 for (int column = 0; column < columnCount; column++)
                     if (!table_facture.isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(table_facture.model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!table_facture.isColumnHidden(column)) {
                             QString data = table_facture.model()->data(table_facture.model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"
                         <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                     out << "<thead><tr bgcolor=#f0f0f0>";

                         out <<  "</table>\n"

                     "</body>\n"
                     "</html>\n";

                 QTextDocument *document = new QTextDocument();
                 document->setHtml(strStream);

                 QPrinter printer;
                 QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                 if (dialog->exec() == QDialog::Accepted) {

                     document->print(&printer);
                 }

                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName("/tmp/facture.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));

                 delete document;
}

void kiosque::on_EXcelF_clicked()
{
    son->play();
    QTableView *table;
               table = ui->tableView_2;

               QString filters("CSV files (.csv);;All files (.*)");
               QString defaultFilter("CSV files (*.csv)");
               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                  filters, &defaultFilter);
               QFile file(fileName);

               QAbstractItemModel *model =  table->model();
               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                   QTextStream data(&file);
                   QStringList strList;
                   for (int i = 0; i < model->columnCount(); i++) {
                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") << "\n";
                   for (int i = 0; i < model->rowCount(); i++) {
                       strList.clear();
                       for (int j = 0; j < model->columnCount(); j++) {

                           if (model->data(model->index(i, j)).toString().length() > 0)
                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") + "\n";
                   }
                   file.close();
                   QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                             QObject::tr("Export avec succes .\n"
                                                         "Click OK to exit."), QMessageBox::Ok);
               }
}


void kiosque::on_pushButtonWEB_clicked()
{
    QString link="http://www.google.com";
    QDesktopServices::openUrl(QUrl(link));
}

void kiosque::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    QSqlQuery query;
    QString ch=arg1;
    query.prepare("select* from FACTURE where NUMFACTURE ='"+ch+"'");
if (query.exec())
{
  while (query.next())
{
      ui->PrixachatModpr->setText(query.value(4).toString());
      ui->PrixventeModfac->setText(query.value(3).toString());
}
}
}

void kiosque::on_CHAT_clicked()
{
    mSocket->write(ui->lineEdit->text().toLatin1().data(),ui->lineEdit->text().size());
    ui->plainTextEdit->appendPlainText(ui->lineEdit->text());
    ui->lineEdit->clear();
}


void kiosque::on_reafficher_rechproduit_clicked()
{
    son->play();
        ui->rech_nom->setText("");
        ui->rech_quantite->setText("");
      ui->tableView->setModel(tempProduit.afficher());
}


void kiosque::on_rechercher_P_clicked()
{
    son->play();
       if (ui->checkBox_nom->isChecked())
       { QString nom=ui->rech_nom->text();
           QSqlQueryModel *verif=tempProduit.rechercher_nom(nom);
           if (verif!=nullptr)
           {
               ui->tableView->setModel(verif);
           }
        }


           if (ui->checkBox_categorie->isChecked())
       { QString categorie=ui->rech_categorie->currentText();
           QSqlQueryModel *verif=tempProduit.rechercher_categorie(categorie);
           if (verif!=nullptr)
           {
               ui->tableView->setModel(verif);
           }
        }

               if (ui->checkBox_quantite->isChecked())
       { int quantite=ui->rech_quantite->text() .toInt();
           QSqlQueryModel *verif=tempProduit.rechercher_quantite(quantite);
           if (verif!=nullptr)
           {
               ui->tableView->setModel(verif);
           }
        }

          if ((ui->checkBox_quantite->isChecked())&&(ui->checkBox_nom->isChecked()))
       {
           int quantite=ui->rech_quantite->text() .toInt();
           QString nom=ui->rech_nom->text();

                       QSqlQueryModel *verif=tempProduit.rechercher_nomQuantite(nom,quantite);
                       if (verif!=nullptr)
                       {
                           ui->tableView->setModel(verif);
                       }

       }
               if ((ui->checkBox_quantite->isChecked())&&(ui->checkBox_categorie->isChecked()))
          {
           QString categorie=ui->rech_categorie->currentText();
          int quantite=ui->rech_quantite->text() .toInt();


                       QSqlQueryModel *verif=tempProduit.rechercher_quantitecategorie(quantite,categorie);
                       if (verif!=nullptr)
                       {
                           ui->tableView->setModel(verif);
                       }

       }
               if ((ui->checkBox_nom->isChecked())&&(ui->checkBox_categorie->isChecked()))
       {
          QString nom=ui->rech_nom->text();
          QString categorie=ui->rech_categorie->currentText();


                       QSqlQueryModel *verif=tempProduit.rechercher_nomcategorie(nom,categorie);
                       if (verif!=nullptr)
                       {
                           ui->tableView->setModel(verif);
                       }

    if ((ui->checkBox_nom->isChecked())&&(ui->checkBox_categorie->isChecked())&&(ui->checkBox_quantite->isChecked()))
    {

        QString categorie=ui->rech_categorie->currentText();
        QString nom=ui->rech_nom->text();
        int quantite=ui->rech_quantite->text() .toInt();


                    QSqlQueryModel *verif=tempProduit.rechercher_tous(nom,categorie,quantite);
                    if (verif!=nullptr)
                    {
                        ui->tableView->setModel(verif);
                    }


    } // else QMessageBox::warning(this,"erreur","Aucun critére n'est coché");
    }
}
