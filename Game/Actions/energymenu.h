#ifndef ENERGYMENU_H
#define ENERGYMENU_H

#include "Utilities/button.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QVector>

class EnergyMenu : public QWidget
{
    Q_OBJECT
public:
    explicit EnergyMenu(QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout layout_;
    QVector<Button *> buttons_;

};

#endif // ENERGYMENU_H
