#ifndef LOGINSCENE_H
#define LOGINSCENE_H

#include <QWidget>
#include <memory>

class MemberManager;

namespace Ui {
class LogInScene;
}

class LogInScene : public QWidget
{
    Q_OBJECT

public:
    explicit LogInScene(std::shared_ptr<MemberManager>, QWidget *parent = nullptr);
    ~LogInScene();

signals:
    void moveToMainMenu();
    void goBack();
    void logInSucceeded();

private:
    Ui::LogInScene *ui;
    std::shared_ptr<MemberManager> memberManager;

private slots:
    void handleLogIn();

};

#endif // LOGINSCENE_H
