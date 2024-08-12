#include "registerscene.h"
#include "ui_registerscene.h"




registerScene::registerScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registerScene)
{
    ui->setupUi(this);

    connect(ui->registerButton, &QPushButton::clicked, this, &registerScene::registerAccount);
    connect(ui->goBackButton, &QPushButton::clicked, this, &registerScene::goBack);
}

registerScene::~registerScene()
{
    delete ui;
}

//잘못봐서 register가 사람 등록인줄 알앗습니다...

void registerScene::registerMember() {
    QString name = ui->accountName->text();
    QString id = ui->balance->text();
    QString pwd = ui->date->text();
    manager->registration(name, id, pwd);
}
