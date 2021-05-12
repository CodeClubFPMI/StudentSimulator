#ifndef EDUCATIONMENU_H
#define EDUCATIONMENU_H

#include "Utilities/button.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QSignalMapper>
#include <QVector>

class EducationMenu : public QWidget
{
    Q_OBJECT
public:
    explicit EducationMenu(QWidget *parent = nullptr);
    QVector<Button *> buttons_;

signals:
    void SendButtonId(int);
private:
    QVBoxLayout layout_;
    QSignalMapper * mapper_;
};

#endif // EDUCATIONMENU_H
