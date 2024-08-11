#include "loginscene.h"
#include "ui_loginscene.h"

loginScene::loginScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginScene)
{
    ui->setupUi(this);

    // buttons
    // connect()
    connect(ui->goBackButton, &QPushButton::clicked, this, &loginScene::goBack);
}

loginScene::~loginScene()
{
    delete ui;
}
