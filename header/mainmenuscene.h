#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include <QWidget>

namespace Ui {
class MainMenuScene;
}

class MainMenuScene : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenuScene(QWidget *parent = nullptr);
    ~MainMenuScene();

signals:
    void moveToInquiryWindow();
    void moveToRegisterWindow();
    void moveToDepositAccountWindow();
    void moveToWithdrawAccountWindow();
    void goBack();

private:
    Ui::MainMenuScene *ui;
};

#endif // MAINMENUSCENE_H
