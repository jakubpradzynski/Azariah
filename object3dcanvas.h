#ifndef OBJECT3DCANVAS_H
#define OBJECT3DCANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include "object3d.h"
#include "light.h"

class Object3DCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit Object3DCanvas(QWidget *parent = nullptr);
    ~Object3DCanvas();
    void start(const char *pathToFile);

protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void translationXChanged(int);
    void translationYChanged(int);
    void translationZChanged(int);
    void scalingXChanged(int);
    void scalingYChanged(int);
    void scalingZChanged(int);
    void rotationXChanged(int);
    void rotationYChanged(int);
    void rotationZChanged(int);
    void perspectiveChanged(int);
    void rValueChanged(int);
    void gValueChanged(int);
    void bValueChanged(int);
    void sceletonOptionClicked(bool);
    void paintedOptionClicked(bool);
    void hideBackSurfacesClicked(bool);
    void smoothingOptionClicked(bool);
    void firstLightOptionClicked(bool);
    void firstLightXChanged(int);
    void firstLightYChanged(int);
    void firstLightZChanged(int);
    void secondLightOptionClicked(bool);
    void secondLightXChanged(int);
    void secondLightYChanged(int);
    void secondLightZChanged(int);

private:
    QSize canvasSize = QSize(1100, 880);
    QImage qImage;
    Object3D object3D;
    Vector3 translation, scaling, rotation;
    int perspective;
    Light firstLight, secondLight;
    RGB objectColor;
    Vector2 centralPoint = Vector2(canvasSize.width() / 2, canvasSize.height() / 2);
    Vector3 observer = Vector3(canvasSize.width() / 2, canvasSize.height() / 2, 0);
};

#endif // OBJECT3DCANVAS_H
