//
// Created by u-keun song on 2024. 8. 12..
//

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <memory>

using namespace std;

class QMainWindow;
class QString;
class MemberManager;
class Date;

class WindowManager : public QObject {
    Q_OBJECT;

    QMainWindow *mainWindow;
    unique_ptr<MemberManager> memberManager;

    void setCentralWidget(QWidget *widget);
    void setUpStartScene();
    void setUpLogInScene();
    void setUpSignUpScene();
    void setUpMainMenu();
    void setUpInquiryScene();
    void setUpRegisterScene();
    void setUpDepositAccountScene();
    void setUpWithdrawAccountScene();
    void setUpDepositScene();
    void setUpWithdrawScene();


private slots:
    // business logic
    void handleLogInAttempt(const QString&, const QString&);
    void handleSignUpAttempt(const QString&, const QString&, const QString&);
    void handleRegisterAttempt(const QString&, const long long, const Date);

public:
    WindowManager(unique_ptr<MemberManager>);
    ~WindowManager();

};

#endif //WINDOWMANAGER_H
