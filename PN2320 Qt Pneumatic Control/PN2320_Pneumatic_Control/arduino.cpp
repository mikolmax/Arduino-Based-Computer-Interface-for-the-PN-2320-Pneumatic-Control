#include "arduino.h"
#include "ui_arduino.h"

arduino::arduino(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::arduino)
{
    ui->setupUi(this);
}

arduino::~arduino()
{
    delete ui;
}

void arduino::setArduino()
{
    microcontroller = new QSerialPort;
    arduinoPortName = "";
    arduinoIsAvailable = false;

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if (serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            if (serialPortInfo.vendorIdentifier() == arduinoVendorId) {
                if (serialPortInfo.productIdentifier() == arduinoProductId) {
                    arduinoPortName = serialPortInfo.portName();
                    arduinoIsAvailable = true;
                }
            }
        }
    }

    if (arduinoIsAvailable) {
        microcontroller->setPortName(arduinoPortName);
        microcontroller->open(QSerialPort::ReadWrite);
        microcontroller->setBaudRate(QSerialPort::Baud115200);
        microcontroller->setDataBits(QSerialPort::Data8);
        microcontroller->setParity(QSerialPort::NoParity);
        microcontroller->setStopBits(QSerialPort::OneStop);
        microcontroller->setFlowControl(QSerialPort::NoFlowControl);
        qDebug() << "Connected";
    } else {
        qDebug() << "Not Connected";
    }
}

void arduino::closeArduino()
{
    if (microcontroller->isOpen()) {
        microcontroller->close();
        qDebug() << "Arduino Closed";
    }
}

void arduino::updateArduino(QString command)
{
    if (microcontroller->isWritable()) {
        microcontroller->write(command.toStdString().c_str());
    } else {
        qDebug() << "Could Not Write";
    }
}
