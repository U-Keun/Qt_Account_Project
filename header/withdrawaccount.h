#ifndef WITHDRAWACCOUNT_H
#define WITHDRAWACCOUNT_H

#include "../header/member.h"

#include <QWidget>

namespace Ui {
class WithdrawAccount;
}

class WithdrawAccount : public QWidget
{
    Q_OBJECT

public:
    explicit WithdrawAccount(Member* member, QWidget *parent = nullptr);
    ~WithdrawAccount();

signals:
    void goBack();
    void accountSelected(const int);

private:
    Ui::WithdrawAccount *ui;
    Member* currentMember;
    void showAccountList();

private slots:
    void handleAccountSelection();

};

#endif // WITHDRAWACCOUNT_H
