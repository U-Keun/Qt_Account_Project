//
// Created by u-keun song on 2024. 8. 12..
//
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>

#include "windowmanager.h"
#include "startscene.h"
#include "loginscene.h"
#include "signupscene.h"
#include "mainmenuscene.h"
#include "inquiryscene.h"
#include "registerscene.h"
#include "depositaccount.h"
#include "withdrawaccount.h"
#include "deposit.h"
#include "withdraw.h"
#include "membermanager.h"

WindowManager::WindowManager(std::unique_ptr<MemberManager> memberManager) {
    mainWindow = new QMainWindow();
    this->memberManager = std::move(memberManager);
    mainWindow->resize(800, 600);

    setUpStartScene();
    mainWindow->show();
}

WindowManager::~WindowManager() {

}

void WindowManager::setCentralWidget(QWidget *widget) {
    if (mainWindow->centralWidget()) {
        mainWindow->centralWidget()->hide();
        delete mainWindow->centralWidget();
    }
    mainWindow->setCentralWidget(widget);
    widget->show();
}

void WindowManager::setUpStartScene() {
    StartScene *scene = new StartScene(nullptr);
    setCentralWidget(scene);

    connect(scene, &StartScene::moveToLogInWindow, this, &WindowManager::setUpLogInScene);
    connect(scene, &StartScene::moveToSignUpWindow, this, &WindowManager::setUpSignUpScene);
}

void WindowManager::setUpLogInScene() {
    LogInScene *scene = new LogInScene(nullptr);
    setCentralWidget(scene);

    connect(scene, &LogInScene::logInAttempted, this, &WindowManager::handleLogInAttempt);
    connect(scene, &LogInScene::goBack, this, &WindowManager::setUpStartScene);
}

void WindowManager::handleLogInAttempt(const QString& id, const QString& pwd) {
    if (memberManager->login(id, pwd)) {
        setUpMainMenu();
        return;
    }

    QMessageBox::warning(nullptr, "Warning", "Invalid ID/PW");
}

void WindowManager::setUpSignUpScene() {
    SignUpScene *scene = new SignUpScene(nullptr);
    setCentralWidget(scene);

    connect(scene, &SignUpScene::signUpAttempted, this, &WindowManager::handleSignUpAttempt);
    connect(scene, &SignUpScene::goBack, this, &WindowManager::setUpStartScene);
}

void WindowManager::handleSignUpAttempt(const QString& name, const QString& id, const QString& pwd) {
    if (memberManager->registerMember(name, id, pwd)) {
        QMessageBox::information(nullptr, "Information", "Sign Up Success!");
        setUpStartScene();
        return;
    }

    QMessageBox::warning(nullptr, "Warning", "This ID is already registered.");
}

void WindowManager::setUpMainMenu() {
    MainMenuScene *scene = new MainMenuScene(nullptr);
    setCentralWidget(scene);

    connect(scene, &MainMenuScene::moveToInquiryWindow, this, &WindowManager::setUpInquiryScene);
    connect(scene, &MainMenuScene::moveToRegisterWindow, this, &WindowManager::setUpRegisterScene);
    connect(scene, &MainMenuScene::moveToDepositAccountWindow, this, &WindowManager::setUpDepositAccountScene);
    connect(scene, &MainMenuScene::moveToWithdrawAccountWindow, this, &WindowManager::setUpWithdrawAccountScene);
    connect(scene, &MainMenuScene::goBack, this, &WindowManager::setUpStartScene);
}

void WindowManager::setUpInquiryScene() {
    InquiryScene *scene = new InquiryScene(memberManager->getCurrentMember(), nullptr);
    setCentralWidget(scene);

    connect(scene, &InquiryScene::goBack, this, &WindowManager::setUpMainMenu);
}

void WindowManager::setUpRegisterScene() {
    RegisterScene *scene = new RegisterScene(nullptr);
    setCentralWidget(scene);

    connect(scene, &RegisterScene::registerAttempted, this, &WindowManager::handleRegisterAttempt);
    connect(scene, &RegisterScene::goBack, this, &WindowManager::setUpMainMenu);
}

void WindowManager::handleRegisterAttempt(const QString& accountName, const long long balance, const Date date) {
    if (memberManager->addAccount(accountName, balance, date)) {
        QMessageBox::information(nullptr, "Information", "Register success!");
        setUpMainMenu();
        return;
    }

    QMessageBox::warning(nullptr, "Warning", "Register failed.");
}


void WindowManager::setUpDepositAccountScene() {
    DepositAccount *scene = new DepositAccount(memberManager->getCurrentMember(), nullptr);
    setCentralWidget(scene);

    connect(scene, &DepositAccount::goBack, this, &WindowManager::setUpMainMenu);
    connect(scene, &DepositAccount::accountSelected, this, &WindowManager::handleDepositSelection);
}

void WindowManager::handleDepositSelection(const int accountId) {
    // 유효하지 않은 accountId가 들어오면 예외 처리
    qDebug() << accountId;

    setUpDepositScene(accountId);
}

void WindowManager::setUpWithdrawAccountScene() {
    WithdrawAccount *scene = new WithdrawAccount(memberManager->getCurrentMember(), nullptr);
    setCentralWidget(scene);

    connect(scene, &WithdrawAccount::goBack, this, &WindowManager::setUpMainMenu);
    connect(scene, &WithdrawAccount::accountSelected, this, &WindowManager::handleWithdrawSelection);
}

void WindowManager::handleWithdrawSelection(const int accountId) {
    // 유효하지 않은 accountId가 들어오면 예외 처리
    qDebug() << accountId;

    setUpWithdrawScene(accountId);
}


void WindowManager::setUpDepositScene(const int accountId) {
    Account* selectedAccount = memberManager->getCurrentMember()->getAccount(accountId);
    Deposit *scene = new Deposit(selectedAccount, nullptr);
    setCentralWidget(scene);

    connect(scene, &Deposit::goBack, this, &WindowManager::setUpDepositAccountScene);
    connect(scene, &Deposit::depositSuccessed, this, &WindowManager::setUpMainMenu);
}

void WindowManager::setUpWithdrawScene(const int accountId) {
    Account* selectedAccount = memberManager->getCurrentMember()->getAccount(accountId);
    Withdraw *scene = new Withdraw(selectedAccount, nullptr);
    setCentralWidget(scene);

    connect(scene, &Withdraw::goBack, this, &WindowManager::setUpWithdrawAccountScene);
    connect(scene, &Withdraw::withdrawSuccessed, this, &WindowManager::setUpMainMenu);
}
