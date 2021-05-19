#include <QString>
#include <QDebug>
#include <QLabel>
#include <QFile>
#include <QPushButton>
#include <QMultiMap>
#include "statistic.h"
#include "Utilities/JSONparser.h"

Statistic::Statistic(QWidget *parent) : QWidget(parent), layout_(this)
{
    QPushButton * but_back_ = new QPushButton("Back", this);

    //Creating main upper label
    QString str = "Best players";
    labels_[0] = new QLabel;
    labels_[0]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    labels_[0]->setText(str);
    labels_[0]->setStyleSheet("QLabel { background-color : gray; color : black; }");
    labels_[0]->setAlignment(Qt::AlignHCenter);
    QFont font = labels_[0]->font();
    font.setPointSize(15);
    font.setBold(true);
    labels_[0]->setFont(font);
    layout_.addWidget(labels_[0], 2);

    for (int i = 0; i < 10; ++i){
      labels_[i + 1] = new QLabel;
      labels_[i + 1]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      labels_[i + 1]->setAlignment(Qt::AlignHCenter);
      layout_.addWidget(labels_[i + 1], 1);
    }
    refresh_statistic();

    layout_.addWidget(but_back_, 1);
    layout_.setSpacing(40);
    layout_.setContentsMargins(250, 20, 250, 100);

    setLayout(&layout_);

    connect(but_back_, &QPushButton::clicked, this, &Statistic::GoToMainMenu);
}

void Statistic::refresh_statistic(){
    JSONParser parser;
    QVector<QPair<int, QString>> statistic = parser.statistic_from_json();
    for (int i = 0; i < statistic.size(); ++i){
      labels_[i + 1]->setText(statistic[i].second + " : " + QString::number(statistic[i].first));
    }
}
