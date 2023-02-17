#ifndef SERVICETECH_H
#define SERVICETECH_H
#include "employe.h"
#include "salle.h"
#include <QDialog>
#include <qradiobutton.h>
#include <QSound>
namespace Ui {
class serviceTech;
}

class serviceTech : public QDialog
{
    Q_OBJECT

public:
    explicit serviceTech(QWidget *parent = nullptr);
    ~serviceTech();

private slots:


    void on_pushButton_ajoutE_clicked();

    void on_pushButton_supprimerEmploye_clicked();

    void on_pushButton_ajoutsalle_clicked();

    void on_pushButton_suppSalle_clicked();

    void on_pushButton_modifS_clicked();

    void on_pushButton_modifEmp_clicked();

    void on_Tri_clicked();


    //void on_pushButton_pdf_clicked();

    void on_pushButton_pdf_clicked();

    void on_expoter_pdf_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_arduinoh_clicked();

private:
    Ui::serviceTech *ui;
    Employe tempEmploye;
    Salle tempSalle;
};

#endif // SERVICETECH_H
