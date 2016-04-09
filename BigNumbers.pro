QT += core
QT -= gui

CONFIG += c++11

TARGET = BigNumbers
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    bignumber.cpp \
    huge.cpp

HEADERS += \
    bignumber.h \
    list.h \
    huge.h
