#include "JSONparser.h"
#include "button.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>

QVector<Button *> JSONParser::buttons_form_json(const QString &file_name){
    qDebug() << "parsing starts";
    QVector<Button *> buttons;

    QFile buttons_file;
    QString file_path = PRO_FILE_PWD;
    file_path += '\\';
    file_path += file_name;
    buttons_file.setFileName(file_path);

    QJsonParseError * errors = new QJsonParseError;

    if(buttons_file.open(QIODevice::ReadOnly|QFile::Text)){
        QJsonDocument buttons_json_doc =
                QJsonDocument::fromJson(QByteArray(buttons_file.readAll()), errors);
        qDebug() << errors->errorString();

        QJsonArray buttons_json_arr = buttons_json_doc.array();

        Button * button_tmp;
        QPushButton * qpushbutton_tmp;
        QJsonObject json_obj_tmp;
        for (int i = 0; i < buttons_json_arr.size(); ++i){
            json_obj_tmp = buttons_json_arr[i].toObject();

            // it is important (?) to set parent, when we put them in the window
            qpushbutton_tmp = new QPushButton(json_obj_tmp.keys().first());

            json_obj_tmp = json_obj_tmp.value(json_obj_tmp.keys().first()).toObject();

            button_tmp = new Button(qpushbutton_tmp, json_obj_tmp.value("food").toInt(),
                                    json_obj_tmp.value("happiness").toInt(),
                                    json_obj_tmp.value("education").toInt(),
                                    json_obj_tmp.value("health").toInt(),
                                    json_obj_tmp.value("energy").toInt(),
                                    qreal(json_obj_tmp.value("money").toDouble()),
                                    json_obj_tmp.value("sem").toInt());

            buttons.push_back(button_tmp);
            button_tmp = nullptr;
            qpushbutton_tmp = nullptr;
        }

    } else{
        qDebug() << "It isn't opened!";
    }
    buttons_file.close();
    qDebug() << "sucsess";
    return buttons;
}

