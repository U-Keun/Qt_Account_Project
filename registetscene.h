#ifndef REGISTETSCENE_H
#define REGISTETSCENE_H

#include <QMainWindow>

namespace Ui {
class registetScene;
}

class registetScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit registetScene(QWidget *parent = nullptr);
    ~registetScene();

private:
    Ui::registetScene *ui;
};

#endif // REGISTETSCENE_H
