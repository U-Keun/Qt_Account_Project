#ifndef REGISTERSCENE_H
#define REGISTERSCENE_H

#include "date.h"

#include <QWidget>

class MemberManager;

namespace Ui {
class RegisterScene;
}

class RegisterScene : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterScene(std::shared_ptr<MemberManager>, QWidget *parent = nullptr);
    ~RegisterScene();

signals:
    void registerSucceeded();
    void goBack();
    void registerAttempted(const QString&, const long long, const Date);

private:
    Ui::RegisterScene *ui;
    std::shared_ptr<MemberManager> memberManager;

private slots:
    void handleRegister();

};

#endif // REGISTERSCENE_H
