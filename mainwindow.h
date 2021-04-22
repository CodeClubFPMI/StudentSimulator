#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QVBoxLayout vertical_layout;
    QHBoxLayout up_horizontal_layout;
    QHBoxLayout down_horizontal_layout;
    QStackedWidget stacked_widget;
};
#endif // MAINWINDOW_H
