#pragma once
#include <iostream>
#include <QVector>
#include "Member.h"

using namespace std;

class MemberManager 
{
    QVector<Member> memberList;
    Member* currentMember = NULL;
    bool isRegister(QString name) const;
    // File IO 함수
    void readFile();
    void writeFile();
public:
    MemberManager();
    ~MemberManager();

    // command function
    void registration(QString name, QString id, QString pwd);
    void searchAllMember();
    void addAccount(long long tmpMoney);
    void transaction();
    bool login(QString tmpId, QString tmpPw);
    void logout();
    void getCurrentMemberStatus();
    void setCurrentMember(Member *member);
    Member* getCurrentMember() const;
};

