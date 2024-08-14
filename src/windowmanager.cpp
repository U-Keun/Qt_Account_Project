//
// Created by u-keun song on 2024. 8. 12..
//
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>

#include "../header/windowmanager.h"
#include "../header/startscene.h"
#include "../header/loginscene.h"
#include "../header/signupscene.h"
#include "../header/mainmenuscene.h"
#include "../header/inquiryscene.h"
#include "../header/registerscene.h"
#include "../header/depositaccount.h"
#include "../header/withdrawaccount.h"
#include "../header/deposit.h"
#include "../header/withdraw.h"
#include "../header/membermanager.h"

WindowManager::WindowManager(std::shared_ptr<MemberManager> memberManager) {
    mainWindow = new QMainWindow();
    this->memberManager = memberManager;
    mainWindow->resize(800, 600);

    setUpStartScene();
    mainWindow->show();
}

WindowManager::~WindowManager() {
    // delete memberManager;
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
    qDebug() << accountId;

    setUpDepositScene();
}

void WindowManager::setUpWithdrawAccountScene() {
    WithdrawAccount *scene = new WithdrawAccount(memberManager->getCurrentMember(), nullptr);
    setCentralWidget(scene);

    connect(scene, &WithdrawAccount::goBack, this, &WindowManager::setUpMainMenu);
    connect(scene, &WithdrawAccount::accountSelected, this, &WindowManager::handleWithdrawSelection);
}

void WindowManager::handleWithdrawSelection(const int accountId) {
    qDebug() << accountId;

    setUpWithdrawScene();
}


void WindowManager::setUpDepositScene() {
    qDebug() << "set up deposit scene";
    // Deposit *scene = new Deposit(nullptr);
    // setCentralWidget(scene.get());
}

void WindowManager::setUpWithdrawScene() {
    qDebug() << "set up withdraw scene";
    // Withdraw *scene = new Withdraw(nullptr);
    // setCentralWidget(scene);
}
