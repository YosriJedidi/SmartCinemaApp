/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralwidget;
    QTextEdit *recordTextEdit;
    QPushButton *sendBtn;
    QLineEdit *msgLineEdit;
    QPushButton *connectBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(422, 330);
        centralwidget = new QWidget(Client);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        recordTextEdit = new QTextEdit(centralwidget);
        recordTextEdit->setObjectName(QStringLiteral("recordTextEdit"));
        recordTextEdit->setGeometry(QRect(6, 10, 391, 191));
        sendBtn = new QPushButton(centralwidget);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(300, 240, 101, 31));
        msgLineEdit = new QLineEdit(centralwidget);
        msgLineEdit->setObjectName(QStringLiteral("msgLineEdit"));
        msgLineEdit->setGeometry(QRect(6, 250, 291, 21));
        connectBtn = new QPushButton(centralwidget);
        connectBtn->setObjectName(QStringLiteral("connectBtn"));
        connectBtn->setGeometry(QRect(300, 210, 101, 23));
        Client->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Client);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 422, 21));
        Client->setMenuBar(menubar);
        statusbar = new QStatusBar(Client);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Client->setStatusBar(statusbar);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "MainWindow", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("Client", "Send", Q_NULLPTR));
        connectBtn->setText(QApplication::translate("Client", "Connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
