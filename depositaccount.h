#ifndef DEPOSITACCOUNT_H
#define DEPOSITACCOUNT_H
#include "globalmanager.h"
#include <QStandardItemModel>
#include <QMainWindow>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>

namespace Ui {
class DepositAccount;
}

class DepositAccount : public QMainWindow
{
    Q_OBJECT

public:
    explicit DepositAccount(QWidget *parent = nullptr);
    ~DepositAccount();

signals:
    void goBack();

private:
    Ui::DepositAccount *ui;
    GlobalManager& globalManager = GlobalManager::getInstance();
    MemberManager* manager = globalManager.getMemberManager();
    Member*currentMember = manager->getCurrentMember();
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *vLayout;

    void showAccountData();
};

#endif // DEPOSITACCOUNT_H

/*
 구현해야될것
반복문 돌면서 현재 계좌 갯수만큼 pushbutton 생성
pushbtn에는 계좌명, id, 잔액이 들어가야됨
pushbutton 클릭하면 해당 pushbutton을 현재 pushbtn으로 지정
버튼 눌리면 currentAcount에 눌린 계좌를 연결
accountid에서 1빼면 눌린 버튼에 해당되는 계좌가 여기 연결되서
그 계좌에서 입/출금 수행
*/
