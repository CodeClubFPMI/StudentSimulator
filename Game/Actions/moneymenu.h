#ifndef MONEYMENU_H
#define MONEYMENU_H

#include "Utilities/button.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QVector>
#include <QSignalMapper>

class MoneyMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MoneyMenu(QWidget *parent = nullptr);
    QVector<Button *> buttons_;

signals:
    void SendButtonId(int);
private:
    QVBoxLayout layout_;
    QSignalMapper * mapper_;

};

#endif // MONEYMENU_H
