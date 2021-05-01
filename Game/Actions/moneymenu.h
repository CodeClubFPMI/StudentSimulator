#ifndef MONEYMENU_H
#define MONEYMENU_H

#include "Utilities/button.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QVector>

class MoneyMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MoneyMenu(QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout layout_;
    QVector<Button *> buttons_;

};

#endif // MONEYMENU_H
