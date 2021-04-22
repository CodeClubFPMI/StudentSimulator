#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include "settings.h"
#include "mainmenu.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QStackedWidget stacked_widget_;
    MainMenu * main_menu_;
    Settings * settings_;
};
#endif // MAINWINDOW_H
