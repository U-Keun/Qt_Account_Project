#include "withdrawaccount.h"
#include "ui_withdrawaccount.h"

WithdrawAccount::WithdrawAccount(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WithdrawAccount)
{
    ui->setupUi(this);
    scrollArea = new QScrollArea(this);
    scrollAreaWidgetContents = new QWidget();
    vLayout = new QVBoxLayout(scrollAreaWidgetContents);
    scrollAreaWidgetContents->setLayout(vLayout);
    scrollArea->setWidget(scrollAreaWidgetContents);
    scrollArea->setWidgetResizable(true);
    ui->verticalLayout->addWidget(scrollArea);
    connect(ui->goBackButton, &QPushButton::clicked, this, &WithdrawAccount::goBack);
    showAccountData();
}

void WithdrawAccount::showAccountData()
{
    if (!currentMember->getAccount().empty()) {
        for (const auto& account : currentMember->getAccount()) {
            QPushButton *button = new QPushButton(account.getName() + " - " +
                                                      QString::number(account.getAccountId()) + " - " +
                                                      QString::number(account.getMoney()), this);
            connect(button, &QPushButton::clicked, this, [this, account]() {
                // qDebug() << "Account Name:" << account.getName() << ", ID:" << account.getAccountId();
                manager->setCurrentAccount(&(currentMember->getAccount()[account.getAccountId()-1]));
                // qDebug() << manager->getCurrentAccount()->getAccountId() << "현재 선택한 계좌ID";
                // qDebug() << manager->getCurrentAccount()->getName() << "현재 선택한 계좌";
            });
            vLayout->addWidget(button);

            connect(button, &QPushButton::clicked, this, &WithdrawAccount::goWithdraw);
        }
    }

    else {
        qDebug() << "Haven't opened an account yet";
    }
}

WithdrawAccount::~WithdrawAccount()
{
    delete ui;
}
