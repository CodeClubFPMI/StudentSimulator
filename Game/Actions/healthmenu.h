#ifndef HEALTHMENU_H
#define HEALTHMENU_H

#include "Utilities/button.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QVector>

class HealthMenu : public QWidget
{
    Q_OBJECT
public:
    explicit HealthMenu(QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout layout_;
    QVector<Button *> buttons_;

};

#endif // HEALTHMENU_H
