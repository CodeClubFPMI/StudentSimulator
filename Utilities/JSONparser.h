#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QVector>
#include <QString>
#include <QMap>
#include <QPair>
#include <QVariant>
#include "button.h"

class JSONParser
{
public:
    explicit JSONParser() = default;
    ~JSONParser() = default;
    QVector<Button *> buttons_form_json(const QString &file_name);
    QMap<QString, QVariant> student_configs(const QString &file_name);
    QVector<QPair<int, QString>> statistic_from_json();
    void statistic_to_json(QVector<QPair<int, QString>>&);
};

#endif // JSONPARSER_H
