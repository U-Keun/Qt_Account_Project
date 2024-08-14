#ifndef INQUIRYSCENE_H
#define INQUIRYSCENE_H

#include <QWidget>
#include <memory>

class Member;
class QStandardItemModel;

namespace Ui {
class InquiryScene;
}

class InquiryScene : public QWidget
{
    Q_OBJECT

public:
    explicit InquiryScene(std::shared_ptr<Member> member, QWidget *parent = nullptr);
    ~InquiryScene();

signals:
    void goBack();

private:
    Ui::InquiryScene *ui;
    std::shared_ptr<Member> member;
    QStandardItemModel *model;
};

#endif // INQUIRYSCENE_H
