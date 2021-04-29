#ifndef FOODMENU_H
#define FOODMENU_H

#include "button.h"

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVector>

class FoodMenu : public QWidget
{
    Q_OBJECT
public:
    explicit FoodMenu(QWidget *parent = nullptr);

signals:
    void raise_food_value_(int);

private:
    QVBoxLayout layout_;
    QVector<Button *> buttons_;
};

#endif // FOODMENU_H
