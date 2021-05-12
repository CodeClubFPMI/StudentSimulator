#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>

class Button : public QWidget
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = nullptr);

    Button (QPushButton * button, int food,
      int happiness, int education, int health,
      int energy, qreal money, int day, int hour, int minute, int sem) : button_(button), food_(food),
          happiness_(happiness), education_(education),
          health_(health), energy_(energy), money_(money),
          day_(day), hour_(hour), minute_(minute), sem_{sem} {}

    int get_food_changes();
    int get_happiness_changes();
    int get_education_changes();
    int get_health_changes();
    int get_energy_changes();
    int get_day_changes();
    int get_hour_changes();
    int get_minute_changes();
    int get_available_sem();
    qreal get_money_changes();
    QPushButton * get_button_ptr();

signals:

private:
    QPushButton * button_{nullptr};
    int food_{0};
    int happiness_{0};
    int education_{0};
    int health_{0};
    int energy_{0};
    qreal money_{0};
    int day_{0};
    int hour_{0};
    int minute_{0};
    int sem_{1};
};

#endif // BUTTON_H
