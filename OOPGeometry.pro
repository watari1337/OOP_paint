QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = OOPGeometry
CONFIG += import_lib
DEFINES += \
    FACTORY_LIBRARY \
    MOVE_LIBRARY
QMAKE_LFLAGS += -Wl,--out-implib,lib$${TARGET}.a

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    car.cpp \
    circle.cpp \
    drawwidget.cpp \
    factory.cpp \
    helicopter.cpp \
    main.cpp \
    mainwindow.cpp \
    moving.cpp \
    rectangle.cpp \
    saveloadfiles.cpp \
    shape.cpp

HEADERS += \
    car.h \
    circle.h \
    drawwidget.h \
    factory.h \
    helicopter.h \
    mainwindow.h \
    moving.h \
    rectangle.h \
    saveloadfiles.h \
    shape.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    basePath.pri
