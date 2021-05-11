#include <QCoreApplication>
#include <QMap>
#include <QString>
#include <QDebug>

#include "student.h"
#include "Utilities/JSONparser.h"

Student::Student(Game game)
{
    QString file_name;
    // TODO correct file path
    switch(game){
    case 0:
        file_name = "new_game.json";
        break;
    case 1:
        file_name = "saved_game.json";
        break;
    default:
        break;
    }
    set_student_config(file_name);
    qDebug() << food_;
    qDebug() << energy_;
    qDebug() << health_;
    qDebug() << education_;
    qDebug() << happiness_;
    qDebug() << money_;
    qDebug() << sem_;
    qDebug() << day_;
    qDebug() << time_;
}

// TODO parser
void Student::set_student_config(const QString &file_name){
    JSONParser parser;
    QMap<QString, QVariant> configs = parser.student_configs(file_name);
    food_ = configs.value("food").toInt();
    energy_ = configs.value("energy").toInt();
    health_ = configs.value("health").toInt();
    education_ = configs.value("education").toInt();
    happiness_ = configs.value("happiness").toInt();
    money_ = qreal(configs.value("money").toDouble());
    sem_ = configs.value("sem").toInt();
    day_ = configs.value("day").toInt();
    time_.setHMS(configs.value("time_hour").toInt(),
                 configs.value("time_minute").toInt(), 0, 0);
    //time_.
}

// for changing properties except for money_
int change_properties(int property, int changing_arg){
    int tmp = property + changing_arg;
    if(tmp > 100){
        tmp = 100;
    } else if(tmp < 0){
        tmp = 0;
    }
    return tmp;

}

int Student::get_food_value(){
    return food_;
}
int Student::get_happiness_value(){
    return happiness_;
}
int Student::get_education_value(){
    return education_;
}
int Student::get_health_value(){
    return health_;
}
int Student::get_energy_value(){
    return energy_;
}
int Student::get_sem_value(){
    return sem_;
}
int Student::get_day(){
    return day_;
}
qreal Student::get_money_value(){
    return money_;
}

QTime Student::get_time(){
    return time_;
}

void Student::raise_food_value_(int increase_arg){
    food_ = change_properties(food_, increase_arg);
}

void Student::raise_energy_value_(int increase_arg){
    energy_ = change_properties(energy_, increase_arg);
}
void Student::raise_health_value_(int increase_arg){
    health_ = change_properties(health_, increase_arg);
}
void Student::raise_happiness_value_(int increase_arg){
    happiness_ = change_properties(happiness_, increase_arg);
}
void Student::raise_education_value_(int increase_arg){
    education_ = change_properties(education_, increase_arg);
}
void Student::raise_money_value_(qreal increase_arg){
    money_ += increase_arg;
}

void Student::reduce_food_value_(int reduce_arg){
    if(change_properties(food_, -reduce_arg) == 0){
        emit death_of_student("Food");
    } else{
        food_ = change_properties(food_, -reduce_arg);
    }
}
void Student::reduce_energy_value_(int reduce_arg){
    if(change_properties(education_, -reduce_arg) == 0){
        emit death_of_student("Energy");
    } else{
        energy_ = change_properties(energy_, -reduce_arg);
    }
}
void Student::reduce_health_value_(int reduce_arg){
    if(change_properties(health_, -reduce_arg) == 0){
        emit death_of_student("Health");
    } else{
        health_ = change_properties(health_, -reduce_arg);
    }
}
void Student::reduce_happiness_value_(int reduce_arg){
    if(change_properties(happiness_, -reduce_arg) == 0){
        emit death_of_student("Happiness");
    } else{
        happiness_ = change_properties(happiness_, -reduce_arg);
    }
}
void Student::reduce_education_value_(int reduce_arg){
    if(change_properties(education_, -reduce_arg) == 0){
        emit death_of_student("Education");
    } else{
        education_ = change_properties(education_, -reduce_arg);
    }
}

void Student::reduce_money_value_(qreal reduce_arg){
    money_ -= reduce_arg;
}
