#ifndef INQUIRYSCENE_H
#define INQUIRYSCENE_H

#include <QWidget>

namespace Ui {
class InquiryScene;
}

class InquiryScene : public QWidget
{
    Q_OBJECT

public:
    explicit InquiryScene(QWidget *parent = nullptr);
    ~InquiryScene();

signals:
    void goBack();

private:
    Ui::InquiryScene *ui;
};

#endif // INQUIRYSCENE_H
