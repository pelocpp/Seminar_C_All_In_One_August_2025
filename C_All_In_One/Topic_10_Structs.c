#include <stdio.h>

struct time
{
    int  hours;
    int  minutes;
    int  seconds;
};

typedef struct time Time;

void test_using_struct_01()
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

void test_using_struct_02()
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

void test_using_struct()
{
    test_using_struct_02();
}