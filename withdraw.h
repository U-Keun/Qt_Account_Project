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

private:
    Ui::withdraw *ui;
    GlobalManager& globalManager = GlobalManager::getInstance();
    MemberManager* manager = globalManager.getMemberManager();
};

#endif // WITHDRAW_H
