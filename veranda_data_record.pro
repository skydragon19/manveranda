#-------------------------------------------------
#
# Project created by QtCreator 2015-04-22T16:04:12
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = veranda_data_record
TEMPLATE = app

OBJECTS_DIR = compile
MOC_DIR = compile

SOURCES += main.cpp\
    view/mainwindow.cpp \
    model/setting.cpp \
    model/database.cpp \
    controller/worker.cpp \
    model/util_skyw.cpp \
    model/parsing_fuction.cpp \
    model/get_db.cpp \
    model/save_db.cpp

HEADERS  += \
    view/mainwindow.h \
    model/setting.h \
    utils/utama.h \
    model/database.h \
    controller/worker.h \
    model/util_skyw.h \
    model/parsing_fuction.h \
    model/get_db.h \
    model/save_db.h

FORMS    += \
    view/mainwindow.ui
