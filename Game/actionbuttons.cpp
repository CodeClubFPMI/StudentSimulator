#include "actionbuttons.h"

ActionButtons::ActionButtons(QWidget *parent) : QWidget(parent), action_buttons_layout_(this)
{
    mapper = new QSignalMapper();
    //create action buttons and add to layout
    health_button_ = new QPushButton;
    health_button_->setText("Health");
    health_button_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    health_button_->setStyleSheet("QPushButton:hover { background-color : red;}");
    action_buttons_layout_.addWidget(health_button_, 1);

    energy_button_ = new QPushButton;
    energy_button_->setText("Energy");
    energy_button_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    energy_button_->setStyleSheet("QPushButton:hover { background-color : yellow;}");
    action_buttons_layout_.addWidget(energy_button_, 1);

    education_button_ = new QPushButton;
    education_button_->setText("Education");
    education_button_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    education_button_->setStyleSheet("QPushButton:hover { background-color : lightblue;}");
    action_buttons_layout_.addWidget(education_button_, 1);

    food_button_ = new QPushButton;
    food_button_->setText("Food");
    food_button_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    food_button_->setStyleSheet("QPushButton:hover { background-color : orange;}");
    action_buttons_layout_.addWidget(food_button_, 1);

    happiness_button_ = new QPushButton;
    happiness_button_->setText("Happiness");
    happiness_button_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    happiness_button_->setStyleSheet("QPushButton:hover { background-color : cyan;}");
    action_buttons_layout_.addWidget(happiness_button_, 1);

    money_button_ = new QPushButton;
    money_button_->setText("Money");
    money_button_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    money_button_->setStyleSheet("QPushButton:hover { background-color : lightgreen;}");
    action_buttons_layout_.addWidget(money_button_, 1);

    //connects which change action buttons
    connect(health_button_, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(health_button_, 0);

    connect(energy_button_, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(energy_button_, 1);

    connect(education_button_, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(education_button_, 2);

    connect(food_button_, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(food_button_, 3);

    connect(happiness_button_, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(happiness_button_, 4);

    connect(money_button_, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(money_button_, 5);

    connect(mapper, SIGNAL(mappedInt(int)), this, SIGNAL(GoToExit(int)));

}
