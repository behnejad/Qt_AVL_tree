#-------------------------------------------------
#
# Project created by QtCreator 2013-12-27T08:07:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app
RC_ICONS = 1.ico

SOURCES += main.cpp\
        widget.cpp \
    struct.cpp

HEADERS  += widget.h \
    node.h \
    struct.h \
    global.h \
    copy.h

OTHER_FILES += \
    node.py

RESOURCES += \
    images.qrc

FORMS += \
    form.ui

#RC_FILE = images.rc
#CONFIG += static embed_manifest_exe

#LIBS += E:\Qt5.2.0\5.2.0\mingw48_32\lib\libQt5Widgetsd.a \
#	    E:\Qt5.2.0\5.2.0\mingw48_32\lib\libQt5Guid.a \
#	    E:\Qt5.2.0\5.2.0\mingw48_32\lib\libQt5Cored.a

#CONFIG += static
#static {
#    CONFIG += static
#    QTPLUGIN += qsqloci qgif
#    DEFINES += STATIC
#    message("Static build.")
#}

#win32: LIBS += -lsupc++
#win32: LIBS += -lgcc_eh
#win32: LIBS += -lgcc
#win32: LIBS += -lgcc_s
#win32: LIBS += -lQt5Cored
#win32: LIBS += -lQt5Guid
#win32: LIBS += -lQt5Widgetsd
#win32: LIBS += -lQt5Core
#win32: LIBS += -lQt5Gui
#win32: LIBS += -lQt5Widgets
#win32: LIBS += -lstdc++
#win32: LIBS += -llibstdc++
