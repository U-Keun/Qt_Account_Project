#include "../header/signupscene.h"
#include "ui_signupscene.h"

SignUpScene::SignUpScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUpScene)
{
    ui->setupUi(this);

    connect(ui->signUpButton, &QPushButton::clicked, this, &SignUpScene::validateSignUp);
    connect(ui->goBackButton, &QPushButton::clicked, this, &SignUpScene::goBack);
}

SignUpScene::~SignUpScene()
{
    delete ui;
}
