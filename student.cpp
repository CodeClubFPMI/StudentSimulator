#include <QCoreApplication>
#include "student.h"

Student::Student(Game game)
{
    QString file_path;
    switch(game){
    case 0:
        file_path = QCoreApplication::applicationDirPath() +
            "/configs/new_game_config.txt";
        break;
    case 1:
        file_path = QCoreApplication::applicationDirPath() +
            "/configs/load_game_config.txt";
        break;
    default:
        break;
    }
    set_student_config(file_path);
}

// TODO parser
void Student::set_student_config(const QString &file_path){}

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
