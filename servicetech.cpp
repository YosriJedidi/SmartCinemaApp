#include "servicetech.h"
#include "ui_servicetech.h"
#include "employe.h"
#include "salle.h"
#include <QMessageBox>
#include <qradiobutton.h>
#include <QPainter>
#include <QTextDocument>
#include <QPrinter>
#include <QTextStream>
#include <QPrintDialog>
#include "excel.h"
#include "QFileDialog"

//QSound *sonClick;
serviceTech::serviceTech(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serviceTech)
{
    ui->setupUi(this);
    ui->lineEdit_IDE->setValidator(new QIntValidator(0,999999,this));
        ui->lineEdit_supprimerEmploye->setValidator(new QIntValidator(0,999999,this));
        ui->lineEdit_suppSalle->setValidator(new QIntValidator(0,99,this));
        ui->numsalle->setValidator(new QIntValidator(0,99,this));
        ui->lineEdit_numE->setValidator(new QIntValidator(0,99999999,this));
        ui->capacitesalle->setValidator(new QIntValidator(0,999,this));
        ui->tableView_employe->setModel(tempEmploye.afficherEmploye());
        ui->tableView_salle->setModel(tempSalle.afficherSalle());
    /*ui->comboBox_tri->addItem("ID");
    ui->comboBox_tri->addItem("NOM");
    ui->comboBox_tri->addItem("PRENOM");
    ui->comboBox_tri->addItem("NUMTEL");*/
    ui->tableView_employe->setModel(tempEmploye.afficherEmploye());
    ui->tableView_salle->setModel(tempSalle.afficherSalle());
    //sonClick=new QSound(":/new/son/Click.wav");

}

serviceTech::~serviceTech()
{
    delete ui;
}



void serviceTech::on_pushButton_ajoutE_clicked()
{
    //sonClick->play();
   int id=ui->lineEdit_IDE->text().toInt();
   int numTel=ui->lineEdit_numE->text().toInt();
   QString nom=ui->lineEdit_nomE->text();
   QString prenom=ui->lineEdit_prenomE->text();
   Employe e(id, nom, prenom, numTel);
   ui->lineEdit_IDE->clear();
   ui->lineEdit_numE->clear();
   ui->lineEdit_nomE->clear();
   ui->lineEdit_prenomE->clear();
   bool test=e.ajouter();
   if(ui->lineEdit_IDE->text().isEmpty()||ui->lineEdit_numE->text().isEmpty()||ui->lineEdit_nomE->text().isEmpty()||ui->lineEdit_prenomE->text().isEmpty())
      {
           test=false;
      }
   if (test)
   {
       ui->tableView_employe->setModel(tempEmploye.afficherEmploye());
       QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout avec succés \n click cancel to exit")
               ,QMessageBox::Cancel);
   }
   else
   {
       QMessageBox::critical(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout échoue \n click cancel to exit")
               ,QMessageBox::Cancel);
   }
}

void serviceTech::on_pushButton_supprimerEmploye_clicked()
{
    //sonClick->play();
int id=ui->lineEdit_supprimerEmploye->text().toInt();
ui->lineEdit_supprimerEmploye->clear();
bool test = tempEmploye.supprimer(id);
if(ui->lineEdit_supprimerEmploye->text().isEmpty())
{
     test=false;
}
if (test)
{
    ui->tableView_employe->setModel(tempEmploye.afficherEmploye());
    QMessageBox::information(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression avec succés \n click cancel to exit")
            ,QMessageBox::Cancel);
}
else
{
    QMessageBox::critical(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression échouée \n click cancel to exit")
            ,QMessageBox::Cancel);
}
}


void serviceTech::on_pushButton_ajoutsalle_clicked()
{
    //sonClick->play();
    int num=ui->numsalle->text().toInt();
    int capacite=ui->capacitesalle->text().toInt();
    QString etat=ui->etatsalle->text();
    Salle s(num, capacite, etat);
    ui->numsalle->clear();
    ui->capacitesalle->clear();
    ui->etatsalle->clear();
    bool test=s.ajouterSalle();
    if(ui->numsalle->text().isEmpty()||ui->capacitesalle->text().isEmpty()||ui->etatsalle->text().isEmpty())
        {
             test=false;
        }
    if (test)
    {
         ui->tableView_salle->setModel(tempSalle.afficherSalle());
        QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout avec succés \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout échoué \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
}

void serviceTech::on_pushButton_suppSalle_clicked()
{
    //sonClick->play();
    int num=ui->lineEdit_suppSalle->text().toInt();
    ui->lineEdit_suppSalle->clear();
    bool test = tempSalle.supprimerSalle(num);
    if(ui->lineEdit_suppSalle->text().isEmpty())
       {
            test=false;
       }
    if (test)
    {
        ui->tableView_salle->setModel(tempSalle.afficherSalle());
        QMessageBox::information(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression avec succés \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression échouée \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
}

void serviceTech::on_pushButton_modifS_clicked()
{
    //sonClick->play();
    int num=ui->numsalle->text().toInt();
        tempSalle.setCapacite(ui->capacitesalle->text().toInt());
        tempSalle.setEtat(ui->etatsalle->text());
        ui->numsalle->clear();
        ui->capacitesalle->clear();
        ui->etatsalle->clear();
        bool test=tempSalle.modifSalle(num);
        if(ui->numsalle->text().isEmpty()||ui->capacitesalle->text().isEmpty()||ui->etatsalle->text().isEmpty())
                {
                     test=false;
                }
        if(test)
        {
           ui->tableView_salle->setModel(tempSalle.afficherSalle());
                    QMessageBox::information(nullptr,QObject::tr("modification"),QObject::tr("modification avec succés \n click ok to exit")
                            ,QMessageBox::Ok);
                                           }
                else
                    QMessageBox::critical(nullptr,QObject::tr("modification"),QObject::tr("modification failed \n click cancel to exit")
                            ,QMessageBox::Ok);
}

void serviceTech::on_pushButton_modifEmp_clicked()
{
    //sonClick->play();
    int id=ui->lineEdit_IDE->text().toInt();
    tempEmploye.setNom(ui->lineEdit_nomE->text());
    tempEmploye.setPrenom(ui->lineEdit_prenomE->text());
    tempEmploye.setNum(ui->lineEdit_numE->text().toInt());
    ui->lineEdit_IDE->clear();
    ui->lineEdit_numE->clear();
    ui->lineEdit_nomE->clear();
    ui->lineEdit_prenomE->clear();
    bool test=tempEmploye.modifier(id);
    if(ui->lineEdit_IDE->text().isEmpty()||ui->lineEdit_numE->text().isEmpty()||ui->lineEdit_nomE->text().isEmpty()||ui->lineEdit_prenomE->text().isEmpty())
       {
            test=false;
       }
    if (test)
    {
        ui->tableView_employe->setModel(tempEmploye.afficherEmploye());
        QMessageBox::information(nullptr,QObject::tr("Modification"),QObject::tr("Modification avec succés \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Modification"),QObject::tr("Modification échoue \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
}

void serviceTech::on_Tri_clicked()
{
//sonClick->play();
    ui->tableView_employe->setModel(tempEmploye.affichageTrier());
}


void serviceTech::on_pushButton_pdf_clicked()
{
    //sonClick->play();
    QSqlDatabase db;
                QTableView tableView_salle;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM SALLES ");
                 qry.exec();
                 Modal->setQuery(qry);
                 tableView_salle.setModel(Modal);



                 db.close();


                 QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = tableView_salle.model()->rowCount();
                 const int columnCount =  tableView_salle.model()->columnCount();


                 const QString strTitle ="Document";


                 out <<  "<html>\n"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des salles")
                    <<"<br>"
                     <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";

                 out << "<thead><tr bgcolor=#f0f0f0>";
                 for (int column = 0; column < columnCount; column++)
                     if (!tableView_salle.isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(tableView_salle.model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!tableView_salle.isColumnHidden(column)) {
                             QString data = tableView_salle.model()->data(tableView_salle.model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"
                       "<p align='center'> <img src='C:/Users/Trabelsi/OneDrive/Bureau/CinemApp/supporTech/logocin2.png' alt='care++logo'></p>"
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
                 printer.setOutputFileName("/tmp/listeSalles.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                 delete document;
}

void serviceTech::on_expoter_pdf_clicked()
{
   // sonClick->play();
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->tableView_employe);

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
void Salle::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery q;
    int i=0;
    q.exec("select NUMSALLE from SALLES");
    while (q.next()) {
        QString refer = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<refer;
}
}
void serviceTech::on_tabWidget_currentChanged(int index)
{
    // set dark background gradient:

              QLinearGradient gradient(0, 0, 0, 400);
              gradient.setColorAt(0, QColor(90, 90, 90));
              gradient.setColorAt(0.38, QColor(105, 105, 105));
              gradient.setColorAt(1, QColor(70, 70, 70));
              ui->plot->setBackground(QBrush(gradient));


              // create empty bar chart objects:
              QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
              amande->setAntialiased(false);
              amande->setStackingGap(1);
               //set names and colors:
              amande->setName("Repartition des salles selon leurs capacités ");
              amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
              amande->setBrush(QColor(0, 168, 140));
              // stack bars on top of each other:


              // prepare x axis with country labels:
              QVector<double> ticks;
              QVector<QString> labels;
              tempSalle.statistique(&ticks,&labels);



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
              ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 0), 0, Qt::DotLine));
              ui->plot->xAxis->setTickLabelColor(Qt::white);
              ui->plot->xAxis->setLabelColor(Qt::white);

              // prepare y axis:
              ui->plot->yAxis->setRange(0,10);
              ui->plot->yAxis->setPadding(5); // a bit more space to the left border
              ui->plot->yAxis->setLabel("Statistiques");
              ui->plot->yAxis->setBasePen(QPen(Qt::blue));
              ui->plot->yAxis->setTickPen(QPen(Qt::blue));
              ui->plot->yAxis->setSubTickPen(QPen(Qt::blue));
              ui->plot->yAxis->grid()->setSubGridVisible(true);
              ui->plot->yAxis->setTickLabelColor(Qt::white);
              ui->plot->yAxis->setLabelColor(Qt::white);
              ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 0), 0, Qt::SolidLine));
              ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 0, 130), 0, Qt::DotLine));

              // Add data:

              QVector<double> PlaceData;
              QSqlQuery q1("select CAPACITESALLE from SALLES");
              while (q1.next()) {
                            int  nbr_fautee = q1.value(0).toInt();
                            PlaceData<< nbr_fautee;
                              }
              amande->setData(ticks, PlaceData);
              // setup legend:
              ui->plot->legend->setVisible(true);
              ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
              ui->plot->legend->setBrush(QColor(255, 50, 255, 100));
              ui->plot->legend->setBorderPen(Qt::NoPen);
              QFont legendFont = font();
              legendFont.setPointSize(10);
              ui->plot->legend->setFont(legendFont);
              ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}

void serviceTech::on_arduinoh_clicked()
{
}
