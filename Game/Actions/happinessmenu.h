#ifndef HAPPINESSMENU_H
#define HAPPINESSMENU_H

#include "Utilities/button.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QVector>
#include <QSignalMapper>

class HappinessMenu : public QWidget
{
    Q_OBJECT
public:
    explicit HappinessMenu(QWidget *parent = nullptr);
    QVector<Button *> buttons_;

signals:
    void SendButtonId(int);
private:
    QVBoxLayout layout_;
    QSignalMapper * mapper_;
};

#endif // HAPPINESSMENU_H
