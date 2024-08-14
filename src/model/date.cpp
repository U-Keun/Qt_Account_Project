#include "../../header/date.h"

#include <QString>
#include <QTextStream>
#include <QStringList>
#include <QVector>
#include <ctime>

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
    this->year = ymd[0].toInt();
    this->month = ymd[1].toInt();
    this->day = ymd[2].toInt();
}

QString Date::toString() const {
    QString result;
    QTextStream oss(&result);
    oss << year << '-'
        << QString("%1").arg(month, 2, 10, QChar('0')) << '-'
        << QString("%1").arg(day, 2, 10, QChar('0'));
    return result;
}