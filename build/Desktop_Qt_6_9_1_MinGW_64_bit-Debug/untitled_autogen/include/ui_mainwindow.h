/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelInput;
    QLineEdit *lineEditInputPath;
    QPushButton *btnBrowseInput;
    QHBoxLayout *layoutMask;
    QLabel *labelMask;
    QLineEdit *lineEditMask;
    QCheckBox *checkDeleteInput;
    QHBoxLayout *layoutSavePath;
    QLabel *labelSavePath;
    QLineEdit *lineEditSavePath;
    QPushButton *btnBrowseOutput;
    QHBoxLayout *layoutNameConflict;
    QLabel *labelNameConflict;
    QComboBox *comboNameConflict;
    QHBoxLayout *layoutMode;
    QLabel *labelMode;
    QRadioButton *radioOnce;
    QRadioButton *radioTimer;
    QHBoxLayout *layoutInterval;
    QLabel *labelInterval;
    QSpinBox *spinInterval;
    QHBoxLayout *layoutXorValue;
    QLabel *labelXorValue;
    QLineEdit *lineEditXorValue;
    QPushButton *btnStart;
    QLabel *labelStatus;
    QProgressBar *progressBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1082, 558);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labelInput = new QLabel(centralwidget);
        labelInput->setObjectName("labelInput");

        horizontalLayout->addWidget(labelInput);

        lineEditInputPath = new QLineEdit(centralwidget);
        lineEditInputPath->setObjectName("lineEditInputPath");

        horizontalLayout->addWidget(lineEditInputPath);

        btnBrowseInput = new QPushButton(centralwidget);
        btnBrowseInput->setObjectName("btnBrowseInput");

        horizontalLayout->addWidget(btnBrowseInput);


        verticalLayout->addLayout(horizontalLayout);

        layoutMask = new QHBoxLayout();
        layoutMask->setObjectName("layoutMask");
        labelMask = new QLabel(centralwidget);
        labelMask->setObjectName("labelMask");

        layoutMask->addWidget(labelMask);

        lineEditMask = new QLineEdit(centralwidget);
        lineEditMask->setObjectName("lineEditMask");

        layoutMask->addWidget(lineEditMask);


        verticalLayout->addLayout(layoutMask);

        checkDeleteInput = new QCheckBox(centralwidget);
        checkDeleteInput->setObjectName("checkDeleteInput");

        verticalLayout->addWidget(checkDeleteInput);

        layoutSavePath = new QHBoxLayout();
        layoutSavePath->setObjectName("layoutSavePath");
        labelSavePath = new QLabel(centralwidget);
        labelSavePath->setObjectName("labelSavePath");

        layoutSavePath->addWidget(labelSavePath);

        lineEditSavePath = new QLineEdit(centralwidget);
        lineEditSavePath->setObjectName("lineEditSavePath");

        layoutSavePath->addWidget(lineEditSavePath);

        btnBrowseOutput = new QPushButton(centralwidget);
        btnBrowseOutput->setObjectName("btnBrowseOutput");

        layoutSavePath->addWidget(btnBrowseOutput);


        verticalLayout->addLayout(layoutSavePath);

        layoutNameConflict = new QHBoxLayout();
        layoutNameConflict->setObjectName("layoutNameConflict");
        labelNameConflict = new QLabel(centralwidget);
        labelNameConflict->setObjectName("labelNameConflict");

        layoutNameConflict->addWidget(labelNameConflict);

        comboNameConflict = new QComboBox(centralwidget);
        comboNameConflict->addItem(QString());
        comboNameConflict->addItem(QString());
        comboNameConflict->setObjectName("comboNameConflict");

        layoutNameConflict->addWidget(comboNameConflict);


        verticalLayout->addLayout(layoutNameConflict);

        layoutMode = new QHBoxLayout();
        layoutMode->setObjectName("layoutMode");
        labelMode = new QLabel(centralwidget);
        labelMode->setObjectName("labelMode");

        layoutMode->addWidget(labelMode);

        radioOnce = new QRadioButton(centralwidget);
        radioOnce->setObjectName("radioOnce");
        radioOnce->setCheckable(true);
        radioOnce->setChecked(true);

        layoutMode->addWidget(radioOnce);

        radioTimer = new QRadioButton(centralwidget);
        radioTimer->setObjectName("radioTimer");
        radioTimer->setChecked(false);

        layoutMode->addWidget(radioTimer);


        verticalLayout->addLayout(layoutMode);

        layoutInterval = new QHBoxLayout();
        layoutInterval->setObjectName("layoutInterval");
        labelInterval = new QLabel(centralwidget);
        labelInterval->setObjectName("labelInterval");

        layoutInterval->addWidget(labelInterval);

        spinInterval = new QSpinBox(centralwidget);
        spinInterval->setObjectName("spinInterval");
        spinInterval->setMinimum(1);
        spinInterval->setMaximum(3600);
        spinInterval->setValue(5);

        layoutInterval->addWidget(spinInterval);


        verticalLayout->addLayout(layoutInterval);

        layoutXorValue = new QHBoxLayout();
        layoutXorValue->setObjectName("layoutXorValue");
        labelXorValue = new QLabel(centralwidget);
        labelXorValue->setObjectName("labelXorValue");

        layoutXorValue->addWidget(labelXorValue);

        lineEditXorValue = new QLineEdit(centralwidget);
        lineEditXorValue->setObjectName("lineEditXorValue");
        lineEditXorValue->setMaxLength(16);

        layoutXorValue->addWidget(lineEditXorValue);


        verticalLayout->addLayout(layoutXorValue);

        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName("btnStart");

        verticalLayout->addWidget(btnStart);

        labelStatus = new QLabel(centralwidget);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setMaximumSize(QSize(1064, 51));

        verticalLayout->addWidget(labelStatus);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273\320\276\320\262\321\213\320\271 \320\274\320\276\320\264\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200 XOR", nullptr));
        labelInput->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\320\260\320\277\320\272\321\203:", nullptr));
        btnBrowseInput->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        labelMask->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\320\272\320\260 \320\262\321\205\320\276\320\264\320\275\321\213\321\205 \321\204\320\260\320\271\320\273\320\276\320\262:", nullptr));
        checkDeleteInput->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\321\217\321\202\321\214 \320\262\321\205\320\276\320\264\320\275\321\213\320\265 \321\204\320\260\320\271\320\273\321\213 \320\277\320\276\321\201\320\273\320\265 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270", nullptr));
        labelSavePath->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\320\277\320\272\320\260 \320\264\320\273\321\217 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217:", nullptr));
        btnBrowseOutput->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        labelNameConflict->setText(QCoreApplication::translate("MainWindow", "\320\225\321\201\320\273\320\270 \320\270\320\274\321\217 \321\203\320\266\320\265 \321\201\321\203\321\211\320\265\321\201\321\202\320\262\321\203\320\265\321\202:", nullptr));
        comboNameConflict->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        comboNameConflict->setItemText(1, QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\207\321\221\321\202\321\207\320\270\320\272", nullptr));

        labelMode->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 \321\200\320\260\320\261\320\276\321\202\321\213:", nullptr));
        radioOnce->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\276\320\262\321\213\320\271 \320\267\320\260\320\277\321\203\321\201\320\272", nullptr));
        radioTimer->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \321\202\320\260\320\271\320\274\320\265\321\200\321\203", nullptr));
        labelInterval->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 \320\276\320\277\321\200\320\276\321\201\320\260 (\321\201\320\265\320\272):", nullptr));
        labelXorValue->setText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 8 \320\261\320\260\320\271\321\202 (hex):", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201: \320\236\320\266\320\270\320\264\320\260\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
