#ifndef SINGINSCENE_H
#define SINGINSCENE_H

#include "GlobalManager.h"
#include <QMainWindow>

namespace Ui {
class SignUpScene;
}

class SignUpScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUpScene(QWidget *parent = nullptr);
    ~SignUpScene();
    void signUpMember();

signals:
    void validateMember();
    void goBack();


private:
    Ui::SignUpScene *ui;
    GlobalManager& globalManager = GlobalManager::getInstance();
    MemberManager* manager = globalManager.getMemberManager();
};

#endif // SINGINSCENE_H
