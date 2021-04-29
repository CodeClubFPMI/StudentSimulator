#ifndef PARSER_H
#define PARSER_H

#include <QVector>
#include <QPushButton>
#include <QMap>
#include <QPair>

class Parser
{
public:
    Parser();
    ~Parser();
    QVector<QPair<QPushButton *, QMap<QString, qreal>>> buttons_form_json;
};

#endif // PARSER_H
