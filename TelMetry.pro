QT       += core gui sql charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    dane.cpp \
    dialogchoose.cpp \
    dialogplot.cpp \
    digit.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    about.h \
    dane.h \
    dialogchoose.h \
    dialogplot.h \
    digit.h \
    mainwindow.h

FORMS += \
    about.ui \
    dialogchoose.ui \
    dialogplot.ui \
    mainwindow.ui

TRANSLATIONS += \
    TelMetry_pl_PL.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
