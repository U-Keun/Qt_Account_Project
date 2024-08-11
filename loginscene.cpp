#include "loginscene.h"
#include "ui_loginscene.h"

loginScene::loginScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginScene)
{
    ui->setupUi(this);

    // buttons
    // connect()
    connect(ui->pushButton_7, &QPushButton::clicked, this, &loginScene::goBack);
}

loginScene::~loginScene()
{
    delete ui;
}

void moveToMainMenu() {

}

void goBack() {

}
