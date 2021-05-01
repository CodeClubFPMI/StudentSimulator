#include "educationmenu.h"
#include "Utilities/utilities.h"

#include <QWidget>
#include <QPushButton>
#include <QVector>

EducationMenu::EducationMenu(QWidget *parent) : QWidget(parent)
{
    // TODO scrollBar (or Area, I don't know)

    menu_buttons::make_buttons("education_buttons.json", buttons_, layout_);
    setLayout(&layout_);
}
