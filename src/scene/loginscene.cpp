#include "loginscene.h"
#include "membermanager.h"
#include "ui_LogInScene.h"

#include <QMessageBox>

LogInScene::LogInScene(std::shared_ptr<MemberManager> memberManager, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogInScene)
    , memberManager(memberManager)
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
    if (memberManager->login(id, pwd)) {
        QMessageBox::information(nullptr, "Information", "Log In success!");
        emit logInSucceeded();
        return;
    }

    QMessageBox::warning(nullptr, "Warning", "Invalid ID/PW");
}
