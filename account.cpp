#include <sstream>

#include "account.h"
#include "date.h"

Account::Account(int accountId, long long money) throw(const char*) {
    if (accountId < 0) throw "accut ID should be a positive integer.\n";
    if (money < 0) throw "balance cannot be negative number.\n";
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

bool Account::deposit(long long money) {
    // 예외가 나오는 경우가 있을까..?
    this->money += money;
    return true;
}

bool Account::withdraw(long long money) {
    if (this->money < money) {
        return false;
    }

    this->money -= money;
    return true;
}

string Account::toString() {
    ostringstream oss;
    oss << "account ID "
        << this->accountId << " | account registerd date: "
        << this->regDate.toString() << " | left : "
        << this->money << '\n';

    return oss.str();
}
