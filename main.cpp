#include <QApplication>
#include <memory>
#include "header/windowmanager.h"
#include "header/membermanager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    unique_ptr<MemberManager> ptr = make_unique<MemberManager>();
    WindowManager window(std::move(ptr));

    return QApplication::exec();
}
