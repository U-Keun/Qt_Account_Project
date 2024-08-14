#ifndef MEMBERMANAGER_H
#define MEMBERMANAGER_H

#include <QMap>
#include <memory>

class QString;
class Member;
class Date;

class MemberManager
{
    QMap<QString, Member> memberList;
    // Member* currentMember = nullptr;
    std::shared_ptr<Member> currentMember = nullptr;
    bool isRegistered(const QString&) const;

    // File IO 함수
    void readFile();
    void writeFile();

public:
    MemberManager();
    ~MemberManager();

    // command function
    bool registerMember(const QString&, const QString&, const QString&);
    void searchAllMember();
    bool addAccount(const QString&, const long long, const Date) const;
    void transaction();
    bool login(QString, QString);
    void logout();
    void getCurrentMemberStatus() const;
    void setCurrentMember(std::shared_ptr<Member>);
    std::shared_ptr<Member> getCurrentMember() const;
};

#endif //MEMBERMANAGER_H
