/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *enter;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(503, 352);
        MainWindow->setStyleSheet(QString::fromUtf8("background:url(C:\\Users\\sx405\\OneDrive\\\345\233\276\347\211\207\\hlju.jpg);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        enter = new QPushButton(centralWidget);
        enter->setObjectName(QString::fromUtf8("enter"));
        enter->setGeometry(QRect(190, 200, 101, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(26);
        enter->setFont(font);
        enter->setStyleSheet(QString::fromUtf8("background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.494, stop:0.255682 rgba(255, 177, 177, 255), stop:0.738636 rgba(255, 191, 87, 255), stop:1 rgba(255, 255, 255, 0));\n"
"color:rgb(14, 2, 108);\n"
"border-style: hidden"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 371, 111));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(30);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color:rgb(0, 170, 255);"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        enter->setText(QApplication::translate("MainWindow", "\350\277\233\345\205\245", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\234\200\345\260\217\347\224\237\346\210\220\346\240\221\346\250\241\346\213\237\347\250\213\345\272\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
