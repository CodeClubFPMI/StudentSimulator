#ifndef FOODMENU_H
#define FOODMENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QScrollBar>

class FoodMenu : public QWidget
{
    Q_OBJECT
public:
    explicit FoodMenu(QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout layout_;
    QScrollBar * scroll_bar_;
    QPushButton ** buttons_;
};

#endif // FOODMENU_H
