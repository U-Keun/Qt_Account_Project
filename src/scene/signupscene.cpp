#include "signupscene.h"
#include "ui_signupscene.h"

SignUpScene::SignUpScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUpScene)
{
    ui->setupUi(this);

    connect(ui->signUpButton, &QPushButton::clicked, this, &SignUpScene::handleSignUp);
    connect(ui->goBackButton, &QPushButton::clicked, this, &SignUpScene::goBack);
}

SignUpScene::~SignUpScene()
{
    delete ui;
}

void SignUpScene::handleSignUp() {
    QString name = ui->nameInput->text(),
            id = ui->idInput->text(),
            pwd = ui->pwInput->text();

    emit signUpAttempted(name, id, pwd);
}
