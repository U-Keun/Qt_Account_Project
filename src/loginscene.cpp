#include "../header/loginscene.h"
#include "ui_LogInScene.h"

LogInScene::LogInScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogInScene)
{
    ui->setupUi(this);

    connect(ui->logInButton, &QPushButton::clicked, this, &LogInScene::moveToMainMenu);
    connect(ui->goBackButton, &QPushButton::clicked, this, &LogInScene::goBack);
}

LogInScene::~LogInScene()
{
    delete ui;
}
