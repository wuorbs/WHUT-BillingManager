#include "tool.h"

// 定义函数timeToString，将时间转换成字符串格式
void timeToString(time_t t, char *Buf) {
    tm *timeinfo;
    timeinfo = localtime(&t);
    strftime(Buf, 20, "%Y-%m-%d %H:%M", timeinfo);
}

// 定义函数stringToTime，将字符串格式的时间转换成time_t类型
time_t stringToTime(char *Time) {
    tm tm1{};
    // 使用sscanf函数将字符串中的时间数据读入tm结构体
    sscanf(Time, "%d-%d-%d %d:%d", &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday, &tm1.tm_hour, &tm1.tm_min);
    tm1.tm_year -= 1900;
    tm1.tm_mon -= 1;
    tm1.tm_sec = 0;
    // 设置tm_isdst为-1，表示使用本地时区
    tm1.tm_isdst = -1;
    return mktime(&tm1);
}