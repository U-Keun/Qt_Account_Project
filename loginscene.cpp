#include "loginscene.h"
#include "ui_loginscene.h"

loginScene::loginScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginScene)
{
    ui->setupUi(this);

    // buttons
    connect(ui->logInButton, &QPushButton::clicked, this, &loginScene::moveToMainMenu);
    connect(ui->goBackButton, &QPushButton::clicked, this, &loginScene::goBack);
}

loginScene::~loginScene()
{
    delete ui;
}
