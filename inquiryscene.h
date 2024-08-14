#ifndef INQUIRYSCENE_H
#define INQUIRYSCENE_H
#include "globalmanager.h"
#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class inquiryScene;
}

class inquiryScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit inquiryScene(QWidget *parent = nullptr);
    ~inquiryScene();

signals:
    void goBack();

private:
    Ui::inquiryScene *ui;
    GlobalManager& globalManager = GlobalManager::getInstance();
    MemberManager* manager = globalManager.getMemberManager();
    Member*currentMember = manager->getCurrentMember();
    //테이블뷰에 모델 속성을 추가해서 만지면 코드로 제어가 된다네요
    QStandardItemModel *model;
    void showAccountData();
};

#endif // INQUIRYSCENE_H
