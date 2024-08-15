#include "../../header/loginscene.h"
#include "ui_LogInScene.h"

LogInScene::LogInScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogInScene)
{
    ui->setupUi(this);

    connect(ui->logInButton, &QPushButton::clicked, this, &LogInScene::handleLogIn);
    connect(ui->goBackButton, &QPushButton::clicked, this, &LogInScene::goBack);
}

LogInScene::~LogInScene()
{
    delete ui;
}

void LogInScene::handleLogIn() {
    QString id = ui->idInput->text(), pwd = ui->pwInput->text();

    emit logInAttempted(id, pwd);
}
