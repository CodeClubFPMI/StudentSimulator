#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QLabel>
#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFile>
#include <QPushButton>
#include "Game/parametrs.h"
#include "Game/actionbuttons.h"
#include "Game/student.h"
#include "Actions/healthmenu.h"
#include "Actions/energymenu.h"
#include "Actions/educationmenu.h"
#include "Actions/foodmenu.h"
#include "Actions/happinessmenu.h"
#include "Actions/moneymenu.h"

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);

public slots:
    void change_index(int i);

private:
    QVBoxLayout main_layout_;
    QStackedWidget stacked_widget_;
    QHBoxLayout buff_buttons_layout_;

    HealthMenu * health_menu_;
    EnergyMenu * energy_menu_;
    EducationMenu * education_menu_;
    FoodMenu * food_menu_;
    HappinessMenu * happiness_menu_;
    MoneyMenu * money_menu_;
    ActionButtons * action_buttons_widget_;
    Parametrs * parametrs_widget_;
    Student * student_;
};

#endif // GAMEWINDOW_H
