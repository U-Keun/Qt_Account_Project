#include "depositaccount.h"
#include "ui_depositaccount.h"


DepositAccount::DepositAccount(Member* member, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DepositAccount)
    , currentMember(member)
    , selectedItem(nullptr)
{
    ui->setupUi(this);

    connect(ui->goBackButton, &QPushButton::clicked, this, &DepositAccount::goBack);

    showAccountList();

    connect(ui->accountList, &QListWidget::itemClicked, this, &DepositAccount::itemClicked);
    connect(ui->selectButton, &QPushButton::clicked, this, &DepositAccount::handleAccountSelection);
}

DepositAccount::~DepositAccount()
{
    delete ui;
}

void DepositAccount::showAccountList() {
    QVector<Account> accountList = currentMember->getAccount();

    for (Account account : accountList) {
        QListWidgetItem* item = new QListWidgetItem(account.getAccountName());
        item->setData(Qt::UserRole, account.getAccountId());
        // item->setData(Qt::UserRole, account.getAccountName());
        ui->accountList->addItem(item);
    }

}

void DepositAccount::itemClicked(QListWidgetItem *item) {
    selectedItem = item;
}

void DepositAccount::handleAccountSelection() {
    if (selectedItem) {
        int accountId = selectedItem->data(Qt::UserRole).toInt();
        emit accountSelected(accountId);
    }
}
