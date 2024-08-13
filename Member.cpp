#include "Member.h"

Member::Member() {
	this->name = "test";
	this->id = "test";
	this->pwd = "1111";
}

Member::Member(QString name, QString id, QString pwd) {
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

QVector<Account>& Member::getAccount() {
	return accountList;
}

void Member::addAccount(Account newAccount) {
	accountList.push_back(newAccount);
}
