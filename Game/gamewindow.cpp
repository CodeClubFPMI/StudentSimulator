#include "gamewindow.h"
#include "student.h"
#include "foodmenu.h"
#include "MainMenu/mainwindow.h"
#include <QDebug>

const int kDecreaseParam = -1;
const int kFrequencyParam = 5;

GameWindow::GameWindow(Game game_config, QWidget *parent) : QWidget(parent), main_layout_(this),
     stacked_widget_(this), buff_buttons_layout_(this){

    //load widget with parametrs of student
    parametrs_widget_ = new Parametrs;


    //get style sheets for buttons
    QFile file(":/Styles/MainMenuStyles.css");
    file.open(QFile::ReadOnly);
    stacked_widget_.setStyleSheet(file.readAll());

    //upload all widgets which connects with action buttons
    void_widget_ = new QWidget;
    stacked_widget_.addWidget(void_widget_);
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

    // student and menues
    // add game mode choosing
    student_ = new Student(game_config);

    //create timer for update game time
    timer_ = new QTimer;
    timer_->setInterval(1000);
    connect(timer_, SIGNAL(timeout()), this, SLOT(add_minute()));
    timer_->start();


    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
    menu_buttons::make_buttons_enable(education_menu_->buttons_, student_);
    menu_buttons::make_buttons_enable(energy_menu_->buttons_, student_);
    menu_buttons::make_buttons_enable(food_menu_->buttons_, student_);
    menu_buttons::make_buttons_enable(happiness_menu_->buttons_, student_);
    menu_buttons::make_buttons_enable(health_menu_->buttons_, student_);
    menu_buttons::make_buttons_enable(money_menu_->buttons_, student_);

    //create esc_menu
    esc_menu_ = new EscMenu;

    connect(esc_menu_->but_save_game_, SIGNAL(clicked()), this, SLOT(save_game()));
    connect(esc_menu_->but_back_to_menu_, SIGNAL(clicked()), this, SLOT(back_to_menu_and_save()));
    connect(esc_menu_->but_exit_, SIGNAL(clicked()), this, SLOT(exit_and_save()));



    connect(student_, &Student::death_of_student, this, &GameWindow::student_death);

    auto session_pass=[&](){
    QMessageBox *session_passed = new QMessageBox;
    session_passed->setText("Congratulations! You passed session!");
    QPixmap session;
    session.load(":/images/session_passed.jpg");
    session_passed->setIconPixmap(session);
    session_passed->exec();
    };

    connect(student_, &Student::pass_session, session_pass);

    connect(student_, &Student::student_win, this, &GameWindow::student_win);
}

void GameWindow::change_index(int i) {
    stacked_widget_.setCurrentIndex(i+1);

}

void GameWindow::change_education_parametrs(int i) {
    if (student_->get_money_value() + education_menu_->buttons_[i]->get_money_changes() >= 0){
    student_->change_education_value_( education_menu_->buttons_[i]->get_education_changes());
    student_->change_energy_value_(education_menu_->buttons_[i]->get_energy_changes());
    student_->change_happiness_value_(education_menu_->buttons_[i]->get_happiness_changes());
    student_->change_money_value_(education_menu_->buttons_[i]->get_money_changes());
    student_->change_food_value_(education_menu_->buttons_[i]->get_food_changes());
    student_->change_health_value_(education_menu_->buttons_[i]->get_health_changes());
    student_->change_day_value_(education_menu_->buttons_[i]->get_day_changes());
    student_->change_hour_value_(education_menu_->buttons_[i]->get_hour_changes());
    student_->change_minute_value(education_menu_->buttons_[i]->get_minute_changes());
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
    } else {
        QMessageBox *not_enough_money_notification = new QMessageBox;
        not_enough_money_notification->setText("Not enough money!");
        QPixmap no_money_pix;
        no_money_pix.load(":/images/no_money.jpg");
        not_enough_money_notification->setIconPixmap(no_money_pix);
        not_enough_money_notification->exec();
    }
}

void GameWindow::change_energy_parametrs(int i) {
    if (student_->get_money_value() + energy_menu_->buttons_[i]->get_money_changes() >= 0){
    student_->change_education_value_( energy_menu_->buttons_[i]->get_education_changes());
    student_->change_energy_value_(energy_menu_->buttons_[i]->get_energy_changes());
    student_->change_happiness_value_(energy_menu_->buttons_[i]->get_happiness_changes());
    student_->change_money_value_(energy_menu_->buttons_[i]->get_money_changes());
    student_->change_food_value_(energy_menu_->buttons_[i]->get_food_changes());
    student_->change_health_value_(energy_menu_->buttons_[i]->get_health_changes());
    student_->change_day_value_(energy_menu_->buttons_[i]->get_day_changes());
    student_->change_hour_value_(energy_menu_->buttons_[i]->get_hour_changes());
    student_->change_minute_value(energy_menu_->buttons_[i]->get_minute_changes());
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
    } else {
        QMessageBox *not_enough_money_notification = new QMessageBox;
        not_enough_money_notification->setText("Not enough money!");
        QPixmap no_money_pix;
        no_money_pix.load(":/images/no_money.jpg");
        not_enough_money_notification->setIconPixmap(no_money_pix);
        not_enough_money_notification->exec();
    }
}

void GameWindow::change_food_parametrs(int i) {
    if (student_->get_money_value() + food_menu_->buttons_[i]->get_money_changes() >= 0){
    student_->change_education_value_( food_menu_->buttons_[i]->get_education_changes());
    student_->change_energy_value_(food_menu_->buttons_[i]->get_energy_changes());
    student_->change_happiness_value_(food_menu_->buttons_[i]->get_happiness_changes());
    student_->change_money_value_(food_menu_->buttons_[i]->get_money_changes());
    student_->change_food_value_(food_menu_->buttons_[i]->get_food_changes());
    student_->change_health_value_(food_menu_->buttons_[i]->get_health_changes());
    student_->change_day_value_(food_menu_->buttons_[i]->get_day_changes());
    student_->change_hour_value_(food_menu_->buttons_[i]->get_hour_changes());
    student_->change_minute_value(food_menu_->buttons_[i]->get_minute_changes());
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
    } else {
        QMessageBox *not_enough_money_notification = new QMessageBox;
        not_enough_money_notification->setText("Not enough money!");
        QPixmap no_money_pix;
        no_money_pix.load(":/images/no_money.jpg");
        not_enough_money_notification->setIconPixmap(no_money_pix);
        not_enough_money_notification->exec();
    }
}

void GameWindow::change_happiness_parametrs(int i) {
    if (student_->get_money_value() + happiness_menu_->buttons_[i]->get_money_changes() >= 0){
    student_->change_education_value_( happiness_menu_->buttons_[i]->get_education_changes());
    student_->change_energy_value_(happiness_menu_->buttons_[i]->get_energy_changes());
    student_->change_happiness_value_(happiness_menu_->buttons_[i]->get_happiness_changes());
    student_->change_money_value_(happiness_menu_->buttons_[i]->get_money_changes());
    student_->change_food_value_(happiness_menu_->buttons_[i]->get_food_changes());
    student_->change_health_value_(happiness_menu_->buttons_[i]->get_health_changes());
    student_->change_day_value_(happiness_menu_->buttons_[i]->get_day_changes());
    student_->change_hour_value_(happiness_menu_->buttons_[i]->get_hour_changes());
    student_->change_minute_value(happiness_menu_->buttons_[i]->get_minute_changes());
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
    } else {
        QMessageBox *not_enough_money_notification = new QMessageBox;
        not_enough_money_notification->setText("Not enough money!");
        QPixmap no_money_pix;
        no_money_pix.load(":/images/no_money.jpg");
        not_enough_money_notification->setIconPixmap(no_money_pix);
        not_enough_money_notification->exec();
    }
}

void GameWindow::change_health_parametrs(int i) {
    if (student_->get_money_value() + health_menu_->buttons_[i]->get_money_changes() >= 0){
    student_->change_education_value_( health_menu_->buttons_[i]->get_education_changes());
    student_->change_energy_value_(health_menu_->buttons_[i]->get_energy_changes());
    student_->change_happiness_value_(health_menu_->buttons_[i]->get_happiness_changes());
    student_->change_money_value_(health_menu_->buttons_[i]->get_money_changes());
    student_->change_food_value_(health_menu_->buttons_[i]->get_food_changes());
    student_->change_health_value_(health_menu_->buttons_[i]->get_health_changes());
    student_->change_day_value_(health_menu_->buttons_[i]->get_day_changes());
    student_->change_hour_value_(health_menu_->buttons_[i]->get_hour_changes());
    student_->change_minute_value(health_menu_->buttons_[i]->get_minute_changes());
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
    } else {
        QMessageBox *not_enough_money_notification = new QMessageBox;
        not_enough_money_notification->setText("Not enough money!");
        QPixmap no_money_pix;
        no_money_pix.load(":/images/no_money.jpg");
        not_enough_money_notification->setIconPixmap(no_money_pix);
        not_enough_money_notification->exec();
    }
}

void GameWindow::change_money_parametrs(int i) {
    student_->change_education_value_( money_menu_->buttons_[i]->get_education_changes());
    student_->change_energy_value_(money_menu_->buttons_[i]->get_energy_changes());
    student_->change_happiness_value_(money_menu_->buttons_[i]->get_happiness_changes());
    student_->change_money_value_(money_menu_->buttons_[i]->get_money_changes());
    student_->change_food_value_(money_menu_->buttons_[i]->get_food_changes());
    student_->change_health_value_(money_menu_->buttons_[i]->get_health_changes());
    student_->change_day_value_(money_menu_->buttons_[i]->get_day_changes());
    student_->change_hour_value_(money_menu_->buttons_[i]->get_hour_changes());
    student_->change_minute_value(money_menu_->buttons_[i]->get_minute_changes());
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
}

void GameWindow::add_minute(){
    student_->change_minute_value(-kDecreaseParam);
    student_->change_education_value_(kDecreaseParam);

    if (!(student_->get_time().minute() % kFrequencyParam)){
        student_->change_energy_value_(kDecreaseParam);
        student_->change_food_value_(kDecreaseParam);
        student_->change_happiness_value_(kDecreaseParam);
        student_->change_health_value_(kDecreaseParam);
    }
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
}

Student* GameWindow::get_student_ptr(){
    return student_;
}

void GameWindow::keyPressEvent(QKeyEvent *event){
   // int key = event->key();
    if (event->key() == Qt::Key_Escape) {
        esc_menu_->setHidden(!(esc_menu_->isHidden()));
    }
}

void GameWindow::save_game(){
    SaveGame save;
    save.save_game_to_JSON(student_);
}

void GameWindow::back_to_menu_and_save(){
    SaveGame save;
    save.save_game_to_JSON(student_);
    esc_menu_->close();
    dynamic_cast<MainWindow *>(this->parentWidget())->stacked_widget_.setCurrentIndex(0);
}

void GameWindow::exit_and_save(){
    SaveGame save;
    save.save_game_to_JSON(student_);
    esc_menu_->close();
    dynamic_cast<MainWindow *>(this->parentWidget())->close();
}

void GameWindow::student_death(QString cause_of_death){
    QMessageBox *death_notification = new QMessageBox;
    death_notification->setText("You lose :c");
    death_notification->setInformativeText(cause_of_death);
    QPixmap message_pix;
    data_update::refresh_parameters_on_window(parametrs_widget_, student_);
    if (cause_of_death == "You starved to death."){
        message_pix.load(":/images/hunger.jpg");
    }
    if (cause_of_death == "You died of lack of sleep."){
        message_pix.load(":/images/sleep.jpg");
    }
    if (cause_of_death == "Your heart has stopped."){
        message_pix.load(":/images/heart.jpg");
    }
    if(cause_of_death == "You died of depression."){
        message_pix.load(":/images/depression.jpg");
    }
    if (cause_of_death == "You have been expelled."){
        message_pix.load(":/images/razmysel.jpg");
    }
    timer_->stop();
    death_notification->setIconPixmap(message_pix);
    death_notification->exec();
    data_update::make_statistic(student_);
    dynamic_cast<MainWindow *>(this->parentWidget())->stacked_widget_.setCurrentIndex(0);
    dynamic_cast<MainWindow *>(this->parentWidget())->statistic_->refresh_statistic();
    dynamic_cast<MainWindow *>(this->parentWidget())->stacked_widget_.removeWidget(this);
}

void GameWindow::student_win(){
    QMessageBox *end_game = new QMessageBox;
    end_game->setText("Congratulations! You win!");
    QPixmap end_game_pix;
    end_game_pix.load(":/images/win.jpg");
    end_game->setIconPixmap(end_game_pix);
    timer_->stop();
    end_game->exec();
    data_update::make_statistic(student_);
    dynamic_cast<MainWindow *>(this->parentWidget())->stacked_widget_.setCurrentIndex(0);
    dynamic_cast<MainWindow *>(this->parentWidget())->statistic_->refresh_statistic();
    dynamic_cast<MainWindow *>(this->parentWidget())->stacked_widget_.removeWidget(this);
}
