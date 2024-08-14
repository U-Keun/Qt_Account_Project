#include "../header/depositaccount.h"
#include "ui_depositaccount.h"


DepositAccount::DepositAccount(Member* member, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DepositAccount)
    , currentMember(member)
{
    ui->setupUi(this);

    connect(ui->goBackButton, &QPushButton::clicked, this, &DepositAccount::goBack);

    showAccountList();

    connect(ui->accountList, &QListWidget::itemDoubleClicked, this, &DepositAccount::handleAccountSelection);
}

DepositAccount::~DepositAccount()
{
    delete ui;
}

void DepositAccount::showAccountList() {
    const auto& accountList = currentMember->getAccount();

    for (const auto& account : accountList) {
        QListWidgetItem* item = new QListWidgetItem(account.getAccountName());
        item->setData(Qt::UserRole, account.getAccountId());
        ui->accountList->addItem(item);
    }

}

void DepositAccount::handleAccountSelection() {
    QListWidgetItem *selectedItem = ui->accountList->currentItem();
    if (selectedItem) {
        int accountId = selectedItem->data(Qt::UserRole).toInt();
        emit accountSelected(accountId);
    }
}
