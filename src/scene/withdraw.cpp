#include "withdraw.h"
#include "account.h"
#include "ui_withdraw.h"

#include <QmessageBox>
#include <QString>

Withdraw::Withdraw(Account* account, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Withdraw)
    , currentAccount(account)
{
    ui->setupUi(this);

    ui->accountName->setText("accountName : " + account->getAccountName() + "\n" + "balance: " + QString::number(account->getBalance()));
    connect(ui->checkButton, &QPushButton::clicked, this, &Withdraw::withdrawRequested);
    connect(ui->goBackButton, &QPushButton::clicked, this, &Withdraw::goBack);
}

Withdraw::~Withdraw()
{
    delete ui;
}

void Withdraw::withdrawRequested() {
    QString amountText = ui->moneyText->text();
    bool valid;
    long long amount = amountText.toLongLong(&valid);

    if (valid && amount > 0) {
        if (currentAccount->withdraw(amount)) {
            QMessageBox::information(this, "Success", "Withdraw success!");
            emit withdrawSucceeded();
            return;
        }

        QMessageBox::warning(this, "Failed", "Withdraw failed..");
        return;
    }

    QMessageBox::warning(this, "Invalid Input", "Please enter a valid amount.");
}
