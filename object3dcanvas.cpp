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
    texture = QImage("texture.bmp");
    textureSize = QSize(texture.width(), texture.height());
    qDebug("%d %d", textureSize.width(), textureSize.height());
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

void Object3DCanvas::texturingOptionClicked(bool b) {
    object3D.texturingOption = b;
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
    object3D.fillColorInPoints(objectColor);
    object3D.fillMeanPointsData();
    update();

    Matrix transformationMatrix = getTransformationMatrix(translation, scaling, rotation);
    for (int i = 0; i < object3D.triangles.size(); i++) {
        object3D.triangles.at(i) = transformTriangle(transformationMatrix, object3D.triangles.at(i));
        object3D.triangles.at(i) = projectionTriangle(object3D.triangles.at(i), centralPoint, perspective);
    }

    if (object3D.sceletonOption && (!object3D.paintedOption && !object3D.texturingOption)) {
        drawSceletonOf3DObject(&qImage, &object3D, objectColor);
    } else if (object3D.paintedOption) {
        drawPainted3DObject(&qImage, &object3D, objectColor);
    } else if (object3D.texturingOption) {
        drawTextured3DObject(&qImage, &object3D, &texture);
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
    transformed.meanPoint.point3DAfterTransform = transformationMatrix.multiplyVector(transformed.meanPoint.point3D);
    return transformed;
}

Triangle Object3DCanvas::projectionTriangle(Triangle triangle, Vector2 centralPoint, int perspective)
{
    Triangle projected = triangle;
    projected.p1.point2D = calculateProjection(triangle.p1.point3DAfterTransform, centralPoint, perspective);
    projected.p2.point2D = calculateProjection(triangle.p2.point3DAfterTransform, centralPoint, perspective);
    projected.p3.point2D = calculateProjection(triangle.p3.point3DAfterTransform, centralPoint, perspective);
    projected.meanPoint.point2D = calculateProjection(triangle.meanPoint.point3DAfterTransform, centralPoint, perspective);
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
//            if (backfaceCullingTest(object3D->triangles.at(i), observer)) {
                drawTriangleEdgesWithBufferZCheck(qImage, &object3D->triangles.at(i), objectColor, object3D);
//            }
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

double Object3DCanvas::calculateLightOnTriangle(Triangle triangle, Light light)
{
    Vector3 l = Vector3(light.x - triangle.p1.point3DAfterTransform.x, light.y -  triangle.p1.point3DAfterTransform.y, light.z - triangle.p1.point3DAfterTransform.z);
    double cosB = dotProductV3(triangle.normalVector, l) / vectorLength(l);
    double lightForce = std::max((double)0, cosB);
    return lightForce;
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
}

void Object3DCanvas::drawTextured3DObject(QImage *qImage, Object3D *object3D, QImage *texture)
{
    if (!object3D->hideBackSurfaces && object3D->texturingOption) {
        for (int i = 0; i < object3D->triangles.size(); i++) {
            drawTexturedTriangle(qImage, object3D->triangles.at(i), texture);
            if(object3D->sceletonOption) {
                if (objectColor.r == 0 && objectColor.g == 0 && objectColor.b == 0) {
                    drawTriangleEdges(qImage, &object3D->triangles.at(i), RGB(255, 255, 255));
                } else {
                    drawTriangleEdges(qImage, &object3D->triangles.at(i), RGB(0, 0, 0));
                }
            }
        }
    } else if (object3D->texturingOption) {
        for (int i = 0; i < object3D->triangles.size(); i++) {
            if (/*backfaceCullingTest(object3D->triangles.at(i), observer)*/true) {
                if(drawTexturedTriangleWithBufferZCheck(qImage, object3D->triangles.at(i), texture) && object3D->sceletonOption) {
                    if (objectColor.r == 0 && objectColor.g == 0 && objectColor.b == 0) {
                        drawTriangleEdges(qImage, &object3D->triangles.at(i), RGB(255, 255, 255));
                    } else {
                        drawTriangleEdges(qImage, &object3D->triangles.at(i), RGB(0, 0, 0));
                    }
                }
            }
        }
    }
}

bool Object3DCanvas::drawTexturedTriangleWithBufferZCheck(QImage *qImage, Triangle triangle, QImage *texture)
{
    triangle.fillNormalVectorInPoints();

    bool hadBeenSthDrawn = false;
    triangle = sortTrianglePointsByYIn2DPoints(triangle);
    for (int y = (int)triangle.p1.point2D.y; y <= (int)triangle.p2.point2D.y; y++) {
        double x1, x2;
        x1 = calculateLinearInterpolation(triangle.p1.point2D, triangle.p2.point2D, y);
        x2 =  calculateLinearInterpolation(triangle.p1.point2D, triangle.p3.point2D, y);
        double z1, z2;
        z1 = calculateLinearInterpolation(Vector2(triangle.p1.point3DAfterTransform.z, triangle.p1.point2D.y), Vector2(triangle.p2.point3DAfterTransform.z, triangle.p2.point2D.y), y);
        z2 =  calculateLinearInterpolation(Vector2(triangle.p1.point3DAfterTransform.z, triangle.p1.point2D.y), Vector2(triangle.p3.point3DAfterTransform.z, triangle.p3.point2D.y), y);
        hadBeenSthDrawn = drawTexturedHorizontalLineWithBufferZCheck(qImage, triangle, Vector3(x1, y, z1), Vector3(x2, y, z2), texture);
    }
    for (int y = (int)triangle.p2.point2D.y; y <= (int)triangle.p3.point2D.y; y++) {
        double x1, x2;
        x1 =  calculateLinearInterpolation(triangle.p2.point2D, triangle.p3.point2D, y);
        x2 =  calculateLinearInterpolation(triangle.p1.point2D, triangle.p3.point2D, y);
        double z1, z2;
        z1 = calculateLinearInterpolation(Vector2(triangle.p2.point3DAfterTransform.z, triangle.p2.point2D.y), Vector2(triangle.p3.point3DAfterTransform.z, triangle.p3.point2D.y), y);
        z2 =  calculateLinearInterpolation(Vector2(triangle.p1.point3DAfterTransform.z, triangle.p1.point2D.y), Vector2(triangle.p3.point3DAfterTransform.z, triangle.p3.point2D.y), y);
        if (hadBeenSthDrawn)
            drawTexturedHorizontalLineWithBufferZCheck(qImage, triangle, Vector3(x1, y, z1), Vector3(x2, y, z2), texture);
        else
            hadBeenSthDrawn = drawTexturedHorizontalLineWithBufferZCheck(qImage, triangle, Vector3(x1, y, z1), Vector3(x2, y, z2), texture);
    }
    return hadBeenSthDrawn;
}

bool Object3DCanvas::drawTexturedHorizontalLineWithBufferZCheck(QImage *qImage, Triangle triangle, Vector3 start, Vector3 end, QImage *texture)
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
        Vector2 uv = calcBarycentric(triangle, i, start.y);
        RGB color = getTextureColor(texture, uv.x, uv.y);
        if (firstLight.isOn || secondLight.isOn) {
            double light1 = calculateLightOnTriangle(triangle, firstLight);
            double light2 = calculateLightOnTriangle(triangle, secondLight);

            if (firstLight.isOn && secondLight.isOn) color = RGB(color.r * (light1 + light2), color.g * (light1 + light2), color.b * (light1 + light2));
            else if (firstLight.isOn) color = RGB(color.r * light1, color.g * light1, color.b * light1);
            else if (secondLight.isOn) color = RGB(color.r * light2, color.g * light2, color.b * light2);
        }
        if (z < object3D.bufferZ[i][(int)start.y]) {
            if (object3D.smoothingOption) {
                putPixel(qImage, Vector2(i, (int)start.y), color);
            } else {
                putPixel(qImage, Vector2(i, (int)start.y), color);
            }
            object3D.bufferZ[i][(int)start.y] = z;
            update();
            hadBeenSthDrawn = true;
        }
    }
    return hadBeenSthDrawn;
}


void Object3DCanvas::drawTexturedTriangle(QImage *qImage, Triangle triangle, QImage *texture)
{
    triangle.fillNormalVectorInPoints();

    triangle = sortTrianglePointsByYIn2DPoints(triangle);
    for (int y = (int)triangle.p1.point2D.y; y <= (int)triangle.p2.point2D.y; y++) {
        double x1, x2;
        x1 = calculateLinearInterpolation(triangle.p1.point2D, triangle.p2.point2D, y);
        x2 =  calculateLinearInterpolation(triangle.p1.point2D, triangle.p3.point2D, y);
        drawTexturedHorizontalLine(qImage, triangle, Vector2(x1, y), Vector2(x2, y), texture);
    }
    for (int y = (int)triangle.p2.point2D.y; y <= (int)triangle.p3.point2D.y; y++) {
        double x1, x2;
        x1 =  calculateLinearInterpolation(triangle.p2.point2D, triangle.p3.point2D, y);
        x2 =  calculateLinearInterpolation(triangle.p1.point2D, triangle.p3.point2D, y);
        drawTexturedHorizontalLine(qImage, triangle, Vector2(x1, y), Vector2(x2, y), texture);
    }
}

void Object3DCanvas::drawTexturedHorizontalLine(QImage *qImage, Triangle triangle, Vector2 start, Vector2 end, QImage *texture)
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
        Vector2 uv = calcBarycentric(triangle, i, start.y);
        RGB color = getTextureColor(texture, uv.x, uv.y);
        if (firstLight.isOn || secondLight.isOn) {
            double light1 = calculateLightOnTriangle(triangle, firstLight);
            double light2 = calculateLightOnTriangle(triangle, secondLight);

            if (firstLight.isOn && secondLight.isOn) color = RGB(color.r * (light1 + light2), color.g * (light1 + light2), color.b * (light1 + light2));
            else if (firstLight.isOn) color = RGB(color.r * light1, color.g * light1, color.b * light1);
            else if (secondLight.isOn) color = RGB(color.r * light2, color.g * light2, color.b * light2);
        }
        putPixel(qImage, Vector2(i, (int)start.y), color);
        update();
    }
}

RGB Object3DCanvas::getTextureColor(QImage *qImage, double x, double y)
{
    if (x < 0 || y < 0) return RGB(255, 255, 255);
    double r, g, b;
    double a, c;
    Vector2 P1 = Vector2(x, y + 1);
    Vector2 P2 = Vector2(x + 1, y + 1);
    Vector2 P3 = Vector2(x + 1, y);
    Vector2 P4 = Vector2(x, y);
    RGB p1RGB = getPointColor(qImage, P1);
    RGB p2RGB = getPointColor(qImage, P2);
    RGB p3RGB = getPointColor(qImage, P3);
    RGB p4RGB = getPointColor(qImage, P4);
    a = x - (double) P1.x;
    c = y - (double) P4.y;
    r = (double) c * ((1 - a) * p1RGB.r + a * p2RGB.r) + (1 - c) * ((1 - a) * p4RGB.r + a * p3RGB.r);
    g = (double) c * ((1 - a) * p1RGB.g + a * p2RGB.g) + (1 - c) * ((1 - a) * p4RGB.g + a * p3RGB.g);
    b = (double) c * ((1 - a) * p1RGB.b + a * p2RGB.b) + (1 - c) * ((1 - a) * p4RGB.b + a * p3RGB.b);
    return RGB(r, g, b);
}

RGB Object3DCanvas::getPointColor(QImage *qImage, Vector2 point)
{
    if (point.x < 0 || point.y < 0) return RGB(255, 255, 255);
    int r, g, b;
    QColor qColor = qImage->pixel(point.x, point.y);
    qColor.getRgb(&r, &g, &b);
    return RGB(r, g, b);
}

Vector2 Object3DCanvas::calcBarycentric(Triangle t, int x, int y)
{
    Vector2 first = t.p1.point2D;
    Vector2 second = t.p2.point2D;
    Vector2 third = t.p3.point2D;

    float xxa = (x-first.x); // x-xa
    float yya = (y-first.y); // y-ya
    float xcxa = (third.x-first.x); // xc-xa
    float ycya = (third.y-first.y); // yc-ya
    float xbxa = (second.x-first.x); // xb-xa
    float ybya = (second.y-first.y); // yb-ya

    float v = ((xxa*ycya)-(xcxa*yya))/
            ((xbxa*ycya)-(xcxa*ybya));

    float w = ((xbxa*yya)-(xxa*ybya))/
           ((xbxa*ycya)-(xcxa*ybya));

    float u = 1-v-w;

    Vector2 textureFirst = Vector2(0, 0);
    Vector2 textureSecond = Vector2(textureSize.width() - 1, 0);
    Vector2 textureThird = Vector2(0, textureSize.height() - 1);

    float rx = u*textureFirst.x + v*textureSecond.x + w*textureThird.x;
    float ry = u*textureFirst.y + v*textureSecond.y + w*textureThird.y;

    return Vector2((int)rx % (textureSize.width() - 1), (int)ry % (textureSize.height() - 1));
}

void Object3DCanvas::drawTriangle(QImage *qImage, Triangle triangle, RGB color)
{
    double light1 = calculateLightOnTriangle(triangle, firstLight);
    double light2 = calculateLightOnTriangle(triangle, secondLight);

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
    if (firstLight.isOn && secondLight.isOn) {
        calculateDoubleLightOnTriangle(&triangle, firstLight, secondLight);
        color = triangle.meanPoint.color;
    }
    else if (firstLight.isOn) {
        calculateSingleLightOnTriangle(&triangle, firstLight);
        color = triangle.meanPoint.color;
    }
    else if (secondLight.isOn) {
        calculateSingleLightOnTriangle(&triangle, secondLight);
        color = triangle.meanPoint.color;
    }

    bool hadBeenSthDrawn = false;
    triangle = sortTrianglePointsByYIn2DPoints(triangle);
    for (int y = (int)triangle.p1.point2D.y; y <= (int)triangle.p2.point2D.y; y++) {
        double x1, x2;
        x1 = calculateLinearInterpolation(triangle.p1.point2D, triangle.p2.point2D, y);
        x2 =  calculateLinearInterpolation(triangle.p1.point2D, triangle.p3.point2D, y);
        double z1, z2;
        z1 = calculateLinearInterpolation(Vector2(triangle.p1.point3DAfterTransform.z, triangle.p1.point2D.y), Vector2(triangle.p2.point3DAfterTransform.z, triangle.p2.point2D.y), y);
        z2 =  calculateLinearInterpolation(Vector2(triangle.p1.point3DAfterTransform.z, triangle.p1.point2D.y), Vector2(triangle.p3.point3DAfterTransform.z, triangle.p3.point2D.y), y);
        double r1, g1, b1, r2, g2, b2;
        r1 = calculateLinearInterpolation(Vector2(triangle.p1.color.r, triangle.p1.point2D.y), Vector2(triangle.p2.color.r, triangle.p2.point2D.y), y);
        g1 = calculateLinearInterpolation(Vector2(triangle.p1.color.g, triangle.p1.point2D.y), Vector2(triangle.p2.color.g, triangle.p2.point2D.y), y);
        b1 = calculateLinearInterpolation(Vector2(triangle.p1.color.b, triangle.p1.point2D.y), Vector2(triangle.p2.color.b, triangle.p2.point2D.y), y);
        r2 = calculateLinearInterpolation(Vector2(triangle.p1.color.r, triangle.p1.point2D.y), Vector2(triangle.p3.color.r, triangle.p3.point2D.y), y);
        g2 = calculateLinearInterpolation(Vector2(triangle.p1.color.g, triangle.p1.point2D.y), Vector2(triangle.p3.color.g, triangle.p3.point2D.y), y);
        b2 = calculateLinearInterpolation(Vector2(triangle.p1.color.b, triangle.p1.point2D.y), Vector2(triangle.p3.color.b, triangle.p3.point2D.y), y);
        hadBeenSthDrawn = drawHorizontalLineWithBufferZCheck(qImage, Vector3(x1, y, z1), Vector3(x2, y, z2), color, RGB(r1, g1, b1), RGB(r2, g2, b2));
    }
    for (int y = (int)triangle.p2.point2D.y; y <= (int)triangle.p3.point2D.y; y++) {
        double x1, x2;
        x1 =  calculateLinearInterpolation(triangle.p2.point2D, triangle.p3.point2D, y);
        x2 =  calculateLinearInterpolation(triangle.p1.point2D, triangle.p3.point2D, y);
        double z1, z2;
        z1 = calculateLinearInterpolation(Vector2(triangle.p2.point3DAfterTransform.z, triangle.p2.point2D.y), Vector2(triangle.p3.point3DAfterTransform.z, triangle.p3.point2D.y), y);
        z2 =  calculateLinearInterpolation(Vector2(triangle.p1.point3DAfterTransform.z, triangle.p1.point2D.y), Vector2(triangle.p3.point3DAfterTransform.z, triangle.p3.point2D.y), y);
        double r1, g1, b1, r2, g2, b2;
        r1 = calculateLinearInterpolation(Vector2(triangle.p2.color.r, triangle.p2.point2D.y), Vector2(triangle.p3.color.r, triangle.p3.point2D.y), y);
        g1 = calculateLinearInterpolation(Vector2(triangle.p2.color.g, triangle.p2.point2D.y), Vector2(triangle.p3.color.g, triangle.p3.point2D.y), y);
        b1 = calculateLinearInterpolation(Vector2(triangle.p2.color.b, triangle.p2.point2D.y), Vector2(triangle.p3.color.b, triangle.p3.point2D.y), y);
        r2 = calculateLinearInterpolation(Vector2(triangle.p1.color.r, triangle.p1.point2D.y), Vector2(triangle.p3.color.r, triangle.p3.point2D.y), y);
        g2 = calculateLinearInterpolation(Vector2(triangle.p1.color.g, triangle.p1.point2D.y), Vector2(triangle.p3.color.g, triangle.p3.point2D.y), y);
        b2 = calculateLinearInterpolation(Vector2(triangle.p1.color.b, triangle.p1.point2D.y), Vector2(triangle.p3.color.b, triangle.p3.point2D.y), y);
        if (hadBeenSthDrawn)
            drawHorizontalLineWithBufferZCheck(qImage, Vector3(x1, y, z1), Vector3(x2, y, z2), color, RGB(r1, g1, b1), RGB(r2, g2, b2));
        else
            hadBeenSthDrawn = drawHorizontalLineWithBufferZCheck(qImage, Vector3(x1, y, z1), Vector3(x2, y, z2), color, RGB(r1, g1, b1), RGB(r2, g2, b2));
    }
    return hadBeenSthDrawn;
}

bool Object3DCanvas::drawHorizontalLineWithBufferZCheck(QImage *qImage, Vector3 start, Vector3 end, RGB defaultColor, RGB rgb1, RGB rgb2)
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
        double r = calculateLinearInterpolation(Vector2(rgb1.r, start.x), Vector2(rgb2.r, end.x), (double)i);
        double g = calculateLinearInterpolation(Vector2(rgb1.g, start.x), Vector2(rgb2.g, end.x), (double)i);
        double b = calculateLinearInterpolation(Vector2(rgb1.b, start.x), Vector2(rgb2.b, end.x), (double)i);
        if (z < object3D.bufferZ[i][(int)start.y]) {
            if (object3D.smoothingOption) {
                putPixel(qImage, Vector2(i, (int)start.y), RGB(r, g, b));
            } else {
                putPixel(qImage, Vector2(i, (int)start.y), defaultColor);
            }
            object3D.bufferZ[i][(int)start.y] = z;
            update();
            hadBeenSthDrawn = true;
        }
    }
    return hadBeenSthDrawn;
}

void Object3DCanvas::calculateSingleLightOnTriangle(Triangle *triangle, Light light)
{
    applySingleLightForceOnPoint(&triangle->meanPoint, calculateLightForceOnPoint(&triangle->meanPoint, light));
    applySingleLightForceOnPoint(&triangle->p1, calculateLightForceOnPoint(&triangle->p1, light));
    applySingleLightForceOnPoint(&triangle->p2, calculateLightForceOnPoint(&triangle->p2, light));
    applySingleLightForceOnPoint(&triangle->p3, calculateLightForceOnPoint(&triangle->p3, light));
}

void Object3DCanvas::calculateDoubleLightOnTriangle(Triangle *triangle, Light firstLight, Light secondLight)
{
    double firstLightForce = calculateLightForceOnPoint(&triangle->meanPoint, firstLight);
    double secondLightForce = calculateLightForceOnPoint(&triangle->meanPoint, secondLight);
    applyDoubleLightForceOnPoint(&triangle->meanPoint, firstLightForce, secondLightForce);

    firstLightForce = calculateLightForceOnPoint(&triangle->p1, firstLight);
    secondLightForce = calculateLightForceOnPoint(&triangle->p1, secondLight);
    applyDoubleLightForceOnPoint(&triangle->p1, firstLightForce, secondLightForce);

    firstLightForce = calculateLightForceOnPoint(&triangle->p2, firstLight);
    secondLightForce = calculateLightForceOnPoint(&triangle->p2, secondLight);
    applyDoubleLightForceOnPoint(&triangle->p2, firstLightForce, secondLightForce);

    firstLightForce = calculateLightForceOnPoint(&triangle->p3, firstLight);
    secondLightForce = calculateLightForceOnPoint(&triangle->p3, secondLight);
    applyDoubleLightForceOnPoint(&triangle->p3, firstLightForce, secondLightForce);
}

double Object3DCanvas::calculateLightForceOnPoint(BigPoint *point, Light light)
{
    Vector3 l = Vector3(light.x - point->point3DAfterTransform.x, light.y - point->point3DAfterTransform.y, light.z - point->point3DAfterTransform.z);
    double cosB = dotProductV3(point->normalVector, l) / vectorLength(l);
    double lightForce = std::max((double)0, cosB);
    return lightForce;
}

void Object3DCanvas::applySingleLightForceOnPoint(BigPoint *point, double lightForce)
{
    point->color = RGB(point->color.r * lightForce, point->color.g * lightForce, point->color.b * lightForce);
}

void Object3DCanvas::applyDoubleLightForceOnPoint(BigPoint *point, double firstLightForce, double secondLightForce)
{
    double sum = firstLightForce + secondLightForce;
    point->color = RGB(point->color.r * sum, point->color.g * sum, point->color.b * sum);
}
