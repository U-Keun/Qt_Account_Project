#ifndef MEMBERMANAGER_H
#define MEMBERMANAGER_H

// #include <QVector>
#include <QMap>

class QString;
class Member;

class MemberManager
{
    // QVector<Member> memberList;
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
    void searchAllMember();
    bool addAccount(const QString&, const long long, const QString&) const;
    void transaction();
    bool login(QString, QString);
    void logout();
    void getCurrentMemberStatus() const;
    void setCurrentMember(Member*);
    Member* getCurrentMember() const;
};

#endif //MEMBERMANAGER_H
