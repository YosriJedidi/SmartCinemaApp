#ifndef RFID_H
#define RFID_H

#include <QDialog>

namespace Ui {
class rfid;
}

class rfid : public QDialog
{
    Q_OBJECT

public:
    explicit rfid(QWidget *parent = nullptr);
    ~rfid();

private:
    Ui::rfid *ui;
};

#endif // RFID_H
