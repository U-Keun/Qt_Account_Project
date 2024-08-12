#include <sstream>
#include <iomanip>
#include <ctime>
#include <vector>

#include "date.h"

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

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;

    vector<string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }

    return result;
}

Date::Date(string date) {
    vector<string> ymd = split(date, '-');
    this->year = stoi(ymd[0]);
    this->month = stoi(ymd[1]);
    this->day = stoi(ymd[2]);
}

string Date::toString() const {
    ostringstream oss;
    oss << year << '-'
        << setw(2) << setfill('0') << month << '-'
        << setw(2) << setfill('0') << day;
    return oss.str();
}