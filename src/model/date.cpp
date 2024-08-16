#include "date.h"

#include <QString>
#include <QTextStream>
#include <QStringList>
#include <QVector>
#include <ctime>
#include <stdexcept>

#if defined(_WIN32) || defined(_WIN64)
#include <time.h>
#else // POSIX 시스템 (Linux, macOS 등)
#include <unistd.h>
#endif

Date::Date() {
    time_t timer = time(NULL);
    struct tm date;

#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&date, &timer);
#else
    localtime_r(&timer, &date);
#endif
    this->year = date.tm_year + 1900;
    this->month = date.tm_mon + 1;
    this->day = date.tm_mday;
}

QVector<QString> split(const QString& str, char delimiter) {
    const QStringList list = str.split(delimiter);
    return QVector<QString>::fromList(list);
}

Date::Date(const QString& date) {
    QVector<QString> ymd = split(date, '-');

    if (ymd.size() != 3) {
        throw std::invalid_argument("Date format must be YYYY-MM-DD");
    }

    bool yearOk, monthOk, dayOk;
    this->year = ymd[0].toInt(&yearOk);
    this->month = ymd[1].toInt(&monthOk);
    this->day = ymd[2].toInt(&dayOk);

    if (ymd[0].size() != 4) {
        throw std::invalid_argument("Year must be a 4-digit number");
    }

    if (!yearOk || !monthOk || !dayOk ||
        this->month < 1 || this->month > 12 ||
        this->day < 1 || this->day > 31) {
        throw std::invalid_argument("Invalid date format or values out of range");
    }
}

QString Date::toString() const {
    QString result;
    QTextStream oss(&result);
    oss << year << '-'
        << QString("%1").arg(month, 2, 10, QChar('0')) << '-'
        << QString("%1").arg(day, 2, 10, QChar('0'));
    return result;
}
