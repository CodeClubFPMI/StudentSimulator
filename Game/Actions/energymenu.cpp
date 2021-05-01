#include "energymenu.h"
#include "Utilities/utilities.h"

#include <QWidget>
#include <QPushButton>
#include <QVector>

EnergyMenu::EnergyMenu(QWidget *parent) : QWidget(parent)
{
    // TODO scrollBar (or Area, I don't know)

    menu_buttons::make_buttons("energy_buttons.json", buttons_, layout_);
    setLayout(&layout_);
}
