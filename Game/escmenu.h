#ifndef ESCMENU_H
#define ESCMENU_H

#include <QWidget>
#include <QKeyEvent>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>

class EscMenu : public QWidget
{
    Q_OBJECT
public:
    explicit EscMenu(QWidget *parent = nullptr);
    QVBoxLayout esc_menu_layout;
    QPushButton * but_save_game_;
    QPushButton * but_music_;
    QPushButton * but_sound_;
    QPushButton * but_back_to_menu_;
    QPushButton * but_exit_;
signals:

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // ESCMENU_H
