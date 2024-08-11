#include "signupscene.h"
#include "ui_signupscene.h"

SignUpScene::SignUpScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignUpScene)
{
    ui->setupUi(this);

    // buttons
    connect(ui->signInButton, &QPushButton::clicked, this, &SignUpScene::validateMember);
    connect(ui->goBackButton, &QPushButton::clicked, this, &SignUpScene::goBack);
}

SignUpScene::~SignUpScene()
{
    delete ui;
}
