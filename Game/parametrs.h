#ifndef PARAMETRS_H
#define PARAMETRS_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class Parametrs : public QWidget
{
    Q_OBJECT
public:
    explicit Parametrs(QWidget *parent = nullptr);


private:
    QGridLayout parametrs_layout_;
    QLabel * health_label;
    QLabel * food_label;
    QLabel * mood_label;
    QLabel * money_label;
    QLabel * energy_label;
    QLabel * study_label;
};

#endif // PARAMETRS_H
