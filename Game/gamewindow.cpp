#include "gamewindow.h"
#include "student.h"
#include "foodmenu.h"

#include "Utilities/utilities.h"
GameWindow::GameWindow(Game game_config, QWidget *parent) : QWidget(parent), main_layout_(this),
     stacked_widget_(this), buff_buttons_layout_(this){

    //load widget with parametrs of student
    parametrs_widget_ = new Parametrs;

    //get style sheets for buttons
    QFile file(":/Styles/MainMenuStyles.css");
    file.open(QFile::ReadOnly);
    stacked_widget_.setStyleSheet(file.readAll());

    //upload all widgets which connects with action buttons
    health_menu_ = new HealthMenu;
    stacked_widget_.addWidget(health_menu_);
    energy_menu_ = new EnergyMenu;
    stacked_widget_.addWidget(energy_menu_);
    education_menu_ = new EducationMenu;
    stacked_widget_.addWidget(education_menu_);
    food_menu_ = new FoodMenu;
    stacked_widget_.addWidget(food_menu_);
    happiness_menu_ = new HappinessMenu;
    stacked_widget_.addWidget(happiness_menu_);

    money_menu_ = new MoneyMenu;
    stacked_widget_.addWidget(money_menu_);


    //connect to change action buttons

    action_buttons_widget_ = new ActionButtons;

    connect(action_buttons_widget_, SIGNAL(GoToExit(int)), this, SLOT(change_index(int)));


    QPushButton *push_but2 = new QPushButton;

    buff_buttons_layout_.addWidget(push_but2);

    main_layout_.addWidget(parametrs_widget_, 1);
    main_layout_.addLayout(&buff_buttons_layout_, 1);
    main_layout_.addWidget(&stacked_widget_, 5);
    main_layout_.addWidget(action_buttons_widget_, 1);
    setLayout(&main_layout_);

    // student and menues
    // add game mode choosing
    student_ = new Student(game_config);
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
}


void GameWindow::change_index(int i) {
    stacked_widget_.setCurrentIndex(i);
}
