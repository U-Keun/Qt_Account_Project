#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include <QMainWindow>

namespace Ui {
class mainmenuScene;
}

class mainmenuScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainmenuScene(QWidget *parent = nullptr);
    ~mainmenuScene();

signals:
    void moveToInquiryWindow();
    void moveToRegisterWindow();
    void moveToDepositAccountWindow();
    void moveToWithdrawAccountWindow();
    void goBack();

private:
    Ui::mainmenuScene *ui;
};

#endif // MAINMENUSCENE_H
