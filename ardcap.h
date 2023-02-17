#ifndef ARDCAP_H
#define ARDCAP_H

#include <QDialog>
#include <QSerialPort>
#include <QByteArray>
QT_BEGIN_NAMESPACE
namespace Ui { class mvt; }
QT_END_NAMESPACE
namespace Ui {
class ardcap;
}

class ardcap : public QDialog
{
    Q_OBJECT

public:
    explicit ardcap(QWidget *parent = nullptr);
    ~ardcap();
private slots:
    void readSerial();
    void updatemouvement(QString);
private:
    Ui::ardcap *ui;
    QSerialPort *arduino;
          static const quint16 arduino_uno_vendor_id = 9025;
          static const quint16 arduino_uno_product_id = 67;
          QByteArray serialData;
          QString serialBuffer;
          QString parsed_data;
          double mouvement_value;
};

#endif // ARDCAP_H
