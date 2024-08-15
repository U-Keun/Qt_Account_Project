#ifndef MEMBER_H
#define MEMBER_H

#include "account.h"

#include <QString>
#include <QVector>

class Member {
    QString name, id, pwd;
    QVector<Account> accountList;

public:
    Member() {}
    Member(const QString&, const QString&, const QString&);
    QString getName() const;
    QString getId() const;
    QString getPwd() const;
    QVector<Account> getAccount();
    Account* getAccount(const int);

    void addAccount(const Account&);
};

#endif //MEMBER_H
