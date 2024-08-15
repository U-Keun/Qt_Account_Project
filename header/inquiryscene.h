#ifndef INQUIRYSCENE_H
#define INQUIRYSCENE_H

#include "member.h"

#include <QWidget>
#include <memory>

class QStandardItemModel;

namespace Ui {
class InquiryScene;
}

class InquiryScene : public QWidget
{
    Q_OBJECT

public:
    explicit InquiryScene(Member* member, QWidget *parent = nullptr);
    ~InquiryScene();

signals:
    void goBack();

private:
    Ui::InquiryScene *ui;
    Member* member;
    QStandardItemModel *model;
};

#endif // INQUIRYSCENE_H
