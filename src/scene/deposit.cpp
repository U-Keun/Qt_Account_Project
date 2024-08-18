#include "deposit.h"
#include "account.h"
#include "ui_deposit.h"

#include <QString>
#include <QMessageBox>

Deposit::Deposit(Account* account, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Deposit)
    , currentAccount(account)
{
    ui->setupUi(this);

    ui->accountName->setText("accountName : " + account->getAccountName() + "\n" + "balance: " + QString::number(account->getBalance()));
    connect(ui->checkButton, &QPushButton::clicked, this, &Deposit::depositRequested);
    connect(ui->goBackButton, &QPushButton::clicked, this, &Deposit::goBack);
}

Deposit::~Deposit()
{
    delete ui;
}

void Deposit::depositRequested() {
    QString amountText = ui->moneyText->text();
    bool valid;
    long long amount = amountText.toLongLong(&valid);

    if (valid && amount > 0) {
        if (currentAccount->deposit(amount)) {
            QMessageBox::information(this, "Success", "Deposit success!");
            emit depositSucceeded();
            return;
        }

        QMessageBox::warning(this, "Failed", "Deposit failed..");
        return;
    }

    QMessageBox::warning(this, "Invalid Input", "Please enter a valid amount.");
}
