#include "ardcap.h"
#include "ui_ardcap.h"
#include "arduino.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>
ardcap::ardcap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ardcap)
{
    ui->setupUi(this);
    arduino = new QSerialPort(this);
           serialBuffer = "";
           parsed_data = "";
           mouvement_value = 0.0;


           bool arduino_is_available = false;
           QString arduino_uno_port_name;
           //
           //  For each available serial port
           foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
               //  check if the serialport has both a product identifier and a vendor identifier
               if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
                   //  check if the product ID and the vendor ID match those of the arduino uno
                   if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                           && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                       arduino_is_available = true; //    arduino uno is available on this port
                       arduino_uno_port_name = serialPortInfo.portName();
                   }
               }
           }

           /*
            *  Open and configure the arduino port if available
            */
           if(arduino_is_available){
               qDebug() << "Found the arduino port...\n";
               arduino->setPortName(arduino_uno_port_name);
               arduino->open(QSerialPort::ReadOnly);
               arduino->setBaudRate(QSerialPort::Baud9600);
               arduino->setDataBits(QSerialPort::Data8);
               arduino->setFlowControl(QSerialPort::NoFlowControl);
               arduino->setParity(QSerialPort::NoParity);
               arduino->setStopBits(QSerialPort::OneStop);
               QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
           }else{
               qDebug() << "Couldn't find the correct port for the arduino.\n";
               QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
           }
       }




   void ardcap::readSerial()
   {

           serialData = arduino->readAll();

         ardcap::updatemouvement(serialData);


   }

   void ardcap::updatemouvement(QString sensor_reading)
   {
       //  update the value displayed on the lcdNumber

   if(sensor_reading=="1"){
    ui->label->setText("motion detected ");
   }
   else{
       ui->label->setText("motion stopped ");
   }

      // ui->temp_lcdNumber->display(sensor_reading);

   }


ardcap::~ardcap()
{
    delete ui;
}
