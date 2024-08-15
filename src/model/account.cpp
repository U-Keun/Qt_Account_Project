#include "account.h"

#include <QTextStream>

Account::Account(const int accountId, const long long balance) {
    if (accountId < 0) throw "Account ID should be a positive integer.\n";
    if (balance < 0) throw "Balance cannot be a negative number.\n";
    this->regDate = Date();
    this->accountId = accountId;
    this->balance = balance;
}

QString Account::getAccountName() const {
    return this->accountName;
}

int Account::getAccountId() const {
    return this->accountId;
}

long long Account::getBalance() const {
    return this->balance;
}

Date Account::getDate() const {
    return this->regDate;
}

bool Account::deposit(const long long money) {
    this->balance += money;
    return true;
}

bool Account::withdraw(const long long money) {
    if (this->balance < money) {
        return false;
    }

    this->balance -= money;
    return true;
}

QString Account::toString() const {
    QString result;
    QTextStream oss(&result);
    oss << "Account ID: "
        << this->accountId << " | Account registered date: "
        << this->regDate.toString() << " | Balance: "
        << this->balance << '\n';

    return result;
}


