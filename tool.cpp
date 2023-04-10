#include "tool.h"

void timeToString(time_t t, char *Buf) {
    tm *timeinfo;
    timeinfo = localtime(&t);
    strftime(Buf, 20, "%Y-%m-%d %H:%M", timeinfo);
}

time_t stringToTime(char *Time) {
    tm tm1{};
    sscanf(Time, "%d-%d-%d %d:%d", &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday, &tm1.tm_hour, &tm1.tm_min);
    tm1.tm_year -= 1900;
    tm1.tm_mon -= 1;
    tm1.tm_sec = 0;
    tm1.tm_isdst = -1;
    return mktime(&tm1);
}