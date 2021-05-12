#include "gamewindow.h"
#include "student.h"
#include "foodmenu.h"

#include "Utilities/utilities.h"
GameWindow::GameWindow(Game game_config, QWidget *parent) : QWidget(parent), main_layout_(this),
     stacked_widget_(this), buff_buttons_layout_(this){

    //load widget with parametrs of student
    parametrs_widget_ = new Parametrs;


    // student and menues
    // add game mode choosing
    student_ = new Student(game_config);
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);

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

    //connect all action menues with student
    connect(education_menu_, SIGNAL(SendButtonId(int)), this, SLOT(change_education_parametrs(int)));
    connect(food_menu_, SIGNAL(SendButtonId(int)), this, SLOT(change_food_parametrs(int)));
    connect(energy_menu_, SIGNAL(SendButtonId(int)), this, SLOT(change_energy_parametrs(int)));
    connect(happiness_menu_, SIGNAL(SendButtonId(int)), this, SLOT(change_happiness_parametrs(int)));
    connect(health_menu_, SIGNAL(SendButtonId(int)), this, SLOT(change_health_parametrs(int)));
    connect(money_menu_, SIGNAL(SendButtonId(int)), this, SLOT(change_money_parametrs(int)));

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

    //---------------------------------
    //education_menu_->buttons_[1]->get_button_ptr()->setEnabled(false);
    //---------------------------------

    // student and menues
    // add game mode choosing
    student_ = new Student(game_config);
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
}


void GameWindow::change_index(int i) {
    stacked_widget_.setCurrentIndex(i);
}

void GameWindow::change_education_parametrs(int i) {
    student_->change_education_value_( education_menu_->buttons_[i]->get_education_changes());
    student_->change_energy_value_(education_menu_->buttons_[i]->get_energy_changes());
    student_->change_happiness_value_(education_menu_->buttons_[i]->get_happiness_changes());
    student_->change_money_value_(education_menu_->buttons_[i]->get_money_changes());
    student_->change_food_value_(education_menu_->buttons_[i]->get_food_changes());
    student_->change_health_value_(education_menu_->buttons_[i]->get_health_changes());
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
}

void GameWindow::change_energy_parametrs(int i) {
    student_->change_education_value_( energy_menu_->buttons_[i]->get_education_changes());
    student_->change_energy_value_(energy_menu_->buttons_[i]->get_energy_changes());
    student_->change_happiness_value_(energy_menu_->buttons_[i]->get_happiness_changes());
    student_->change_money_value_(energy_menu_->buttons_[i]->get_money_changes());
    student_->change_food_value_(energy_menu_->buttons_[i]->get_food_changes());
    student_->change_health_value_(energy_menu_->buttons_[i]->get_health_changes());
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
}

void GameWindow::change_food_parametrs(int i) {
    student_->change_education_value_( food_menu_->buttons_[i]->get_education_changes());
    student_->change_energy_value_(food_menu_->buttons_[i]->get_energy_changes());
    student_->change_happiness_value_(food_menu_->buttons_[i]->get_happiness_changes());
    student_->change_money_value_(food_menu_->buttons_[i]->get_money_changes());
    student_->change_food_value_(food_menu_->buttons_[i]->get_food_changes());
    student_->change_health_value_(food_menu_->buttons_[i]->get_health_changes());
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
}

void GameWindow::change_happiness_parametrs(int i) {
    student_->change_education_value_( happiness_menu_->buttons_[i]->get_education_changes());
    student_->change_energy_value_(happiness_menu_->buttons_[i]->get_energy_changes());
    student_->change_happiness_value_(happiness_menu_->buttons_[i]->get_happiness_changes());
    student_->change_money_value_(happiness_menu_->buttons_[i]->get_money_changes());
    student_->change_food_value_(happiness_menu_->buttons_[i]->get_food_changes());
    student_->change_health_value_(happiness_menu_->buttons_[i]->get_health_changes());
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
}

void GameWindow::change_health_parametrs(int i) {
    student_->change_education_value_( health_menu_->buttons_[i]->get_education_changes());
    student_->change_energy_value_(health_menu_->buttons_[i]->get_energy_changes());
    student_->change_happiness_value_(health_menu_->buttons_[i]->get_happiness_changes());
    student_->change_money_value_(health_menu_->buttons_[i]->get_money_changes());
    student_->change_food_value_(health_menu_->buttons_[i]->get_food_changes());
    student_->change_health_value_(health_menu_->buttons_[i]->get_health_changes());
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
}

void GameWindow::change_money_parametrs(int i) {
    student_->change_education_value_( money_menu_->buttons_[i]->get_education_changes());
    student_->change_energy_value_(money_menu_->buttons_[i]->get_energy_changes());
    student_->change_happiness_value_(money_menu_->buttons_[i]->get_happiness_changes());
    student_->change_money_value_(money_menu_->buttons_[i]->get_money_changes());
    student_->change_food_value_(money_menu_->buttons_[i]->get_food_changes());
    student_->change_health_value_(money_menu_->buttons_[i]->get_health_changes());
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
}
