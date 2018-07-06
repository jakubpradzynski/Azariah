#-------------------------------------------------
#
# Project created by QtCreator 2018-07-04T22:53:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = azariah
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        object3dwindow.cpp \
        object3dcanvas.cpp \
        bigpoint.cpp \
        light.cpp \
        matrix.cpp \
        rgb.cpp \
        triangle.cpp \
        vector2.cpp \
        vector3.cpp \
        object3d.cpp

HEADERS += \
        mainwindow.h \
        object3dwindow.h \
        object3dcanvas.h \
        bigpoint.h \
        light.h \
        matrix.h \
        rgb.h \
        triangle.h \
        vector2.h \
        vector3.h \
        object3d.h

FORMS += \
        mainwindow.ui \
        object3dwindow.ui
