#include "registerscene.h"
#include "ui_registerscene.h"

registerScene::registerScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registerScene)
{
    ui->setupUi(this);

    connect(ui->registerButton, &QPushButton::clicked, this, &registerScene::registerAccount);
    connect(ui->goBackButton, &QPushButton::clicked, this, &registerScene::goBack);
}

registerScene::~registerScene()
{
    delete ui;
}
