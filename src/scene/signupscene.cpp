#include "signupscene.h"
#include "membermanager.h"
#include "ui_signupscene.h"

#include <QMessageBox>

SignUpScene::SignUpScene(std::shared_ptr<MemberManager> memberManager, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUpScene)
    , memberManager(memberManager)
{
    ui->setupUi(this);

    connect(ui->signUpButton, &QPushButton::clicked, this, &SignUpScene::handleSignUp);
    connect(ui->goBackButton, &QPushButton::clicked, this, &SignUpScene::goBack);
}

SignUpScene::~SignUpScene()
{
    delete ui;
}

void SignUpScene::handleSignUp() {
    QString name = ui->nameInput->text(),
            id = ui->idInput->text(),
            pwd = ui->pwInput->text();

    if (memberManager->registerMember(name, id, pwd)) {
        QMessageBox::information(nullptr, "Information", "Sign Up Success!");
        emit signUpSucceeded();
        return;
    }

    QMessageBox::warning(nullptr, "Warning", "This ID is already registered.");
}
