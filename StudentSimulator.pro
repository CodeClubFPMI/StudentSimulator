QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += PRO_FILE_PWD=$$sprintf("\"\\\"%1\\\"\"", $$_PRO_FILE_PWD_)

SOURCES += \
    Game/Actions/educationmenu.cpp \
    Game/Actions/energymenu.cpp \
    Game/Actions/happinessmenu.cpp \
    Game/Actions/healthmenu.cpp \
    Game/Actions/moneymenu.cpp \
    Utilities/JSONparser.cpp \
    Utilities/button.cpp \
    Game/Actions/foodmenu.cpp \
    Game/gamewindow.cpp \
    main.cpp \
    MainMenu/mainmenu.cpp \
    MainMenu/mainwindow.cpp \
    Game/parametrs.cpp \
    Utilities/savegame.cpp \
    MainMenu/settings.cpp \
    Game/student.cpp \
    MainMenu/statistic.cpp \
    Utilities/utilities.cpp

HEADERS += \
    Game/Actions/educationmenu.h \
    Game/Actions/energymenu.h \
    Game/Actions/happinessmenu.h \
    Game/Actions/healthmenu.h \
    Game/Actions/moneymenu.h \
    Utilities/JSONparser.h \
    Utilities/button.h \
    Game/Actions/foodmenu.h \
    Game/gamewindow.h \
    MainMenu/mainmenu.h \
    MainMenu/mainwindow.h \
    Game/parametrs.h \
    Utilities/savegame.h \
    MainMenu/settings.h \
    Game/student.h \
    MainMenu/statistic.h \
    Utilities/utilities.h


FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
