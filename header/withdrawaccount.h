#ifndef WITHDRAWACCOUNT_H
#define WITHDRAWACCOUNT_H

#include <QWidget>

namespace Ui {
class WithdrawAccount;
}

class WithdrawAccount : public QWidget
{
    Q_OBJECT

public:
    explicit WithdrawAccount(QWidget *parent = nullptr);
    ~WithdrawAccount();

signals:
    void goBack();

private:
    Ui::WithdrawAccount *ui;
};

#endif // WITHDRAWACCOUNT_H
