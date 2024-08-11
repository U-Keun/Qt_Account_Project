#ifndef SINGINSCENE_H
#define SINGINSCENE_H

#include <QMainWindow>

namespace Ui {
class signinScene;
}

class signinScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit signinScene(QWidget *parent = nullptr);
    ~signinScene();

signals:
    void validateMember();
    void goBack();

private:
    Ui::signinScene *ui;
};

#endif // SINGINSCENE_H
