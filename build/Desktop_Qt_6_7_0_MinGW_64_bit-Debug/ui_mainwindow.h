/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *displayPanel;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *actionClear;
    QPushButton *actionDel;
    QPushButton *actionDiv;
    QPushButton *switch1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *num7;
    QPushButton *num8;
    QPushButton *num9;
    QPushButton *actionMul;
    QPushButton *switch2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *num4;
    QPushButton *num5;
    QPushButton *num6;
    QPushButton *actionMinus;
    QPushButton *switch3;
    QHBoxLayout *horizontalLayout;
    QPushButton *num1;
    QPushButton *num2;
    QPushButton *num3;
    QPushButton *actionPlus;
    QPushButton *switch4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *num0;
    QPushButton *comma;
    QPushButton *switchPage;
    QPushButton *actionCalc;
    QButtonGroup *switchGroup;
    QButtonGroup *lockGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(447, 319);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(306, 319));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #f5f5f5;\n"
"color: rgb(0, 0, 0);\n"
""));
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"min-width: 65;\n"
"min-height: 40;\n"
"max-width: 65;\n"
"max-height: 40;\n"
"}"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        displayPanel = new QLabel(centralWidget);
        displayPanel->setObjectName("displayPanel");
        displayPanel->setMinimumSize(QSize(290, 40));
        displayPanel->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setKerning(true);
        displayPanel->setFont(font);
        displayPanel->setLayoutDirection(Qt::LeftToRight);
        displayPanel->setStyleSheet(QString::fromUtf8("border: 1 solid #b8b8b8;\n"
"background-color: #fff;"));
        displayPanel->setScaledContents(true);
        displayPanel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        displayPanel->setWordWrap(true);
        displayPanel->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(displayPanel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        actionClear = new QPushButton(centralWidget);
        actionClear->setObjectName("actionClear");
        actionClear->setStyleSheet(QString::fromUtf8("background-color: #cb1a21;\n"
"color: #ffffff;"));

        horizontalLayout_5->addWidget(actionClear);

        actionDel = new QPushButton(centralWidget);
        actionDel->setObjectName("actionDel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(actionDel->sizePolicy().hasHeightForWidth());
        actionDel->setSizePolicy(sizePolicy1);
        actionDel->setMinimumSize(QSize(150, 42));
        actionDel->setMaximumSize(QSize(150, 42));

        horizontalLayout_5->addWidget(actionDel);

        actionDiv = new QPushButton(centralWidget);
        lockGroup = new QButtonGroup(MainWindow);
        lockGroup->setObjectName("lockGroup");
        lockGroup->addButton(actionDiv);
        actionDiv->setObjectName("actionDiv");

        horizontalLayout_5->addWidget(actionDiv);

        switch1 = new QPushButton(centralWidget);
        switchGroup = new QButtonGroup(MainWindow);
        switchGroup->setObjectName("switchGroup");
        switchGroup->addButton(switch1);
        switch1->setObjectName("switch1");

        horizontalLayout_5->addWidget(switch1);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        num7 = new QPushButton(centralWidget);
        lockGroup->addButton(num7);
        num7->setObjectName("num7");

        horizontalLayout_3->addWidget(num7);

        num8 = new QPushButton(centralWidget);
        lockGroup->addButton(num8);
        num8->setObjectName("num8");
        sizePolicy.setHeightForWidth(num8->sizePolicy().hasHeightForWidth());
        num8->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(num8);

        num9 = new QPushButton(centralWidget);
        lockGroup->addButton(num9);
        num9->setObjectName("num9");

        horizontalLayout_3->addWidget(num9);

        actionMul = new QPushButton(centralWidget);
        lockGroup->addButton(actionMul);
        actionMul->setObjectName("actionMul");

        horizontalLayout_3->addWidget(actionMul);

        switch2 = new QPushButton(centralWidget);
        switchGroup->addButton(switch2);
        switch2->setObjectName("switch2");

        horizontalLayout_3->addWidget(switch2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        num4 = new QPushButton(centralWidget);
        lockGroup->addButton(num4);
        num4->setObjectName("num4");

        horizontalLayout_2->addWidget(num4);

        num5 = new QPushButton(centralWidget);
        lockGroup->addButton(num5);
        num5->setObjectName("num5");

        horizontalLayout_2->addWidget(num5);

        num6 = new QPushButton(centralWidget);
        lockGroup->addButton(num6);
        num6->setObjectName("num6");

        horizontalLayout_2->addWidget(num6);

        actionMinus = new QPushButton(centralWidget);
        lockGroup->addButton(actionMinus);
        actionMinus->setObjectName("actionMinus");

        horizontalLayout_2->addWidget(actionMinus);

        switch3 = new QPushButton(centralWidget);
        switchGroup->addButton(switch3);
        switch3->setObjectName("switch3");

        horizontalLayout_2->addWidget(switch3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        num1 = new QPushButton(centralWidget);
        lockGroup->addButton(num1);
        num1->setObjectName("num1");
        sizePolicy.setHeightForWidth(num1->sizePolicy().hasHeightForWidth());
        num1->setSizePolicy(sizePolicy);
        num1->setMinimumSize(QSize(67, 42));
        num1->setMaximumSize(QSize(67, 42));

        horizontalLayout->addWidget(num1);

        num2 = new QPushButton(centralWidget);
        lockGroup->addButton(num2);
        num2->setObjectName("num2");
        sizePolicy.setHeightForWidth(num2->sizePolicy().hasHeightForWidth());
        num2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(num2);

        num3 = new QPushButton(centralWidget);
        lockGroup->addButton(num3);
        num3->setObjectName("num3");
        sizePolicy.setHeightForWidth(num3->sizePolicy().hasHeightForWidth());
        num3->setSizePolicy(sizePolicy);
        num3->setMaximumSize(QSize(67, 42));

        horizontalLayout->addWidget(num3);

        actionPlus = new QPushButton(centralWidget);
        lockGroup->addButton(actionPlus);
        actionPlus->setObjectName("actionPlus");

        horizontalLayout->addWidget(actionPlus);

        switch4 = new QPushButton(centralWidget);
        switchGroup->addButton(switch4);
        switch4->setObjectName("switch4");

        horizontalLayout->addWidget(switch4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, -1, 0, -1);
        num0 = new QPushButton(centralWidget);
        lockGroup->addButton(num0);
        num0->setObjectName("num0");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(num0->sizePolicy().hasHeightForWidth());
        num0->setSizePolicy(sizePolicy2);
        num0->setMinimumSize(QSize(150, 42));
        num0->setMaximumSize(QSize(150, 42));

        horizontalLayout_4->addWidget(num0);

        comma = new QPushButton(centralWidget);
        lockGroup->addButton(comma);
        comma->setObjectName("comma");

        horizontalLayout_4->addWidget(comma);

        switchPage = new QPushButton(centralWidget);
        switchPage->setObjectName("switchPage");
        switchPage->setAutoDefault(false);
        switchPage->setFlat(false);

        horizontalLayout_4->addWidget(switchPage);

        actionCalc = new QPushButton(centralWidget);
        actionCalc->setObjectName("actionCalc");
        actionCalc->setMouseTracking(false);
        actionCalc->setStyleSheet(QString::fromUtf8("background-color: #3490cd;\n"
"color: #ffffff;"));

        horizontalLayout_4->addWidget(actionCalc);


        verticalLayout->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        switchPage->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        displayPanel->setText(QString());
        actionClear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        actionDel->setText(QCoreApplication::translate("MainWindow", "Del", nullptr));
        actionDiv->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        switch1->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        num7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        num8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        num9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        actionMul->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        switch2->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        num4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        num5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        num6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        actionMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        switch3->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        num1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        num2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        num3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        actionPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        switch4->setText(QCoreApplication::translate("MainWindow", "pow", nullptr));
        num0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        comma->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        switchPage->setText(QCoreApplication::translate("MainWindow", "Page", nullptr));
        actionCalc->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
