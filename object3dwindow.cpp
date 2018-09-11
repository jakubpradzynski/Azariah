#include "object3dwindow.h"
#include "ui_object3dwindow.h"

Object3DWindow::Object3DWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Object3DWindow)
{
    ui->setupUi(this);

    connect(ui->translationXSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(translationXChanged(int)));
    connect(ui->translationYSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(translationYChanged(int)));
    connect(ui->translationZSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(translationZChanged(int)));
    connect(ui->translationXSlider, SIGNAL(valueChanged(int)), ui->translationXLabel, SLOT(setNum(int)));
    connect(ui->translationYSlider, SIGNAL(valueChanged(int)), ui->translationYLabel, SLOT(setNum(int)));
    connect(ui->translationZSlider, SIGNAL(valueChanged(int)), ui->translationZLabel, SLOT(setNum(int)));

    connect(ui->scalingXSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(scalingXChanged(int)));
    connect(ui->scalingYSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(scalingYChanged(int)));
    connect(ui->scalingZSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(scalingZChanged(int)));
    connect(ui->scalingXSlider, SIGNAL(valueChanged(int)), ui->scalingXLabel, SLOT(setNum(int)));
    connect(ui->scalingYSlider, SIGNAL(valueChanged(int)), ui->scalingYLabel, SLOT(setNum(int)));
    connect(ui->scalingZSlider, SIGNAL(valueChanged(int)), ui->scalingZLabel, SLOT(setNum(int)));

    connect(ui->rotationXSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(rotationXChanged(int)));
    connect(ui->rotationYSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(rotationYChanged(int)));
    connect(ui->rotationZSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(rotationZChanged(int)));
    connect(ui->rotationXSlider, SIGNAL(valueChanged(int)), ui->rotationXLabel, SLOT(setNum(int)));
    connect(ui->rotationYSlider, SIGNAL(valueChanged(int)), ui->rotationYLabel, SLOT(setNum(int)));
    connect(ui->rotationZSlider, SIGNAL(valueChanged(int)), ui->rotationZLabel, SLOT(setNum(int)));

    connect(ui->perspectiveSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(perspectiveChanged(int)));
    connect(ui->perspectiveSlider, SIGNAL(valueChanged(int)), ui->perspectiveValueLabel, SLOT(setNum(int)));

    connect(ui->rValueSpinBox, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(rValueChanged(int)));
    connect(ui->gValueSpinBox, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(gValueChanged(int)));
    connect(ui->bValueSpinBox, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(bValueChanged(int)));

    connect(ui->sceletonCheckBox, SIGNAL(clicked(bool)), ui->object3DCanvas, SLOT(sceletonOptionClicked(bool)));
    connect(ui->paintedCheckBox, SIGNAL(clicked(bool)), ui->object3DCanvas, SLOT(paintedOptionClicked(bool)));
    connect(ui->hideBackSurfaceCheckBox, SIGNAL(clicked(bool)), ui->object3DCanvas, SLOT(hideBackSurfacesClicked(bool)));
    connect(ui->texturing3DObjectCheckBox, SIGNAL(clicked(bool)), ui->object3DCanvas, SLOT(texturingOptionClicked(bool)));

    connect(ui->firstLightCheckBox, SIGNAL(clicked(bool)), ui->object3DCanvas, SLOT(firstLightOptionClicked(bool)));
    connect(ui->firstLightXSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(firstLightXChanged(int)));
    connect(ui->firstLightYSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(firstLightYChanged(int)));
    connect(ui->firstLightZSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(firstLightZChanged(int)));
    connect(ui->firstLightXSlider, SIGNAL(valueChanged(int)), ui->firstLightXLabel, SLOT(setNum(int)));
    connect(ui->firstLightYSlider, SIGNAL(valueChanged(int)), ui->firstLightYLabel, SLOT(setNum(int)));
    connect(ui->firstLightZSlider, SIGNAL(valueChanged(int)), ui->firstLightZLabel, SLOT(setNum(int)));

    connect(ui->secondLightCheckBox, SIGNAL(clicked(bool)), ui->object3DCanvas, SLOT(secondLightOptionClicked(bool)));
    connect(ui->secondLightXSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(secondLightXChanged(int)));
    connect(ui->secondLightYSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(secondLightYChanged(int)));
    connect(ui->secondLightZSlider, SIGNAL(valueChanged(int)), ui->object3DCanvas, SLOT(secondLightZChanged(int)));
    connect(ui->secondLightXSlider, SIGNAL(valueChanged(int)), ui->secondLightXLabel, SLOT(setNum(int)));
    connect(ui->secondLightYSlider, SIGNAL(valueChanged(int)), ui->secondLightYLabel, SLOT(setNum(int)));
    connect(ui->secondLightZSlider, SIGNAL(valueChanged(int)), ui->secondLightZLabel, SLOT(setNum(int)));
}

Object3DWindow::~Object3DWindow()
{
    delete ui;
}

void Object3DWindow::start(const char *pathToFile)
{
    ui->object3DCanvas->start(pathToFile);
}
