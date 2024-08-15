#include "../../header/withdraw.h"
#include "../../header/account.h"
#include "ui_withdraw.h"

#include <QmessageBox>

Withdraw::Withdraw(Account* account, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Withdraw)
    , currentAccount(account)
{
    ui->setupUi(this);
    qDebug() << account->getAccountName();

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
            emit withdrawSuccessed();
            return;
        }

        QMessageBox::warning(this, "Failed", "Withdraw failed..");
        return;
    }

    QMessageBox::warning(this, "Invalid Input", "Please enter a valid amount.");
}
