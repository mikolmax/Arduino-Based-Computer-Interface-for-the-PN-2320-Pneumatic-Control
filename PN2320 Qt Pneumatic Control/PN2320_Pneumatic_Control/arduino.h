#ifndef ARDUINO_H
#define ARDUINO_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>

namespace Ui {
class arduino;
}

class arduino : public QWidget
{
    Q_OBJECT

public:
    explicit arduino(QWidget *parent = 0);
    ~arduino();
    void setArduino();
    void closeArduino();
    void updateArduino(QString);
    QSerialPort *microcontroller;

private:
    Ui::arduino *ui;
    static const quint16 arduinoVendorId = 9025;
    static const quint16 arduinoProductId = 67;
    QString arduinoPortName;
    bool arduinoIsAvailable;
};

#endif // ARDUINO_H
