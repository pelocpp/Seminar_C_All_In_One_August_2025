#include <stdio.h>

#include "Time.h"

static void test_using_struct_01()
{
    struct time now;

    now.hours = 10;
    now.minutes = 15;
    now.seconds = 30;

    struct time than;

    than.hours = 12;
    than.minutes = 30;
    than.seconds = 0;
}

static void test_using_struct_02()
{
    Time now;

    now.hours = 10;
    now.minutes = 15;
    now.seconds = 30;

    Time than = { 12, 30, 0 } ;
    //than.hours = 12;
    //than.minutes = 30;
    //than.seconds = 0;

    // designated initializer syntax
    Time later = {
        .hours = 12,
        .minutes = 30,
        .seconds = 0
    };
}

//static void printTime(Time time)
//{
//    printf("%02d:%02d:%02d\n", time.hours, time.minutes, time.seconds);
//}

static void printTime(const Time* time)
{
    printf("%02d:%02d:%02d\n", time->hours, time->minutes, time->seconds);
}

//static void resetTime(Time time)
//{
//    time.hours = 0;
//    time.minutes = 0;
//    time.seconds = 0;
//}

void resetTime(Time* time)
{
    //time.hours = 0;
    //time.minutes = 0;
    //time.seconds = 0;

    //(*time).hours = 0;
    //(*time).minutes = 0;
    //(*time).seconds = 0;

    time->hours = 0;
    time->minutes = 0;
    time->seconds = 0;
}

int compareTimes(const Time* left, const Time* right)
{
    if (left->hours != right->hours) {
        return 0;
    }
    else if (left->minutes != right->minutes) {
        return 0;
    }
    else if (left->seconds != right->seconds) {
        return 0;
    }
    else {
        return 1;
    }
}

void test_using_struct_03()
{
    Time now = { 10, 55, 0 };
    printTime(&now);

    resetTime(&now);
    printTime(&now);
}

void test_using_struct_04()
{
    Time now = { 10, 55, 0 };
    printTime(&now);

    Time than = { 10, 55, 1 };
    printTime(&than);

    int cmp = compareTimes(&now, &than);

    printf("Vergleich: %d\n", cmp);
}

void test_using_struct()
{
    test_using_struct_04();
}