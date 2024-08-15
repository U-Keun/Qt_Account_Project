#include <QApplication>
#include "header/windowmanager.h"
#include "header/membermanager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    std::unique_ptr<MemberManager> ptr = std::make_unique<MemberManager>();
    WindowManager window(std::move(ptr));

    return a.exec();
}
