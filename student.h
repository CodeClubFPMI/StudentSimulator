#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QString>

enum Game{
    NEW_GAME,
    LOAD_GAME
};

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(Game);

signals:
    // when one of the properties (except of money) drops to 0, student dies :(
    // TODO: mb swap QString for enum
    void death_of_student(QString cause_of_death);

public slots:
    void raise_food_value_(int increase_arg);
    void raise_energy_value_(int increase_arg);
    void raise_health_value_(int increase_arg);
    void raise_happiness_value_(int increase_arg);
    void raise_education_value_(int increase_arg);
    void raise_money_value_(int increase_arg);

    void reduce_food_value_(int reduce_arg);
    void reduce_energy_value_(int reduce_arg);
    void reduce_health_value_(int reduce_arg);
    void reduce_happiness_value_(int reduce_arg);
    void reduce_education_value_(int reduce_arg);
    // !!! control over whether a student has enough money DOES NOT lie with the slot !!!
    void reduce_money_value_(int reduce_arg);
private:
   // this method sets properties, read from file
   void set_student_config(const QString &file_path);

   // this properties can have less than or equal to 100 and more than or equal to 0
   int food_;
   int energy_;
   int health_;
   int happiness_;
   int education_;

   // this properie can have more than or less 0
   int money_;
};

#endif // STUDENT_H
