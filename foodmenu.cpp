#include "gamemenu.h"
#include <QWidget>
#include <QScrollBar>

GameMenu::GameMenu(QWidget *parent) : QWidget(parent)
{
    // test
    // TODO scrollBar (or Area, I don't know)
    QPushButton * but1 = new QPushButton("but1", this);
    QPushButton * but2 = new QPushButton("but2", this);
    QPushButton * but3 = new QPushButton("but3", this);
    QPushButton * but4 = new QPushButton("but4", this);
    QPushButton * but5 = new QPushButton("but5", this);
    QPushButton * but6 = new QPushButton("but6", this);

    but1->setFixedSize(200, 1000);
    but1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout_.addWidget(but1, 1);
    layout_.addWidget(but2, 1);
    layout_.addWidget(but3, 1);
    layout_.addWidget(but4, 1);
    layout_.addWidget(but5, 1);
    layout_.addWidget(but6, 1);

    layout_.setSpacing(5);
    layout_.setContentsMargins(0, 0, 0, 0);

    /*
    scroll_area_->addScrollBarWidget(but1,Qt::AlignVCenter);
    scroll_area_->addScrollBarWidget(but2,Qt::AlignVCenter);
    scroll_area_->addScrollBarWidget(but3,Qt::AlignVCenter);
    scroll_area_->addScrollBarWidget(but4,Qt::AlignVCenter);
    scroll_area_->addScrollBarWidget(but5,Qt::AlignVCenter);
    scroll_area_->addScrollBarWidget(but6,Qt::AlignVCenter);
    */
    //scroll_area_->setWidgetResizable(true);
    //scroll_area_->setLayout(&layout_);

    // scroll_area_->setWidget(this);
    //scroll_area_->show();
    setLayout(&layout_);
}
