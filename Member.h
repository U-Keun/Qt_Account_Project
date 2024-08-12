#pragma once
#include <iostream>
#include <vector>
#include "account.h"


using namespace std;

class Member{
    string name, id, pwd;
    vector<Account> accountList;

    public:
        Member();
        Member(string name, string id, string pwd);
        string getName() const;
        string getId() const;
        string getPwd() const;
        vector<Account>& getAccount();

        void addAccount(Account newAccount);

};