#ifndef SINGINSCENE_H
#define SINGINSCENE_H

#include <QMainWindow>

namespace Ui {
class SignUpScene;
}

class SignUpScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUpScene(QWidget *parent = nullptr);
    ~SignUpScene();

signals:
    void validateMember();
    void goBack();

private:
    Ui::SignUpScene *ui;
};

#endif // SINGINSCENE_H
