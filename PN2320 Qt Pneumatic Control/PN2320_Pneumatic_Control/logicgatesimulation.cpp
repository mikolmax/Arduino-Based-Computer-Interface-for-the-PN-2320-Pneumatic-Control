#include "logicgatesimulation.h"
#include "ui_logicgatesimulation.h"

logicGateSimulation::logicGateSimulation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logicGateSimulation)
{
    ui->setupUi(this);
}

logicGateSimulation::~logicGateSimulation()
{
    delete ui;
}

int logicGateSimulation::logicGateAND(int input1, int input2)
{
    int result = 0;
    
    if(input1 == 1 && input2 == 1)
        result = 1;
    else
        result = 0;
    
    return result;
}

int logicGateSimulation::logicGateOR(int input1, int input2)
{
    int result = 0;
    
    if(input1 == 1 || input2 == 1)
        result = 1;
    else
        result = 0;
    
    return result;
}
