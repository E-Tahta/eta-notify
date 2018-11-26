TEMPLATE = app

QT += qml quick core

CONFIG += c++11

SOURCES += src/main.cpp \
    src/bridge.cpp \
    src/singleinstance.cpp \
    src/argumentparser.cpp

HEADERS += src/bridge.h \
    src/singleinstance.h \
    src/argumentparser.h

RESOURCES += qml.qrc

DEFINES += QT_DEPRECATED_WARNINGS

TARGET = eta-notify

target.path = /usr/bin/

INSTALLS += target

