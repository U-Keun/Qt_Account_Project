#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QMainWindow>

namespace Ui {
class deposit;
}

class deposit : public QMainWindow
{
    Q_OBJECT

public:
    explicit deposit(QWidget *parent = nullptr);
    ~deposit();

private:
    Ui::deposit *ui;
};

#endif // DEPOSIT_H
