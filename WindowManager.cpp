#include "WindowManager.h"
#include "startscene.h"
#include "loginscene.h"
#include "signinscene.h"

WindowManager::WindowManager() {
    setUpStartScene();
    windowStack.top()->show();
}

WindowManager::~WindowManager() {
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
    connect(window, &StartScene::moveToSignInWindow, this, &WindowManager::setUpSignInScene);
}

void WindowManager::setUpLogInScene() {
    loginScene *window = new loginScene(nullptr);
    pushWindow(window);

    connect(window, &loginScene::goBack, this, &WindowManager::popWindow);
}

void WindowManager::setUpSignInScene() {
    singinScene *window = new singinScene(nullptr);
    pushWindow(window);

    connect(window, &singinScene::goBack, this, &WindowManager::popWindow);
}
