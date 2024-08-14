#ifndef DEPOSITACCOUNT_H
#define DEPOSITACCOUNT_H

#include "../header/member.h"

#include <QWidget>

namespace Ui {
class DepositAccount;
}

class DepositAccount : public QWidget
{
    Q_OBJECT

public:
    explicit DepositAccount(Member* member, QWidget *parent = nullptr);
    ~DepositAccount();

signals:
    void goBack();
    void accountSelected(const int);
    void test(const int);

private:
    Ui::DepositAccount *ui;
    Member* currentMember;
    void showAccountList();

private slots:
    void handleAccountSelection();

};

#endif // DEPOSITACCOUNT_H
