#include "gamewindow.h"
#include "student.h"
#include "foodmenu.h"
GameWindow::GameWindow(QWidget *parent) : QWidget(parent), main_layout_(this),
    parametrs_layout_(this), stacked_widget_(this), buff_buttons_layout_(this), action_buttons_layout_(this)
{
    //load widget with parametrs of student
    parametrs_widget_ = new Parametrs;
    QPushButton *push_but2 = new QPushButton;
    QPushButton *push_but3 = new QPushButton;

    buff_buttons_layout_.addWidget(push_but2);
    action_buttons_layout_.addWidget(push_but3);

    //main_layout_.addLayout(&parametrs_layout_, 1);
    main_layout_.addWidget(parametrs_widget_, 1);
    main_layout_.addLayout(&buff_buttons_layout_, 1);
    main_layout_.addWidget(&stacked_widget_, 5);
    main_layout_.addLayout(&action_buttons_layout_, 1);
    setLayout(&main_layout_);

    // student and menues
    // add game mode choosing
    //student_ = new Student(Game::NEW_GAME);

    //food_menu_ = new FoodMenu;

   // connect(food_menu_, &FoodMenu::raise_food_value_, student_,
     //       &Student::raise_food_value_);

}
