#ifndef WITHDRAW_H
#define WITHDRAW_H
#include "globalmanager.h"

#include <QMainWindow>

namespace Ui {
class withdraw;
}

class withdraw : public QMainWindow
{
    Q_OBJECT

public:
    explicit withdraw(QWidget *parent = nullptr);
    ~withdraw();

signals:
    void goBack();


private:
    Ui::withdraw *ui;
    GlobalManager& globalManager = GlobalManager::getInstance();
    MemberManager* manager = globalManager.getMemberManager();
    Member* currentMember = manager->getCurrentMember();
    Account* currentAccount = manager->getCurrentAccount();
    void withdrawAmount();
};

#endif // WITHDRAW_H
