QT       += core xml xmlpatterns network

TARGET = libcommon
TEMPLATE = lib

SOURCES += \
    filelist.cpp \
    modinfo.cpp \
    hash.cpp \
    handler.cpp \
    savage2.cxx

HEADERS += \
    filelist.h \
    modinfo.h \
    hash.h \
    handler.h \
    savage2.hxx

RESOURCES += \
    resources.qrc
