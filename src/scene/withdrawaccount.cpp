#include "withdrawaccount.h"
#include "ui_withdrawaccount.h"

WithdrawAccount::WithdrawAccount(Member* member, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WithdrawAccount)
    , currentMember(member)
{
    ui->setupUi(this);

    connect(ui->goBackButton, &QPushButton::clicked, this, &WithdrawAccount::goBack);

    showAccountList();

    connect(ui->accountList, &QListWidget::itemClicked, this, &WithdrawAccount::itemClicked);
    connect(ui->selectButton, &QPushButton::clicked, this, &WithdrawAccount::handleAccountSelection);
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

void WithdrawAccount::itemClicked(QListWidgetItem *item) {
    selectedItem = item;
}

void WithdrawAccount::handleAccountSelection() {
    if (selectedItem) {
        int accountId = selectedItem->data(Qt::UserRole).toInt();
        emit accountSelected(accountId);
    }
}
