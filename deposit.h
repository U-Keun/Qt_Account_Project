#ifndef DEPOSIT_H
#define DEPOSIT_H
#include "globalmanager.h"

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

private:
    Ui::deposit *ui;
    GlobalManager& globalManager = GlobalManager::getInstance();
    MemberManager* manager = globalManager.getMemberManager();
};

#endif // DEPOSIT_H
