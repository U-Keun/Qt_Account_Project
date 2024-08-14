#ifndef REGISTERSCENE_H
#define REGISTERSCENE_H

#include "../header/date.h"

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
    void registerAttempted(const QString&, const long long, const Date);

private:
    Ui::RegisterScene *ui;

private slots:
    void handleRegister();

};

#endif // REGISTERSCENE_H
