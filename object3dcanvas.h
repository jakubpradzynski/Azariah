#ifndef OBJECT3DCANVAS_H
#define OBJECT3DCANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include "object3d.h"
#include "light.h"
#include "matrix.h"

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

    void readObject3DFromBinarySTLFile(std::string fname, Object3D *object3D);
    void sortPointsInTrianglesByY(Object3D *object3D);
    Triangle sortTrianglePointsByY(Triangle triangle);
    Triangle sortTrianglePointsByYIn2DPoints(Triangle triangle);
    void sortTrianglesByMeanZ(Object3D *object3D);
    static bool sortTrianglesByMeanZComparator(const Triangle &t1, const Triangle &t2);

    void draw3DObject();

    Matrix getTranslationMatrix(Vector3 translation);
    Matrix getScalingMatrix(Vector3 scaling);
    Matrix getXRotationMatrix(int xAlpha);
    Matrix getYRotationMatrix(int yAlpha);
    Matrix getZRotationMatrix(int zAlpha);
    Matrix getTransformationMatrix(Vector3 translation, Vector3 scaling, Vector3 rotation);

    Triangle transformTriangle(Matrix transformationMatrix, Triangle triangle);
    Triangle projectionTriangle(Triangle triangle, Vector2 centralPoint, int perspective);
    Vector2 calculateProjection(Vector3 vector3, Vector2 centralPoint, double perspective);

    void drawSceletonOf3DObject(QImage *qImage, Object3D *object3D, RGB objectColor);
    void drawTriangleEdges(QImage *qImage, Triangle *triangle, RGB color);
    void drawTriangleEdgesWithBufferZCheck(QImage *qImage, Triangle *triangle, RGB color, Object3D *object3D);
    void drawLine(QImage *qImage, Vector2 start, Vector2 end, RGB rgb);
    void drawLineWithBufferZCheck(QImage *qImage, Vector3 start, Vector3 end, RGB rgb, Object3D *object3D);
    void putPixel(QImage *qImage, Vector2 point, RGB rgb);
    double calculateLinearInterpolation(Vector2 A, Vector2 B, double y);
    bool backfaceCullingTest(Triangle triangle, Vector3 observer);

    Vector3 calculateVector(Vector3 p1, Vector3 p2);
    Vector3 calculateVectorForPoint(int pointNumber, Triangle triangle);
    Vector3 calculateVectorForPointAfterTransformation(int pointNumber, Triangle triangle);
    double vectorLength(Vector3 vector);
    Vector3 normalizeVector(Vector3 vector);
    double dotProductV3(Vector3 v1, Vector3 v2);
    double dotProductV2(Vector2 v1, Vector2 v2);
    Vector3 crossProduct(Vector3 v1, Vector3 v2);
    Vector3 getNormalizedVector(Vector3 v1, Vector3 v2);
    double calculateLightOnTriangle(Triangle triangle, Vector3 light);
};

#endif // OBJECT3DCANVAS_H
