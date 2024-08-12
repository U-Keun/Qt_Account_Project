#include <QApplication>
#include <QPushButton>
#include "WindowManager.h"
#include "globalmanager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MemberManager* manager = new MemberManager();
    GlobalManager& globalManager = GlobalManager::getInstance();
    globalManager.setMemberManager(manager);
    WindowManager s;

    return a.exec();
}
