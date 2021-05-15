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

    //Set main labels on screen
    health_label = new QLabel;
    health_label->setStyleSheet("QLabel { background-color : red;}");
    parametrs_layout_.addWidget(health_label, 1, 1);
    health_label->setAlignment(Qt::AlignHCenter);

    food_label = new QLabel;
    food_label->setStyleSheet("QLabel { background-color : orange;}");
    parametrs_layout_.addWidget(food_label, 3, 1);
    food_label->setAlignment(Qt::AlignHCenter);

    energy_label = new QLabel;
    energy_label->setStyleSheet("QLabel { background-color : yellow;}");
    parametrs_layout_.addWidget(energy_label, 1, 2);
    energy_label->setAlignment(Qt::AlignHCenter);

    education_label = new QLabel;
    education_label->setStyleSheet("QLabel { background-color : lightblue;}");
    parametrs_layout_.addWidget(education_label, 1, 3);
    education_label->setAlignment(Qt::AlignHCenter);

    happiness_label = new QLabel;
    happiness_label->setStyleSheet("QLabel { background-color : cyan;}");
    parametrs_layout_.addWidget(happiness_label, 3, 2);
    happiness_label->setAlignment(Qt::AlignHCenter);

    money_label = new QLabel;
    money_label->setStyleSheet("QLabel { background-color : lightgreen;}");
    parametrs_layout_.addWidget(money_label, 3, 3);
    money_label->setAlignment(Qt::AlignHCenter);


    QLabel * border = new QLabel;
    border->setStyleSheet("QLabel { border: 5px solid black; background-color: cyan}");
    parametrs_layout_.addWidget(border, 1, 4, 3, 1);

    time_label = new QLabel;
    parametrs_layout_.addWidget(time_label, 3, 4);
    time_label->setAlignment(Qt::AlignHCenter);

    semestr_label = new QLabel;
    parametrs_layout_.addWidget(semestr_label, 1, 4);
    semestr_label->setAlignment(Qt::AlignHCenter);

    day_label = new QLabel;
    parametrs_layout_.addWidget(day_label, 2, 4);
    day_label->setAlignment(Qt::AlignHCenter);

}

void Parametrs::setFoodCurrentValue(int value){
    food_label->setText("Food: " + QString::number(value));
}
void Parametrs::setHealthCurrentValue(int value){
    health_label->setText("Health: " + QString::number(value));
}
void Parametrs::setHappinessCurrentValue(int value){
    happiness_label->setText("Happiness: " + QString::number(value));
}
void Parametrs::setMoneyCurrentValue(qreal value){
    money_label->setText("Money: " + QString::number(value));
}
void Parametrs::setEnergyCurrentValue(int value){
    energy_label->setText("Energy: " + QString::number(value));
}
void Parametrs::setEducationCurrentValue(int value){
    education_label->setText("Education: " + QString::number(value));
}
void Parametrs::setTimeCurrentValue(const QTime& value){
    QString time = value.toString();
    time.resize(5);
    time_label->setText(time);
}
void Parametrs::setSemestrCurrentValue(int value){
    semestr_label->setText(QString::number(value) + " semestr");
}

void Parametrs::setDayCurrentValue(int value){
    day_label->setText("Day: " + QString::number(value));
}
