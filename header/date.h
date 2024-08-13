#ifndef DATE_H
#define DATE_H

#include <QString>

using namespace std;

class Date {
    int year, month, day;
public:
    Date();
    Date(const int year, const int month, const int day)
    : year(year), month(month), day(day) {}
    Date(const QString&);
    QString toString() const;

};

#endif //DATE_H
