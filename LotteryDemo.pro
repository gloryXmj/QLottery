# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = LotteryDemo
DESTDIR = ../Win32/Debug
QT += core widgets gui
CONFIG += debug
DEFINES += WIN64 QT_DLL QT_WIDGETS_LIB

QMAKE_CXXFLAGS += -gstabs+

INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles


HEADERS += ./lotterydemo.h \
    PopWidget.h
SOURCES += ./main.cpp \
    ./lotterydemo.cpp \
    PopWidget.cpp
FORMS += ./lotterydemo.ui \
    PopWidget.ui


RESOURCES += lotterydemo.qrc