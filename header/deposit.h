#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>

namespace Ui {
class Deposit;
}

class Deposit : public QWidget
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();

signals:
    // void depositRequested();
    void goBack();

private:
    Ui::Deposit *ui;
};

#endif // DEPOSIT_H
