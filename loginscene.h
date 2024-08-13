#ifndef LOGINSCENE_H
#define LOGINSCENE_H
#include "globalmanager.h"
#include <QMainWindow>

namespace Ui {
class loginScene;
}

class loginScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginScene(QWidget *parent = nullptr);
    ~loginScene();
    void login();

signals:
    void moveToMainMenu();
    void goBack();

private:
    Ui::loginScene *ui;
    GlobalManager& globalManager = GlobalManager::getInstance();
    MemberManager* manager = globalManager.getMemberManager();
};

#endif // LOGINSCENE_H
