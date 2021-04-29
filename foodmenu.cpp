#include "foodmenu.h"
#include "student.h"
#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QDebug>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>

FoodMenu::FoodMenu(QWidget *parent) : QWidget(parent)
{
    // test
    // TODO scrollBar (or Area, I don't know)

    /*
    QPushButton * buttons_[10];
    buttons_[0] = new QPushButton("but1", this);
    buttons_[1] = new QPushButton("but2", this);
    buttons_[2] = new QPushButton("but3", this);
    buttons_[3] = new QPushButton("but4", this);
    buttons_[4] = new QPushButton("but5", this);
    buttons_[5] = new QPushButton("but6", this);
    */
    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////

    // working with a .json

    // find .json file
    QFile food_buttons_file;
    QString file_path = PRO_FILE_PWD;
    file_path += "/food_buttons.json";
    food_buttons_file.setFileName(file_path);

   // QJsonDocument food_buttons_json_doc;
    QJsonParseError * errors = new QJsonParseError;

    // opening json file and read it into food_buttnos_json_doc
    if(food_buttons_file.open(QIODevice::ReadOnly|QFile::Text)){
        QJsonDocument food_buttons_json_doc =
                QJsonDocument::fromJson(QByteArray(food_buttons_file.readAll()), errors);
        qDebug() << errors->errorString();

        QJsonArray food_buttons_json_arr = food_buttons_json_doc.array();
        qDebug() << food_buttons_json_arr.size();

        qDebug() << food_buttons_json_arr[0].toObject().keys()[0];

        QPushButton * tmp_button;
        for (int i = 0; i < food_buttons_json_arr.size(); ++i){
            tmp_button = new QPushButton(food_buttons_json_arr[i].toObject().keys()[0], this);
            buttons_.push_back(tmp_button);
            tmp_button = nullptr;

            buttons_[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            layout_.addWidget(buttons_[i], 1);

            // mb will be the other system of slots-signals
            connect(buttons_[i], &QPushButton::clicked, this, &FoodMenu::raise_food_value_);
        }
        qDebug() << food_buttons_json_arr[0].toObject().
                value(food_buttons_json_arr[0].toObject().keys()[0]).toObject().
                value(food_buttons_json_arr[0].toObject().
                value(food_buttons_json_arr[0].toObject().keys()[0]).toObject().keys()[0]);
    } else{
        qDebug() << "It isn't opened!";
    }
    food_buttons_file.close();

    /*
    for(int i = 0; i < 3; ++i){
        buttons_[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        layout_.addWidget(buttons_[i], 1);
    }
    */

    //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////

    layout_.setSpacing(5);
    layout_.setContentsMargins(100, 100, 100, 100);

    setLayout(&layout_);
}
