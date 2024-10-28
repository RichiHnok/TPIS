QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choosingservice.cpp \
    main.cpp \
    mainwindow.cpp \
    recipepanel.cpp \
    recipeseditor.cpp \
    servicewindows.cpp

HEADERS += \
    choosingservice.h \
    mainwindow.h \
    recipepanel.h \
    recipeseditor.h \
    servicewindows.h

FORMS += \
    choosingservice.ui \
    mainwindow.ui \
    recipepanel.ui \
    recipeseditor.ui \
    servicewindows.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
