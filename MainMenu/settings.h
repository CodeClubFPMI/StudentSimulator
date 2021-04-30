#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QVBoxLayout>

class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = nullptr);

signals:
    void GoToMainMenu();
private:
    QVBoxLayout layout_;
};

#endif // SETTINGS_H
