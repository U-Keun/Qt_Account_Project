#include "signinscene.h"
#include "ui_signinscene.h"

singinScene::singinScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::singinScene)
{
    ui->setupUi(this);

    // buttons
    connect(ui->goBackButton, &QPushButton::clicked, this, &singinScene::goBack);
}

singinScene::~singinScene()
{
    delete ui;
}
