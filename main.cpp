#include <QApplication>
#include "windowmanager.h"
#include "membermanager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    std::shared_ptr<MemberManager> ptr = std::make_shared<MemberManager>();
    WindowManager window(ptr);

    return a.exec();
}
