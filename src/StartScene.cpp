#include "../header/StartScene.h"
#include "../ui_StartScene.h"

StartScene::StartScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartScene)
{
    ui->setupUi(this);

    connect(ui->logInButton, &QPushButton::clicked, this, &StartScene::moveToLogInWindow);
    connect(ui->signUpButton, &QPushButton::clicked, this, &StartScene::moveToSignUpWindow);
    connect(ui->quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
}

StartScene::~StartScene()
{
    delete ui;
}
