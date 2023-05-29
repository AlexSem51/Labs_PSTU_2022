QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BinarySearchTree
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderarea.cpp \
    bst_properties_window.cpp

HEADERS  += mainwindow.h \
    binarysearchtree.h \
    renderarea.h \
    bst_properties_window.h

FORMS    +=
