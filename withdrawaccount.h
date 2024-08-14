#ifndef WITHDRAWACCOUNT_H
#define WITHDRAWACCOUNT_H
#include "globalmanager.h"
#include <QStandardItemModel>
#include <QMainWindow>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>

namespace Ui {
class WithdrawAccount;
}

class WithdrawAccount : public QMainWindow
{
    Q_OBJECT

public:
    explicit WithdrawAccount(QWidget *parent = nullptr);
    ~WithdrawAccount();

signals:
    void goBack();
    void goWithdraw();

private:
    Ui::WithdrawAccount *ui;
    GlobalManager& globalManager = GlobalManager::getInstance();
    MemberManager* manager = globalManager.getMemberManager();
    Member* currentMember = manager->getCurrentMember();
    Account* currentAcount = NULL;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *vLayout;

    void showAccountData();
};

#endif // WITHDRAWACCOUNT_H
