#include "inquiryscene.h"
#include "ui_inquiryscene.h"

inquiryScene::inquiryScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inquiryScene)
{
    ui->setupUi(this);

    connect(ui->goBackButton, &QPushButton::clicked, this, &inquiryScene::goBack);
}

inquiryScene::~inquiryScene()
{
    delete ui;
}
