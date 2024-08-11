#ifndef INQUIRYSCENE_H
#define INQUIRYSCENE_H

#include <QMainWindow>

namespace Ui {
class inquiryScene;
}

class inquiryScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit inquiryScene(QWidget *parent = nullptr);
    ~inquiryScene();

signals:
    void goBack();

private:
    Ui::inquiryScene *ui;
};

#endif // INQUIRYSCENE_H
