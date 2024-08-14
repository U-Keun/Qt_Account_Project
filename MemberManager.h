#pragma once
#include <QVector>
#include "Member.h"

using namespace std;

class MemberManager 
{
    QVector<Member> memberList;
    Member* currentMember = NULL;
    Account* currentAccount = NULL;
    bool isRegister(QString name) const;
    // File IO 함수
    void readFile();
    void writeFile();
public:
    MemberManager();
    ~MemberManager();

    // command function
    bool registration(QString name, QString id, QString pwd);
    void searchAllMember();
    bool addAccount(QString accountName, long long tmpMoney, QString date);
    void deposit(long long amount);
    void withdraw(long long amount);
    bool login(QString tmpId, QString tmpPw);
    void logout();
    void getCurrentMemberStatus();
    void setCurrentMember(Member *member);
    Account* getCurrentAccount() const;
    void setCurrentAccount(Account* account);
    Member* getCurrentMember() const;
};

