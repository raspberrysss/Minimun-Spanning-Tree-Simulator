/********************************************************************************
** Form generated from reading UI file 'mst.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MST_H
#define UI_MST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MST
{
public:
    QPushButton *clean;
    QPushButton *addvex;
    QPushButton *delevex;
    QPushButton *addadj;
    QPushButton *deleadj;
    QPushButton *showweight;
    QPushButton *changew;
    QPushButton *prim;
    QPushButton *k;
    QLabel *vexnum;
    QLabel *edgenum;
    QListWidget *listWidget;
    QLabel *tishiinformation;
    QPushButton *clean_2;
    QLabel *qidian;
    QPushButton *changein;

    void setupUi(QWidget *MST)
    {
        if (MST->objectName().isEmpty())
            MST->setObjectName(QString::fromUtf8("MST"));
        MST->resize(937, 495);
        clean = new QPushButton(MST);
        clean->setObjectName(QString::fromUtf8("clean"));
        clean->setGeometry(QRect(30, 50, 91, 31));
        addvex = new QPushButton(MST);
        addvex->setObjectName(QString::fromUtf8("addvex"));
        addvex->setGeometry(QRect(30, 100, 91, 31));
        delevex = new QPushButton(MST);
        delevex->setObjectName(QString::fromUtf8("delevex"));
        delevex->setGeometry(QRect(30, 140, 91, 31));
        addadj = new QPushButton(MST);
        addadj->setObjectName(QString::fromUtf8("addadj"));
        addadj->setGeometry(QRect(30, 220, 91, 31));
        deleadj = new QPushButton(MST);
        deleadj->setObjectName(QString::fromUtf8("deleadj"));
        deleadj->setGeometry(QRect(30, 260, 91, 31));
        showweight = new QPushButton(MST);
        showweight->setObjectName(QString::fromUtf8("showweight"));
        showweight->setGeometry(QRect(30, 310, 91, 31));
        changew = new QPushButton(MST);
        changew->setObjectName(QString::fromUtf8("changew"));
        changew->setGeometry(QRect(30, 350, 91, 31));
        prim = new QPushButton(MST);
        prim->setObjectName(QString::fromUtf8("prim"));
        prim->setGeometry(QRect(30, 400, 91, 31));
        k = new QPushButton(MST);
        k->setObjectName(QString::fromUtf8("k"));
        k->setGeometry(QRect(30, 440, 101, 31));
        vexnum = new QLabel(MST);
        vexnum->setObjectName(QString::fromUtf8("vexnum"));
        vexnum->setGeometry(QRect(160, 445, 71, 21));
        QFont font;
        font.setPointSize(12);
        vexnum->setFont(font);
        edgenum = new QLabel(MST);
        edgenum->setObjectName(QString::fromUtf8("edgenum"));
        edgenum->setGeometry(QRect(160, 470, 71, 21));
        edgenum->setFont(font);
        listWidget = new QListWidget(MST);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(620, 50, 311, 431));
        QFont font1;
        font1.setPointSize(15);
        listWidget->setFont(font1);
        tishiinformation = new QLabel(MST);
        tishiinformation->setObjectName(QString::fromUtf8("tishiinformation"));
        tishiinformation->setGeometry(QRect(160, 10, 421, 31));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        tishiinformation->setFont(font2);
        clean_2 = new QPushButton(MST);
        clean_2->setObjectName(QString::fromUtf8("clean_2"));
        clean_2->setGeometry(QRect(30, 10, 91, 31));
        qidian = new QLabel(MST);
        qidian->setObjectName(QString::fromUtf8("qidian"));
        qidian->setGeometry(QRect(620, 10, 91, 41));
        qidian->setFont(font2);
        changein = new QPushButton(MST);
        changein->setObjectName(QString::fromUtf8("changein"));
        changein->setGeometry(QRect(30, 180, 91, 31));

        retranslateUi(MST);

        QMetaObject::connectSlotsByName(MST);
    } // setupUi

    void retranslateUi(QWidget *MST)
    {
        MST->setWindowTitle(QApplication::translate("MST", "Form", nullptr));
        clean->setText(QApplication::translate("MST", "\346\270\205\351\231\244\345\233\276", nullptr));
        addvex->setText(QApplication::translate("MST", "\346\267\273\345\212\240\347\202\271", nullptr));
        delevex->setText(QApplication::translate("MST", "\345\210\240\351\231\244\347\202\271", nullptr));
        addadj->setText(QApplication::translate("MST", "\346\267\273\345\212\240\350\276\271", nullptr));
        deleadj->setText(QApplication::translate("MST", "\345\210\240\351\231\244\350\276\271", nullptr));
        showweight->setText(QApplication::translate("MST", "\346\230\276\347\244\272\346\235\203\345\200\274", nullptr));
        changew->setText(QApplication::translate("MST", "\344\277\256\346\224\271\346\235\203\345\200\274", nullptr));
        prim->setText(QApplication::translate("MST", "\346\231\256\351\207\214\345\247\206\347\256\227\346\263\225", nullptr));
        k->setText(QApplication::translate("MST", "\345\205\213\351\262\201\346\226\257\345\215\241\345\260\224\347\256\227\346\263\225", nullptr));
        vexnum->setText(QApplication::translate("MST", "\347\202\271\346\225\260\357\274\232", nullptr));
        edgenum->setText(QApplication::translate("MST", "\350\276\271\346\225\260\357\274\232", nullptr));
        tishiinformation->setText(QString());
        clean_2->setText(QApplication::translate("MST", "\346\270\205\351\231\244\344\277\241\346\201\257\346\240\217", nullptr));
        qidian->setText(QString());
        changein->setText(QApplication::translate("MST", "\346\224\271\345\217\230\347\202\271\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MST: public Ui_MST {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MST_H
