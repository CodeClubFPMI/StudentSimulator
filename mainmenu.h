#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = nullptr);

signals:

private:
   QVBoxLayout layout_;
   QPushButton but_new_game_;
   QPushButton but_load_game_;
   QPushButton but_statisic_;
   QPushButton but_settings_;
   QPushButton but_exit_;
};

#endif // MAINMENU_H
