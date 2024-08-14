﻿#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include "MemberManager.h"
#include "account.h"
#include "line.h"
#include <QDate>
#include <QMessageBox>

using namespace std;

void MemberManager::readFile() {
// #if defined(_WIN32) || defined(_WIN64)
//     QFile file("C:/Users/change08/Desktop/Veda_fisrtProject/info.txt");
// #else
//     QFile file("info.txt");
// #endif
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
        this->memberList.emplace_back(Member(name, id, pwd));
        in >> accountCount;

        int accountId;
        long long money;
        QString date;
        QString accountName;
        for (int j = 0; j < accountCount; j++) {
            in >> accountName >> accountId >> money >> date;
            this->memberList[i].addAccount(Account(accountName, accountId, money, date));
        }
    }

    file.close();
}

void MemberManager::writeFile() {
// #if defined(_WIN32) || defined(_WIN64)
//     QFile file("C:/Users/change08/Desktop/Veda_fisrtProject/info.txt");
// #else
//     QFile file("info.txt");
// #endif
    qDebug("writefile 메서드 호출");
    QFile file("info.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Error opening file for writing";
        return;
    }


    QTextStream out(&file);
    out << memberList.size() << "\n";
    for (auto& member : memberList) {
        // qDebug() << "저장 테스트용으로 찍은 디버그" << member.getName() << member.getId() << member.getPwd() << __FILE__;
        out << member.getName() << " "
            << member.getId() << " "
            << member.getPwd() << "\n";
        out << member.getAccount().size() << "\n";
        for (const auto& account : member.getAccount()) {
            out << account.getName() << " "
                << account.getAccountId() << " "
                << account.getMoney() << " "
                << account.getDate().toString() << "\n";
        }
    }
    file.close();
}

MemberManager::MemberManager() {
    qDebug() << "MemberManager 생성";
    readFile();
}

MemberManager::~MemberManager() {
    qDebug() << "MemberManager 소멸";
    writeFile();
}

//멤버 등록
bool MemberManager::registration(QString name, QString id, QString pwd) {
    // qDebug() << "Enter member name, ID, PW:";
    // QTextStream qin(stdin);
    // qin >> name >> id >> pwd;

    qDebug()<< "사용자 등록 요청 왓음 " << __FILE__;

    for (auto& member : memberList) {
        if (member.getId() == id) {
            qDebug() << "Already registered member!";
            return false;
        }
    }
    Member mem(name, id, pwd);
    memberList.push_back(mem);
    return true;
    // writeFile();
}

void MemberManager::searchAllMember() {
    line();
    qDebug() << "Search all registered members:";
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

bool MemberManager::isRegister(QString name) const {
    for (const auto& member : memberList) {
        if (name == member.getName()) {
            qDebug() << "Already registered member";
            return true;
        }
    }

    qDebug() << "Not registered member";
    return false;
}

void MemberManager::setCurrentMember(Member* member) {
    currentMember = member;
}

Member* MemberManager::getCurrentMember() const {
    return currentMember;
}

Account* MemberManager::getCurrentAccount() const{
    return currentAccount;
}
void MemberManager::setCurrentAccount(Account* account){
    currentAccount = account;
}

void MemberManager::getCurrentMemberStatus() {
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


bool MemberManager::addAccount(QString accountName, long long tmpMoney, QString date) {
    if (currentMember == nullptr) {
        qDebug() << "Please login";
        return false;
    }

    int tmpId = currentMember->getAccount().size() + 1;
    qDebug() << "Enter initial account balance:";
    try {
        Account account(accountName, tmpId, tmpMoney, date);
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

void MemberManager::deposit(long long amount) {
    currentAccount->deposit(amount);
}

void MemberManager::withdraw(long long amount) {
    currentAccount->withdraw(amount);
}

/*
 *     } else if (choice == 2) {
        account.withdraw(amount);
        qDebug() << "Withdraw success!";
    }
*/
