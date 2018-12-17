QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = triangle
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h \
    Plane.h \
    Triangle.h \
    Vector3D.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    Triangle.cpp \
    Vector3D.cpp
