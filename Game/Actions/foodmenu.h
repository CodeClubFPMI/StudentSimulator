#ifndef FOODMENU_H
#define FOODMENU_H

#include "Utilities/button.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QVector>
#include <QSignalMapper>

class FoodMenu : public QWidget
{
    Q_OBJECT
public:
    explicit FoodMenu(QWidget *parent = nullptr);
    QVector<Button *> buttons_;

signals:
    void SendButtonId(int);
private:
    QVBoxLayout layout_;
    QSignalMapper * mapper_;
};

#endif // FOODMENU_H
