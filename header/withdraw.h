#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QWidget>

class Account;

namespace Ui {
class Withdraw;
}

class Withdraw : public QWidget
{
    Q_OBJECT

public:
    explicit Withdraw(Account*, QWidget *parent = nullptr);
    ~Withdraw();

signals:
    void goBack();
    void withdrawSucceeded();

private:
    Ui::Withdraw *ui;
    Account* currentAccount;

private slots:
    void withdrawRequested();
};

#endif // WITHDRAW_H
