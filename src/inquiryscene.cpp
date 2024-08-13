#include "../header/inquiryscene.h"
#include "ui_inquiryscene.h"

InquiryScene::InquiryScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InquiryScene)
{
    ui->setupUi(this);

    connect(ui->goBackButton, &QPushButton::clicked, this, &InquiryScene::goBack);
}

InquiryScene::~InquiryScene()
{
    delete ui;
}
