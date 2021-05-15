#include "savegame.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

void SaveGame::save_game_to_JSON(Student *player, QString file_name){
    QJsonObject toRecordObject;
    toRecordObject.insert("food", QJsonValue::fromVariant(player->get_food_value()));
    toRecordObject.insert("money", QJsonValue::fromVariant(player->get_money_value()));
    toRecordObject.insert("happiness", QJsonValue::fromVariant(player->get_happiness_value()));
    toRecordObject.insert("education", QJsonValue::fromVariant(player->get_education_value()));
    toRecordObject.insert("health", QJsonValue::fromVariant(player->get_health_value()));
    toRecordObject.insert("energy", QJsonValue::fromVariant(player->get_energy_value()));
    toRecordObject.insert("sem", QJsonValue::fromVariant(player->get_sem_value()));
    toRecordObject.insert("name", QJsonValue::fromVariant(player->get_name()));
    toRecordObject.insert("day", QJsonValue::fromVariant(player->get_day()));
    toRecordObject.insert("time_hour", QJsonValue::fromVariant(player->get_time().hour()));
    toRecordObject.insert("time_minute", QJsonValue::fromVariant(player->get_time().minute()));

    QFile save_file;
    QString file_path = PRO_FILE_PWD;
    file_path += "//Data//";
    file_path += file_name;
    save_file.setFileName(file_path);
    if(save_file.open(QIODevice::WriteOnly)){
        save_file.write(QJsonDocument(toRecordObject).toJson());
    } else{
        qDebug() << "Error with saving game!";
    }
    save_file.close();
}
