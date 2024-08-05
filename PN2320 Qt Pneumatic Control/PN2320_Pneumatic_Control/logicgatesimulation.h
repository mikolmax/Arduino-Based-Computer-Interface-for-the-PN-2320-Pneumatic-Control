#ifndef LOGICGATESIMULATION_H
#define LOGICGATESIMULATION_H

#include <QWidget>

namespace Ui {
class logicGateSimulation;
}

class logicGateSimulation : public QWidget
{
    Q_OBJECT

public:
    explicit logicGateSimulation(QWidget *parent = 0);
    ~logicGateSimulation();
    int logicGateAND(int input1, int input2);
    int logicGateOR(int input1, int input2);

private:
    Ui::logicGateSimulation *ui;
};

#endif // LOGICGATESIMULATION_H
