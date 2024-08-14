#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "date.h"

#include <QString>

class Account {
    QString accountName;
    int accountId;
    long long balance;
    Date regDate;

public:
    Account(const int,const long long)/* throw(const char*)*/;
    Account(const QString& accountName,
            const int accountId,
            const long long balance,
            const Date date)
        : accountName(accountName), accountId(accountId), balance(balance), regDate(date) {}
    Account(const Account& other)
        : accountName(other.accountName),
        accountId(other.accountId),
        balance(other.balance),
        regDate(other.regDate) {}
    QString getAccountName() const;
    int getAccountId() const;
    long long getBalance() const;
    Date getDate() const;
    bool deposit(const long long);
    bool withdraw(const long long);
    QString  toString() const;
};

#endif //ACCOUNT_H
