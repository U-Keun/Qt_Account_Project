//
// Created by u-keun song on 2024. 8. 12..
//

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

class QMainWindow;
class QString;
class MemberManager;

class WindowManager : public QObject {
    Q_OBJECT;

    QMainWindow *mainWindow;
    MemberManager *memberManager;

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

public:
    // WindowManager();
    WindowManager(MemberManager* memberManager);
    ~WindowManager();

};

#endif //WINDOWMANAGER_H
