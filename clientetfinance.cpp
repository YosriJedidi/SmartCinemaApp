#include "clientetfinance.h"
#include "ui_clientetfinance.h"
#include "ClientF.h"
#include <QMessageBox>
#include "caisse.h"
#include <QString>
#include <QTextStream>
#include <QTextDocument>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include "qcustomplot.h"
#include <src/SmtpMime>
#include <QFile>
#include "excel.h"
#include "notification.h"
clientetfinance::clientetfinance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientetfinance)
{
    ui->setupUi(this);
    //ui->tableViewclient->setModel(clienttemp.afficher());
    ui->lineEdit_9->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
         ui->lineEdit_10->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
         ui->lineEdit_11->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
          ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
           ui->lineEdit_15->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
           ui->adresse->setValidator(new QRegExpValidator(QRegExp("\\b[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}\\b")));
           ui->lineEdit_12->setValidator(new QRegExpValidator(QRegExp("\\b[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}\\b")));


           //ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
    ui->comboBox_id->setModel(caissetemp.afficher1());
}

clientetfinance::~clientetfinance()
{
    delete ui;
}

void clientetfinance::on_pushButton_clicked()
{
    int num=ui->lineEdit->text().toInt();
    QString type=ui->lineEdit_15->text();
  float montant=ui->lineEdit_2->text().toFloat();
     Caisse  c(num,montant,type);
     bool test=c.ajouterBudget();

     if(test){
ui->tableViewcaisse->setModel(caissetemp.afficher1());
ui->comboBox_id->setModel(caissetemp.afficher1());
         QMessageBox::information(nullptr,QObject::tr("ajout"),QObject::tr("ajout avec succés \n click ok to exit")
                 ,QMessageBox::Ok);
                                }
     else
         QMessageBox::critical(nullptr,QObject::tr("ajout"),QObject::tr("ajout failed \n click cancel to exit")
                 ,QMessageBox::Ok);
}

void clientetfinance::on_pushButton_5_clicked()
{
    int id=ui->lineEdit_9->text().toInt();
    QString nom=ui->lineEdit_10->text();
    QString prenom=ui->lineEdit_11->text();
    QString adresse=ui->lineEdit_12->text();
     clientF  c(id,nom,prenom,adresse);
     bool test=c.ajouterClient();
     notification n;

     if(test){
ui->tableViewclient->setModel(clienttemp.afficher());
 //n.notificationC();
         QMessageBox::information(nullptr,QObject::tr("ajout"),QObject::tr("ajout avec succés \n click ok to exit")
                 ,QMessageBox::Ok);

                                }
     else
         QMessageBox::critical(nullptr,QObject::tr("ajout"),QObject::tr("ajout failed \n click cancel to exit")
                 ,QMessageBox::Ok);

}




void clientetfinance::on_pushButton_2_clicked()
{

    int num=ui->lineEdit_3->text().toInt();
    bool test=caissetemp.supprimerBudget(num);
    if(ui->lineEdit_3->text().contains(QRegExp("^[1-9]"))==0){

            QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                                   QObject::tr("ERREUR.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
        } else
    if(test){
ui->tableViewcaisse->setModel(caissetemp.afficher1());
        QMessageBox::information(nullptr,QObject::tr("suppression"),QObject::tr("suppression avec succés \n click ok to exit")
                ,QMessageBox::Ok);
                               }
  /*  else
        QMessageBox::critical(nullptr,QObject::tr("suppression"),QObject::tr("suppression failed \n click cancel to exit")
                ,QMessageBox::Ok);*/
}





void clientetfinance::on_pushButton_4_clicked()
{ QString num=ui->comboBox_id->currentText();

    caissetemp.setmontant(ui->lineEdit_8->text().toInt());
    caissetemp.settype(ui->lineEdit_4->text());

    bool test=caissetemp.modifiersalaire(num);
    if(test)
    {
        ui->comboBox_id->setModel(caissetemp.afficher1());

        ui->tableViewcaisse->setModel(caissetemp.afficher1());
                QMessageBox::information(nullptr,QObject::tr("modification"),QObject::tr("modification avec succés \n click ok to exit")
                        ,QMessageBox::Ok);
                                       }
            else
                QMessageBox::critical(nullptr,QObject::tr("modification"),QObject::tr("modification failed \n click cancel to exit")
                        ,QMessageBox::Ok);
}



void clientetfinance::on_pushButton_recherche_clicked()
{
    int num = ui->lineEdit_5->text().toInt();
            QString type = ui->lineEdit_6->text();
           float montant=ui->lineEdit_17->text().toFloat();

                QString txt=ui->lineEdit_5->text();
                 QString txt1=ui->lineEdit_17->text();
                  QString txt2=ui->lineEdit_6->text();
                ui->tableViewcaisse->setModel(caissetemp.rechercher(txt));
                 ui->tableViewcaisse->setModel(caissetemp.rechercher2(txt1));
                      ui->tableViewcaisse->setModel(caissetemp.rechercher1(txt2));

                      if(montant==0&&type==""){
                           ui->tableViewcaisse->setModel(caissetemp.rechercher(txt));
                      }
               else    if(num==0&&type==""){
                    QString txt1=ui->lineEdit_17->text();
                   ui->tableViewcaisse->setModel(caissetemp.rechercher2(txt1));}

                else    if(num==0&&montant==0){
                    QString txt2=ui->lineEdit_6->text();
                  ui->tableViewcaisse->setModel(caissetemp.rechercher1(txt2));}

                      else    if(num==0/*&&montant==0*/){

                           QString txt2=ui->lineEdit_6->text();
                           QString txt1=ui->lineEdit_17->text();
                          ui->tableViewcaisse->setModel(caissetemp.rechercher2(txt1));
                        ui->tableViewcaisse->setModel(caissetemp.rechercher1(txt2));}
                      else    if(montant==0/*&&type==""*/){
                          QString txt=ui->lineEdit_5->text();
                           QString txt1=ui->lineEdit_6->text();
                          ui->tableViewcaisse->setModel(caissetemp.rechercher(txt));
                           ui->tableViewcaisse->setModel(caissetemp.rechercher1(txt1));

                          }
                      else    if(type==""){
                          QString txt=ui->lineEdit_5->text();
                            QString txt2=ui->lineEdit_17->text();
                           ui->tableViewcaisse->setModel(caissetemp.rechercher(txt));
                          ui->tableViewcaisse->setModel(caissetemp.rechercher2(txt2));
                          }

}




void clientetfinance::on_pushButton_7_clicked()
{
    int id = ui->lineEdit_13->text().toInt();
        QString nom = ui->lineEdit_14->text();
         QString adresse = ui->lineEdit_19->text();
            if(id==0&&nom==""){
            QString txt=ui->lineEdit_19->text();
            ui->tableViewclient->setModel(clienttemp.rechercher_adresse(txt));
            }
            else    if(id==0&&adresse==""){
                QString txt=ui->lineEdit_14->text();
               ui->tableViewclient->setModel(clienttemp.rechercher_nom(txt));}

            else    if(adresse==""&&nom==""){
                QString txt=ui->lineEdit_13->text();
              ui->tableViewclient->setModel(clienttemp.rechercher_id(txt));


            }
}



void clientetfinance::on_pushButton_triercaisse_clicked()
{
      ui->tableViewcaisse->setModel(caissetemp.triercaisse());
}

void clientetfinance::on_pushButton_3_clicked()
{
    ui->tableViewclient->setModel(clienttemp.trierclient());
}



void clientetfinance::on_pushButton_pdf_clicked()
{
    QSqlDatabase db;
                QTableView table_caisse;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM caisse ");
                 qry.exec();
                 Modal->setQuery(qry);
                 table_caisse.setModel(Modal);



                 db.close();


                 QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = table_caisse.model()->rowCount();
                 const int columnCount =  table_caisse.model()->columnCount();


                 const QString strTitle ="Document";


                 out <<  "<html>\n"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des services")
                    <<"<br>"
                     <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                 out << "<thead><tr bgcolor=#f0f0f0>";
                 for (int column = 0; column < columnCount; column++)
                     if (!table_caisse.isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(table_caisse.model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!table_caisse.isColumnHidden(column)) {
                             QString data = table_caisse.model()->data(table_caisse.model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"
                         //<< QString("<p><img src=":/img/aze.png"; width="200"; height="200";\">%1</p>\n")
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

                     QLabel lab;
                      QPixmap pixmap(":/img/aze.png");
                     lab.setPixmap(pixmap);
                     QPainter painter(&lab);
                     //QPrinter printer(QPrinter::PrinterResolution);

                     //pixmap.load("aze.png");
                     //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                     //painter.drawPixmap(10,10,50,50, pixmap);

                     document->print(&printer);
                 }

                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName("/tmp/client.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                 delete document;
}


void clientetfinance::on_tabWidget_currentChanged(int index)
{
    // set dark background gradient:
          QLinearGradient gradient(0, 0, 0, 400);
          gradient.setColorAt(0, QColor(90, 90, 90));
          gradient.setColorAt(0.38, QColor(234, 234, 234));
          gradient.setColorAt(1, QColor(10, 10, 10));
          ui->plot->setBackground(QBrush(gradient));


          // create empty bar chart objects:
          QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
          amande->setAntialiased(false);
          amande->setStackingGap(1);
           //set names and colors:
          amande->setName("Repartition des services selon leurs montants ");
          amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
          amande->setBrush(QColor(0, 168, 140));
          // stack bars on top of each other:



          QVector<double> ticks;
          QVector<QString> labels;
          caissetemp.statistique(&ticks,&labels);



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

          // prepare y axis:
          ui->plot->yAxis->setRange(0,10);
          ui->plot->yAxis->setPadding(5); // a bit more space to the left border
          ui->plot->yAxis->setLabel("Statistiques");
          ui->plot->yAxis->setBasePen(QPen(Qt::white));
          ui->plot->yAxis->setTickPen(QPen(Qt::white));
          ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
          ui->plot->yAxis->grid()->setSubGridVisible(true);
          ui->plot->yAxis->setTickLabelColor(Qt::white);
          ui->plot->yAxis->setLabelColor(Qt::white);
          ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
          ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

          // Add data:

          QVector<double> PlaceData;
          QSqlQuery q1("select montant from caisse");
          while (q1.next()) {
                        int  nbr_fautee = q1.value(0).toInt();
                        PlaceData<< nbr_fautee;
                          }
          amande->setData(ticks, PlaceData);
          // setup legend:
          ui->plot->legend->setVisible(true);
          ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
          ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
          ui->plot->legend->setBorderPen(Qt::NoPen);
          QFont legendFont = font();
          legendFont.setPointSize(10);
          ui->plot->legend->setFont(legendFont);
          ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}


void clientetfinance::on_comboBox_currentIndexChanged(int index)
{
  
      {
            ui->tableViewcaisse->setModel(caissetemp.tricaisse(index));
      }

}



void clientetfinance::on_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                           tr("Excel Files (*.xls)"));
           if (fileName.isEmpty())
               return;

           ExportExcelObject obj(fileName, "mydata", ui->tableViewclient);

           obj.addField(0, "colum1", "char(20)");
           obj.addField(1, "colum2", "char(20)");
           obj.addField(2, "colum3", "char(20)");
           obj.addField(3, "colum4", "char(20)");

           int retVal = obj.export2Excel();

           if( retVal > 0)
           {
               QMessageBox::information(this, tr("Done"),
                                        QString(tr("%1 records exported!")).arg(retVal)
                                        );
           }
}

void clientetfinance::on_comboBox_2_currentIndexChanged(int index)
{
     ui->tableViewclient->setModel(clienttemp.triclient(index));
}



void clientetfinance::on_envoyer_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
              smtp.setUser("ecinema.client@gmail.com");
              smtp.setPassword("");
              MimeMessage message;
              message.setSender(new EmailAddress("ecinema.client@gmail.com", "ecinema client"));
              QString emaiil =ui->adresse->text();
              message.addRecipient(new EmailAddress(emaiil, ""));
              message.setSubject("client informations");
              MimeText text;
              QString emaill = ui->contenu->toPlainText();
              text.setText(emaill);
              message.addPart(&text);
              smtp.connectToHost();
              smtp.login();
              if(smtp.sendMail(message))
              {
                  QMessageBox::information(this, "PAS D'ERREUR", "Envoyé");
              }
              else
              {
                  QMessageBox::critical(this, "ERREUR", "Non Envoyé (probleme de connexion)");
              }
              smtp.quit();
}


void clientetfinance::on_arduinow_clicked()
{

}

void clientetfinance::on_comboBox_id_currentTextChanged(const QString &arg1)
{
    QSqlQuery query;
        QString ch=arg1;
        query.prepare("select* from caisse where num ='"+ch+"'");
    if (query.exec())
    {
      while (query.next())
      {
           ui->lineEdit_8->setText(query.value(2).toString());
            ui->lineEdit_4->setText(query.value(1).toString());



      }
    }
}
