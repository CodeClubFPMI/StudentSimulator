#ifndef EDUCATIONMENU_H
#define EDUCATIONMENU_H

#include "Utilities/button.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QVector>

class EducationMenu : public QWidget
{
    Q_OBJECT
public:
    explicit EducationMenu(QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout layout_;
    QVector<Button *> buttons_;
};

#endif // EDUCATIONMENU_H
