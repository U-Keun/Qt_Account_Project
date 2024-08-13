#ifndef DEPOSIT_H
#define DEPOSIT_H
#include "globalmanager.h"
#include <QStandardItemModel>
#include <QMainWindow>

namespace Ui {
class deposit;
}

class deposit : public QMainWindow
{
    Q_OBJECT

public:
    explicit deposit(QWidget *parent = nullptr);
    ~deposit();

signals:
    void goBack();

private:
    Ui::deposit *ui;
    GlobalManager& globalManager = GlobalManager::getInstance();
    MemberManager* manager = globalManager.getMemberManager();
    Member*currentMember = manager->getCurrentMember();
    void showAccountData();
};

#endif // DEPOSIT_H
