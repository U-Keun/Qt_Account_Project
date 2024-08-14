#include <QApplication>
#include <memory>
#include "header/windowmanager.h"
#include "header/membermanager.h"
#include "header/deposit.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // MemberManager *ptr = new MemberManager;
    std::shared_ptr<MemberManager> ptr = std::make_shared<MemberManager>();
    WindowManager window(ptr);

    return a.exec();
}
