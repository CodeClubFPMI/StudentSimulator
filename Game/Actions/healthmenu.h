#ifndef HEALTHMENU_H
#define HEALTHMENU_H

#include "Utilities/button.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QVector>
#include <QSignalMapper>

class HealthMenu : public QWidget
{
    Q_OBJECT
public:
    explicit HealthMenu(QWidget *parent = nullptr);
    QVector<Button *> buttons_;

signals:
    void SendButtonId(int);
private:
    QVBoxLayout layout_;
    QSignalMapper * mapper_;

};

#endif // HEALTHMENU_H
