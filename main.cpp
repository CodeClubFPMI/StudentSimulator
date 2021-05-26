#include "MainMenu\mainwindow.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    //Upload css to game window
    QFile file(":/Styles/MainMenuStyles.css");
    file.open(QFile::ReadOnly);
    window.setStyleSheet(file.readAll());
    window.show();
    return app.exec();
}
