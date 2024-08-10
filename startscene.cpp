#include "startscene.h"
#include "ui_startscene.h"

StartScene::StartScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartScene)
{
    ui->setupUi(this);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &StartScene::moveToLogInWindow);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &StartScene::moveToSignInWindow);
}

StartScene::~StartScene()
{
    delete ui;
}


