#ifndef SIGNUPSCENE_H
#define SIGNUPSCENE_H

#include <QWidget>

class MemberManager;

namespace Ui {
class SignUpScene;
}

class SignUpScene : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpScene(std::shared_ptr<MemberManager>, QWidget *parent = nullptr);
    ~SignUpScene();

signals:
    void goBack();
    void signUpSucceeded();

private:
    Ui::SignUpScene *ui;
    std::shared_ptr<MemberManager> memberManager;

private slots:
    void handleSignUp();

};

#endif // SIGNUPSCENE_H
