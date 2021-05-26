#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QString>
#include <QInputDialog>
#include <QTime>

enum Game{
    NEW_GAME,
    LOAD_GAME
};

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(Game);

    int get_food_value();
    int get_happiness_value();
    int get_education_value();
    int get_health_value();
    int get_energy_value();
    int get_sem_value();
    int get_day();
    qreal get_money_value();
    QTime get_time();
    QString get_name();

signals:
    // when one of the properties (except of money) drops to 0, student dies :(
    // TODO: mb swap QString for enum
    void death_of_student(QString cause_of_death);
    void student_win();
    void pass_session();

    // TODO connect them
public slots:
    void change_food_value_(int increase_arg);
    void change_energy_value_(int increase_arg);
    void change_health_value_(int increase_arg);
    void change_happiness_value_(int increase_arg);
    void change_education_value_(int increase_arg);
    void change_day_value_(int increase_arg);
    void change_hour_value_(int);
    void change_minute_value(int);
    void change_money_value_(qreal increase_arg);

private:
   // this method sets properties, read from file
   void set_student_config(const QString &file_path);

   // this properties can have less than or equal to 100 and more than or equal to 0
   int food_;
   int energy_;
   int health_;
   int happiness_;
   int education_;

   // this propertie can have more than or less 0
   qreal money_;

   // this propertie is for saving the term. The actions available to the user depend on this
   int sem_;

   QString name_;
   int day_;
   QTime time_;
};

#endif // STUDENT_H
