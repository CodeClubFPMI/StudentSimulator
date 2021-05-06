#ifndef PARAMETRS_H
#define PARAMETRS_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QTime>

class Parametrs : public QWidget
{
    Q_OBJECT
public:
    explicit Parametrs(QWidget *parent = nullptr);

    void setFoodCurrentValue(int);
    void setHealthCurrentValue(int);
    void setHappinessCurrentValue(int);
    void setMoneyCurrentValue(qreal);
    void setEnergyCurrentValue(int);
    void setEducationCurrentValue(int);
    void setTimeCurrentValue(const QTime&);
    void setSemestrCurrentValue(int);
    void setDayCurrentValue(int);

private:
    QGridLayout parametrs_layout_;
    QLabel * health_label;
    QLabel * food_label;
    QLabel * happiness_label;
    QLabel * money_label;
    QLabel * energy_label;
    QLabel * education_label;
    QLabel * time_label;
    QLabel * semestr_label;
    QLabel * day_label;
};

#endif // PARAMETRS_H
