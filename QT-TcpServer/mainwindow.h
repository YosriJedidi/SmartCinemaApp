#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTcpServer>
#include<QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void connexion_nueva();
    void leer_socket();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer*mServer;
    QTcpSocket*mSocket;
};
#endif // MAINWINDOW_H
