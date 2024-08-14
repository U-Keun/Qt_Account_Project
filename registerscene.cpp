#include "registerscene.h"
#include "ui_registerscene.h"
#include <QDate>


registerScene::registerScene(QWidget *parent) :QMainWindow(parent), ui(new Ui::registerScene)
{
    ui->setupUi(this);
    QString currentDate = QDate::currentDate().toString("yyyy-MM-dd");
    ui->date->setText(currentDate);
    connect(ui->registerButton, &QPushButton::clicked, this, &registerScene::registerAccount);
    connect(ui->goBackButton, &QPushButton::clicked, this, &registerScene::goBack);
}

registerScene::~registerScene()
{
    delete ui;
}

void registerScene::registerAccount() {
    QString accountName = ui->accountName->text();
    long long accountBalance = ui->balance->text().toDouble();
    QString accountDate = ui->date->text();
    if(manager->addAccount(accountName, accountBalance, accountDate)){
        qDebug() << "계좌 등록 성공" << __FUNCTION__;
    }
    else qDebug() << "계좌 등록 실패";
}
