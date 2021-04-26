#ifndef FOODMENU_H
#define FOODMENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QScrollBar>

class GameMenu : public QWidget
{
    Q_OBJECT
public:
    explicit GameMenu(QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout layout_;
    QScrollBar * scroll_bar_;
    QPushButton ** buttons_;
};

#endif // FOODMENU_H
