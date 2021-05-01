#ifndef ACTIONBUTTONS_H
#define ACTIONBUTTONS_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

class ActionButtons : public QWidget
{
    Q_OBJECT
public:
    explicit ActionButtons(QWidget *parent = nullptr);

private:
    QHBoxLayout action_buttons_layout_;
    QPushButton * food_button_;
    QPushButton * happiness_button_;
    QPushButton * education_button_;
    QPushButton * money_button_;
    QPushButton * health_button_;
    QPushButton * energy_button_;
};

#endif // ACTIONBUTTONS_H
