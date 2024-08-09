#include "startscene.h"
#include "ui_startscene.h"

StartScene::StartScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartScene)
{
    ui->setupUi(this);
}

StartScene::~StartScene()
{
    delete ui;
}
