#ifndef FOODMENU_H
#define FOODMENU_H

#include "Utilities/button.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QVector>

class FoodMenu : public QWidget
{
    Q_OBJECT
public:
    explicit FoodMenu(QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout layout_;
    QVector<Button *> buttons_;
};

#endif // FOODMENU_H
