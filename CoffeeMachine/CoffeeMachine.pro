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
    mediator.cpp \
    productswindow.cpp \
    recipepanel.cpp \
    recipeseditor.cpp \
    roli.cpp \
    ystanovka_tsen.cpp    

HEADERS += \
    choosingservice.h \
    mainwindow.h \
    mediator.h \
    productswindow.h \
    recipepanel.h \
    recipeseditor.h \
    roli.h \
    ystanovka_tsen.h

FORMS += \
    choosingservice.ui \
    mainwindow.ui \
    productswindow.ui \
    recipepanel.ui \
    recipeseditor.ui \
    roli.ui \
    ystanovka_tsen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
