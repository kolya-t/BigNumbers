QT += core
QT -= gui

CONFIG += c++11

TARGET = BigNumbers
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    huge.cpp

HEADERS += \
    list.h \
    huge.h
