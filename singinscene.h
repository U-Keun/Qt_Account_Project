#ifndef SINGINSCENE_H
#define SINGINSCENE_H

#include <QMainWindow>

namespace Ui {
class singinScene;
}

class singinScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit singinScene(QWidget *parent = nullptr);
    ~singinScene();

private:
    Ui::singinScene *ui;
};

#endif // SINGINSCENE_H
