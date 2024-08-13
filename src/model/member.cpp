#include "../../header/member.h"
#include "../../header/account.h"

Member::Member(const QString& name, const QString& id, const QString& pw) {
    this->name = name;
    this->id = id;
    this->pw = pw;
}

QString Member::getName() const {
    return name;
}

QString Member::getId() const {
    return id;
}

QString Member::getPw() const {
    return pw;
}

QVector<Account>& Member::getAccount() {
    return accountList;
}

void Member::addAccount(const Account& newAccount) {
    accountList.push_back(newAccount);
}


