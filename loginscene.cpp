#include "loginscene.h"
#include "ui_loginscene.h"

loginScene::loginScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginScene)
{
    ui->setupUi(this);

    // buttons
    connect(ui->logInButton, &QPushButton::clicked, this, &loginScene::login);
    connect(ui->goBackButton, &QPushButton::clicked, this, &loginScene::goBack);
}

loginScene::~loginScene()
{
    delete ui;
}

void loginScene::login() {
    QString id = ui->IdInput->text();
    QString pwd = ui->PwInput->text();
    qDebug() << id << pwd << "로그인 시도!" << __FUNCTION__;
    manager->login(id,pwd);
    emit moveToMainMenu();
    // connect(ui->logInButton, &QPushButton::clicked, this, &loginScene::login);
}
