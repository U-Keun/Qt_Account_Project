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
    void logInAttempted(const QString&, const QString&);

private:
    Ui::LogInScene *ui;

private slots:
    void handleLogIn();

};

#endif // LOGINSCENE_H
