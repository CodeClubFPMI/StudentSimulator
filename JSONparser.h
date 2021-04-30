#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QVector>
#include <QString>
#include "button.h"

class JSONParser
{
public:
    explicit JSONParser() = default;
    ~JSONParser() = default;
    QVector<Button *> buttons_form_json(const QString &file_name);
};

#endif // JSONPARSER_H
