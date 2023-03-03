QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

greaterThan(QT_MAJOR_VERSION, 4) {
    TARGET_ARCH=$${QT_ARCH}
} else {
    TARGET_ARCH=$${QMAKE_HOST.arch}
}

contains(TARGET_ARCH, x86_64) {
    ARCHITECTURE = x64
}

win32-g++:contains(ARCHITECTURE, x64): {
    INCLUDEPATH += C:/boost/boost_mingw1120_64/include/boost-1_61
    LIBS += "-LC:/boost/boost_mingw1120_64/lib" \
            -llibboost_date_time-mgw49-mt-d-1_61 \
}

SOURCES += \
    combination.cpp \
    main.cpp \
    mainwindow.cpp \
    permuntation.cpp

HEADERS += \
    combination.h \
    mainwindow.h \
    permuntation.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
