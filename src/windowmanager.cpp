//
// Created by u-keun song on 2024. 8. 12..
//
#include <QApplication>
#include <QMainWindow>

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

WindowManager::WindowManager(std::shared_ptr<MemberManager> memberManager) {
    mainWindow = new QMainWindow();
    this->memberManager = memberManager;
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
    LogInScene *scene = new LogInScene(memberManager, nullptr);
    setCentralWidget(scene);

    connect(scene, &LogInScene::logInSucceeded, this, &WindowManager::setUpMainMenu);
    connect(scene, &LogInScene::goBack, this, &WindowManager::setUpStartScene);
}

void WindowManager::setUpSignUpScene() {
    SignUpScene *scene = new SignUpScene(memberManager, nullptr);
    setCentralWidget(scene);

    connect(scene, &SignUpScene::signUpSucceeded, this, &WindowManager::setUpStartScene);
    connect(scene, &SignUpScene::goBack, this, &WindowManager::setUpStartScene);
}

void WindowManager::setUpMainMenu() {
    MainMenuScene *scene = new MainMenuScene(nullptr);
    setCentralWidget(scene);

    connect(scene, &MainMenuScene::moveToInquiryWindow, this, &WindowManager::setUpInquiryScene);
    connect(scene, &MainMenuScene::moveToRegisterWindow, this, &WindowManager::setUpRegisterScene);
    connect(scene, &MainMenuScene::moveToDepositAccountWindow, this, &WindowManager::setUpDepositAccountScene);
    connect(scene, &MainMenuScene::moveToWithdrawAccountWindow, this, &WindowManager::setUpWithdrawAccountScene);
    connect(scene, &MainMenuScene::goBack, this, [&]() {
        memberManager->logOut();
        setUpStartScene();
    });
}

void WindowManager::setUpInquiryScene() {
    InquiryScene *scene = new InquiryScene(memberManager->getCurrentMember(), nullptr);
    setCentralWidget(scene);

    connect(scene, &InquiryScene::goBack, this, &WindowManager::setUpMainMenu);
}

void WindowManager::setUpRegisterScene() {
    RegisterScene *scene = new RegisterScene(memberManager, nullptr);
    setCentralWidget(scene);

    connect(scene, &RegisterScene::registerSucceeded, this, &WindowManager::setUpMainMenu);
    connect(scene, &RegisterScene::goBack, this, &WindowManager::setUpMainMenu);
}

void WindowManager::setUpDepositAccountScene() {
    DepositAccount *scene = new DepositAccount(memberManager->getCurrentMember(), nullptr);
    setCentralWidget(scene);

    connect(scene, &DepositAccount::goBack, this, &WindowManager::setUpMainMenu);
    connect(scene, &DepositAccount::accountSelected, this, &WindowManager::setUpDepositScene);
}

void WindowManager::setUpWithdrawAccountScene() {
    WithdrawAccount *scene = new WithdrawAccount(memberManager->getCurrentMember(), nullptr);
    setCentralWidget(scene);

    connect(scene, &WithdrawAccount::goBack, this, &WindowManager::setUpMainMenu);
    connect(scene, &WithdrawAccount::accountSelected, this, &WindowManager::setUpWithdrawScene);
}

void WindowManager::setUpDepositScene(const int accountId) {
    Account* selectedAccount = memberManager->getCurrentMember()->getAccount(accountId);
    Deposit *scene = new Deposit(selectedAccount, nullptr);
    setCentralWidget(scene);

    connect(scene, &Deposit::goBack, this, &WindowManager::setUpDepositAccountScene);
    connect(scene, &Deposit::depositSucceeded, this, &WindowManager::setUpMainMenu);
}

void WindowManager::setUpWithdrawScene(const int accountId) {
    Account* selectedAccount = memberManager->getCurrentMember()->getAccount(accountId);
    Withdraw *scene = new Withdraw(selectedAccount, nullptr);
    setCentralWidget(scene);

    connect(scene, &Withdraw::goBack, this, &WindowManager::setUpWithdrawAccountScene);
    connect(scene, &Withdraw::withdrawSucceeded, this, &WindowManager::setUpMainMenu);
}
