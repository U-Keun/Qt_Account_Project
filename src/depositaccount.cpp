#include "../header/depositaccount.h"
#include "ui_depositaccount.h"

DepositAccount::DepositAccount(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DepositAccount)
{
    ui->setupUi(this);

    connect(ui->goBackButton, &QPushButton::clicked, this, &DepositAccount::goBack);
}

DepositAccount::~DepositAccount()
{
    delete ui;
}
