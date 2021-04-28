#include "parametrs.h"

Parametrs::Parametrs(QWidget *parent) : QWidget(parent), parametrs_layout_(this)
{
    //set proportions of parametrs layout
    parametrs_layout_.setColumnStretch(1, 1);
    parametrs_layout_.setColumnStretch(2, 1);
    parametrs_layout_.setColumnStretch(3, 1);
    parametrs_layout_.setColumnStretch(4, 1);
    parametrs_layout_.setRowStretch(1, 1);
    parametrs_layout_.setRowStretch(2, 1);
    parametrs_layout_.setRowStretch(3, 1);
//    parametrs_layout_.setRowStretch(4, 1);
//    parametrs_layout_.setRowStretch(5, 1);
//    parametrs_layout_.setRowStretch(6, 1);

    //Set main labels on screen
    health_label = new QLabel;
    health_label->setStyleSheet("QLabel { background-color : red; color : black;  border: 2px solid black;}");
    parametrs_layout_.addWidget(health_label, 1, 1);
    health_label->setText("Health: 15");
    QFont font = health_label->font();
    font.setPointSize(15);
    font.setBold(true);
    health_label->setFont(font);
    health_label->setAlignment(Qt::AlignHCenter);

    food_label = new QLabel;
    food_label->setStyleSheet("QLabel { background-color : orange; color : black; border: 2px solid black; }");
    parametrs_layout_.addWidget(food_label, 3, 1);
    food_label->setText("Food: 10");
    food_label->setFont(font);
    food_label->setAlignment(Qt::AlignHCenter);

    energy_label = new QLabel;
    energy_label->setStyleSheet("QLabel { background-color : yellow; color : black; border: 2px solid black; }");
    parametrs_layout_.addWidget(energy_label, 1, 2);
    energy_label->setText("Energy: 3");
    energy_label->setFont(font);
    energy_label->setAlignment(Qt::AlignHCenter);

    study_label = new QLabel;
    study_label->setStyleSheet("QLabel { background-color : lightblue; color : black; border: 2px solid black; }");
    parametrs_layout_.addWidget(study_label, 1, 3);
    study_label->setText("Studing: 0");
    study_label->setFont(font);
    study_label->setAlignment(Qt::AlignHCenter);

    mood_label = new QLabel;
    mood_label->setStyleSheet("QLabel { background-color : cyan; color : black; border: 2px solid black;}");
    parametrs_layout_.addWidget(mood_label, 3, 2);
    mood_label->setText("Happiness: 322");
    mood_label->setFont(font);
    mood_label->setAlignment(Qt::AlignHCenter);

    money_label = new QLabel;
    money_label->setStyleSheet("QLabel { background-color : green; color : black; border: 2px solid black;}");
    parametrs_layout_.addWidget(money_label, 3, 3);
    money_label->setText("Buks: 300$");
    money_label->setFont(font);
    money_label->setAlignment(Qt::AlignHCenter);
}
