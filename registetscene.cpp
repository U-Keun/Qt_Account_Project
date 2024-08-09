#include "registetscene.h"
#include "ui_registetscene.h"

registetScene::registetScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registetScene)
{
    ui->setupUi(this);
}

registetScene::~registetScene()
{
    delete ui;
}
