#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QStack>
#include <QObject>
#include <QWidget>

class WindowManager : public QObject {
    Q_OBJECT;

    QStack<QWidget*> windowStack;

    // window transition helper
    void setUpStartScene();
    void setUpLogInScene();
    void setUpSignInScene();
public:
    WindowManager();
    ~WindowManager();

    // functions
    void pushWindow(QWidget*);
    void popWindow();
    QWidget* currentWindow() const;

};

#endif // WINDOWMANAGER_H
