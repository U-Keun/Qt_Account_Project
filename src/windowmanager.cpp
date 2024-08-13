//
// Created by u-keun song on 2024. 8. 12..
//
#include <QApplication>
#include <QMainWindow>

#include "../header/windowmanager.h"
#include "../header/startscene.h"
#include "../header/loginscene.h"
#include "../header/signupscene.h"
#include "../header/mainmenuscene.h"

WindowManager::WindowManager() {
    mainWindow = new QMainWindow();

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

    connect(scene, &LogInScene::moveToMainMenu, this, &WindowManager::setUpMainMenu);
    connect(scene, &LogInScene::goBack, this, &WindowManager::setUpStartScene);
}

void WindowManager::setUpSignUpScene() {
    SignUpScene *scene = new SignUpScene(nullptr);
    setCentralWidget(scene);

    connect(scene, &SignUpScene::validateSignUp, this, &WindowManager::setUpStartScene);
    connect(scene, &SignUpScene::goBack, this, &WindowManager::setUpStartScene);
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
    qDebug() << "set up inquiry scene.";
}

void WindowManager::setUpRegisterScene() {
    qDebug() << "set up register scene.";
}

void WindowManager::setUpDepositAccountScene() {
    qDebug() << "set up deposit account scene.";
}

void WindowManager::setUpWithdrawAccountScene() {
    qDebug() << "set up withdraw account scene.";
}
