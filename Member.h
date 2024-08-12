#pragma once
// #include <iostream>
#include "account.h"
#include <QString>
#include <QVector>

using namespace std;

class Member{
    QString name;
    QString id;
    QString pwd;
    QVector<Account> accountList;

    public:
        Member();
        Member(QString name, QString id, QString pwd);
        QString getName() const;
        QString getId() const;
        QString getPwd() const;
        QVector<Account>& getAccount();

        void addAccount(Account newAccount);

};
