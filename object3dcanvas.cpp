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
    object3D.print();
    //    draw3DObject();
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
