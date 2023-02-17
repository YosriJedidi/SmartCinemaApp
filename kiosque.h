#ifndef KIOSQUE_H
#define KIOSQUE_H
#include "produit.h"
#include"facture.h"
#include <QSound>
#include <QSystemTrayIcon>
#include <QDialog>
#include <QTcpSocket>
#include "historique.h"
#include <QFile>
#include<QTextStream>



class QMediaPlayer;
namespace Ui {
class kiosque;
}
class QSystemTrayIcon;

class kiosque : public QDialog
{
    Q_OBJECT

public:
    explicit kiosque(QWidget *parent = nullptr);
    ~kiosque();

private slots:
    void on_pushButton_AjoutProdui_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_ModifProduit_clicked();
    void on_suppProduit_clicked();
    void on_ajoutFacture_clicked();
    void on_SuppFacture_clicked();
    void on_ModiFacture_clicked();
    void on_pushButton_PDFProd_clicked();
    void on_radioButton_TRInProd_clicked();
    void on_radioButton_TRIqProd_clicked();
    void on_TriDateFacture_clicked();
    void on_TriidFacture_clicked();
    void on_rehercheFacture_textChanged(const QString &arg1);
    void on_pushButton_apport_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_stop_clicked();
    void on_play_clicked();
    void on_avance_valueChanged(int value);
    void on_pushButton_PDFFac_clicked();
    void on_volume_valueChanged(int value);
    void on_mute_clicked();
    void on_EXCELPr_clicked();
    void on_EXcelF_clicked();
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_pushButtonWEB_clicked();
    void on_comboBox_2_currentTextChanged(const QString &arg1);
    void leer();
    void on_CHAT_clicked();
    void on_reafficher_rechproduit_clicked();
    void on_rechercher_P_clicked();

private:
    Ui::kiosque *ui;
    Produit tempProduit;
    facture temFacture;
    QMediaPlayer *mMediaPlayer;
    QSound *son;
    QSystemTrayIcon *mSystemTrayIcon;
    QTcpSocket*mSocket;
    Historique histo;

};

#endif // KIOSQUE_H
