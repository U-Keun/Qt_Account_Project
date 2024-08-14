#include "withdraw.h"
#include "ui_withdraw.h"
#include <QString>
#include <QMessageBox>

withdraw::withdraw(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::withdraw)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui->accountName->setText(currentAccount->getName());
    ui->accountBalance->setText(QString::number(currentAccount->getMoney()));
    connect(ui->goBackButton, &QPushButton::clicked, this, &withdraw::goBack);
    connect(ui->checkButton, &QPushButton::clicked, this, &withdraw::withdrawAmount);
}

void withdraw::withdrawAmount() {
    int amount = ui->inputBox->text().toLongLong();
    if ((manager->getCurrentAccount()->getMoney() - amount) >= 0) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(nullptr, "출금 성공", "출금 성공", QMessageBox::Ok);
        if (reply == QMessageBox::Ok) {
            manager->withdraw(amount);
            emit goBack();
        }
        return;
    }

    else
    {
        QMessageBox::warning(nullptr, "잔고 부족", "출금할 금액은 잔액보다 적게 입력");
        return;
    }
}


withdraw::~withdraw()
{
    delete ui;
}
