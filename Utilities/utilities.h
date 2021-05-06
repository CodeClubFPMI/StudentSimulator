#ifndef UTILITIES_H
#define UTILITIES_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QVBoxLayout>
#include "button.h"
#include "Game/parametrs.h"
#include "Game/student.h"
#include "Game/parametrs.h"

namespace menu_buttons{

    // this method parse .json file with information about buttons
    // and calls add_buttons and change_buttons_style
    void make_buttons(const QString &file_name, QVector<Button *> &buttons, QVBoxLayout &layout);

    void add_buttons(QVector<Button *> &buttons, QVBoxLayout &layout);
    void change_buttons_style(QVector<Button *> &buttons, QVBoxLayout &layout);
}

// this namespace is for displaying current data on window
namespace data_update {
    // this function will be called when properties of Student class are chenged and we need to
    // update parameters (with the Parametrs class) and show checnges (change them in the window)
    void refresh_parameters_on_window(QWidget *, Student *);
}

#endif // UTILITIES_H
