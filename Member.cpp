#include "Member.h"

Member::Member() {
	this->name = "test";
	this->id = "test";
	this->pwd = "1111";
}

Member::Member(string name, string id, string pwd) {
	this->name = name;
	this->id = id;
	this->pwd = pwd;
}

string Member::getName() const {
	return name;
}

string Member::getId() const {
	return id;
}

string Member::getPwd() const {
	return pwd;
}

vector<Account>& Member::getAccount() {
	return accountList;
}

void Member::addAccount(Account newAccount) {
	accountList.push_back(newAccount);
}