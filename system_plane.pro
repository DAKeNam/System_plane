#-------------------------------------------------
#
# Project created by QtCreator 2017-02-23T18:01:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = system_plane
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
        mainwindow.cpp \
    planewindow.cpp \
    plane.cpp \
    planeUtil.cpp \
    ticket.cpp \
    User.cpp \
    dialog_ip_plane.cpp \
    res.cpp \
    dialog_ed_plane.cpp \
    dialog_user.cpp \
    dialog_ticket.cpp \
    dialog_information.cpp

HEADERS  += mainwindow.h \
    planewindow.h \
    plane.h \
    planeUtil.h \
    ticket.h \
    User.h \
    dialog_ip_plane.h \
    res.h \
    dialog_ed_plane.h \
    dialog_user.h \
    dialog_ticket.h \
    dialog_information.h

FORMS    += mainwindow.ui \
    planewindow.ui \
    dialog_ip_plane.ui \
    dialog_ed_plane.ui \
    dialog_user.ui \
    dialog_ticket.ui \
    dialog_information.ui
