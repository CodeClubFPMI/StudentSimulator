#ifndef ENERGYMENU_H
#define ENERGYMENU_H

#include "Utilities/button.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QSignalMapper>
#include <QVector>

class EnergyMenu : public QWidget
{
    Q_OBJECT
public:
    explicit EnergyMenu(QWidget *parent = nullptr);
    QVector<Button *> buttons_;

signals:
    void SendButtonId(int);
private:
    QVBoxLayout layout_;
    QSignalMapper * mapper_;

};

#endif // ENERGYMENU_H
