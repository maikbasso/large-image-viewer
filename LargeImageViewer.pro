QT += core
QT -= gui

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11 -lopencv_imgproc

TARGET = LargeImageViewer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    largeimageviewer.cpp

LIBS += `pkg-config opencv --libs`

HEADERS += \
    largeimageviewer.h
