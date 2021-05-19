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
    labels_[0]->setStyleSheet("QLabel { background-color : gold; color : black; border: 3px solid black; }");
    labels_[0]->setAlignment(Qt::AlignCenter);
    QFont font = labels_[0]->font();
    font.setPointSize(25);
    font.setBold(true);
    labels_[0]->setFont(font);
    layout_.addWidget(labels_[0], 2);

<<<<<<< HEAD
    for (int i = 0; i < 10; ++i){
      labels_[i + 1] = new QLabel;
      labels_[i + 1]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      labels_[i + 1]->setAlignment(Qt::AlignCenter);
      labels_[i]->setStyleSheet("QLabel { background-color : orange; color : black; border: 2px solid black; }");
      layout_.addWidget(labels_[i + 1], 1);
=======
    for (int i = 1; i < kAmountOfPlaces+1; ++i){
      labels_[i] = new QLabel;
      labels_[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      labels_[i]->setText(str);
      labels_[i]->setAlignment(Qt::AlignCenter);
      labels_[i]->setStyleSheet("QLabel { background-color : orange; color : black; border: 2px solid black; }");
      layout_.addWidget(labels_[i], 1);
>>>>>>> starosta
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
