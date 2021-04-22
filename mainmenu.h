#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QVBoxLayout>

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = nullptr);

signals:
   void GoToExit();
   void GoToSettings();
   void GoToStatistic();
private:
    QVBoxLayout layout_;
};

#endif // MAINMENU_H
