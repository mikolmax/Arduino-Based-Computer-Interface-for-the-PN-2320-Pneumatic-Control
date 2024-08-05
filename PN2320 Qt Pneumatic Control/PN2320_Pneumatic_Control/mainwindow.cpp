#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    microcontroller = new arduino;
    gate = new logicGateSimulation;

    microcontroller->setArduino();

    connect(microcontroller->microcontroller, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
}

MainWindow::~MainWindow()
{
    microcontroller->closeArduino();
    delete ui;
}

void MainWindow::readText()
{
    QTextDocument *doc = ui->plainTextEdit->document();
    int line = doc->lineCount();
    //qDebug() << s << line;

    for(int i = 0; i < line; i++) {
        QTextBlock tb = doc->findBlockByLineNumber(i);
        QString text = tb.text();
        text = text.replace(" ", "");

        if(text != "") {
            qDebug() << text;
            microcontroller->updateArduino(text);
            Sleep(uint(200));
        }
    }
}

void MainWindow::readSerialData()
{
    QByteArray serialData = microcontroller->microcontroller->readAll();
    QString temp = QString::fromStdString(serialData.toStdString());
    qDebug() << temp;
    ui->timeValue->setText(temp);
}

void MainWindow::getSwitchState()
{
    int SW1 = 0, SW2 = 0, SW3 = 0, SW4 = 0;
    int result1 = 0, result2 = 0;

    if (ui->comboBoxSW1->currentText() == "ON")
        SW1 = 1;
    if (ui->comboBoxSW2->currentText() == "ON")
        SW2 = 1;
    if (ui->comboBoxSW3->currentText() == "ON")
        SW3 = 1;
    if (ui->comboBoxSW4->currentText() == "ON")
        SW4 = 1;

    if(ui->checkBoxCircuit1->isChecked())
        result1 = getCircuit1Result(SW1, SW2, SW3, SW4);
    if(ui->checkBoxCircuit2->isChecked())
        result2 = getCircuit2Result(SW1, SW2, SW3, SW4);

    outputCircuitResults(result1, result2);
}

int MainWindow::getCircuit1Result(int SW1, int SW2, int SW3, int SW4)
{
    int input1=0, input2=0, result=0;
    qDebug() << SW1 << SW2 << SW3 << SW4;

    if(ui->comboBoxUpper1->currentText() == "SW1")
        input1 = SW1;
    else if(ui->comboBoxUpper1->currentText() == "SW2")
        input1 = SW2;
    else if(ui->comboBoxUpper1->currentText() == "SW3")
        input1 = SW3;
    else if(ui->comboBoxUpper1->currentText() == "SW4")
        input1 = SW4;

    if(ui->comboBoxLower1->currentText() == "SW1")
        input2 = SW1;
    else if(ui->comboBoxLower1->currentText() == "SW2")
        input2 = SW2;
    else if(ui->comboBoxLower1->currentText() == "SW3")
        input2 = SW3;
    else if(ui->comboBoxLower1->currentText() == "SW4")
        input2 = SW4;

    if(ui->comboBoxGate1->currentText() == "AND")
        result = gate->logicGateAND(input1, input2);
    else if(ui->comboBoxGate1->currentText() == "OR")
        result = gate->logicGateOR(input1, input2);

    if(ui->checkBoxCon1->isChecked()) {
        if(ui->comboBoxLower2->currentText() == "SW1")
            input2 = SW1;
        else if(ui->comboBoxLower2->currentText() == "SW2")
            input2 = SW2;
        else if(ui->comboBoxLower2->currentText() == "SW3")
            input2 = SW3;
        else if(ui->comboBoxLower2->currentText() == "SW4")
            input2 = SW4;

        if(ui->comboBoxGate2->currentText() == "AND")
            result = gate->logicGateAND(result, input2);
        else if(ui->comboBoxGate2->currentText() == "OR")
            result = gate->logicGateOR(result, input2);
    }

    if(ui->checkBoxCon2->isChecked()) {
        if(ui->comboBoxLower3->currentText() == "SW1")
            input2 = SW1;
        else if(ui->comboBoxLower3->currentText() == "SW2")
            input2 = SW2;
        else if(ui->comboBoxLower3->currentText() == "SW3")
            input2 = SW3;
        else if(ui->comboBoxLower3->currentText() == "SW4")
            input2 = SW4;

        if(ui->comboBoxGate3->currentText() == "AND")
            result = gate->logicGateAND(result, input2);
        else if(ui->comboBoxGate3->currentText() == "OR")
            result = gate->logicGateOR(result, input2);
    }

    qDebug() << "result 1 is" << result;
    return result;
}

int MainWindow::getCircuit2Result(int SW1, int SW2, int SW3, int SW4)
{
    int input1=0, input2=0, result=0;

    if(ui->comboBoxUpper1_2->currentText() == "SW1")
        input1 = SW1;
    else if(ui->comboBoxUpper1_2->currentText() == "SW2")
        input1 = SW2;
    else if(ui->comboBoxUpper1_2->currentText() == "SW3")
        input1 = SW3;
    else if(ui->comboBoxUpper1_2->currentText() == "SW4")
        input1 = SW4;

    if(ui->comboBoxLower1_2->currentText() == "SW1")
        input2 = SW1;
    else if(ui->comboBoxLower1_2->currentText() == "SW2")
        input2 = SW2;
    else if(ui->comboBoxLower1_2->currentText() == "SW3")
        input2 = SW3;
    else if(ui->comboBoxLower1_2->currentText() == "SW4")
        input2 = SW4;

    if(ui->comboBoxGate1_2->currentText() == "AND")
        result = gate->logicGateAND(input1, input2);
    else if(ui->comboBoxGate1_2->currentText() == "OR")
        result = gate->logicGateOR(input1, input2);

    if(ui->checkBoxCon1_2->isChecked()) {
        if(ui->comboBoxLower2_2->currentText() == "SW1")
            input2 = SW1;
        else if(ui->comboBoxLower2_2->currentText() == "SW2")
            input2 = SW2;
        else if(ui->comboBoxLower2_2->currentText() == "SW3")
            input2 = SW3;
        else if(ui->comboBoxLower2_2->currentText() == "SW4")
            input2 = SW4;

        if(ui->comboBoxGate2_2->currentText() == "AND")
            result = gate->logicGateAND(result, input2);
        else if(ui->comboBoxGate2_2->currentText() == "OR")
            result = gate->logicGateOR(result, input2);
    }

    if(ui->checkBoxCon2_2->isChecked()) {
        if(ui->comboBoxLower3_2->currentText() == "SW1")
            input2 = SW1;
        else if(ui->comboBoxLower3_2->currentText() == "SW2")
            input2 = SW2;
        else if(ui->comboBoxLower3_2->currentText() == "SW3")
            input2 = SW3;
        else if(ui->comboBoxLower3_2->currentText() == "SW4")
            input2 = SW4;

        if(ui->comboBoxGate3_2->currentText() == "AND")
            result = gate->logicGateAND(result, input2);
        else if(ui->comboBoxGate3_2->currentText() == "OR")
            result = gate->logicGateOR(result, input2);
    }

    qDebug() << "result 2 is" << result;
    return result;
}

void MainWindow::outputCircuitResults(int output1, int output2)
{
    QString value1, value2;

    if (output1 == 1) {
        if (ui->comboBoxOutput1->currentText() == "Valve 1")
            value1 = "valve1,1";
        else if (ui->comboBoxOutput1->currentText() == "Valve 2")
            value1 = "valve2,1";
        else if (ui->comboBoxOutput1->currentText() == "Valve 3 C+")
            value1 = "valve3Pos,1";
        else if (ui->comboBoxOutput1->currentText() == "Valve 3 C-")
            value1 = "valve3Neg,1";
    } else {
        if (ui->comboBoxOutput1->currentText() == "Valve 1")
            value1 = "valve1,0";
        else if (ui->comboBoxOutput1->currentText() == "Valve 2")
            value1 = "valve2,0";
        else if (ui->comboBoxOutput1->currentText() == "Valve 3 C+")
            value1 = "valve3Pos,0";
        else if (ui->comboBoxOutput1->currentText() == "Valve 3 C-")
            value1 = "valve3Neg,0";
    } microcontroller->updateArduino(value1);

    if (output2 == 1) {
        if (ui->comboBoxOutput2->currentText() == "Valve 1")
            value2 = "valve1,1";
        else if (ui->comboBoxOutput2->currentText() == "Valve 2")
            value2 = "valve2,1";
        else if (ui->comboBoxOutput2->currentText() == "Valve 3 C+")
            value2 = "valve3Pos,1";
        else if (ui->comboBoxOutput2->currentText() == "Valve 3 C-")
            value2 = "valve3Neg,1";
    } else {
        if (ui->comboBoxOutput2->currentText() == "Valve 1")
            value2 = "valve1,0";
        else if (ui->comboBoxOutput2->currentText() == "Valve 2")
            value2 = "valve2,0";
        else if (ui->comboBoxOutput2->currentText() == "Valve 3 C+")
            value2 = "valve3Pos,0";
        else if (ui->comboBoxOutput2->currentText() == "Valve 3 C-")
            value2 = "valve3Neg,0";
    } microcontroller->updateArduino(value2);
}

void MainWindow::on_directButton1_clicked()
{
    if (ui->directButton1->text() == "ON") {
        ui->directButton1->setText("OFF");
        QString value = "valve1,1";
        microcontroller->updateArduino(value);
    } else if (ui->directButton1->text() == "OFF") {
        ui->directButton1->setText("ON");
        QString value = "valve1,0";
        microcontroller->updateArduino(value);
    }
}

void MainWindow::on_directButton2_clicked()
{
    if (ui->directButton2->text() == "ON") {
        ui->directButton2->setText("OFF");
        QString value = "valve2,1";
        microcontroller->updateArduino(value);
    } else if (ui->directButton2->text() == "OFF") {
        ui->directButton2->setText("ON");
        QString value = "valve2,0";
        microcontroller->updateArduino(value);
    }
}

void MainWindow::on_directButton3Pos_clicked()
{
    if (ui->directButton3Pos->text() == "ON") {
        if(ui->directButton3Neg->text() == "OFF")
            on_directButton3Neg_clicked();

        ui->directButton3Pos->setText("OFF");
        QString value = "valve3Pos,1";
        microcontroller->updateArduino(value);
    } else if (ui->directButton3Pos->text() == "OFF") {
        ui->directButton3Pos->setText("ON");
        QString value = "valve3Pos,0";
        microcontroller->updateArduino(value);
    }
}

void MainWindow::on_directButton3Neg_clicked()
{
    if (ui->directButton3Neg->text() == "ON") {
        if(ui->directButton3Pos->text() == "OFF")
            on_directButton3Pos_clicked();

        ui->directButton3Neg->setText("OFF");
        QString value = "valve3Neg,1";
        microcontroller->updateArduino(value);
    } else if (ui->directButton3Neg->text() == "OFF") {
        ui->directButton3Neg->setText("ON");
        QString value = "valve3Neg,0";
        microcontroller->updateArduino(value);
    }
}

void MainWindow::on_send_clicked()
{
    int i = 0;
    int value = ui->spinBox->value();
    for(i=0; i<value; i++) {
        readText();
    }
}

void MainWindow::on_outputButton_clicked()
{
    getSwitchState();
}

void MainWindow::on_pushButton1_pressed()
{
    QString value = "valve1,1";
    microcontroller->updateArduino(value);
}

void MainWindow::on_pushButton1_released()
{
    QString value = "valve1,0";
    microcontroller->updateArduino(value);
}

void MainWindow::on_pushButton2_pressed()
{
    QString value = "valve2,1";
    microcontroller->updateArduino(value);
}

void MainWindow::on_pushButton2_released()
{
    QString value = "valve2,0";
    microcontroller->updateArduino(value);
}

void MainWindow::on_pushButton3Pos_pressed()
{
    QString value = "valve3Pos,1";
    microcontroller->updateArduino(value);
}

void MainWindow::on_pushButton3Pos_released()
{
    QString value = "valve3Pos,0";
    microcontroller->updateArduino(value);
}

void MainWindow::on_pushButton3Neg_pressed()
{
    QString value = "valve3Neg,1";
    microcontroller->updateArduino(value);
}

void MainWindow::on_pushButton3Neg_released()
{
    QString value = "valve3Neg,0";
    microcontroller->updateArduino(value);
}
