#ifndef DEPOSITACCOUNT_H
#define DEPOSITACCOUNT_H

#include "member.h"

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class DepositAccount;
}

class DepositAccount : public QWidget
{
    Q_OBJECT

public:
    explicit DepositAccount(Member* member, QWidget *parent = nullptr);
    ~DepositAccount();

signals:
    void goBack();
    void accountSelected(const int);

private:
    Ui::DepositAccount *ui;
    Member* currentMember;
    QListWidgetItem* selectedItem;

    void showAccountList();

private slots:
    void itemClicked(QListWidgetItem *);
    void handleAccountSelection();

};

#endif // DEPOSITACCOUNT_H
