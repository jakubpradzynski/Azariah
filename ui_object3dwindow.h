/********************************************************************************
** Form generated from reading UI file 'object3dwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECT3DWINDOW_H
#define UI_OBJECT3DWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "object3dcanvas.h"

QT_BEGIN_NAMESPACE

class Ui_Object3DWindow
{
public:
    QSlider *secondLightYSlider;
    QSlider *secondLightZSlider;
    QLabel *rotationLabel;
    QCheckBox *paintedCheckBox;
    QSlider *rotationZSlider;
    QLabel *firstLightYLabel;
    QSlider *translationXSlider;
    QSpinBox *gValueSpinBox;
    QSlider *perspectiveSlider;
    QLabel *scalingZLabel;
    QLabel *firstLightXLabel;
    QSlider *firstLightYSlider;
    QLabel *translationXLabel;
    QSlider *rotationYSlider;
    QLabel *bValueLabel;
    QSlider *firstLightXSlider;
    QSlider *secondLightXSlider;
    QCheckBox *secondLightCheckBox;
    Object3DCanvas *object3DCanvas;
    QLabel *scalingLabel;
    QLabel *firstLightLabel;
    QLabel *rValueLabel;
    QLabel *objectColorLabel;
    QCheckBox *smoothing3DObjectCheckBox;
    QSlider *scalingZSlider;
    QLabel *perspectiveValueLabel;
    QSlider *translationZSlider;
    QLabel *rotationYLabel;
    QLabel *perspectiveLabel;
    QLabel *translationYLabel;
    QLabel *scalingXLabel;
    QSlider *scalingXSlider;
    QLabel *firstLightZLabel;
    QCheckBox *sceletonCheckBox;
    QLabel *gValueLabel;
    QSlider *translationYSlider;
    QSlider *rotationXSlider;
    QLabel *scalingYLabel;
    QLabel *secondLightZLabel;
    QLabel *rotationXLabel;
    QLabel *secondLightLabel;
    QCheckBox *hideBackSurfaceCheckBox;
    QSpinBox *bValueSpinBox;
    QLabel *secondLightYLabel;
    QSpinBox *rValueSpinBox;
    QLabel *translationLabel;
    QSlider *scalingYSlider;
    QLabel *rotationZLabel;
    QSlider *firstLightZSlider;
    QLabel *secondLightXLabel;
    QCheckBox *firstLightCheckBox;
    QLabel *translationZLabel;

    void setupUi(QWidget *Object3DWindow)
    {
        if (Object3DWindow->objectName().isEmpty())
            Object3DWindow->setObjectName(QStringLiteral("Object3DWindow"));
        Object3DWindow->resize(1900, 900);
        secondLightYSlider = new QSlider(Object3DWindow);
        secondLightYSlider->setObjectName(QStringLiteral("secondLightYSlider"));
        secondLightYSlider->setGeometry(QRect(1540, 280, 291, 22));
        secondLightYSlider->setMinimum(-880);
        secondLightYSlider->setMaximum(1760);
        secondLightYSlider->setValue(0);
        secondLightYSlider->setOrientation(Qt::Horizontal);
        secondLightZSlider = new QSlider(Object3DWindow);
        secondLightZSlider->setObjectName(QStringLiteral("secondLightZSlider"));
        secondLightZSlider->setGeometry(QRect(1540, 320, 291, 22));
        secondLightZSlider->setMinimum(-500);
        secondLightZSlider->setMaximum(1000);
        secondLightZSlider->setValue(0);
        secondLightZSlider->setOrientation(Qt::Horizontal);
        rotationLabel = new QLabel(Object3DWindow);
        rotationLabel->setObjectName(QStringLiteral("rotationLabel"));
        rotationLabel->setGeometry(QRect(1150, 370, 141, 31));
        rotationLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        paintedCheckBox = new QCheckBox(Object3DWindow);
        paintedCheckBox->setObjectName(QStringLiteral("paintedCheckBox"));
        paintedCheckBox->setGeometry(QRect(1260, 770, 131, 41));
        paintedCheckBox->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        paintedCheckBox->setChecked(false);
        rotationZSlider = new QSlider(Object3DWindow);
        rotationZSlider->setObjectName(QStringLiteral("rotationZSlider"));
        rotationZSlider->setGeometry(QRect(1150, 500, 291, 22));
        rotationZSlider->setMinimum(-360);
        rotationZSlider->setMaximum(360);
        rotationZSlider->setOrientation(Qt::Horizontal);
        firstLightYLabel = new QLabel(Object3DWindow);
        firstLightYLabel->setObjectName(QStringLiteral("firstLightYLabel"));
        firstLightYLabel->setGeometry(QRect(1840, 90, 51, 31));
        firstLightYLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        translationXSlider = new QSlider(Object3DWindow);
        translationXSlider->setObjectName(QStringLiteral("translationXSlider"));
        translationXSlider->setGeometry(QRect(1150, 60, 291, 22));
        translationXSlider->setMinimum(-200);
        translationXSlider->setMaximum(200);
        translationXSlider->setValue(0);
        translationXSlider->setOrientation(Qt::Horizontal);
        gValueSpinBox = new QSpinBox(Object3DWindow);
        gValueSpinBox->setObjectName(QStringLiteral("gValueSpinBox"));
        gValueSpinBox->setGeometry(QRect(1210, 710, 42, 22));
        gValueSpinBox->setMaximum(255);
        gValueSpinBox->setValue(255);
        perspectiveSlider = new QSlider(Object3DWindow);
        perspectiveSlider->setObjectName(QStringLiteral("perspectiveSlider"));
        perspectiveSlider->setGeometry(QRect(1150, 590, 291, 22));
        perspectiveSlider->setMinimum(0);
        perspectiveSlider->setMaximum(1000);
        perspectiveSlider->setSingleStep(10);
        perspectiveSlider->setPageStep(20);
        perspectiveSlider->setValue(500);
        perspectiveSlider->setOrientation(Qt::Horizontal);
        scalingZLabel = new QLabel(Object3DWindow);
        scalingZLabel->setObjectName(QStringLiteral("scalingZLabel"));
        scalingZLabel->setGeometry(QRect(1450, 310, 51, 31));
        scalingZLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        firstLightXLabel = new QLabel(Object3DWindow);
        firstLightXLabel->setObjectName(QStringLiteral("firstLightXLabel"));
        firstLightXLabel->setGeometry(QRect(1840, 50, 51, 31));
        firstLightXLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        firstLightYSlider = new QSlider(Object3DWindow);
        firstLightYSlider->setObjectName(QStringLiteral("firstLightYSlider"));
        firstLightYSlider->setGeometry(QRect(1540, 100, 291, 22));
        firstLightYSlider->setMinimum(-880);
        firstLightYSlider->setMaximum(1760);
        firstLightYSlider->setValue(0);
        firstLightYSlider->setOrientation(Qt::Horizontal);
        translationXLabel = new QLabel(Object3DWindow);
        translationXLabel->setObjectName(QStringLiteral("translationXLabel"));
        translationXLabel->setGeometry(QRect(1450, 50, 51, 31));
        translationXLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        rotationYSlider = new QSlider(Object3DWindow);
        rotationYSlider->setObjectName(QStringLiteral("rotationYSlider"));
        rotationYSlider->setGeometry(QRect(1150, 460, 291, 22));
        rotationYSlider->setMinimum(-360);
        rotationYSlider->setMaximum(360);
        rotationYSlider->setOrientation(Qt::Horizontal);
        bValueLabel = new QLabel(Object3DWindow);
        bValueLabel->setObjectName(QStringLiteral("bValueLabel"));
        bValueLabel->setGeometry(QRect(1280, 680, 21, 31));
        bValueLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        firstLightXSlider = new QSlider(Object3DWindow);
        firstLightXSlider->setObjectName(QStringLiteral("firstLightXSlider"));
        firstLightXSlider->setGeometry(QRect(1540, 60, 291, 22));
        firstLightXSlider->setMinimum(-1100);
        firstLightXSlider->setMaximum(2200);
        firstLightXSlider->setValue(0);
        firstLightXSlider->setOrientation(Qt::Horizontal);
        secondLightXSlider = new QSlider(Object3DWindow);
        secondLightXSlider->setObjectName(QStringLiteral("secondLightXSlider"));
        secondLightXSlider->setGeometry(QRect(1540, 240, 291, 22));
        secondLightXSlider->setMinimum(-1100);
        secondLightXSlider->setMaximum(2200);
        secondLightXSlider->setValue(0);
        secondLightXSlider->setOrientation(Qt::Horizontal);
        secondLightCheckBox = new QCheckBox(Object3DWindow);
        secondLightCheckBox->setObjectName(QStringLiteral("secondLightCheckBox"));
        secondLightCheckBox->setGeometry(QRect(1710, 190, 111, 41));
        secondLightCheckBox->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        secondLightCheckBox->setChecked(false);
        object3DCanvas = new Object3DCanvas(Object3DWindow);
        object3DCanvas->setObjectName(QStringLiteral("object3DCanvas"));
        object3DCanvas->setGeometry(QRect(10, 10, 1100, 880));
        scalingLabel = new QLabel(Object3DWindow);
        scalingLabel->setObjectName(QStringLiteral("scalingLabel"));
        scalingLabel->setGeometry(QRect(1150, 190, 171, 31));
        scalingLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        firstLightLabel = new QLabel(Object3DWindow);
        firstLightLabel->setObjectName(QStringLiteral("firstLightLabel"));
        firstLightLabel->setGeometry(QRect(1540, 10, 131, 31));
        firstLightLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        rValueLabel = new QLabel(Object3DWindow);
        rValueLabel->setObjectName(QStringLiteral("rValueLabel"));
        rValueLabel->setGeometry(QRect(1160, 680, 21, 31));
        rValueLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        objectColorLabel = new QLabel(Object3DWindow);
        objectColorLabel->setObjectName(QStringLiteral("objectColorLabel"));
        objectColorLabel->setGeometry(QRect(1150, 640, 121, 31));
        objectColorLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        smoothing3DObjectCheckBox = new QCheckBox(Object3DWindow);
        smoothing3DObjectCheckBox->setObjectName(QStringLiteral("smoothing3DObjectCheckBox"));
        smoothing3DObjectCheckBox->setGeometry(QRect(1540, 370, 291, 41));
        smoothing3DObjectCheckBox->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        smoothing3DObjectCheckBox->setChecked(false);
        scalingZSlider = new QSlider(Object3DWindow);
        scalingZSlider->setObjectName(QStringLiteral("scalingZSlider"));
        scalingZSlider->setGeometry(QRect(1150, 320, 291, 22));
        scalingZSlider->setMinimum(0);
        scalingZSlider->setMaximum(10);
        scalingZSlider->setValue(1);
        scalingZSlider->setSliderPosition(1);
        scalingZSlider->setOrientation(Qt::Horizontal);
        perspectiveValueLabel = new QLabel(Object3DWindow);
        perspectiveValueLabel->setObjectName(QStringLiteral("perspectiveValueLabel"));
        perspectiveValueLabel->setGeometry(QRect(1450, 580, 51, 31));
        perspectiveValueLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        translationZSlider = new QSlider(Object3DWindow);
        translationZSlider->setObjectName(QStringLiteral("translationZSlider"));
        translationZSlider->setGeometry(QRect(1150, 140, 291, 22));
        translationZSlider->setMinimum(0);
        translationZSlider->setMaximum(200);
        translationZSlider->setValue(100);
        translationZSlider->setOrientation(Qt::Horizontal);
        rotationYLabel = new QLabel(Object3DWindow);
        rotationYLabel->setObjectName(QStringLiteral("rotationYLabel"));
        rotationYLabel->setGeometry(QRect(1450, 450, 51, 31));
        rotationYLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        perspectiveLabel = new QLabel(Object3DWindow);
        perspectiveLabel->setObjectName(QStringLiteral("perspectiveLabel"));
        perspectiveLabel->setGeometry(QRect(1150, 540, 131, 31));
        perspectiveLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        translationYLabel = new QLabel(Object3DWindow);
        translationYLabel->setObjectName(QStringLiteral("translationYLabel"));
        translationYLabel->setGeometry(QRect(1450, 90, 51, 31));
        translationYLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        scalingXLabel = new QLabel(Object3DWindow);
        scalingXLabel->setObjectName(QStringLiteral("scalingXLabel"));
        scalingXLabel->setGeometry(QRect(1450, 230, 51, 31));
        scalingXLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        scalingXSlider = new QSlider(Object3DWindow);
        scalingXSlider->setObjectName(QStringLiteral("scalingXSlider"));
        scalingXSlider->setGeometry(QRect(1150, 240, 291, 22));
        scalingXSlider->setMinimum(0);
        scalingXSlider->setMaximum(10);
        scalingXSlider->setValue(1);
        scalingXSlider->setOrientation(Qt::Horizontal);
        firstLightZLabel = new QLabel(Object3DWindow);
        firstLightZLabel->setObjectName(QStringLiteral("firstLightZLabel"));
        firstLightZLabel->setGeometry(QRect(1840, 130, 51, 31));
        firstLightZLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        sceletonCheckBox = new QCheckBox(Object3DWindow);
        sceletonCheckBox->setObjectName(QStringLiteral("sceletonCheckBox"));
        sceletonCheckBox->setGeometry(QRect(1160, 770, 111, 41));
        sceletonCheckBox->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        sceletonCheckBox->setChecked(true);
        gValueLabel = new QLabel(Object3DWindow);
        gValueLabel->setObjectName(QStringLiteral("gValueLabel"));
        gValueLabel->setGeometry(QRect(1220, 680, 21, 31));
        gValueLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        translationYSlider = new QSlider(Object3DWindow);
        translationYSlider->setObjectName(QStringLiteral("translationYSlider"));
        translationYSlider->setGeometry(QRect(1150, 100, 291, 22));
        translationYSlider->setMinimum(-200);
        translationYSlider->setMaximum(200);
        translationYSlider->setValue(0);
        translationYSlider->setOrientation(Qt::Horizontal);
        rotationXSlider = new QSlider(Object3DWindow);
        rotationXSlider->setObjectName(QStringLiteral("rotationXSlider"));
        rotationXSlider->setGeometry(QRect(1150, 420, 291, 22));
        rotationXSlider->setMinimum(-360);
        rotationXSlider->setMaximum(360);
        rotationXSlider->setOrientation(Qt::Horizontal);
        scalingYLabel = new QLabel(Object3DWindow);
        scalingYLabel->setObjectName(QStringLiteral("scalingYLabel"));
        scalingYLabel->setGeometry(QRect(1450, 270, 51, 31));
        scalingYLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        secondLightZLabel = new QLabel(Object3DWindow);
        secondLightZLabel->setObjectName(QStringLiteral("secondLightZLabel"));
        secondLightZLabel->setGeometry(QRect(1840, 310, 51, 31));
        secondLightZLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        rotationXLabel = new QLabel(Object3DWindow);
        rotationXLabel->setObjectName(QStringLiteral("rotationXLabel"));
        rotationXLabel->setGeometry(QRect(1450, 410, 51, 31));
        rotationXLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        secondLightLabel = new QLabel(Object3DWindow);
        secondLightLabel->setObjectName(QStringLiteral("secondLightLabel"));
        secondLightLabel->setGeometry(QRect(1540, 190, 131, 31));
        secondLightLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        hideBackSurfaceCheckBox = new QCheckBox(Object3DWindow);
        hideBackSurfaceCheckBox->setObjectName(QStringLiteral("hideBackSurfaceCheckBox"));
        hideBackSurfaceCheckBox->setGeometry(QRect(1160, 810, 271, 61));
        hideBackSurfaceCheckBox->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        hideBackSurfaceCheckBox->setChecked(false);
        bValueSpinBox = new QSpinBox(Object3DWindow);
        bValueSpinBox->setObjectName(QStringLiteral("bValueSpinBox"));
        bValueSpinBox->setGeometry(QRect(1270, 710, 42, 22));
        bValueSpinBox->setMaximum(255);
        secondLightYLabel = new QLabel(Object3DWindow);
        secondLightYLabel->setObjectName(QStringLiteral("secondLightYLabel"));
        secondLightYLabel->setGeometry(QRect(1840, 270, 51, 31));
        secondLightYLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        rValueSpinBox = new QSpinBox(Object3DWindow);
        rValueSpinBox->setObjectName(QStringLiteral("rValueSpinBox"));
        rValueSpinBox->setGeometry(QRect(1150, 710, 42, 22));
        rValueSpinBox->setMaximum(255);
        translationLabel = new QLabel(Object3DWindow);
        translationLabel->setObjectName(QStringLiteral("translationLabel"));
        translationLabel->setGeometry(QRect(1150, 10, 161, 31));
        translationLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        scalingYSlider = new QSlider(Object3DWindow);
        scalingYSlider->setObjectName(QStringLiteral("scalingYSlider"));
        scalingYSlider->setGeometry(QRect(1150, 280, 291, 22));
        scalingYSlider->setMinimum(0);
        scalingYSlider->setMaximum(10);
        scalingYSlider->setValue(1);
        scalingYSlider->setSliderPosition(1);
        scalingYSlider->setOrientation(Qt::Horizontal);
        rotationZLabel = new QLabel(Object3DWindow);
        rotationZLabel->setObjectName(QStringLiteral("rotationZLabel"));
        rotationZLabel->setGeometry(QRect(1450, 490, 51, 31));
        rotationZLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        firstLightZSlider = new QSlider(Object3DWindow);
        firstLightZSlider->setObjectName(QStringLiteral("firstLightZSlider"));
        firstLightZSlider->setGeometry(QRect(1540, 140, 291, 22));
        firstLightZSlider->setMinimum(-500);
        firstLightZSlider->setMaximum(1000);
        firstLightZSlider->setValue(0);
        firstLightZSlider->setOrientation(Qt::Horizontal);
        secondLightXLabel = new QLabel(Object3DWindow);
        secondLightXLabel->setObjectName(QStringLiteral("secondLightXLabel"));
        secondLightXLabel->setGeometry(QRect(1840, 230, 51, 31));
        secondLightXLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        firstLightCheckBox = new QCheckBox(Object3DWindow);
        firstLightCheckBox->setObjectName(QStringLiteral("firstLightCheckBox"));
        firstLightCheckBox->setGeometry(QRect(1710, 10, 111, 41));
        firstLightCheckBox->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        firstLightCheckBox->setChecked(false);
        translationZLabel = new QLabel(Object3DWindow);
        translationZLabel->setObjectName(QStringLiteral("translationZLabel"));
        translationZLabel->setGeometry(QRect(1450, 130, 51, 31));
        translationZLabel->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));

        retranslateUi(Object3DWindow);

        QMetaObject::connectSlotsByName(Object3DWindow);
    } // setupUi

    void retranslateUi(QWidget *Object3DWindow)
    {
        Object3DWindow->setWindowTitle(QApplication::translate("Object3DWindow", "Form", nullptr));
        rotationLabel->setText(QApplication::translate("Object3DWindow", "Rotacja obiektu", nullptr));
        paintedCheckBox->setText(QApplication::translate("Object3DWindow", "Zamalowany", nullptr));
        firstLightYLabel->setText(QApplication::translate("Object3DWindow", "0", nullptr));
        scalingZLabel->setText(QApplication::translate("Object3DWindow", "1", nullptr));
        firstLightXLabel->setText(QApplication::translate("Object3DWindow", "0", nullptr));
        translationXLabel->setText(QApplication::translate("Object3DWindow", "0", nullptr));
        bValueLabel->setText(QApplication::translate("Object3DWindow", "B", nullptr));
        secondLightCheckBox->setText(QApplication::translate("Object3DWindow", "Zapalone", nullptr));
        scalingLabel->setText(QApplication::translate("Object3DWindow", "Skalowanie obiektu", nullptr));
        firstLightLabel->setText(QApplication::translate("Object3DWindow", "\305\232wiat\305\202o 1", nullptr));
        rValueLabel->setText(QApplication::translate("Object3DWindow", "R", nullptr));
        objectColorLabel->setText(QApplication::translate("Object3DWindow", "Kolor obiektu", nullptr));
        smoothing3DObjectCheckBox->setText(QApplication::translate("Object3DWindow", "Wyg\305\202adzenie kraw\304\231dzi obiektu", nullptr));
        perspectiveValueLabel->setText(QApplication::translate("Object3DWindow", "500", nullptr));
        rotationYLabel->setText(QApplication::translate("Object3DWindow", "0", nullptr));
        perspectiveLabel->setText(QApplication::translate("Object3DWindow", "Perspektywa", nullptr));
        translationYLabel->setText(QApplication::translate("Object3DWindow", "0", nullptr));
        scalingXLabel->setText(QApplication::translate("Object3DWindow", "1", nullptr));
        firstLightZLabel->setText(QApplication::translate("Object3DWindow", "0", nullptr));
        sceletonCheckBox->setText(QApplication::translate("Object3DWindow", "Szkielet", nullptr));
        gValueLabel->setText(QApplication::translate("Object3DWindow", "G", nullptr));
        scalingYLabel->setText(QApplication::translate("Object3DWindow", "1", nullptr));
        secondLightZLabel->setText(QApplication::translate("Object3DWindow", "0", nullptr));
        rotationXLabel->setText(QApplication::translate("Object3DWindow", "0", nullptr));
        secondLightLabel->setText(QApplication::translate("Object3DWindow", "\305\232wiat\305\202o 2", nullptr));
        hideBackSurfaceCheckBox->setText(QApplication::translate("Object3DWindow", "Schowanie tylnych \305\233cian\n"
"(buffor Z + backface culling)", nullptr));
        secondLightYLabel->setText(QApplication::translate("Object3DWindow", "0", nullptr));
        translationLabel->setText(QApplication::translate("Object3DWindow", "Translacja obiektu", nullptr));
        rotationZLabel->setText(QApplication::translate("Object3DWindow", "0", nullptr));
        secondLightXLabel->setText(QApplication::translate("Object3DWindow", "0", nullptr));
        firstLightCheckBox->setText(QApplication::translate("Object3DWindow", "Zapalone", nullptr));
        translationZLabel->setText(QApplication::translate("Object3DWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Object3DWindow: public Ui_Object3DWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECT3DWINDOW_H
