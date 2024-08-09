#ifndef LOGINSCENE_H
#define LOGINSCENE_H

#include <QMainWindow>

namespace Ui {
class loginScene;
}

class loginScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginScene(QWidget *parent = nullptr);
    ~loginScene();

private:
    Ui::loginScene *ui;
};

#endif // LOGINSCENE_H
