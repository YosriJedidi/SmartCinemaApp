#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QSystemTrayIcon>
#include<QString>
class notification
{
private:
   // int num;
public:
    notification();

    void notificationAF();
    void notificationSF();
    void notificationMF();
    void notificationAT();
    void notificationST();
    void notificationMT();
    void notificationChat();

};


#endif // NOTIFICATION_H
