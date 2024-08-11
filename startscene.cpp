#include "startscene.h"
#include "ui_startscene.h"

StartScene::StartScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartScene)
{
    ui->setupUi(this);

    // buttons
    connect(ui->logInButton, &QPushButton::clicked, this, &StartScene::moveToLogInWindow);
    connect(ui->signInButton, &QPushButton::clicked, this, &StartScene::moveToSignInWindow);
    connect(ui->quitButton, &QPushButton::clicked, this, &StartScene::goBack);
}

StartScene::~StartScene()
{
    delete ui;
}


