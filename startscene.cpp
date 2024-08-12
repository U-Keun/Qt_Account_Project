#include "startscene.h"
#include "ui_startscene.h"

StartScene::StartScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartScene)
{
    ui->setupUi(this);

    connect(ui->logInButton, &QPushButton::clicked, [=](){
        qDebug("start -> login 버튼");
    });

    // buttons
    connect(ui->logInButton, &QPushButton::clicked, this, &StartScene::moveToLogInWindow);
    connect(ui->signInButton, &QPushButton::clicked, this, &StartScene::moveToSignUpWindow);
    connect(ui->quitButton, &QPushButton::clicked, this, &StartScene::goBack);
}

StartScene::~StartScene()
{
    delete ui;
}


