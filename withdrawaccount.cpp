#include "withdrawaccount.h"
#include "ui_withdrawaccount.h"

WithdrawAccount::WithdrawAccount(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WithdrawAccount)
{
    ui->setupUi(this);

    connect(ui->goBackButton, &QPushButton::clicked, this, &WithdrawAccount::goBack);
}

WithdrawAccount::~WithdrawAccount()
{
    delete ui;
}
