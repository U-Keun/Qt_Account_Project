#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>

class Account;

namespace Ui {
class Deposit;
}

class Deposit : public QWidget
{
    Q_OBJECT

public:
    explicit Deposit(Account*, QWidget *parent = nullptr);
    ~Deposit();

signals:
    void goBack();
    void depositSuccessed();

private:
    Ui::Deposit *ui;
    Account* currentAccount;

private slots:
    void depositRequested();
};

#endif // DEPOSIT_H
