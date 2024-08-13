#include "signupscene.h"
#include "ui_signupscene.h"


SignUpScene::SignUpScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignUpScene)
{
    ui->setupUi(this);

    // buttons
    // connect(ui->signInButton, &QPushButton::clicked, this, &SignUpScene::validateMember);
    connect(ui->goBackButton, &QPushButton::clicked, this, &SignUpScene::goBack);
    connect(ui->signInButton, &QPushButton::clicked, this, &SignUpScene::signUpMember);
}

SignUpScene::~SignUpScene()
{
    delete ui;
}


void SignUpScene::signUpMember() {
    QString name = ui->nameInput->text();
    QString id = ui->IdInput->text();
    QString pwd = ui->PwInput->text();
    qDebug() << name << id << pwd << "멤버 생성!";
    // manager->registration(name, id, pwd);
}
