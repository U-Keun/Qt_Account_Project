#include "mainmenuscene.h"
#include "ui_mainmenuscene.h"

mainmenuScene::mainmenuScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainmenuScene)
{
    ui->setupUi(this);

    // buttons
    connect(ui->accountInquiryButton, &QPushButton::clicked, this, &mainmenuScene::moveToInquiryWindow);
    connect(ui->accountRegisterButton, &QPushButton::clicked, this, &mainmenuScene::moveToRegisterWindow);
    connect(ui->depositButton, &QPushButton::clicked, this, &mainmenuScene::moveToDepositWindow);
    connect(ui->withdrawButton, &QPushButton::clicked, this, &mainmenuScene::moveToWithdrawWindow);
    connect(ui->goBackButton, &QPushButton::clicked, this, &mainmenuScene::goBack);
}

mainmenuScene::~mainmenuScene()
{
    delete ui;
}
