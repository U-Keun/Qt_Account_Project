#include <QApplication>
#include <QPushButton>
#include "header/windowmanager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    WindowManager window;

    return QApplication::exec();
}
