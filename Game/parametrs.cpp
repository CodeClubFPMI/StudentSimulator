#include "parametrs.h"
#include "Utilities/utilities.h"

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
    health_label->setStyleSheet("QLabel { background-color : red;}");
    parametrs_layout_.addWidget(health_label, 1, 1);
    health_label->setText("Health: 15");
    health_label->setAlignment(Qt::AlignHCenter);

    food_label = new QLabel;
    food_label->setStyleSheet("QLabel { background-color : orange;}");
    parametrs_layout_.addWidget(food_label, 3, 1);
    food_label->setText("Food: 10");
    food_label->setAlignment(Qt::AlignHCenter);

    energy_label = new QLabel;
    energy_label->setStyleSheet("QLabel { background-color : yellow;}");
    parametrs_layout_.addWidget(energy_label, 1, 2);
    energy_label->setText("Energy: 3");
    energy_label->setAlignment(Qt::AlignHCenter);

    study_label = new QLabel;
    study_label->setStyleSheet("QLabel { background-color : lightblue;}");
    parametrs_layout_.addWidget(study_label, 1, 3);
    study_label->setText("Eduaction: 0");
    study_label->setAlignment(Qt::AlignHCenter);

    mood_label = new QLabel;
    mood_label->setStyleSheet("QLabel { background-color : cyan;}");
    parametrs_layout_.addWidget(mood_label, 3, 2);
    mood_label->setText("Happiness: 322");
    mood_label->setAlignment(Qt::AlignHCenter);

    money_label = new QLabel;
    money_label->setStyleSheet("QLabel { background-color : lightgreen;}");
    parametrs_layout_.addWidget(money_label, 3, 3);
    money_label->setText("Buks: 300$");
    money_label->setAlignment(Qt::AlignHCenter);



    time_label = new QLabel;
    //time_label->setStyleSheet("QLabel { background-color : cyan;}");
    parametrs_layout_.addWidget(time_label, 1, 4);
    time_label->setText("20/03 14:50");
    time_label->setAlignment(Qt::AlignHCenter);

    semestr_label = new QLabel;
    parametrs_layout_.addWidget(semestr_label, 2, 4);
    semestr_label->setText("2 semestr");
    semestr_label->setAlignment(Qt::AlignHCenter);

    status_label = new QLabel;
    parametrs_layout_.addWidget(status_label, 3, 4);
    status_label->setText("Pozer");
    status_label->setAlignment(Qt::AlignHCenter);

    QLabel * border = new QLabel;
    border->setStyleSheet("QLabel { border: 5px solid red;}");
    parametrs_layout_.addWidget(border, 1, 4, 3, 1);
}
