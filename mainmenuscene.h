#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include <QMainWindow>

namespace Ui {
class mainmenuScene;
}

class mainmenuScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainmenuScene(QWidget *parent = nullptr);
    ~mainmenuScene();

private:
    Ui::mainmenuScene *ui;
};

#endif // MAINMENUSCENE_H
