#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTextDocument>
#include <QTextBlock>
#include "arduino.h"
#include "logicgatesimulation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void readText();
    void readSerialData();
    void getSwitchState();
    int getCircuit1Result(int SW1, int SW2, int SW3, int SW4);
    int getCircuit2Result(int SW1, int SW2, int SW3, int SW4);
    void outputCircuitResults(int output1, int output2);

private slots:
    void on_directButton1_clicked();
    void on_directButton2_clicked();
    void on_directButton3Pos_clicked();
    void on_directButton3Neg_clicked();
    void on_send_clicked();
    void on_outputButton_clicked();
    void on_pushButton1_pressed();
    void on_pushButton1_released();
    void on_pushButton2_pressed();
    void on_pushButton2_released();
    void on_pushButton3Pos_pressed();
    void on_pushButton3Pos_released();
    void on_pushButton3Neg_pressed();
    void on_pushButton3Neg_released();

private:
    Ui::MainWindow *ui;
    arduino *microcontroller;
    logicGateSimulation *gate;
};

#endif // MAINWINDOW_H
