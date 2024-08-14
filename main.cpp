#include <QApplication>
#include "header/windowmanager.h"
#include "header/membermanager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // MemberManager data;
    WindowManager window;

    return QApplication::exec();
}
