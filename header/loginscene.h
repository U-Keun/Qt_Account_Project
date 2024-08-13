#ifndef LOGINSCENE_H
#define LOGINSCENE_H

#include <QWidget>

namespace Ui {
class LogInScene;
}

class LogInScene : public QWidget
{
    Q_OBJECT

public:
    explicit LogInScene(QWidget *parent = nullptr);
    ~LogInScene();

signals:
    void moveToMainMenu();
    void goBack();

private:
    Ui::LogInScene *ui;
};

#endif // LOGINSCENE_H
