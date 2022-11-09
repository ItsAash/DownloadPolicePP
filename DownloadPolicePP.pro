QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aria2cpp.cpp \
    home.cpp \
    main.cpp \
    slots.cpp \
    thread.cpp

HEADERS += \
    aria2cpp.h \
    home.h \
    thread.h

FORMS += \
    home.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource/images.qrc \
    resource/qss.qrc

unix|win32: LIBS += -laria2

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/includes/release/ -laria2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/includes/debug/ -laria2
else:unix: LIBS += -L$$PWD/includes/ -laria2

INCLUDEPATH += $$PWD/includes
DEPENDPATH += $$PWD/includes
