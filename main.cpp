#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}