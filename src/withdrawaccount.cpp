#include "../header/withdrawaccount.h"
#include "../cmake-build-debug/Qt_account_project_autogen/include/ui_withdrawaccount.h"

WithdrawAccount::WithdrawAccount(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WithdrawAccount)
{
    ui->setupUi(this);

    connect(ui->goBackButton, &QPushButton::clicked, this, &WithdrawAccount::goBack);
}

WithdrawAccount::~WithdrawAccount()
{
    delete ui;
}
