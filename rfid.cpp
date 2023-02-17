#include "rfid.h"
#include "ui_rfid.h"

rfid::rfid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rfid)
{
    ui->setupUi(this);
}

rfid::~rfid()
{
    delete ui;
}
