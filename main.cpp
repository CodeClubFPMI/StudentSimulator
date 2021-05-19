#include "MainMenu\mainwindow.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    //Upload css to game window
    //window.setStyleSheet("border-image: url(D:/van.jpg) 0 0 0 0 stretch stretch");
    QFile file(":/Styles/MainMenuStyles.css");
    file.open(QFile::ReadOnly);
    window.setStyleSheet(file.readAll());
    window.show();
    return app.exec();
}
