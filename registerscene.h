#ifndef REGISTERSCENE_H
#define REGISTERSCENE_H

#include <QMainWindow>

namespace Ui {
class registerScene;
}

class registerScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit registerScene(QWidget *parent = nullptr);
    ~registerScene();

signals:
    void registerAccount();
    void goBack();

private:
    Ui::registerScene *ui;
};

#endif // REGISTERSCENE_H
