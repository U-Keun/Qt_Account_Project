#include <QApplication>
#include <QPushButton>
#include "WindowManager.h"
#include "MemberManager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    WindowManager s;
    MemberManager m;
    m.registration();

    return QApplication::exec();
}
