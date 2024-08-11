#include "signinscene.h"
#include "ui_signinscene.h"

signinScene::signinScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::signinScene)
{
    ui->setupUi(this);

    // buttons
    connect(ui->signInButton, &QPushButton::clicked, this, &signinScene::validateMember);
    connect(ui->goBackButton, &QPushButton::clicked, this, &signinScene::goBack);
}

signinScene::~signinScene()
{
    delete ui;
}
