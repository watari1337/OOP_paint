/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "drawwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    DrawWidget *draw;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *PBColor;
    QLabel *LColor;
    QPushButton *PBclear;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QComboBox *CBShape;
    QPushButton *PBPlugin;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *CBMovement;
    QComboBox *CBSaveFormat;
    QPushButton *PBSave;
    QPushButton *PBLoad;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        draw = new DrawWidget(centralwidget);
        draw->setObjectName("draw");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(draw->sizePolicy().hasHeightForWidth());
        draw->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(draw);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        PBColor = new QPushButton(widget_2);
        PBColor->setObjectName("PBColor");
        PBColor->setMinimumSize(QSize(200, 30));
        PBColor->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(PBColor);

        LColor = new QLabel(widget_2);
        LColor->setObjectName("LColor");
        LColor->setMinimumSize(QSize(40, 40));
        LColor->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(LColor);


        verticalLayout_2->addWidget(widget_2);

        PBclear = new QPushButton(widget_3);
        PBclear->setObjectName("PBclear");
        PBclear->setMinimumSize(QSize(0, 30));
        PBclear->setMaximumSize(QSize(240, 16777215));

        verticalLayout_2->addWidget(PBclear);


        horizontalLayout_3->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName("widget_4");
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        CBShape = new QComboBox(widget_4);
        CBShape->setObjectName("CBShape");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CBShape->sizePolicy().hasHeightForWidth());
        CBShape->setSizePolicy(sizePolicy2);
        CBShape->setMinimumSize(QSize(0, 30));
        CBShape->setMaximumSize(QSize(240, 16777215));

        verticalLayout_3->addWidget(CBShape);

        PBPlugin = new QPushButton(widget_4);
        PBPlugin->setObjectName("PBPlugin");
        sizePolicy2.setHeightForWidth(PBPlugin->sizePolicy().hasHeightForWidth());
        PBPlugin->setSizePolicy(sizePolicy2);
        PBPlugin->setMinimumSize(QSize(0, 30));
        PBPlugin->setMaximumSize(QSize(240, 16777215));

        verticalLayout_3->addWidget(PBPlugin);


        horizontalLayout_3->addWidget(widget_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName("widget_5");
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        CBMovement = new QCheckBox(widget_5);
        CBMovement->setObjectName("CBMovement");
        CBMovement->setChecked(true);

        horizontalLayout_2->addWidget(CBMovement);

        CBSaveFormat = new QComboBox(widget_5);
        CBSaveFormat->addItem(QString());
        CBSaveFormat->addItem(QString());
        CBSaveFormat->setObjectName("CBSaveFormat");

        horizontalLayout_2->addWidget(CBSaveFormat);

        PBSave = new QPushButton(widget_5);
        PBSave->setObjectName("PBSave");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        PBSave->setIcon(icon);

        horizontalLayout_2->addWidget(PBSave);

        PBLoad = new QPushButton(widget_5);
        PBLoad->setObjectName("PBLoad");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        PBLoad->setIcon(icon1);

        horizontalLayout_2->addWidget(PBLoad);


        verticalLayout->addWidget(widget_5);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        PBColor->setText(QCoreApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202", nullptr));
        LColor->setText(QString());
        PBclear->setText(QCoreApplication::translate("MainWindow", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        PBPlugin->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\277\320\273\320\260\320\263\320\270\320\275\321\213", nullptr));
        CBMovement->setText(QCoreApplication::translate("MainWindow", "moving", nullptr));
        CBSaveFormat->setItemText(0, QCoreApplication::translate("MainWindow", "binary save format", nullptr));
        CBSaveFormat->setItemText(1, QCoreApplication::translate("MainWindow", "text save format", nullptr));

        PBSave->setText(QCoreApplication::translate("MainWindow", " \321\201\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        PBLoad->setText(QCoreApplication::translate("MainWindow", " \320\267\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
