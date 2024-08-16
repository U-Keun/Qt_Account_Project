#include "registerscene.h"
#include "membermanager.h"
#include "ui_registerscene.h"

#include <QMessageBox>
#include <QDate>
#include <stdexcept>

using namespace std;

RegisterScene::RegisterScene(std::shared_ptr<MemberManager> memberManager, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterScene)
    , memberManager(memberManager)
{
    ui->setupUi(this);
    QString currentDate = QDate::currentDate().toString("yyyy-MM-dd");
    ui->date->setText(currentDate);

    connect(ui->registerButton, &QPushButton::clicked, this, &RegisterScene::handleRegister);
    connect(ui->goBackButton, &QPushButton::clicked, this, &RegisterScene::goBack);
}

RegisterScene::~RegisterScene()
{
    delete ui;
}

void RegisterScene::handleRegister() {
    QString accountName = ui->accountName->text(),
        balance = ui->balance->text(),
        date = ui->date->text();


    bool isValidBalance = false;
    long long balanceValue = balance.toLongLong(&isValidBalance);

    if (!isValidBalance) {
        QMessageBox::warning(this, "Invalid Input", "Balance must be a numeric value.");
        return;
    }

    Date parsedDate;

    try {
        parsedDate = Date(date);
    } catch (const std::invalid_argument& e) {
        QMessageBox::warning(this, "Invalid Input", "Date must be in YYYY-MM-DD format.");
        return;
    } catch (...) {
        QMessageBox::warning(this, "Invalid Input", "An unknown error occurred while parsing the date.");
        return;
    }

    if (memberManager->addAccount(accountName, balanceValue, parsedDate)) {
        QMessageBox::information(nullptr, "Information", "Register success!");
        emit registerSucceeded();
        return;
    }

    QMessageBox::warning(nullptr, "Warning", "Register failed.");
}
