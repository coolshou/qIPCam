#-------------------------------------------------
#
# Project created by QtCreator 2017-11-19T16:27:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webenginewidgets

TARGET = qIPCam
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp \
    src/vlcplayer.cpp \
    src/EqualizerDialog.cpp \
    src/controlpanel.cpp \
    src/editcamera.cpp \
    src/viewform.cpp

HEADERS += \
        src/mainwindow.h \
    src/vlcplayer.h \
    src/EqualizerDialog.h \
    src/controlpanel.h \
    src/editcamera.h \
    src/viewform.h

FORMS += \
        src/mainwindow.ui \
    src/vlcplayer.ui \
    src/EqualizerDialog.ui \
    src/controlpanel.ui \
    src/editcamera.ui \
    src/viewform.ui

DISTFILES += \
    qIPCam.desktop

RESOURCES += \
    qipcam.qrc



# Edit below for custom library location
LIBS       += -L./vlc-qt/lib -lVLCQtCore -lVLCQtWidgets
INCLUDEPATH += ./vlc-qt/include
