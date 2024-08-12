#pragma once
#include <iostream>
#include <vector>
#include "Member.h"

using namespace std;

class MemberManager 
{
    vector<Member> memberList;
    Member* currentMember = NULL;
    bool isRegister(string name) const;
    // File IO 함수
    void readFile();
    void writeFile();
public:
    MemberManager();
    ~MemberManager();

    // command function
    void registration();
    void searchAllMember();
    void addAccount();
    void transaction();
    void login();
    void logout();
    void getCurrentMemberStatus();
    void setCurrentMember(Member *member);
    Member* getCurrentMember() const;
};

