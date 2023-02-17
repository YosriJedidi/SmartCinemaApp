#ifndef ARDRFID_H
#define ARDRFID_H

#include <QDialog>
#include "arduino.h"
namespace Ui {
class ardrfid;
}

class ardrfid : public QDialog
{
    Q_OBJECT

public:
    explicit ardrfid(QWidget *parent = nullptr);
    ~ardrfid();

private slots:
    void on_pushButton_clicked();

    void on_ouvrir_clicked();

    void on_fermer_clicked();
    void update_label();
private:
    Ui::ardrfid *ui;

    QByteArray data; // variable contenant les données reçues

    Arduino A;


};

#endif // ARDRFID_H
