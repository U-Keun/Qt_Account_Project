#include "inquiryscene.h"
#include "ui_inquiryscene.h"

inquiryScene::inquiryScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inquiryScene)
{
    ui->setupUi(this);
}

inquiryScene::~inquiryScene()
{
    delete ui;
}
