#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "date.h"

#include <QString>

class Account {
    QString accountName;
    int accountId;
    long long money;
    Date regDate;

public:
    Account(const int,const long long)/* throw(const char*)*/;
    Account(const QString& accountName,
            const int accountId,
            const long long money,
            const Date date)
        : accountName(accountName), accountId(accountId), money(money), regDate(date) {}
    int getAccountId() const;
    long long getMoney() const;
    Date getDate() const;
    bool deposit(const long long);
    bool withdraw(const long long);
    QString  toString() const;
};

#endif //ACCOUNT_H
