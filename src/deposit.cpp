#include "../header/deposit.h"
#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Deposit)
{
    ui->setupUi(this);

    connect(ui->checkButton, &QPushButton::clicked, this, &Deposit::depositRequested);
    connect(ui->goBackButton, &QPushButton::clicked, this, &Deposit::goBack);
}

Deposit::~Deposit()
{
    delete ui;
}
