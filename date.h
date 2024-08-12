#include <string>

using namespace std;

#ifndef DATE_H
#define DATE_H

class Date {
    int year, month, day;
public:
    Date();
    Date(const int year, const int month, const int day)
    : year(year), month(month), day(day) {}
    Date(string);
    string toString() const;

};

#endif //DATE_H
