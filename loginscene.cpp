#include "loginscene.h"
#include "ui_loginscene.h"

loginScene::loginScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginScene)
{
    ui->setupUi(this);
}

loginScene::~loginScene()
{
    delete ui;
}
