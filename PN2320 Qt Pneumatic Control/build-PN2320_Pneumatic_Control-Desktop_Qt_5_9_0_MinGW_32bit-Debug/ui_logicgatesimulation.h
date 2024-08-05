/********************************************************************************
** Form generated from reading UI file 'logicgatesimulation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGICGATESIMULATION_H
#define UI_LOGICGATESIMULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logicGateSimulation
{
public:

    void setupUi(QWidget *logicGateSimulation)
    {
        if (logicGateSimulation->objectName().isEmpty())
            logicGateSimulation->setObjectName(QStringLiteral("logicGateSimulation"));
        logicGateSimulation->resize(400, 300);

        retranslateUi(logicGateSimulation);

        QMetaObject::connectSlotsByName(logicGateSimulation);
    } // setupUi

    void retranslateUi(QWidget *logicGateSimulation)
    {
        logicGateSimulation->setWindowTitle(QApplication::translate("logicGateSimulation", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class logicGateSimulation: public Ui_logicGateSimulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGICGATESIMULATION_H
