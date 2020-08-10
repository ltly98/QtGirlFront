#-------------------------------------------------
#
# Project created by QtCreator 2019-06-30T18:07:08
#
#-------------------------------------------------

QT       += core gui
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GirlFront1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        dialog_about.cpp \
        dialog_add_effect.cpp \
        dialog_add_equip.cpp \
        dialog_add_goblin.cpp \
        dialog_add_skill.cpp \
        dialog_command.cpp \
        dialog_delete.cpp \
        dialog_effect.cpp \
        dialog_equip.cpp \
        dialog_goblin.cpp \
        dialog_login.cpp \
        dialog_new.cpp \
        dialog_select.cpp \
        dialog_sign.cpp \
        dialog_skill.cpp \
        dialog_update.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        dialog_about.h \
        dialog_add_effect.h \
        dialog_add_equip.h \
        dialog_add_goblin.h \
        dialog_add_skill.h \
        dialog_command.h \
        dialog_delete.h \
        dialog_effect.h \
        dialog_equip.h \
        dialog_goblin.h \
        dialog_login.h \
        dialog_new.h \
        dialog_select.h \
        dialog_sign.h \
        dialog_skill.h \
        dialog_update.h \
        mainwindow.h

FORMS += \
        dialog_about.ui \
        dialog_add_effect.ui \
        dialog_add_equip.ui \
        dialog_add_goblin.ui \
        dialog_add_skill.ui \
        dialog_command.ui \
        dialog_delete.ui \
        dialog_effect.ui \
        dialog_equip.ui \
        dialog_goblin.ui \
        dialog_login.ui \
        dialog_new.ui \
        dialog_select.ui \
        dialog_sign.ui \
        dialog_skill.ui \
        dialog_update.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
