#include "mainmenuscene.h"
#include "ui_mainmenuscene.h"

mainmenuScene::mainmenuScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainmenuScene)
{
    ui->setupUi(this);
}

mainmenuScene::~mainmenuScene()
{
    delete ui;
}
