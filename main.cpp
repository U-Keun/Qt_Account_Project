#include <QApplication>
#include <memory>
#include "header/windowmanager.h"
#include "header/membermanager.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    const unique_ptr<MemberManager> ptr(new MemberManager());
    WindowManager window(ptr.get());

    return QApplication::exec();
}
