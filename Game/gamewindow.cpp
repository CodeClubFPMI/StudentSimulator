#include "gamewindow.h"
#include "student.h"
#include "foodmenu.h"
#include "Utilities/utilities.h"
GameWindow::GameWindow(Game game_config, QWidget *parent) : QWidget(parent), main_layout_(this),
     stacked_widget_(this), buff_buttons_layout_(this), action_buttons_layout_(this)
{
    //load widget with parametrs of student
    parametrs_widget_ = new Parametrs;

    action_buttons_widget_ = new ActionButtons;

    QPushButton *push_but2 = new QPushButton;

    buff_buttons_layout_.addWidget(push_but2);

    //main_layout_.addLayout(&parametrs_layout_, 1);
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
