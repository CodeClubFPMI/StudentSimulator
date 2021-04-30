#ifndef STATISTIC_H
#define STATISTIC_H

#include <QWidget>
#include <QVBoxLayout>

class Statistic : public QWidget
{
    Q_OBJECT
public:
    explicit Statistic(QWidget *parent = nullptr);

signals:
    void GoToMainMenu();
private:
    QVBoxLayout layout_;

};

#endif // STATISTIC_H
