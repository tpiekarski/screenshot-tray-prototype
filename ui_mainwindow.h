/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *screenshotBox;
    QGraphicsView *screenshotView;
    QWidget *layoutWidget;
    QHBoxLayout *buttonLayout;
    QPushButton *shootButton;
    QPushButton *saveButton;
    QPushButton *hideButton;
    QPushButton *quitButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(919, 654);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        screenshotBox = new QGroupBox(centralWidget);
        screenshotBox->setObjectName(QStringLiteral("screenshotBox"));
        screenshotBox->setGeometry(QRect(10, 10, 900, 600));
        screenshotView = new QGraphicsView(screenshotBox);
        screenshotView->setObjectName(QStringLiteral("screenshotView"));
        screenshotView->setGeometry(QRect(10, 30, 881, 561));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(410, 620, 501, 27));
        buttonLayout = new QHBoxLayout(layoutWidget);
        buttonLayout->setSpacing(6);
        buttonLayout->setContentsMargins(11, 11, 11, 11);
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        shootButton = new QPushButton(layoutWidget);
        shootButton->setObjectName(QStringLiteral("shootButton"));

        buttonLayout->addWidget(shootButton);

        saveButton = new QPushButton(layoutWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        buttonLayout->addWidget(saveButton);

        hideButton = new QPushButton(layoutWidget);
        hideButton->setObjectName(QStringLiteral("hideButton"));

        buttonLayout->addWidget(hideButton);

        quitButton = new QPushButton(layoutWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        buttonLayout->addWidget(quitButton);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "System-trayed Application", nullptr));
        screenshotBox->setTitle(QApplication::translate("MainWindow", "Screenshot", nullptr));
        shootButton->setText(QApplication::translate("MainWindow", "&Shoot", nullptr));
        saveButton->setText(QApplication::translate("MainWindow", "S&ave", nullptr));
        hideButton->setText(QApplication::translate("MainWindow", "&Hide", nullptr));
        quitButton->setText(QApplication::translate("MainWindow", "&Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
