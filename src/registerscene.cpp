#include "../header/registerscene.h"
#include "ui_registerscene.h"

RegisterScene::RegisterScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterScene)
{
    ui->setupUi(this);

    connect(ui->registerButton, &QPushButton::clicked, this, &RegisterScene::registerAccount);
    connect(ui->goBackButton, &QPushButton::clicked, this, &RegisterScene::goBack);
}

RegisterScene::~RegisterScene()
{
    delete ui;
}
