#include "member.h"
#include "membermanager.h"
#include "account.h"

#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QDate>

using namespace std;

void MemberManager::readFile() {
    QFile file("info.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug("파일 생성 실패");
            return;
        }
        QTextStream out(&file);
        out << "0\n";
        file.close();
    }

    QTextStream in(&file);
    int memberCount;
    in >> memberCount;

    QString name, id, pwd;
    int accountCount;
    for (int i = 0; i < memberCount; i++) {
        in >> name >> id >> pwd;
        this->memberList.insert(id, Member(name, id, pwd));

        in >> accountCount;
        int accountId;
        long long money;
        QString date;
        QString accountName;
        for (int j = 0; j < accountCount; j++) {
            in >> accountName >> accountId >> money >> date;
            memberList[id].addAccount(Account(accountName, accountId, money, date));
        }
    }

    file.close();
}

void MemberManager::writeFile() {
    QFile file("info.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Error opening file for writing";
        return;
    }


    QTextStream out(&file);
    out << memberList.size() << "\n";
    for (auto it = memberList.begin(); it != memberList.end(); ++it) {
        out << it->getName() << " "
            << it->getId() << " "
            << it->getPwd() << " " << "\n";
        out << it->getAccount().size() << '\n';
        for (const auto& account : it->getAccount()) {
            out << account.getAccountName() << " "
                << account.getAccountId() << " "
                << account.getBalance() << " "
                << account.getDate().toString() << "\n";
        }
    }
    
    file.close();
}

MemberManager::MemberManager() {
    readFile();
}

MemberManager::~MemberManager() {
    writeFile();
}

bool MemberManager::registerMember(const QString& name, const QString& id, const QString& pwd) {
    if (isRegistered(id)) {
        return false;
    }

    const Member member(name, id, pwd);
    memberList.insert(id, member);
    return true;
}

bool MemberManager::isRegistered(const QString& id) const {
    return memberList.contains(id);
}

void MemberManager::setCurrentMember(Member* member) {
    currentMember = member;
}

Member* MemberManager::getCurrentMember() const {
    return currentMember;
}

bool MemberManager::addAccount(
    const QString& accountName,
    const long long tmpMoney,
    const Date date) const {
    if (currentMember == nullptr) {
        return false;
    }

    const int tmpId = currentMember->getAccount().size() + 1;
    try {
        const Account account(accountName, tmpId, tmpMoney, date);
        currentMember->addAccount(account);
        return true;
    } catch (const char* err) {
        qDebug() << err;
        return false;
    }
}

bool MemberManager::login(QString tmpId, QString tmpPw) {
    if (isRegistered(tmpId)) {
        Member* tmpMember = &memberList[tmpId];
        if (tmpMember->getPwd() == tmpPw) {
            setCurrentMember(tmpMember);
            return true;
        }
    }

    return false;
}

void MemberManager::logOut() {
    if (currentMember != nullptr) {
        currentMember = nullptr;
    }
}
