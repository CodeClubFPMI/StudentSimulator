#ifndef HAPPINESSMENU_H
#define HAPPINESSMENU_H

#include "Utilities/button.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QVector>

class HappinessMenu : public QWidget
{
    Q_OBJECT
public:
    explicit HappinessMenu(QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout layout_;
    QVector<Button *> buttons_;
};

#endif // HAPPINESSMENU_H
