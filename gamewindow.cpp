#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QWidget(parent), main_layout_(this),
    parametrs_layout_(this), stacked_widget_(this), buff_buttons_layout_(this), action_buttons_layout_(this)
{
    //set proportions of parametrs layout
    parametrs_layout_.setColumnStretch(1, 1);
    parametrs_layout_.setColumnStretch(2, 1);
    parametrs_layout_.setColumnStretch(3, 1);
    parametrs_layout_.setColumnStretch(4, 1);
    parametrs_layout_.setRowStretch(1, 1);
    parametrs_layout_.setRowStretch(2, 1);

//    QPushButton *push_but1 = new QPushButton;
    QLabel * health_label = new QLabel;
    health_label->setStyleSheet("QLabel { background-color : red; color : black; }");
    parametrs_layout_.addWidget(health_label, 1, 1);

    QLabel * food_label = new QLabel;
    food_label->setStyleSheet("QLabel { background-color : orange; color : black; }");
    parametrs_layout_.addWidget(food_label, 2, 1);

    QLabel * energy_label = new QLabel;
    energy_label->setStyleSheet("QLabel { background-color : yellow; color : black; }");
    parametrs_layout_.addWidget(energy_label, 1, 2);

    QLabel * study_label = new QLabel;
    study_label->setStyleSheet("QLabel { background-color : green; color : black; }");
    parametrs_layout_.addWidget(study_label, 1, 3);

    QLabel * mood_label = new QLabel;
    mood_label->setStyleSheet("QLabel { background-color : blue; color : black; }");
    parametrs_layout_.addWidget(mood_label, 2, 2);

    QPushButton *push_but2 = new QPushButton;
    QPushButton *push_but3 = new QPushButton;

//    parametrs_layout_.setRowStretch(3, 1);
   // parametrs_layout_.addWidget(health_label, 1, 1);
  //  parametrs_layout_.addWidget(food_label, 2, 1);
   // parametrs_layout_.addWidget(energy_label, 2, 2);
//    parametrs_layout_.setRowMinimumHeight(50, 50);
//    parametrs_layout_.setColumnMinimumWidth(100, 150);
    //parametrs_layout_.setAlignment(push_but1, Qt::Alignment::Ce)
   // parametrs_layout_.
    buff_buttons_layout_.addWidget(push_but2);
    action_buttons_layout_.addWidget(push_but3);

    main_layout_.addLayout(&parametrs_layout_, 1);
    main_layout_.addLayout(&buff_buttons_layout_, 1);
    main_layout_.addWidget(&stacked_widget_, 5);
    main_layout_.addLayout(&action_buttons_layout_, 1);
    setLayout(&main_layout_);
}
