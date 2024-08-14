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
    void goDeposit();

private:
    Ui::DepositAccount *ui;
    GlobalManager& globalManager = GlobalManager::getInstance();
    MemberManager* manager = globalManager.getMemberManager();
    Member* currentMember = manager->getCurrentMember();
    Account* currentAcount = NULL;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *vLayout;

    void showAccountData();
};

#endif // DEPOSITACCOUNT_H
