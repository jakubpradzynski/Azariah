#include "object3dcanvas.h"
#include <fstream>

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
    readObject3DFromBinarySTLFile(str, &object3D);
    sortPointsInTrianglesByY(&object3D);
    object3D.fillTrianglesData();
    sortTrianglesByMeanZ(&object3D);
    draw3DObject();
}


void Object3DCanvas::translationXChanged(int x)
{
    translation.x = x;
    draw3DObject();
}

void Object3DCanvas::translationYChanged(int y)
{
    translation.y = y;
    draw3DObject();
}

void Object3DCanvas::translationZChanged(int z)
{
    translation.z = z;
    draw3DObject();
}

void Object3DCanvas::scalingXChanged(int x)
{
    scaling.x = x;
    draw3DObject();
}

void Object3DCanvas::scalingYChanged(int y)
{
    scaling.y = y;
    draw3DObject();
}

void Object3DCanvas::scalingZChanged(int z)
{
    scaling.z = z;
    draw3DObject();
}

void Object3DCanvas::rotationXChanged(int x)
{
    rotation.x = x;
    draw3DObject();
}

void Object3DCanvas::rotationYChanged(int y)
{
    rotation.y = y;
    draw3DObject();
}

void Object3DCanvas::rotationZChanged(int z)
{
    rotation.z = z;
    draw3DObject();
}

void Object3DCanvas::rValueChanged(int r)
{
    objectColor.r = r;
    draw3DObject();
}

void Object3DCanvas::gValueChanged(int g )
{
    objectColor.g = g;
    draw3DObject();
}

void Object3DCanvas::bValueChanged(int b)
{
    objectColor.b = b;
    draw3DObject();
}

void Object3DCanvas::sceletonOptionClicked(bool b)
{
    object3D.sceletonOption = b;
    draw3DObject();
}

void Object3DCanvas::paintedOptionClicked(bool b)
{
    object3D.paintedOption = b;
    draw3DObject();
}

void Object3DCanvas::hideBackSurfacesClicked(bool b)
{
    object3D.hideBackSurfaces = b;
    draw3DObject();
}

void Object3DCanvas::smoothingOptionClicked(bool b)
{
    object3D.smoothingOption = b;
    draw3DObject();
}

void Object3DCanvas::firstLightOptionClicked(bool b)
{
    firstLight.isOn = b;
    draw3DObject();
}

void Object3DCanvas::firstLightXChanged(int x)
{
    firstLight.x = x;
    draw3DObject();
}

void Object3DCanvas::firstLightYChanged(int y)
{
    firstLight.y = y;
    draw3DObject();
}

void Object3DCanvas::firstLightZChanged(int z)
{
    firstLight.z = z;
    draw3DObject();
}

void Object3DCanvas::secondLightOptionClicked(bool b)
{
    secondLight.isOn = b;
    draw3DObject();
}

void Object3DCanvas::secondLightXChanged(int x)
{
    secondLight.x = x;
    draw3DObject();
}

void Object3DCanvas::secondLightYChanged(int y)
{
    secondLight.y = y;
    draw3DObject();
}

void Object3DCanvas::secondLightZChanged(int z)
{
    secondLight.z = z;
    draw3DObject();
}

void Object3DCanvas::firstLightColorRValueChanged(int r)
{
    firstLight.color.r = r;
    draw3DObject();
}

void Object3DCanvas::firstLightColorGValueChanged(int g)
{
    firstLight.color.g = g;
    draw3DObject();
}

void Object3DCanvas::firstLightColorBValueChanged(int b)
{
    firstLight.color.b = b;
    draw3DObject();
}

void Object3DCanvas::secondLightColorRValueChanged(int r)
{
    secondLight.color.r = r;
    draw3DObject();
}

void Object3DCanvas::secondLightColorGValueChanged(int g)
{
    secondLight.color.g = g;
    draw3DObject();
}

void Object3DCanvas::secondLightColorBValueChanged(int b)
{
    secondLight.color.b = b;
    draw3DObject();
}

void Object3DCanvas::perspectiveChanged(int f)
{
    this->perspective = f;
    draw3DObject();
}

void Object3DCanvas::readObject3DFromBinarySTLFile(std::string fname, Object3D *object3D)
{
    std::vector<Triangle> v;
    std::ifstream myFile (
                fname.c_str(), std::ios::in | std::ios::binary);

    char header_info[80] = "";
    char nTri[4] = "";
    unsigned long nTriLong;

    //read 80 byte header
    if (myFile) {
        myFile.read (header_info, 80);
    }
    else{
        qDebug("Error reading header");
    }
    //read 4-byte ulong
    if (myFile) {
        myFile.read (nTri, 4);
        nTriLong = *((unsigned long*)nTri) ;
    }
    else{
        qDebug("Error reading 4-byte ulong");
    }
    //now read in all the triangles
    for(int i = 0; i < nTriLong; i++){

        char facet[50];

        if (myFile) {

            //read one 50-byte triangle
            myFile.read (facet, 50);

            //populate each point of the triangle
            //using v3::v3(char* bin);
            //facet + 12 skips the triangle's unit normal
            Vector3 normal(facet);
            Vector3 p1(facet+12);
            Vector3 p2(facet+24);
            Vector3 p3(facet+36);

            //add a new triangle to the array
            v.push_back( Triangle(normal,p1,p2,p3) );

        }
    }

    object3D->triangles = v;
}

void Object3DCanvas::sortPointsInTrianglesByY(Object3D *object3D)
{
    std::vector<Triangle> sorted = object3D->triangles;
    for (int i = 0; i < object3D->triangles.size(); i++) {
        sorted.at(i) = sortTrianglePointsByY(object3D->triangles.at(i));
    }
    object3D->triangles = sorted;
}

Triangle Object3DCanvas::sortTrianglePointsByY(Triangle triangle)
{
    Triangle sorted = triangle;
    if (sorted.p1.point3D.y > sorted.p2.point3D.y) {
        Vector3 tmp = sorted.p1.point3D;
        sorted.p1.point3D = sorted.p2.point3D;
        sorted.p2.point3D = tmp;
    }
    if (sorted.p2.point3D.y > sorted.p3.point3D.y) {
        Vector3 tmp = sorted.p2.point3D;
        sorted.p2.point3D = sorted.p3.point3D;
        sorted.p3.point3D = tmp;
    }
    if (sorted.p1.point3D.y > sorted.p2.point3D.y) {
        Vector3 tmp = sorted.p1.point3D;
        sorted.p1.point3D = sorted.p2.point3D;
        sorted.p2.point3D = tmp;
    }
    return sorted;
}

Triangle Object3DCanvas::sortTrianglePointsByYIn2DPoints(Triangle triangle)
{
    Triangle sorted = triangle;
    if (sorted.p1.point2D.y > sorted.p2.point2D.y) {
        Vector2 tmp = sorted.p1.point2D;
        sorted.p1.point2D = sorted.p2.point2D;
        sorted.p2.point2D = tmp;
    }
    if (sorted.p2.point2D.y > sorted.p3.point2D.y) {
        Vector2 tmp = sorted.p2.point2D;
        sorted.p2.point2D = sorted.p3.point2D;
        sorted.p3.point2D = tmp;
    }
    if (sorted.p1.point2D.y > sorted.p2.point2D.y) {
        Vector2 tmp = sorted.p1.point2D;
        sorted.p1.point2D = sorted.p2.point2D;
        sorted.p2.point2D = tmp;
    }
    return sorted;
}

void Object3DCanvas::sortTrianglesByMeanZ(Object3D *object3D)
{
    std::vector<Triangle> sorted = object3D->triangles;
    std::sort(sorted.begin(), sorted.end(), Object3DCanvas::sortTrianglesByMeanZComparator);
    object3D->triangles = sorted;
}

bool Object3DCanvas::sortTrianglesByMeanZComparator(const Triangle &t1, const Triangle &t2)
{
    return t1.meanPoint.point3D.z < t2.meanPoint.point3D.z;
}

void Object3DCanvas::draw3DObject()
{
    qImage.fill(Qt::white);
    object3D.initBufferZ(9999999.);
    update();

    Matrix transformationMatrix = getTransformationMatrix(translation, scaling, rotation);
    for (int i = 0; i < object3D.triangles.size(); i++) {
        object3D.triangles.at(i) = transformTriangle(transformationMatrix, object3D.triangles.at(i));
        object3D.triangles.at(i) = projectionTriangle(object3D.triangles.at(i), centralPoint, perspective);
    }

    if (object3D.sceletonOption && !object3D.paintedOption) {
        drawSceletonOf3DObject(&qImage, &object3D, objectColor);
    } else {
        drawPainted3DObject(&qImage, &object3D, objectColor);
    }
}


Matrix Object3DCanvas::getTranslationMatrix(Vector3 translation)
{
    Matrix A = Matrix(4, 4);
    A.set(0, 0, 1);
    A.set(1, 1, 1);
    A.set(2, 2, 1);
    A.set(3, 3, 1);
    A.set(0, 3, translation.x);
    A.set(1, 3, translation.y);
    A.set(2, 3, translation.z);
    return A;
}

Matrix Object3DCanvas::getScalingMatrix(Vector3 scaling)
{
    Matrix A = Matrix(4, 4);
    A.set(0, 0, scaling.x);
    A.set(1, 1, scaling.y);
    A.set(2, 2, scaling.z);
    A.set(3, 3, 1);
    return A;
}

Matrix Object3DCanvas::getXRotationMatrix(int xAlpha)
{
    Matrix A = Matrix(4, 4);
    A.set(0, 0, 1);
    A.set(1, 1, cos((double)xAlpha * M_PI / 180.0));
    A.set(2, 1, sin((double)xAlpha * M_PI / 180.0));
    A.set(1, 2, -sin((double)xAlpha * M_PI / 180.0));
    A.set(2, 2, cos((double)xAlpha * M_PI / 180.0));
    A.set(3, 3, 1);
    return A;
}

Matrix Object3DCanvas::getYRotationMatrix(int yAlpha)
{
    Matrix A = Matrix(4, 4);
    A.set(0, 0, cos((double)yAlpha * M_PI / 180.0));
    A.set(1, 1, 1);
    A.set(2, 0, -sin((double)yAlpha * M_PI / 180.0));
    A.set(0, 2, sin((double)yAlpha * M_PI / 180.0));
    A.set(2, 2, cos((double)yAlpha * M_PI / 180.0));
    A.set(3, 3, 1);
    return A;
}

Matrix Object3DCanvas::getZRotationMatrix(int zAlpha)
{
    Matrix A = Matrix(4, 4);
    A.set(0, 0, cos((double)zAlpha * M_PI / 180.0));
    A.set(1, 0, sin((double)zAlpha * M_PI / 180.0));
    A.set(0, 1, -sin((double)zAlpha * M_PI / 180.0));
    A.set(1, 1, cos((double)zAlpha * M_PI / 180.0));
    A.set(2, 2, 1);
    A.set(3, 3, 1);
    return A;
}

Matrix Object3DCanvas::getTransformationMatrix(Vector3 translation, Vector3 scaling, Vector3 rotation)
{
    Matrix translationMatrix = getTranslationMatrix(translation);
    Matrix scalingMatrix = getScalingMatrix(scaling);
    Matrix xRotationMatrix = getXRotationMatrix(rotation.x);
    Matrix yRotationMatrix = getYRotationMatrix(rotation.y);
    Matrix zRotationMatrix = getZRotationMatrix(rotation.z);
    Matrix transformationMatrix = translationMatrix.multiply(scalingMatrix);
    Matrix transformationMatrix1 = transformationMatrix.multiply(xRotationMatrix);
    Matrix transformationMatrix2 = transformationMatrix1.multiply(yRotationMatrix);
    Matrix transformationMatrix3 = transformationMatrix2.multiply(zRotationMatrix);
    return transformationMatrix3;
}

Triangle Object3DCanvas::transformTriangle(Matrix transformationMatrix, Triangle triangle)
{
    Triangle transformed = triangle;
    transformed.p1.point3DAfterTransform = transformationMatrix.multiplyVector(transformed.p1.point3D);
    transformed.p2.point3DAfterTransform = transformationMatrix.multiplyVector(transformed.p2.point3D);
    transformed.p3.point3DAfterTransform = transformationMatrix.multiplyVector(transformed.p3.point3D);
    return transformed;
}

Triangle Object3DCanvas::projectionTriangle(Triangle triangle, Vector2 centralPoint, int perspective)
{
    Triangle projected = triangle;
    projected.p1.point2D = calculateProjection(triangle.p1.point3DAfterTransform, centralPoint, perspective);
    projected.p2.point2D = calculateProjection(triangle.p2.point3DAfterTransform, centralPoint, perspective);
    projected.p3.point2D = calculateProjection(triangle.p3.point3DAfterTransform, centralPoint, perspective);
    return projected;
}

Vector2 Object3DCanvas::calculateProjection(Vector3 vector3, Vector2 centralPoint, double perspective)
{
    if (vector3.z == 0) {
        vector3.z = 0.001;
    }
    double x = (double)vector3.x / (double)vector3.z * perspective + (double)centralPoint.x;
    double y = (double)vector3.y / (double)vector3.z * perspective + (double)centralPoint.y;
    return Vector2(x, y);
}

void Object3DCanvas::drawSceletonOf3DObject(QImage *qImage, Object3D *object3D, RGB objectColor)
{
    if (!object3D->hideBackSurfaces) {
        for (int i = 0; i < object3D->triangles.size(); i++) {
            drawTriangleEdges(qImage, &object3D->triangles.at(i), objectColor);
        }
    } else {
        for (int i = 0; i < object3D->triangles.size(); i++) {
            if (backfaceCullingTest(object3D->triangles.at(i), observer)) {
                drawTriangleEdgesWithBufferZCheck(qImage, &object3D->triangles.at(i), objectColor, object3D);
            }
        }
    }
}

void Object3DCanvas::drawTriangleEdges(QImage *qImage, Triangle *triangle, RGB color)
{
    drawLine(qImage, Vector2(triangle->p1.point2D.x, triangle->p1.point2D.y), Vector2(triangle->p2.point2D.x, triangle->p2.point2D.y), color);
    drawLine(qImage, Vector2(triangle->p1.point2D.x, triangle->p1.point2D.y), Vector2(triangle->p3.point2D.x, triangle->p3.point2D.y), color);
    drawLine(qImage, Vector2(triangle->p2.point2D.x, triangle->p2.point2D.y), Vector2(triangle->p3.point2D.x, triangle->p3.point2D.y), color);
}

void Object3DCanvas::drawTriangleEdgesWithBufferZCheck(QImage *qImage, Triangle *triangle, RGB color, Object3D *object3D)
{
    drawLineWithBufferZCheck(qImage, Vector3(triangle->p1.point2D.x, triangle->p1.point2D.y, triangle->p1.point3DAfterTransform.z), Vector3(triangle->p2.point2D.x, triangle->p2.point2D.y, triangle->p2.point3DAfterTransform.z), color, object3D);
    drawLineWithBufferZCheck(qImage, Vector3(triangle->p1.point2D.x, triangle->p1.point2D.y, triangle->p1.point3DAfterTransform.z), Vector3(triangle->p3.point2D.x, triangle->p3.point2D.y, triangle->p3.point3DAfterTransform.z), color, object3D);
    drawLineWithBufferZCheck(qImage, Vector3(triangle->p2.point2D.x, triangle->p2.point2D.y, triangle->p2.point3DAfterTransform.z), Vector3(triangle->p3.point2D.x, triangle->p3.point2D.y, triangle->p3.point3DAfterTransform.z), color, object3D);
}

void Object3DCanvas::drawLine(QImage *qImage, Vector2 start, Vector2 end, RGB rgb)
{
    if(start.x < 0 || start.y < 0 || end.x < 0 || end.y < 0 || start.x > qImage->width() || start.y > qImage->height() || end.x > qImage->width() || end.y > qImage->height()) return;

    if(start.x == end.x && start.y == end.y) {
        putPixel(qImage, start, rgb);
        return;
    }
    double dx = (double) end.x - start.x;
    double dy = (double) end.y - start.y;
    if (abs(dx) >= abs(dy)) {
        if(start.x > end.x) {
            Vector2 tmp = start;
            start = end;
            end = tmp;
        }
        for (int x = start.x; x <= end.x; x++) {
            double y = (double) start.y + dy * (x - start.x) / dx;
            putPixel(qImage, Vector2(x, (int)y), rgb);
        }
    } else {
        if(start.y > end.y) {
            Vector2 tmp = start;
            start = end;
            end = tmp;
        }
        for (int y = start.y; y <= end.y; y++) {
            float x = (float) start.x + dx * (y - start.y) / dy;
            putPixel(qImage, Vector2((int)x, y), rgb);
        }
    }
}

void Object3DCanvas::drawLineWithBufferZCheck(QImage *qImage, Vector3 start, Vector3 end, RGB rgb, Object3D *object3D)
{
    if(start.x < 0 || start.y < 0 || end.x < 0 || end.y < 0 || start.x > qImage->width() || start.y > qImage->height() || end.x > qImage->width() || end.y > qImage->height()) return;

    if(start.x == end.x && start.y == end.y) {
        putPixel(qImage, Vector2(start.x, start.y), rgb);
        return;
    }
    double dx = (double) end.x - start.x;
    double dy = (double) end.y - start.y;
    if (abs(dx) >= abs(dy)) {
        if(start.x > end.x) {
            Vector3 tmp = start;
            start = end;
            end = tmp;
        }
        for (int x = start.x; x <= end.x; x++) {
            double y = (double) start.y + dy * (x - start.x) / dx;
            double z = calculateLinearInterpolation(Vector2(start.z, start.x), Vector2(end.z, end.x), (double)x);
            if (z < object3D->bufferZ[x][(int)y]) {
                putPixel(qImage, Vector2(x, (int)y), rgb);
                object3D->bufferZ[x][(int)y] = z;
            }
            putPixel(qImage, Vector2(x, (int)y), rgb);
        }
    } else {
        if(start.y > end.y) {
            Vector3 tmp = start;
            start = end;
            end = tmp;
        }
        for (int y = start.y; y <= end.y; y++) {
            double x = (double) start.x + dx * (y - start.y) / dy;
            double z = calculateLinearInterpolation(Vector2(start.z, start.x), Vector2(end.z, end.x), (double)x);
            if (z < object3D->bufferZ[(int)x][y]) {
                putPixel(qImage, Vector2((int)x, y), rgb);
                object3D->bufferZ[(int)x][y] = z;
            }
            putPixel(qImage, Vector2((int)x, y), rgb);
        }
    }
}

void Object3DCanvas::putPixel(QImage *qImage, Vector2 point, RGB rgb)
{
    if ((int)point.x < 0 || (int)point.y < 0 || (int)point.x >= qImage->width() || (int)point.y >= qImage->height()) {
        return;
    }
    uchar *pix = qImage->scanLine((int)point.y);
    pix[4 * (int)point.x] = rgb.b;
    pix[4 * (int)point.x + 1] = rgb.g;
    pix[4 * (int)point.x + 2] = rgb.r;
}

double Object3DCanvas::calculateLinearInterpolation(Vector2 A, Vector2 B, double y)
{
    double alpha = (double) (y - A.y) / (B.y - A.y);
    if (alpha > 1.) alpha = 1.;
    if (alpha < 0.) alpha = 0.;
    double x = (double) A.x + alpha * (B.x - A.x);
    return x;
}

bool Object3DCanvas::backfaceCullingTest(Triangle triangle, Vector3 observer) {
    //    return dotProductV3(triangle.normalVector, Vector3(observer.x, observer.y, translation.z)) >= dotProductV3(triangle.normalVector, triangle.p1.point3DAfterTransform);
    //    Vector3 normal = calculateVectorForPointAfterTransformation(1, triangle);
    //    return (-dotProductV3(normal, triangle.p1.point3DAfterTransform)) >= 0;
    //    return (0 * normal.x + 0 * normal.y + -translation.z * normal.z + (-dotProductV3(triangle.p1.point3DAfterTransform, triangle.normalVector))) >= 0;
    double ax = triangle.p2.point2D.x - triangle.p1.point2D.x;
    double ay = triangle.p2.point2D.y - triangle.p1.point2D.y;
    double bx = triangle.p3.point2D.x - triangle.p1.point2D.x;
    double by = triangle.p3.point2D.y - triangle.p1.point2D.y;
    double nz = ax * by - ay * bx;
    return nz < 0;
    //    double ax = triangle.p1.point2D.x - triangle.p2.point2D.x;
    //    double ay = triangle.p1.point2D.y - triangle.p2.point2D.y;
    //    double bx = triangle.p1.point2D.x - triangle.p3.point2D.x;
    //    double by = triangle.p1.point2D.y - triangle.p3.point2D.y;
    //    double nz = ax * by - ay * bx;
    //    return nz < 0;
}

Vector3 Object3DCanvas::calculateVector(Vector3 p1, Vector3 p2)
{
    return Vector3(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
}

Vector3 Object3DCanvas::calculateVectorForPoint(int pointNumber, Triangle triangle)
{
    switch (pointNumber) {
    case 1:
        return crossProduct(calculateVector(triangle.p1.point3D, triangle.p2.point3D), calculateVector(triangle.p1.point3D, triangle.p3.point3D));
        break;
    case 2:
        return crossProduct(calculateVector(triangle.p2.point3D, triangle.p1.point3D), calculateVector(triangle.p2.point3D, triangle.p3.point3D));
        break;
    case 3:
        return crossProduct(calculateVector(triangle.p3.point3D, triangle.p1.point3D), calculateVector(triangle.p3.point3D, triangle.p2.point3D));
        break;
    default:
        throw "Incorrect point number";
        return Vector3();
        break;
    }
}

Vector3 Object3DCanvas::calculateVectorForPointAfterTransformation(int pointNumber, Triangle triangle)
{
    switch (pointNumber) {
    case 1:
        return crossProduct(calculateVector(triangle.p1.point3DAfterTransform, triangle.p2.point3DAfterTransform), calculateVector(triangle.p1.point3DAfterTransform, triangle.p3.point3DAfterTransform));
        break;
    case 2:
        return crossProduct(calculateVector(triangle.p2.point3DAfterTransform, triangle.p1.point3DAfterTransform), calculateVector(triangle.p2.point3DAfterTransform, triangle.p3.point3DAfterTransform));
        break;
    case 3:
        return crossProduct(calculateVector(triangle.p3.point3DAfterTransform, triangle.p1.point3DAfterTransform), calculateVector(triangle.p3.point3DAfterTransform, triangle.p2.point3DAfterTransform));
        break;
    default:
        throw "Incorrect point number";
        return Vector3();
        break;
    }
}

double Object3DCanvas::vectorLength(Vector3 vector)
{
    return sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}

Vector3 Object3DCanvas::normalizeVector(Vector3 vector)
{
    double length = vectorLength(vector);
    return Vector3(vector.x / length, vector.y / length, vector.z / length);
}

double Object3DCanvas::dotProductV3(Vector3 v1, Vector3 v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

double Object3DCanvas::dotProductV2(Vector2 v1, Vector2 v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

Vector3 Object3DCanvas::crossProduct(Vector3 v1, Vector3 v2)
{
    return Vector3(v1.y * v2.z - v2.y * v1.z, v2.x * v1.z - v1.x * v2.z, v1.x * v2.y - v2.x * v1.y);
}

Vector3 Object3DCanvas::getNormalizedVector(Vector3 v1, Vector3 v2)
{
    return normalizeVector(crossProduct(v1, v2));
}

double Object3DCanvas::calculateLightOnTriangle(Triangle triangle, Vector3 light)
{
    Vector3 l = Vector3(triangle.p1.point3DAfterTransform.x - light.x, triangle.p1.point3DAfterTransform.y - light.y, triangle.p1.point3DAfterTransform.z - light.z);
    double cosB = dotProductV3(triangle.normalVector, l) / vectorLength(l);
    return std::max((double)0, cosB)/* / (vectorLength(l) * vectorLength(l))*/;
}

void Object3DCanvas::drawPainted3DObject(QImage *qImage, Object3D *object3D, RGB objectColor)
{
    if (!object3D->hideBackSurfaces && object3D->paintedOption) {
        for (int i = 0; i < object3D->triangles.size(); i++) {
            drawTriangle(qImage, object3D->triangles.at(i), objectColor);
            if(object3D->sceletonOption) {
                if (objectColor.r == 0 && objectColor.g == 0 && objectColor.b == 0) {
                    drawTriangleEdges(qImage, &object3D->triangles.at(i), RGB(255, 255, 255));
                } else {
                    drawTriangleEdges(qImage, &object3D->triangles.at(i), RGB(0, 0, 0));
                }
            }
        }
    } else if (object3D->paintedOption) {
        for (int i = 0; i < object3D->triangles.size(); i++) {
            if (/*backfaceCullingTest(object3D->triangles.at(i), observer)*/true) {
                if(drawTriangleWithBufferZCheck(qImage, object3D->triangles.at(i), objectColor) && object3D->sceletonOption) {
                    if (objectColor.r == 0 && objectColor.g == 0 && objectColor.b == 0) {
                        drawTriangleEdges(qImage, &object3D->triangles.at(i), RGB(255, 255, 255));
                    } else {
                        drawTriangleEdges(qImage, &object3D->triangles.at(i), RGB(0, 0, 0));
                    }
                }
            }
        }
    }

    //    if (!object3D->hideBackSurfaces) {
    //        for (int i = 0; i < object3D->triangles.size(); i++) {
    //            drawTriangleEdges(qImage, &object3D->triangles.at(i), objectColor);
    //        }
    //    } else {
    //        for (int i = 0; i < object3D->triangles.size(); i++) {
    //            if (backfaceCullingTest(object3D->triangles.at(i), observer)) {
    //                drawTriangleEdgesWithBufferZCheck(qImage, &object3D->triangles.at(i), objectColor, object3D);
    //            }
    //        }
    //    }
}

void Object3DCanvas::drawTriangle(QImage *qImage, Triangle triangle, RGB color)
{
    double light1 = calculateLightOnTriangle(triangle, Vector3(firstLight.x, firstLight.y, firstLight.z));
    double light2 = calculateLightOnTriangle(triangle, Vector3(secondLight.x, secondLight.y, secondLight.z));

    if (firstLight.isOn && secondLight.isOn) color = RGB(color.r * (light1 + light2), color.g * (light1 + light2), color.b * (light1 + light2));
    else if (firstLight.isOn) color = RGB(color.r * light1, color.g * light1, color.b * light1);
    else if (secondLight.isOn) color = RGB(color.r * light2, color.g * light2, color.b * light2);

    triangle = sortTrianglePointsByYIn2DPoints(triangle);
    for (int y = (int)triangle.p1.point2D.y; y <= (int)triangle.p2.point2D.y; y++) {
        double x1, x2;
        x1 = calculateLinearInterpolation(triangle.p1.point2D, triangle.p2.point2D, y);
        x2 =  calculateLinearInterpolation(triangle.p1.point2D, triangle.p3.point2D, y);
        drawHorizontalLine(qImage, Vector2(x1, y), Vector2(x2, y), color);
    }
    for (int y = (int)triangle.p2.point2D.y; y <= (int)triangle.p3.point2D.y; y++) {
        double x1, x2;
        x1 =  calculateLinearInterpolation(triangle.p2.point2D, triangle.p3.point2D, y);
        x2 =  calculateLinearInterpolation(triangle.p1.point2D, triangle.p3.point2D, y);
        drawHorizontalLine(qImage, Vector2(x1, y), Vector2(x2, y), color);
    }
}

void Object3DCanvas::drawHorizontalLine(QImage *qImage, Vector2 start, Vector2 end, RGB rgb)
{
    if ((int)end.x >= qImage->width()) {
        end.x = (double)qImage->width();
    }
    if(start.x > end.x) {
        Vector2 temp = start;
        start = end;
        end = temp;
    }
    for(int i = (int)start.x; i < (int)end.x; i++) {
        putPixel(qImage, Vector2(i, (int)start.y), rgb);
        update();
    }
}

bool Object3DCanvas::drawTriangleWithBufferZCheck(QImage *qImage, Triangle triangle, RGB color)
{
    double light1 = calculateLightOnTriangle(triangle, Vector3(firstLight.x, firstLight.y, firstLight.z));
    double light2 = calculateLightOnTriangle(triangle, Vector3(secondLight.x, secondLight.y, secondLight.z));

    if (firstLight.isOn && secondLight.isOn) color = RGB(color.r * (light1 + light2), color.g * (light1 + light2), color.b * (light1 + light2));
    else if (firstLight.isOn) color = RGB(color.r * light1, color.g * light1, color.b * light1);
    else if (secondLight.isOn) color = RGB(color.r * light2, color.g * light2, color.b * light2);

    bool hadBeenSthDrawn = false;
    triangle = sortTrianglePointsByYIn2DPoints(triangle);
    for (int y = (int)triangle.p1.point2D.y; y <= (int)triangle.p2.point2D.y; y++) {
        double x1, x2;
        x1 = calculateLinearInterpolation(triangle.p1.point2D, triangle.p2.point2D, y);
        x2 =  calculateLinearInterpolation(triangle.p1.point2D, triangle.p3.point2D, y);
        double z1, z2;
        z1 = calculateLinearInterpolation(Vector2(triangle.p1.point3DAfterTransform.z, triangle.p1.point2D.y), Vector2(triangle.p2.point3DAfterTransform.z, triangle.p2.point2D.y), y);
        z2 =  calculateLinearInterpolation(Vector2(triangle.p1.point3DAfterTransform.z, triangle.p1.point2D.y), Vector2(triangle.p3.point3DAfterTransform.z, triangle.p3.point2D.y), y);
        hadBeenSthDrawn = drawHorizontalLineWithBufferZCheck(qImage, Vector3(x1, y, z1), Vector3(x2, y, z2), color);
    }
    for (int y = (int)triangle.p2.point2D.y; y <= (int)triangle.p3.point2D.y; y++) {
        double x1, x2;
        x1 =  calculateLinearInterpolation(triangle.p2.point2D, triangle.p3.point2D, y);
        x2 =  calculateLinearInterpolation(triangle.p1.point2D, triangle.p3.point2D, y);
        double z1, z2;
        z1 = calculateLinearInterpolation(Vector2(triangle.p2.point3DAfterTransform.z, triangle.p2.point2D.y), Vector2(triangle.p3.point3DAfterTransform.z, triangle.p3.point2D.y), y);
        z2 =  calculateLinearInterpolation(Vector2(triangle.p1.point3DAfterTransform.z, triangle.p1.point2D.y), Vector2(triangle.p3.point3DAfterTransform.z, triangle.p3.point2D.y), y);
        if (hadBeenSthDrawn)
            drawHorizontalLineWithBufferZCheck(qImage, Vector3(x1, y, z1), Vector3(x2, y, z2), color);
        else
            hadBeenSthDrawn = drawHorizontalLineWithBufferZCheck(qImage, Vector3(x1, y, z1), Vector3(x2, y, z2), color);
    }
    return hadBeenSthDrawn;
}

bool Object3DCanvas::drawHorizontalLineWithBufferZCheck(QImage *qImage, Vector3 start, Vector3 end, RGB rgb)
{
    bool hadBeenSthDrawn = false;
    if ((int)end.x >= qImage->width()) {
        end.x = (double)qImage->width();
    }
    if(start.x > end.x) {
        Vector3 temp = start;
        start = end;
        end = temp;
    }
    for(int i = (int)start.x; i < (int)end.x; i++) {
        double z = calculateLinearInterpolation(Vector2(start.z, start.x), Vector2(end.z, end.x), (double)i);
        if (z < object3D.bufferZ[i][(int)start.y]) {
            putPixel(qImage, Vector2(i, (int)start.y), rgb);
            object3D.bufferZ[i][(int)start.y] = z;
            update();
            hadBeenSthDrawn = true;
        }
    }
    return hadBeenSthDrawn;
}
