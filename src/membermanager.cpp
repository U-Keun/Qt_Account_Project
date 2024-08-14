#include "../header/member.h"
#include "../header/membermanager.h"
#include "../header/account.h"

#include <iostream>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QDate>

using namespace std;

void MemberManager::readFile() {
    QFile file("info.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug("파일 오픈 안됨");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug("파일 생성 실패");
            return;
        }
        file.close();

        //만들어 둔거 다시 열기
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug("파일을 다시 열 수 없습니다.");
            return;
        }
    }

    QTextStream in(&file);
    int memberCount;
    in >> memberCount;

    QString name, id, pwd;
    int accountCount;
    for (int i = 0; i < memberCount; i++) {
        in >> name >> id >> pwd;
        // this->memberList.emplace_back(Member(name, id, pwd));
        this->memberList.insert(id, Member(name, id, pwd));

        in >> accountCount;

        int accountId;
        long long money;
        QString date;
        QString accountName;
        for (int j = 0; j < accountCount; j++) {
            in >> accountId >> money >> date;
            this->memberList[id].addAccount(Account(accountName, accountId, money, date));
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
            << it->getPwd() << " ";
        out << it->getAccount().size() << '\n';
        for (const auto& account : it->getAccount()) {
            out << account.getAccountId() << " "
                << account.getMoney() << " "
                << account.getDate().toString() << "\n";
        }
    }
    
    file.close();
}

MemberManager::MemberManager() {
    // qDebug() << "MemberManager 생성";
    readFile();
}

MemberManager::~MemberManager() {
    // qDebug() << "MemberManager 소멸";
    writeFile();
}

//멤버 등록
void MemberManager::registerMember(QString& name, QString& id, QString& pwd) {
    // qDebug() << "Enter member name, ID, PW:";
    QTextStream qin(stdin);
    qin >> name >> id >> pwd;

    // qDebug()<< "사용자 등록 요청 왓음 " << __FILE__;
    if (isRegistered(id)) {
        qDebug() << "Already registered member!";
        return;
    }

    const Member member(name, id, pwd);
    memberList.insert(id, member);
    // writeFile();
}

void MemberManager::searchAllMember() {
    // line();
    // qDebug() << "Search all registered members:";
    for (auto& member : memberList) {
        qDebug() << "Name:" << member.getName() << "ID:" << member.getId();
        if (!member.getAccount().empty()) {
            for (const auto& account : member.getAccount()) {
                qDebug() << account.toString();
            }
        } else {
            qDebug() << "Haven't opened an account yet";
        }
    }
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

void MemberManager::getCurrentMemberStatus() const {
    if (currentMember == nullptr) {
        qDebug() << "Please login";
        return;
    }

    qDebug() << "Name:" << currentMember->getName() << "ID:" << currentMember->getId();
    if (!currentMember->getAccount().empty()) {
        qDebug() << "Account ID, account balance:";
        for (const auto& account : currentMember->getAccount()) {
            qDebug() << account.toString();
        }
    } else {
        qDebug() << "Haven't opened an account yet";
    }
}


bool MemberManager::addAccount(
    const QString& accountName,
    const long long tmpMoney,
    const QString& date) const {
    if (currentMember == nullptr) {
        qDebug() << "Please login";
        return false;
    }

    const int tmpId = currentMember->getAccount().size() + 1;
    qDebug() << "Enter initial account balance:";
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
    qDebug() << "로그인 요청" << __FUNCTION__ ;
    for (auto& member : memberList) {
        if (member.getId() == tmpId) {
            if (member.getPwd() == tmpPw) {
                qDebug() << "Login success";
                setCurrentMember(&member);
                return true;
            } else {
                qDebug() << "Password error! Login fail";
                return false;
            }
        }
    }

    qDebug() << "ID not exist! Login fail";
    return false;
}

void MemberManager::logout() {
    if (currentMember == nullptr) {
        qDebug() << "Not logged in!";
    } else {
        currentMember = nullptr;
        qDebug() << "Logout!";
    }
}

void MemberManager::transaction() {
    if (currentMember == nullptr) {
        qDebug() << "Please login";
        return;
    }

    if (currentMember->getAccount().empty()) {
        qDebug() << "No account found";
        return;
    }

    qDebug() << "Deposit: 1, Withdraw: 2";
    int choice;
    QTextStream qin(stdin);
    qin >> choice;

    qDebug() << "Account list:";
    int maxAccountCount = currentMember->getAccount().size();
    for (const auto& account : currentMember->getAccount()) {
        qDebug() << account.toString();
    }

    int selectedAccount;
    qin >> selectedAccount;

    if (selectedAccount > maxAccountCount) {
        qDebug() << "Invalid account number";
        return;
    }

    qDebug() << "Enter amount:";
    int amount;
    qin >> amount;

    if (amount < 0) {
        qDebug() << "Please enter a positive integer";
        return;
    }

    auto& account = currentMember->getAccount()[selectedAccount - 1];
    if (choice == 1) {
        if (account.deposit(amount)) {
            qDebug() << "Deposit success!";
        }
    } else if (choice == 2) {
        account.withdraw(amount);
        qDebug() << "Withdraw success!";
    }
}
