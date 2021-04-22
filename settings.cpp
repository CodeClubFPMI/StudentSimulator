#include "settings.h"
#include <QPushButton>

Settings::Settings(QWidget *parent) : QWidget(parent)
{
    QPushButton * but_music_ = new QPushButton("Music", this);
    QPushButton * but_sound_ = new QPushButton("Sound", this);
    QPushButton * but_back_ = new QPushButton("Back", this);

    but_music_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_sound_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_back_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // TODO: make buttons dimensions better
    layout_.addWidget(but_music_, 1);
    layout_.addWidget(but_sound_, 1);
    layout_.addWidget(but_back_, 1);

    layout_.setSpacing(100);
    layout_.setContentsMargins(250, 200, 250, 200);
    setLayout(&layout_);
}
