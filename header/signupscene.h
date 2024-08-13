#ifndef SIGNUPSCENE_H
#define SIGNUPSCENE_H

#include <QWidget>

namespace Ui {
class SignUpScene;
}

class SignUpScene : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpScene(QWidget *parent = nullptr);
    ~SignUpScene();

signals:
    void validateSignUp();
    void goBack();

private:
    Ui::SignUpScene *ui;
};

#endif // SIGNUPSCENE_H
