#include "mainmenuscene.h"
#include "ui_mainmenuscene.h"

MainMenuScene::MainMenuScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenuScene)
{
    ui->setupUi(this);

    connect(ui->inquiryButton, &QPushButton::clicked, this, &MainMenuScene::moveToInquiryWindow);
    connect(ui->registerButton, &QPushButton::clicked, this, &MainMenuScene::moveToRegisterWindow);
    connect(ui->depositButton, &QPushButton::clicked, this, &MainMenuScene::moveToDepositAccountWindow);
    connect(ui->withdrawButton, &QPushButton::clicked, this, &MainMenuScene::moveToWithdrawAccountWindow);
    connect(ui->goBackButton, &QPushButton::clicked, this, &MainMenuScene::goBack);
}

MainMenuScene::~MainMenuScene()
{
    delete ui;
}
