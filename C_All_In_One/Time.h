// ===================================
// types

struct time
{
    int  hours;
    int  minutes;
    int  seconds;
};

typedef struct time Time;

// ==================================
// methods // functions operating on type Time

extern void printTime(const Time* time);
extern void resetTime(Time* time);
extern int compareTimes(const Time* left, const Time* right);

