TEMPLATE = app

#QT += qml quick widgets
QT += qml quick positioning multimedia location widgets

SOURCES += main.cpp

RESOURCES += qml.qrc \
    res.qrc \
    res.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

CONFIG += c++11

OTHER_FILES += / *.qml \
    QChart/* \
    res/*
