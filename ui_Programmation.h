/********************************************************************************
** Form generated from reading UI file 'Programmation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMMATION_H
#define UI_PROGRAMMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Programmation
{
public:
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_Nom;
    QLineEdit *lineEdit_categorie;
    QPushButton *pushButton_modifFilm;
    QPushButton *pushButton_ajoutFilm;
    QLineEdit *lineEdit_duree;
    QLabel *label_9;
    QLineEdit *lineEdit_ID;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLineEdit *lineEdit_suppFilm;
    QPushButton *pushButton_suppFilm;
    QGroupBox *groupBox_3;
    QTableView *tableView_Film;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_7;
    QRadioButton *radioButton;
    QGroupBox *groupBox_8;
    QLineEdit *lineEdit_rechercheF;
    QPushButton *pushButton_rechercheF;
    QWidget *tab_4;
    QGroupBox *groupBox_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_15;
    QLineEdit *lineEdit_IDE;
    QLineEdit *lineEdit_nomC;
    QLineEdit *lineEdit_NbPlaces;
    QPushButton *pushButton_modifTicket;
    QPushButton *pushButton_ajoutTicket;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QGroupBox *groupBox_5;
    QLabel *label_16;
    QLineEdit *lineEdit_supprimerTicket;
    QPushButton *pushButton_supprimerTicket;
    QGroupBox *groupBox_6;
    QTableView *tableView_Ticket;
    QPushButton *pushButton_excel;
    QWidget *tab;
    QPushButton *pushButton_Chat;

    void setupUi(QDialog *Programmation)
    {
        if (Programmation->objectName().isEmpty())
            Programmation->setObjectName(QStringLiteral("Programmation"));
        Programmation->resize(862, 539);
        label = new QLabel(Programmation);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-5, -5, 871, 551));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/cinemApp.jpg")));
        label->setScaledContents(true);
        tabWidget = new QTabWidget(Programmation);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(-4, 69, 871, 441));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 30, 371, 181));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 71, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 110, 56, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 150, 56, 16));
        lineEdit_Nom = new QLineEdit(groupBox);
        lineEdit_Nom->setObjectName(QStringLiteral("lineEdit_Nom"));
        lineEdit_Nom->setGeometry(QRect(120, 70, 113, 22));
        lineEdit_categorie = new QLineEdit(groupBox);
        lineEdit_categorie->setObjectName(QStringLiteral("lineEdit_categorie"));
        lineEdit_categorie->setGeometry(QRect(120, 110, 113, 22));
        pushButton_modifFilm = new QPushButton(groupBox);
        pushButton_modifFilm->setObjectName(QStringLiteral("pushButton_modifFilm"));
        pushButton_modifFilm->setGeometry(QRect(260, 140, 93, 28));
        pushButton_ajoutFilm = new QPushButton(groupBox);
        pushButton_ajoutFilm->setObjectName(QStringLiteral("pushButton_ajoutFilm"));
        pushButton_ajoutFilm->setGeometry(QRect(260, 100, 93, 28));
        lineEdit_duree = new QLineEdit(groupBox);
        lineEdit_duree->setObjectName(QStringLiteral("lineEdit_duree"));
        lineEdit_duree->setGeometry(QRect(120, 150, 113, 22));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 30, 56, 16));
        lineEdit_ID = new QLineEdit(groupBox);
        lineEdit_ID->setObjectName(QStringLiteral("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(120, 30, 113, 22));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 230, 371, 101));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 50, 71, 16));
        lineEdit_suppFilm = new QLineEdit(groupBox_2);
        lineEdit_suppFilm->setObjectName(QStringLiteral("lineEdit_suppFilm"));
        lineEdit_suppFilm->setGeometry(QRect(120, 50, 113, 22));
        pushButton_suppFilm = new QPushButton(groupBox_2);
        pushButton_suppFilm->setObjectName(QStringLiteral("pushButton_suppFilm"));
        pushButton_suppFilm->setGeometry(QRect(260, 50, 93, 28));
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(419, 29, 421, 301));
        tableView_Film = new QTableView(groupBox_3);
        tableView_Film->setObjectName(QStringLiteral("tableView_Film"));
        tableView_Film->setGeometry(QRect(20, 40, 391, 211));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 260, 93, 28));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 260, 93, 28));
        groupBox_7 = new QGroupBox(tab_3);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(30, 340, 371, 51));
        radioButton = new QRadioButton(groupBox_7);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 20, 97, 21));
        groupBox_8 = new QGroupBox(tab_3);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(420, 340, 421, 51));
        lineEdit_rechercheF = new QLineEdit(groupBox_8);
        lineEdit_rechercheF->setObjectName(QStringLiteral("lineEdit_rechercheF"));
        lineEdit_rechercheF->setGeometry(QRect(90, 20, 181, 22));
        pushButton_rechercheF = new QPushButton(groupBox_8);
        pushButton_rechercheF->setObjectName(QStringLiteral("pushButton_rechercheF"));
        pushButton_rechercheF->setGeometry(QRect(290, 20, 93, 28));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_4 = new QGroupBox(tab_4);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 30, 351, 241));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 40, 71, 16));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 80, 56, 16));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 120, 61, 16));
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(0, 180, 81, 16));
        lineEdit_IDE = new QLineEdit(groupBox_4);
        lineEdit_IDE->setObjectName(QStringLiteral("lineEdit_IDE"));
        lineEdit_IDE->setGeometry(QRect(80, 40, 113, 22));
        lineEdit_nomC = new QLineEdit(groupBox_4);
        lineEdit_nomC->setObjectName(QStringLiteral("lineEdit_nomC"));
        lineEdit_nomC->setGeometry(QRect(80, 80, 113, 22));
        lineEdit_NbPlaces = new QLineEdit(groupBox_4);
        lineEdit_NbPlaces->setObjectName(QStringLiteral("lineEdit_NbPlaces"));
        lineEdit_NbPlaces->setGeometry(QRect(80, 120, 113, 22));
        pushButton_modifTicket = new QPushButton(groupBox_4);
        pushButton_modifTicket->setObjectName(QStringLiteral("pushButton_modifTicket"));
        pushButton_modifTicket->setGeometry(QRect(240, 200, 93, 28));
        pushButton_ajoutTicket = new QPushButton(groupBox_4);
        pushButton_ajoutTicket->setObjectName(QStringLiteral("pushButton_ajoutTicket"));
        pushButton_ajoutTicket->setGeometry(QRect(240, 160, 93, 28));
        dateEdit = new QDateEdit(groupBox_4);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(70, 180, 91, 22));
        timeEdit = new QTimeEdit(groupBox_4);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(160, 180, 61, 22));
        groupBox_5 = new QGroupBox(tab_4);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 280, 351, 71));
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 30, 71, 16));
        lineEdit_supprimerTicket = new QLineEdit(groupBox_5);
        lineEdit_supprimerTicket->setObjectName(QStringLiteral("lineEdit_supprimerTicket"));
        lineEdit_supprimerTicket->setGeometry(QRect(80, 30, 113, 22));
        pushButton_supprimerTicket = new QPushButton(groupBox_5);
        pushButton_supprimerTicket->setObjectName(QStringLiteral("pushButton_supprimerTicket"));
        pushButton_supprimerTicket->setGeometry(QRect(240, 30, 93, 28));
        groupBox_6 = new QGroupBox(tab_4);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(389, 29, 461, 321));
        tableView_Ticket = new QTableView(groupBox_6);
        tableView_Ticket->setObjectName(QStringLiteral("tableView_Ticket"));
        tableView_Ticket->setGeometry(QRect(20, 30, 421, 241));
        pushButton_excel = new QPushButton(groupBox_6);
        pushButton_excel->setObjectName(QStringLiteral("pushButton_excel"));
        pushButton_excel->setGeometry(QRect(180, 280, 93, 28));
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton_Chat = new QPushButton(tab);
        pushButton_Chat->setObjectName(QStringLiteral("pushButton_Chat"));
        pushButton_Chat->setGeometry(QRect(290, 160, 241, 61));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        pushButton_Chat->setFont(font);
        tabWidget->addTab(tab, QString());

        retranslateUi(Programmation);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Programmation);
    } // setupUi

    void retranslateUi(QDialog *Programmation)
    {
        Programmation->setWindowTitle(QApplication::translate("Programmation", "Programmation", Q_NULLPTR));
        label->setText(QString());
        groupBox->setTitle(QApplication::translate("Programmation", "Ajout / modification", Q_NULLPTR));
        label_2->setText(QApplication::translate("Programmation", "Nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("Programmation", "Categorie", Q_NULLPTR));
        label_4->setText(QApplication::translate("Programmation", "Dur\303\251e", Q_NULLPTR));
        lineEdit_Nom->setText(QString());
        pushButton_modifFilm->setText(QApplication::translate("Programmation", "Modifier", Q_NULLPTR));
        pushButton_ajoutFilm->setText(QApplication::translate("Programmation", "Ajouter", Q_NULLPTR));
        label_9->setText(QApplication::translate("Programmation", "ID Film", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Programmation", "Suppression", Q_NULLPTR));
        label_5->setText(QApplication::translate("Programmation", "ID Film", Q_NULLPTR));
        pushButton_suppFilm->setText(QApplication::translate("Programmation", "Supprimer", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Programmation", "Liste des Films", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Programmation", "PDF", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Programmation", "Imprimer", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("Programmation", "Tri", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Programmation", "Dur\303\251e \342\206\223", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("Programmation", "Recherche", Q_NULLPTR));
        pushButton_rechercheF->setText(QApplication::translate("Programmation", "Recherche", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Programmation", "Gestion des Films", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Programmation", "Ajout / modification", Q_NULLPTR));
        label_6->setText(QApplication::translate("Programmation", "Num Ticket", Q_NULLPTR));
        label_7->setText(QApplication::translate("Programmation", "Nom ", Q_NULLPTR));
        label_8->setText(QApplication::translate("Programmation", "Nb Places", Q_NULLPTR));
        label_15->setText(QApplication::translate("Programmation", "Date/Heure", Q_NULLPTR));
        pushButton_modifTicket->setText(QApplication::translate("Programmation", "Modifier", Q_NULLPTR));
        pushButton_ajoutTicket->setText(QApplication::translate("Programmation", "Ajouter", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("Programmation", "Suppression", Q_NULLPTR));
        label_16->setText(QApplication::translate("Programmation", "Num Ticket", Q_NULLPTR));
        pushButton_supprimerTicket->setText(QApplication::translate("Programmation", "Supprimer", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("Programmation", "Liste Tickets", Q_NULLPTR));
        pushButton_excel->setText(QApplication::translate("Programmation", "Export Excel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Programmation", "Billeterie", Q_NULLPTR));
        pushButton_Chat->setText(QApplication::translate("Programmation", "D\303\251marrer un Chat", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Programmation", "Chat", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Programmation: public Ui_Programmation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMMATION_H
