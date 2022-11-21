QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



CONFIG += c++11

CONFIG += qaxcontainer QT += axcontainer

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0





SOURCES += \
    battlewidget_1.cpp \
    callcardwidget.cpp \
    cardlabel.cpp \
    cardshowwigdet.cpp \
    cardwidget.cpp \
    gameguidepage.cpp \
    gameguidepage_adventure.cpp \
    gameguidepage_adventure_map.cpp \
    gameguidepage_story.cpp \
    gamestoryscene.cpp \
    iconlabel.cpp \
    main.cpp \
    mainwindow.cpp \
    mystyle.cpp \
    paintlabel.cpp \
    player.cpp \
    readexcel.cpp \
    readtxt.cpp \
    returnbutton.cpp \
    scenelabel.cpp \
    talkshowauto.cpp

HEADERS += \
    battlewidget_1.h \
    callcardwidget.h \
    cardlabel.h \
    cardshowwigdet.h \
    cardwidget.h \
    gameguidepage.h \
    gameguidepage_adventure.h \
    gameguidepage_adventure_map.h \
    gameguidepage_story.h \
    gamestoryscene.h \
    iconlabel.h \
    mainwindow.h \
    mystyle.h \
    paintlabel.h \
    player.h \
    readexcel.h \
    readtxt.h \
    returnbutton.h \
    scenelabel.h \
    talkshowauto.h

FORMS += \
    mainwindow.ui

CONFIG += resources_big
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    text.qrc

RC_ICONS = widgetIcon.ico

QT +=core gui sql
QT +=sql
