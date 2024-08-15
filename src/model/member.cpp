#include "../../header/member.h"
#include "../../header/account.h"

Member::Member(const QString& name, const QString& id, const QString& pwd) {
    this->name = name;
    this->id = id;
    this->pwd = pwd;
}

QString Member::getName() const {
    return name;
}

QString Member::getId() const {
    return id;
}

QString Member::getPwd() const {
    return pwd;
}

QVector<Account> Member::getAccount() {
    return accountList;
}

Account* Member::getAccount(const int accountId) {
    if (accountId >= 1 && accountId <= accountList.size()) {
        return &accountList[accountId - 1];
    }
    return nullptr;
}

void Member::addAccount(const Account& newAccount) {
    accountList.push_back(newAccount);
}


