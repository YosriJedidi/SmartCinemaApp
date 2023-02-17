#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QObject>
#include "login.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setid(QString);
    void setmdp(QString);
    QString getid();
    QString getmdp();

private slots:


    void on_Connect_clicked();

    void on_pushButton_clicked();

    void on_connect_clicked();

    void on_pushButton_2_clicked();

    void on_hama_clicked();

    void on_wiem_clicked();

    void on_farah_clicked();

    void on_prog_clicked();

private:
    Login templog;
      QByteArray data;
    QString id,mdp;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
