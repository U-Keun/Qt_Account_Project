#ifndef REGISTERSCENE_H
#define REGISTERSCENE_H

#include <QMainWindow>
#include "GlobalManager.h"


namespace Ui {
class registerScene;
}

class registerScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit registerScene(QWidget *parent = nullptr);
    void registerAccount();
    ~registerScene();

signals:
    void goBack();

private:
    Ui::registerScene *ui;
    GlobalManager& globalManager = GlobalManager::getInstance();
    MemberManager* manager = globalManager.getMemberManager();


public slots :
    void registerMember();
};

#endif // REGISTERSCENE_H
