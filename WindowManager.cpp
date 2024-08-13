#include <QApplication>

#include "WindowManager.h"
#include "startscene.h"
#include "loginscene.h"
#include "signupscene.h"
#include "mainmenuscene.h"
#include "inquiryscene.h"
#include "registerscene.h"
#include "depositaccount.h"
#include "withdrawaccount.h"

WindowManager::WindowManager() {
    setUpStartScene();
    windowStack.top()->show();
}

WindowManager::~WindowManager() {
    qDebug("windowmanager 소멸");
    while (!windowStack.isEmpty()) {
        delete windowStack.pop();
    }
}

void WindowManager::pushWindow(QWidget *window) {
    if (!windowStack.isEmpty()) {
        windowStack.top()->hide();
    }
    windowStack.push(window);
    window->show();
}

void WindowManager::popWindow() {
    if (!windowStack.isEmpty()) {
        QWidget *window = windowStack.pop();
        window->hide();
        delete window;
    }

    if (!windowStack.isEmpty()) {
        windowStack.top()->show();
    }
}

QWidget* WindowManager::currentWindow() const {
    return windowStack.isEmpty() ? nullptr : windowStack.top();
}

void WindowManager::setUpStartScene() {
    StartScene *window = new StartScene(nullptr);
    pushWindow(window);

    connect(window, &StartScene::moveToLogInWindow, this, &WindowManager::setUpLogInScene);
    connect(window, &StartScene::moveToSignUpWindow, this, &WindowManager::setUpSignUpScene);
    connect(window, &StartScene::goBack, qApp, &QApplication::quit);
}

void WindowManager::setUpLogInScene() {
    qDebug("windownamager");
    loginScene *window = new loginScene(nullptr);
    pushWindow(window);

    connect(window, &loginScene::moveToMainMenu, this, &WindowManager::setUpMainMenu);
    connect(window, &loginScene::goBack, this, &WindowManager::popWindow);
}

void WindowManager::setUpSignUpScene() {
    SignUpScene *window = new SignUpScene(nullptr);
    pushWindow(window);

    connect(window, &SignUpScene::validateMember, this, &WindowManager::popWindow); // 회원 검증 로직 추가 필요
    connect(window, &SignUpScene::goBack, this, &WindowManager::popWindow);
}

void WindowManager::setUpMainMenu() {
    mainmenuScene *window = new mainmenuScene(nullptr);
    pushWindow(window);

    connect(window, &mainmenuScene::moveToInquiryWindow, this, &WindowManager::setUpInquiryScene);
    connect(window, &mainmenuScene::moveToRegisterWindow, this, &WindowManager::setUpRegisterScene);
    connect(window, &mainmenuScene::moveToDepositAccountWindow, this, &WindowManager::setUpDepositAccountScene);
    connect(window, &mainmenuScene::moveToWithdrawAccountWindow, this, &WindowManager::setUpWithdrawAccountScene);
    connect(window, &mainmenuScene::goBack, this, &WindowManager::popWindow);
}

void WindowManager::setUpInquiryScene() {
    inquiryScene *window = new inquiryScene(nullptr);
    pushWindow(window);



    connect(window, &inquiryScene::goBack, this, &WindowManager::popWindow);
}

void WindowManager::setUpRegisterScene() {
    registerScene *window = new registerScene(nullptr);
    pushWindow(window);

    connect(window, &registerScene::registerAccount, this, &WindowManager::popWindow); // 계좌 등록 성공 후 메인 메뉴로 돌아가는 로직 필요
    connect(window, &registerScene::goBack, this, &WindowManager::popWindow);
}

void WindowManager::setUpDepositAccountScene() {
    DepositAccount *window = new DepositAccount(nullptr);
    pushWindow(window);

    connect(window, &DepositAccount::goBack, this, &WindowManager::popWindow);
}

void WindowManager::setUpWithdrawAccountScene() {
    qDebug() << "let's show withdraw scene.";
    WithdrawAccount *window = new WithdrawAccount(nullptr);
    pushWindow(window);


    connect(window, &WithdrawAccount::goBack, this, &WindowManager::popWindow);

}
