#include "singinscene.h"
#include "ui_singinscene.h"

singinScene::singinScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::singinScene)
{
    ui->setupUi(this);
}

singinScene::~singinScene()
{
    delete ui;
}
