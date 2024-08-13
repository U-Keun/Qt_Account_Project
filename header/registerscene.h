#ifndef REGISTERSCENE_H
#define REGISTERSCENE_H

#include <QWidget>

namespace Ui {
class RegisterScene;
}

class RegisterScene : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterScene(QWidget *parent = nullptr);
    ~RegisterScene();

signals:
    void registerAccount();
    void goBack();

private:
    Ui::RegisterScene *ui;
};

#endif // REGISTERSCENE_H
