QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += PRO_FILE_PWD=$$sprintf("\"\\\"%1\\\"\"", $$_PRO_FILE_PWD_)

SOURCES += \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    settings.cpp \
    student.cpp \
    statistic.cpp \

HEADERS += \
    mainmenu.h \
    mainwindow.h \
    settings.h \
    student.h \
    statistic.h \


FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
