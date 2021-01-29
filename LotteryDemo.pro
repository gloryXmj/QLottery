# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = LotteryDemo
CONFIG(debug,debug|release):DESTDIR = ../Win32/Debug
CONFIG(release,debug|release):DESTDIR = ../Win32/Release

QT += core widgets gui
DEFINES += WIN64 QT_DLL QT_WIDGETS_LIB

win32:CONFIG(debug,debug|release):CONFIG += console

win32:CONFIG(debug,debug|release):QMAKE_CXXFLAGS += -gstabs+

INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles


HEADERS += ./lotterydemo.h \
    messagewidget.h \
    qDebug2Logcat.h
SOURCES += ./main.cpp \
    ./lotterydemo.cpp \
    messagewidget.cpp \
    qDebug2Logcat.cpp
FORMS += ./lotterydemo.ui \
    messagewidget.ui


RESOURCES += lotterydemo.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

