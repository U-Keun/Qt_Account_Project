#include "depositaccount.h"
#include "ui_depositaccount.h"

DepositAccount::DepositAccount(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DepositAccount)
{
    ui->setupUi(this);
}

DepositAccount::~DepositAccount()
{
    delete ui;
}
