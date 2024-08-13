#ifndef DEPOSITACCOUNT_H
#define DEPOSITACCOUNT_H
#include "globalmanager.h"

#include <QMainWindow>

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
};

#endif // DEPOSITACCOUNT_H
