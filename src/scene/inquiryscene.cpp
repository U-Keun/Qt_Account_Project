#include "inquiryscene.h"
#include "member.h"
#include "account.h"
#include "ui_inquiryscene.h"

#include <QStandardItem>

InquiryScene::InquiryScene(Member* member, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InquiryScene)
    , member(member)
{
    ui->setupUi(this);

    connect(ui->goBackButton, &QPushButton::clicked, this, &InquiryScene::goBack);

    model = new QStandardItemModel(this);

    model->setHorizontalHeaderLabels({"Account Name", "Account ID", "Balance", "Date"});

    QVector<Account> accounts = member->getAccount();

    for (int i = 0; i < accounts.size(); ++i) {
        const Account& account = accounts[i];
        model->setItem(i, 0, new QStandardItem(account.getAccountName()));
        model->setItem(i, 1, new QStandardItem(QString::number(account.getAccountId())));
        model->setItem(i, 2, new QStandardItem(QString::number(account.getBalance())));
        model->setItem(i, 3, new QStandardItem(account.getDate().toString()));
    }

    ui->tableView->setModel(model);
}

InquiryScene::~InquiryScene()
{
    delete ui;
}
