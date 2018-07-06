#include "object3dcanvas.h"

Object3DCanvas::Object3DCanvas(QWidget *parent) : QWidget(parent)
{
    objectColor = RGB(0, 255, 0);
    translation = Vector3(0, 0, 100);
    rotation = Vector3(0, 0, 0);
    scaling = Vector3(1, 1, 1);
    perspective = 500;
    firstLight = Light();
    secondLight = Light();

    qImage = QImage(canvasSize.width(), canvasSize.height(), QImage::Format_RGB32);
    qImage.fill(Qt::white);
    update();
}

Object3DCanvas::~Object3DCanvas()
{
    return;
}

void Object3DCanvas::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    qPainter.fillRect(0, 0, canvasSize.width(), canvasSize.height(), Qt::white);
    qPainter.drawImage(0, 0, qImage);
}

void Object3DCanvas::start(const char *pathToFile)
{
    std::string str(pathToFile);
}


void Object3DCanvas::translationXChanged(int x)
{
    translation.x = x;
}

void Object3DCanvas::translationYChanged(int y)
{
    translation.y = y;
}

void Object3DCanvas::translationZChanged(int z)
{
    translation.z = z;
}

void Object3DCanvas::scalingXChanged(int x)
{
    scaling.x = x;
}

void Object3DCanvas::scalingYChanged(int y)
{
    scaling.y = y;
}

void Object3DCanvas::scalingZChanged(int z)
{
    scaling.z = z;
}

void Object3DCanvas::rotationXChanged(int x)
{
    rotation.x = x;
}

void Object3DCanvas::rotationYChanged(int y)
{
    rotation.y = y;
}

void Object3DCanvas::rotationZChanged(int z)
{
    rotation.z = z;
}

void Object3DCanvas::rValueChanged(int r)
{
    objectColor.r = r;
}

void Object3DCanvas::gValueChanged(int g )
{
    objectColor.g = g;
}

void Object3DCanvas::bValueChanged(int b)
{
    objectColor.b = b;
}

void Object3DCanvas::sceletonOptionClicked(bool b)
{
    object3D.sceletonOption = b;
}

void Object3DCanvas::paintedOptionClicked(bool b)
{
    object3D.paintedOption = b;
}

void Object3DCanvas::hideBackSurfacesClicked(bool b)
{
    object3D.hideBackSurfaces = b;
}

void Object3DCanvas::smoothingOptionClicked(bool b)
{
    object3D.smoothingOption = b;
}

void Object3DCanvas::firstLightOptionClicked(bool b)
{
    firstLight.isOn = b;
}

void Object3DCanvas::firstLightXChanged(int x)
{
    firstLight.x = x;
}

void Object3DCanvas::firstLightYChanged(int y)
{
    firstLight.y = y;
}

void Object3DCanvas::firstLightZChanged(int z)
{
    firstLight.z = z;
}

void Object3DCanvas::secondLightOptionClicked(bool b)
{
    secondLight.isOn = b;
}

void Object3DCanvas::secondLightXChanged(int x)
{
    secondLight.x = x;
}

void Object3DCanvas::secondLightYChanged(int y)
{
    secondLight.y = y;
}

void Object3DCanvas::secondLightZChanged(int z)
{
    secondLight.z = z;
}

void Object3DCanvas::perspectiveChanged(int f)
{
    this->perspective = f;
}
