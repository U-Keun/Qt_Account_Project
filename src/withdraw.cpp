#include "../header/withdraw.h"
#include "ui_withdraw.h"

Withdraw::Withdraw(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Withdraw)
{
    ui->setupUi(this);

    connect(ui->checkButton, &QPushButton::clicked, this, &Withdraw::withdrawRequested);
    connect(ui->goBackButton, &QPushButton::clicked, this, &Withdraw::goBack);
}

Withdraw::~Withdraw()
{
    delete ui;
}
