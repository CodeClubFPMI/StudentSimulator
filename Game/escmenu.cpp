#include "escmenu.h"

EscMenu::EscMenu(QWidget *parent) : QWidget(parent), esc_menu_layout(this)
{
    setFixedSize(600, 800);
    QFile file(":/Styles/MainMenuStyles.css");
    file.open(QFile::ReadOnly);

    setWindowTitle(tr("Menu"));

    setStyleSheet(file.readAll());

    but_save_game_ = new QPushButton("Save Game");
    but_music_ = new QPushButton("Music");
    but_sound_ = new QPushButton("Sound");
    but_back_to_menu_ = new QPushButton("Save and Back to menu");
    but_exit_ = new QPushButton("Save and Exit");

    but_save_game_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_music_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_sound_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_back_to_menu_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_exit_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    esc_menu_layout.addWidget(but_save_game_, 1);
    esc_menu_layout.addWidget(but_music_, 1);
    esc_menu_layout.addWidget(but_sound_, 1);
    esc_menu_layout.addWidget(but_back_to_menu_, 1);
    esc_menu_layout.addWidget(but_exit_, 1);


    esc_menu_layout.setSpacing(40);
    //      esc_menu_layout.setContentsMargins(250, 200, 250, 200);

    setLayout(&esc_menu_layout);
}

void EscMenu::keyPressEvent(QKeyEvent *event){
   // int key = event->key();
    if (event->key() == Qt::Key_Escape) {
        this->setHidden(!(this->isHidden()));
    }
}
