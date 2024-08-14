#ifndef WITHDRAWACCOUNT_H
#define WITHDRAWACCOUNT_H

#include "../header/member.h"

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class WithdrawAccount;
}

class WithdrawAccount : public QWidget
{
    Q_OBJECT

public:
    explicit WithdrawAccount(Member* member, QWidget *parent = nullptr);
    ~WithdrawAccount();

signals:
    void goBack();
    void accountSelected(const int);

private:
    Ui::WithdrawAccount *ui;
    Member* currentMember;
    QListWidgetItem* selectedItem;

    void showAccountList();

private slots:
    void itemClicked(QListWidgetItem *);
    void handleAccountSelection();

};

#endif // WITHDRAWACCOUNT_H
