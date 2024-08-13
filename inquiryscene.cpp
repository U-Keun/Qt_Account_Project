#include "inquiryscene.h"
#include "ui_inquiryscene.h"

inquiryScene::inquiryScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inquiryScene)
    ,model(new QStandardItemModel(this))
{
    ui->setupUi(this);
    ui->memberName->setText(currentMember->getName());
    model->setColumnCount(4); // 계좌명, 계좌ID, 잔액, 생성일 행 만들어두기
    model->setHeaderData(0, Qt::Horizontal, "Account Name");
    model->setHeaderData(1, Qt::Horizontal, "Account ID");
    model->setHeaderData(2, Qt::Horizontal, "Balance");
    model->setHeaderData(3, Qt::Horizontal, "Creation Date");
    ui->tableView->setModel(model);
    showAccountData();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->goBackButton, &QPushButton::clicked, this, &inquiryScene::goBack);
}

void inquiryScene::showAccountData()
{

    if (!currentMember->getAccount().empty()) {
        for (const auto& account : currentMember->getAccount()) {
            QList<QStandardItem *> rowItems;

            rowItems.append(new QStandardItem(account.getName()));
            rowItems.append(new QStandardItem(QString::number(account.getAccountId())));
            rowItems.append(new QStandardItem(QString::number(account.getMoney())));
            rowItems.append(new QStandardItem(account.getDate().toString()));
            model->appendRow(rowItems);
        }
    } else {
        qDebug() << "Haven't opened an account yet";
    }
}

inquiryScene::~inquiryScene()
{
    delete ui;
}
