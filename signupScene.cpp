#include "signupscene.h"
#include "ui_signupscene.h"
#include <QMessageBox>


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
    if(manager->registration(name, id, pwd)){
        QMessageBox::information(nullptr, "회원가입 성공", "성공!");
    }

    else{
        QMessageBox::warning(nullptr, "회원가입 실패", "회원가입 실패!");
    }
}
