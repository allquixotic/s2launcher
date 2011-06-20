QT       += core gui xml webkit

TARGET = s2launcher
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += ../common

LIBS += ../common/libcommon.so

PRE_TARGETDEPS += ../common/libcommon.so
