#ifndef CLIENTETFINANCE_H
#define CLIENTETFINANCE_H
#include <QObject>
#include <QDialog>
#include "QMainWindow"
#include "ClientF.h"
#include "caisse.h"

namespace Ui {
class clientetfinance;
}

class clientetfinance : public QDialog
{
    Q_OBJECT

public:
    explicit clientetfinance(QWidget *parent = nullptr);
    ~clientetfinance();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();



    void on_pushButton_2_clicked();



    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_recherche_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_triercaisse_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_pdf_clicked();

    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_8_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_excel_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_id_currentIndexChanged(int index);

    void on_comboBox_id_currentIndexChanged(const QString &arg1);

    void on_envoyer_clicked();

    void on_arduinow_clicked();

    void on_comboBox_id_activated(const QString &arg1);

    void on_comboBox_id_currentTextChanged(const QString &arg1);

private:
    Ui::clientetfinance *ui;
    clientF clienttemp;
     Caisse caissetemp;

};

#endif // CLIENTETFINANCE_H
