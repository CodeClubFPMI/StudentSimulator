#ifndef STATISTIC_H
#define STATISTIC_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

const int kAmountOfPlaces = 10;

class Statistic : public QWidget
{
    Q_OBJECT
public:
    explicit Statistic(QWidget *parent = nullptr);
    void refresh_statistic();
signals:
    void GoToMainMenu();
private:
    QVBoxLayout layout_;
    QLabel *labels_[kAmountOfPlaces + 2];

};

#endif // STATISTIC_H
