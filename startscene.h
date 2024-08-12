#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QMainWindow>

namespace Ui {
class StartScene;
}

class StartScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartScene(QWidget *parent = nullptr);
    ~StartScene();

signals:
    void moveToLogInWindow();
    void moveToSignUpWindow();
    void goBack();
private:
    Ui::StartScene *ui;
};

#endif // STARTSCENE_H
