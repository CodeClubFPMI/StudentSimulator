#include "JSONparser.h"
#include "button.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QString>
#include <QMap>
#include <QMultiMap>
#include <QVariant>

void sort_vector_pairs(QVector<QPair<int, QString>>&);

QVector<Button *> JSONParser::buttons_form_json(const QString &file_name){
    qDebug() << "parsing starts";
    QVector<Button *> buttons;

    QFile buttons_file;
    QString file_path = PRO_FILE_PWD;
    file_path += "//Data//";
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
                                    json_obj_tmp.value("day").toInt(),
                                    json_obj_tmp.value("time_hour").toInt(),
                                    json_obj_tmp.value("time_minute").toInt(),
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

QMap<QString, QVariant> JSONParser::student_configs(const QString &file_name){
    QFile config_file;
    QString file_path = PRO_FILE_PWD;
    file_path += "/Data/";
    file_path += file_name;
    config_file.setFileName(file_path);

    QJsonParseError * errors = new QJsonParseError;

    if(config_file.open(QIODevice::ReadOnly|QFile::Text)){
        QJsonDocument config_json_doc =
                QJsonDocument::fromJson(QByteArray(config_file.readAll()), errors);
        qDebug() << errors->errorString();

        QJsonObject config_json_obj = config_json_doc.object();
        QMap<QString, QVariant> configs(config_json_obj.toVariantMap().toStdMap());
        return configs;
    }
    return QMap<QString, QVariant>();
}

QVector<QPair<int, QString>> JSONParser::statistic_from_json(){
    QMap<QString, QVariant> statistic_qvariant = student_configs("statistic.json");
    QVector<QPair<int, QString>> statistic;
    QList<QString> names = statistic_qvariant.keys();
    for(int i = 0; i < statistic_qvariant.size(); ++i){
        statistic.push_back(std::make_pair(statistic_qvariant[names[i]].toInt(),names[i]));
    }

    sort_vector_pairs(statistic);
    return statistic;
}

void JSONParser::statistic_to_json(QVector<QPair<int, QString>> & statistic){
    sort_vector_pairs(statistic);
    QJsonObject statistic_obj;
    for(int i = 0; i < statistic.size() && i < 10; ++i){
       statistic_obj.insert(statistic[i].second, QJsonValue::fromVariant(statistic[i].first));
    }

    QFile save_file;
    QString file_path = PRO_FILE_PWD;
    file_path += "//Data//";
    file_path += "statistic.json";
    save_file.setFileName(file_path);
    if(save_file.open(QIODevice::WriteOnly)){
        save_file.write(QJsonDocument(statistic_obj).toJson());
    } else{
        qDebug() << "Error with saving game!";
    }
    save_file.close();
}

void sort_vector_pairs(QVector<QPair<int, QString>>& v){
    for(int i = 0; i < v.size() - 1; ++i){
        for(int j = 0; j < v.size() - 1; ++j){
            if(v[j].first < v[j + 1].first){
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

