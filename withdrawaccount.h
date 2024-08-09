#ifndef WITHDRAWACCOUNT_H
#define WITHDRAWACCOUNT_H

#include <QMainWindow>

namespace Ui {
class withdrawaccount;
}

class withdrawaccount : public QMainWindow
{
    Q_OBJECT

public:
    explicit withdrawaccount(QWidget *parent = nullptr);
    ~withdrawaccount();

private:
    Ui::withdrawaccount *ui;
};

#endif // WITHDRAWACCOUNT_H
