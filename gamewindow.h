#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QLabel>
#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include "parametrs.h"

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);

private:
    QVBoxLayout main_layout_;
    QGridLayout parametrs_layout_;
    QStackedWidget stacked_widget_;
    QHBoxLayout buff_buttons_layout_;
    QHBoxLayout action_buttons_layout_;
    Parametrs * parametrs_widget_;

};

#endif // GAMEWINDOW_H
