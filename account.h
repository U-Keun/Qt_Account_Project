#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include "date.h"


class Account {
    int accountId;
    long long money;
    Date regDate;
public:
    Account(int accountId, long long money)/* throw(const char*)*/;
    Account(int accountId, long long money, Date date)
    : accountId(accountId), money(money), regDate(date) {}
    int getAccountId() const;
    long long getMoney() const;
    Date getDate() const;
    bool deposit(long long money);
    bool withdraw(long long money);
    QString  toString() const;
};


#endif // ACCOUNT_H
