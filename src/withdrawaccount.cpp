#include "../header/withdrawaccount.h"
#include "ui_withdrawaccount.h"

WithdrawAccount::WithdrawAccount(Member* member, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WithdrawAccount)
    , currentMember(member)
{
    ui->setupUi(this);

    connect(ui->goBackButton, &QPushButton::clicked, this, &WithdrawAccount::goBack);

    showAccountList();

    connect(ui->accountList, &QListWidget::itemDoubleClicked, this, &WithdrawAccount::handleAccountSelection);
}

WithdrawAccount::~WithdrawAccount()
{
    delete ui;
}

void WithdrawAccount::showAccountList() {
    const auto& accountList = currentMember->getAccount();

    for (const auto& account : accountList) {
        QListWidgetItem* item = new QListWidgetItem(account.getAccountName());
        item->setData(Qt::UserRole, account.getAccountId());
        ui->accountList->addItem(item);
    }
}

void WithdrawAccount::handleAccountSelection() {
    QListWidgetItem *selectedItem = ui->accountList->currentItem();
    if (selectedItem) {
        int accountId = selectedItem->data(Qt::UserRole).toInt();
        emit accountSelected(accountId);
    }
}
