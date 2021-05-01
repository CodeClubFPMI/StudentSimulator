#ifndef UTILITIES_H
#define UTILITIES_H

#include <QVector>
#include <QString>
#include <QVBoxLayout>
#include "button.h"
#include "Game/parametrs.h"

namespace menu_buttons{
    void add_buttons(QVector<Button *> &buttons, QVBoxLayout &layout);
    void change_buttons_style(QVector<Button *> &buttons, QVBoxLayout &layout);
}


#endif // UTILITIES_H
