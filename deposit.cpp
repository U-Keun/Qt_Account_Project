#include "deposit.h"
#include "ui_deposit.h"
#include <QString>
#include <QMessageBox>

deposit::deposit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deposit)
{
    ui->setupUi(this);
    ui->accountName->setText(currentAccount->getName());
    ui->accountBalance->setText(QString::number(currentAccount->getMoney()));
    connect(ui->goBackButton, &QPushButton::clicked, this, &deposit::goBack);
    connect(ui->checkButton, &QPushButton::clicked, this, &deposit::depositAmount);
}

void deposit::depositAmount() {
    int amount = ui->inputBox->text().toLongLong();
    if (amount > 0) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(nullptr, "입금 성공", "입금 성공", QMessageBox::Ok);
        if (reply == QMessageBox::Ok) {
            manager->deposit(amount);
            emit goBack();
        }
        return;
    }

    else
    {
        QMessageBox::warning(nullptr, "음수 입금", "입금할 금액은 양수로 입력");
        return;
    }
}

deposit::~deposit()
{
    delete ui;
}
