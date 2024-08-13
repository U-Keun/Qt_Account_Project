#include "depositaccount.h"
#include "ui_depositaccount.h"

DepositAccount::DepositAccount(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DepositAccount)
{
    ui->setupUi(this);
    scrollArea = new QScrollArea(this);
    scrollAreaWidgetContents = new QWidget();
    vLayout = new QVBoxLayout(scrollAreaWidgetContents);
    scrollAreaWidgetContents->setLayout(vLayout);
    scrollArea->setWidget(scrollAreaWidgetContents);
    scrollArea->setWidgetResizable(true);
    ui->verticalLayout->addWidget(scrollArea);

    connect(ui->goBackButton, &QPushButton::clicked, this, &DepositAccount::goBack);
    showAccountData();
}

DepositAccount::~DepositAccount()
{
    delete ui;
}

void DepositAccount::showAccountData()
{
    if (!currentMember->getAccount().empty()) {
        for (const auto& account : currentMember->getAccount()) {
            QPushButton *button = new QPushButton(account.getName() + " - " +
                                                      QString::number(account.getAccountId()) + " - " +
                                                      QString::number(account.getMoney()), this);


            connect(button, &QPushButton::clicked, this, [this, account]() {
                qDebug() << "Account Name:" << account.getName() << ", ID:" << account.getAccountId();
                // 있다 학원가서 매니저 currentAccount = account; + 시그널로 씬넘기기 추가하기
            });
            vLayout->addWidget(button);
        }
    } else {
        qDebug() << "Haven't opened an account yet";
    }
}

