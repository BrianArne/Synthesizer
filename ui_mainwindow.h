/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSlider *verticalSlider_8;
    QSlider *verticalSlider_7;
    QSlider *verticalSlider_14;
    QSlider *verticalSlider_13;
    QSlider *verticalSlider_12;
    QSlider *verticalSlider_11;
    QSlider *verticalSlider_5;
    QSlider *verticalSlider_4;
    QSlider *verticalSlider_6;
    QSlider *verticalSlider_15;
    QSlider *verticalSlider_3;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider;
    QSlider *verticalSlider_9;
    QSlider *verticalSlider_16;
    QSlider *verticalSlider_10;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_15;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuSynthesizer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(823, 542);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 81, 20));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 20, 61, 21));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(570, 380, 114, 32));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 380, 114, 32));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 60, 771, 261));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSlider_8 = new QSlider(layoutWidget);
        verticalSlider_8->setObjectName(QStringLiteral("verticalSlider_8"));
        verticalSlider_8->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_8, 0, 7, 1, 1);

        verticalSlider_7 = new QSlider(layoutWidget);
        verticalSlider_7->setObjectName(QStringLiteral("verticalSlider_7"));
        verticalSlider_7->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_7, 0, 6, 1, 1);

        verticalSlider_14 = new QSlider(layoutWidget);
        verticalSlider_14->setObjectName(QStringLiteral("verticalSlider_14"));
        verticalSlider_14->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_14, 0, 13, 1, 1);

        verticalSlider_13 = new QSlider(layoutWidget);
        verticalSlider_13->setObjectName(QStringLiteral("verticalSlider_13"));
        verticalSlider_13->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_13, 0, 12, 1, 1);

        verticalSlider_12 = new QSlider(layoutWidget);
        verticalSlider_12->setObjectName(QStringLiteral("verticalSlider_12"));
        verticalSlider_12->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_12, 0, 11, 1, 1);

        verticalSlider_11 = new QSlider(layoutWidget);
        verticalSlider_11->setObjectName(QStringLiteral("verticalSlider_11"));
        verticalSlider_11->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_11, 0, 10, 1, 1);

        verticalSlider_5 = new QSlider(layoutWidget);
        verticalSlider_5->setObjectName(QStringLiteral("verticalSlider_5"));
        verticalSlider_5->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_5, 0, 4, 1, 1);

        verticalSlider_4 = new QSlider(layoutWidget);
        verticalSlider_4->setObjectName(QStringLiteral("verticalSlider_4"));
        verticalSlider_4->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_4, 0, 3, 1, 1);

        verticalSlider_6 = new QSlider(layoutWidget);
        verticalSlider_6->setObjectName(QStringLiteral("verticalSlider_6"));
        verticalSlider_6->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_6, 0, 5, 1, 1);

        verticalSlider_15 = new QSlider(layoutWidget);
        verticalSlider_15->setObjectName(QStringLiteral("verticalSlider_15"));
        verticalSlider_15->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_15, 0, 14, 1, 1);

        verticalSlider_3 = new QSlider(layoutWidget);
        verticalSlider_3->setObjectName(QStringLiteral("verticalSlider_3"));
        verticalSlider_3->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_3, 0, 2, 1, 1);

        verticalSlider_2 = new QSlider(layoutWidget);
        verticalSlider_2->setObjectName(QStringLiteral("verticalSlider_2"));
        verticalSlider_2->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_2, 0, 1, 1, 1);

        verticalSlider = new QSlider(layoutWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider, 0, 0, 1, 1);

        verticalSlider_9 = new QSlider(layoutWidget);
        verticalSlider_9->setObjectName(QStringLiteral("verticalSlider_9"));
        verticalSlider_9->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_9, 0, 8, 1, 1);

        verticalSlider_16 = new QSlider(layoutWidget);
        verticalSlider_16->setObjectName(QStringLiteral("verticalSlider_16"));
        verticalSlider_16->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_16, 0, 15, 1, 1);

        verticalSlider_10 = new QSlider(layoutWidget);
        verticalSlider_10->setObjectName(QStringLiteral("verticalSlider_10"));
        verticalSlider_10->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_10, 0, 9, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(58, 330, 31, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 330, 59, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 330, 59, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(208, 330, 10, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(255, 330, 10, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(300, 330, 59, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(345, 330, 20, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(395, 330, 10, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(442, 330, 10, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(488, 330, 10, 16));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(530, 330, 59, 16));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(584, 330, 10, 16));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(627, 330, 16, 16));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(720, 330, 16, 16));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(771, 330, 10, 16));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(675, 330, 16, 16));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 823, 22));
        menuSynthesizer = new QMenu(menuBar);
        menuSynthesizer->setObjectName(QStringLiteral("menuSynthesizer"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuSynthesizer->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Partial Parser", nullptr));
        label->setText(QApplication::translate("MainWindow", "Fundmental: ", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "440", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Play Jpeg", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Play Partials", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Root", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "5", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "3", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "5", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "b7", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "9", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "3", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "#4", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "5", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "13", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "7", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "b7", nullptr));
        menuSynthesizer->setTitle(QApplication::translate("MainWindow", "Synthesizer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
