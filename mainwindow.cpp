#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), vertical_layout(this), up_horizontal_layout(this),
      down_horizontal_layout(this), stacked_widget(this)

{
    resize(800, 790);
    vertical_layout.addLayout(&up_horizontal_layout, 1);
    vertical_layout.addWidget(&stacked_widget, 3);
    vertical_layout.addLayout(&down_horizontal_layout, 1);
}

MainWindow::~MainWindow()
{
}

