#ifndef MEMBERMANAGER_H
#define MEMBERMANAGER_H

#include <QMap>

class QString;
class Member;
class Date;

class MemberManager
{
    QMap<QString, Member> memberList;
    Member* currentMember = nullptr;

    bool isRegistered(const QString&) const;

    // File IO 함수
    void readFile();
    void writeFile();

public:
    MemberManager();
    ~MemberManager();

    // command function
    bool registerMember(const QString&, const QString&, const QString&);
    bool addAccount(const QString&, const long long, const Date) const;
    bool login(QString, QString);
    void logOut();
    void getCurrentMemberStatus() const;
    void setCurrentMember(Member*);
    Member* getCurrentMember() const;
};

#endif //MEMBERMANAGER_H
