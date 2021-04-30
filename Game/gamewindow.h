#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Game/student.h"
#include "Game/foodmenu.h"
#include <QLabel>
#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include "Game/parametrs.h"

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

    Student * student_;
    FoodMenu * food_menu_;
};

#endif // GAMEWINDOW_H
