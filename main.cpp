#include <QApplication>
#include <QPushButton>
#include "startscene.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    StartScene s;
    s.show();
    return QApplication::exec();
}
