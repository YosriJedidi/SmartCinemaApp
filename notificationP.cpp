#include "notificationP.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}

void notification::notificationAF()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("/new/prefix1/cinemApp.jpg"));

    notifyIcon->show();
    notifyIcon->showMessage("Attention ","Un Film a été Ajouté ",QSystemTrayIcon::Information,15000);
}

void notification::notificationSF()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("/new/prefix1/cinemApp.jpg"));

    notifyIcon->show();
    notifyIcon->showMessage("Attention ","Un Film a été Supprimé ",QSystemTrayIcon::Information,15000);
}

void notification::notificationMF()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("/new/prefix1/cinemApp.jpg"));

    notifyIcon->show();
    notifyIcon->showMessage("Attention ","Un Film a été Modifié ",QSystemTrayIcon::Information,15000);
}

void notification::notificationAT()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("/new/prefix1/cinemApp.jpg"));

    notifyIcon->show();
    notifyIcon->showMessage("Attention ","Un Ticket a été Ajouté ",QSystemTrayIcon::Information,15000);
}

void notification::notificationST()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("/new/prefix1/cinemApp.jpg"));

    notifyIcon->show();
    notifyIcon->showMessage("Attention ","Un Ticket a été Supprimé ",QSystemTrayIcon::Information,15000);
}

void notification::notificationMT()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("/new/prefix1/cinemApp.jpg"));

    notifyIcon->show();
    notifyIcon->showMessage("Attention ","Un Ticket a été Modifié ",QSystemTrayIcon::Information,15000);
}

void notification::notificationChat()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("/new/prefix1/cinemApp.jpg"));

    notifyIcon->show();
    notifyIcon->showMessage("Attention ","Un Chat a été démarré ",QSystemTrayIcon::Information,15000);
}
