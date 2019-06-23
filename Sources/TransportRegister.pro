#-------------------------------------------------
#
# Project created by QtCreator 2017-02-16T13:28:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TransportRegister
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


SOURCES += main.cpp\
        transportregisterwindow.cpp \
    bus.cpp \
    companycar.cpp \
    companyvan.cpp \
    motorbike.cpp \
    privatecar.cpp \
    privatevan.cpp \
    vehicle.cpp \
    companyvehicle.cpp \
    privatevehicle.cpp \
    transportregister.cpp \
    addpcardialog.cpp \
    deldialog.cpp \
    addpvandialog.cpp \
    addmbikedialog.cpp \
    addccardialog.cpp \
    addcvandialog.cpp \
    addbusdialog.cpp \
    editbusdialog.cpp \
    editccardialog.cpp \
    editcvandialog.cpp \
    editmbikedialog.cpp \
    editpvandialog.cpp \
    editpcardialog.cpp \
    about.cpp \
    fileexport.cpp \
    login.cpp

HEADERS  += transportregisterwindow.h \
    bus.h \
    companycar.h \
    companyvan.h \
    motorbike.h \
    privatecar.h \
    privatevan.h \
    vehicle.h \
    companyvehicle.h \
    privatevehicle.h \
    transportregister.h \
    addpcardialog.h \
    deldialog.h \
    addpvandialog.h \
    addmbikedialog.h \
    addccardialog.h \
    addcvandialog.h \
    addbusdialog.h \
    editbusdialog.h \
    editccardialog.h \
    editcvandialog.h \
    editmbikedialog.h \
    editpvandialog.h \
    editpcardialog.h \
    about.h \
    fileexport.h \
    login.h

FORMS    += transportregisterwindow.ui \
    addpcardialog.ui \
    deldialog.ui \
    addpvandialog.ui \
    addmbikedialog.ui \
    addccardialog.ui \
    addcvandialog.ui \
    addbusdialog.ui \
    editbusdialog.ui \
    editccardialog.ui \
    editcvandialog.ui \
    editmbikedialog.ui \
    editpvandialog.ui \
    editpcardialog.ui \
    about.ui \
    fileexport.ui \
    login.ui

DISTFILES += \
    ../tr.png

RESOURCES += \
    logo.qrc
# ICON
RC_ICONS = tr-ico.ico
