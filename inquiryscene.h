#ifndef INQUIRYSCENE_H
#define INQUIRYSCENE_H
#include "globalmanager.h"

#include <QMainWindow>

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
};

#endif // INQUIRYSCENE_H