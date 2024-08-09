#include "withdrawaccount.h"
#include "ui_withdrawaccount.h"

withdrawaccount::withdrawaccount(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::withdrawaccount)
{
    ui->setupUi(this);
}

withdrawaccount::~withdrawaccount()
{
    delete ui;
}
