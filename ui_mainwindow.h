/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *titleLabel;
    QLabel *subtitleLabel;
    QLabel *classNameLabel;
    QLabel *fileLoaderLabel;
    QLineEdit *pathToFileLine;
    QPushButton *loadFileButton;
    QLabel *errorLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(522, 584);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(220, 20, 91, 31));
        titleLabel->setStyleSheet(QStringLiteral("font: 75 20pt \"MS Shell Dlg 2\"; color: rgb(0, 0, 255);"));
        subtitleLabel = new QLabel(centralWidget);
        subtitleLabel->setObjectName(QStringLiteral("subtitleLabel"));
        subtitleLabel->setGeometry(QRect(10, 80, 271, 41));
        subtitleLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        classNameLabel = new QLabel(centralWidget);
        classNameLabel->setObjectName(QStringLiteral("classNameLabel"));
        classNameLabel->setGeometry(QRect(200, 130, 311, 41));
        classNameLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        fileLoaderLabel = new QLabel(centralWidget);
        fileLoaderLabel->setObjectName(QStringLiteral("fileLoaderLabel"));
        fileLoaderLabel->setGeometry(QRect(70, 280, 381, 41));
        fileLoaderLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        pathToFileLine = new QLineEdit(centralWidget);
        pathToFileLine->setObjectName(QStringLiteral("pathToFileLine"));
        pathToFileLine->setGeometry(QRect(70, 330, 371, 41));
        pathToFileLine->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        loadFileButton = new QPushButton(centralWidget);
        loadFileButton->setObjectName(QStringLiteral("loadFileButton"));
        loadFileButton->setGeometry(QRect(180, 390, 161, 31));
        loadFileButton->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        errorLabel = new QLabel(centralWidget);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setGeometry(QRect(130, 430, 271, 41));
        errorLabel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0); font: 14pt \"MS Shell Dlg 2\";"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 522, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        titleLabel->setText(QApplication::translate("MainWindow", "Azariah", nullptr));
        subtitleLabel->setText(QApplication::translate("MainWindow", "Projekt zaliczeniowy na zaj\304\231cia:", nullptr));
        classNameLabel->setText(QApplication::translate("MainWindow", "\"Laboratorium Grafiki i Multimedi\303\263w\"", nullptr));
        fileLoaderLabel->setText(QApplication::translate("MainWindow", "Podaj pe\305\202n\304\205 \305\233cie\305\274k\304\231 do pliku binarnego STL:", nullptr));
        pathToFileLine->setText(QApplication::translate("MainWindow", "D:\\GitHub\\azariah\\pikachu.STL", nullptr));
        loadFileButton->setText(QApplication::translate("MainWindow", "Za\305\202aduj plik", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
