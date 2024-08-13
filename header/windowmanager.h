//
// Created by u-keun song on 2024. 8. 12..
//

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

class QMainWindow;

class WindowManager : public QObject {
    Q_OBJECT;

    QMainWindow *mainWindow;

    void setCentralWidget(QWidget *widget);
    void setUpStartScene();
    void setUpLogInScene();
    void setUpSignUpScene();
    void setUpMainMenu();
    void setUpInquiryScene();
    void setUpRegisterScene();
    void setUpDepositAccountScene();
    void setUpWithdrawAccountScene();

public:
    WindowManager();
    ~WindowManager();

};

#endif //WINDOWMANAGER_H