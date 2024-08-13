#include "account.h"

#include <QTextStream>

Account::Account(const int accountId, const long long money) {
    if (accountId < 0) throw "Account ID should be a positive integer.\n";
    if (money < 0) throw "Balance cannot be a negative number.\n";
    this->regDate = Date();
    this->accountId = accountId;
    this->money = money;
}

int Account::getAccountId() const {
    return this->accountId;
}

long long Account::getMoney() const {
    return this->money;
}

Date Account::getDate() const {
    return this->regDate;
}

bool Account::deposit(const long long money) {
    // 예외가 발생할 가능성 고려
    this->money += money;
    return true;
}

bool Account::withdraw(const long long money) {
    if (this->money < money) {
        return false;
    }

    this->money -= money;
    return true;
}

QString Account::toString() const {
    QString result;
    QTextStream oss(&result);
    oss << "Account ID: "
        << this->accountId << " | Account registered date: "
        << this->regDate.toString() << " | Balance: "
        << this->money << '\n';

    return result;
}


