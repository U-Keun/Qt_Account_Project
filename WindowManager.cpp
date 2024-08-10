#include "WindowManager.h"
#include "startscene.h"
#include "loginscene.h"
#include "singinscene.h"

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

    QObject::connect(window, &StartScene::moveToLogInWindow, this, &WindowManager::setUpLogInScene);
    QObject::connect(window, &StartScene::moveToSignInWindow, this, &WindowManager::setUpSignInScene);
}

void WindowManager::setUpLogInScene() {
    loginScene *window = new loginScene(nullptr);
    pushWindow(window);


}

void WindowManager::setUpSignInScene() {
    singinScene *window = new singinScene(nullptr);
    pushWindow(window);


}
