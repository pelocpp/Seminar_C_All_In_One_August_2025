#include <stdio.h>

struct Status1
{
    unsigned int widthValidated;      // 2 Werte: 0 oder 1 
    unsigned int heightValidated;     // 2 Werte: 0 oder 1 
    unsigned int positionValidated;   // 15 Werte: 0 .. 15
};

/* define same simple structure with bit fields */
struct Status2
{
    unsigned int widthValidated : 1;     // Anzahl Bits !!!!
    unsigned int heightValidated : 1;
    unsigned int positionValidated : 4;
};

// ===============================================

struct Flags
 {
    unsigned char flag_01;  // 0 oder 1
    unsigned char flag_02;
    unsigned char flag_03;
    unsigned char flag_04;
    unsigned char flag_05;
    unsigned char flag_06;
    unsigned char flag_07;
    unsigned char flag_08;
};

 struct FlagsWithBitfield
 {
    unsigned char flag_01 : 1;
    unsigned char flag_02 : 1;
    unsigned char flag_03 : 1;
    unsigned char flag_04 : 1;
    unsigned char flag_05 : 1;
    unsigned char flag_06 : 1;
    unsigned char flag_07 : 1;
    unsigned char flag_08 : 1;
};

// ==================================================

union FirstUnionExample
{
    char   member1;
    short  member2;
    float  member3;
    double member4;
};

// ==========================================

// Wert für rot, gruen, blau und alpha
// Kompakt:   0xFF000000   Rot == FF, der Rest = 0 => Farbe rot

union rgb
{
    unsigned int  color;
    unsigned char bytes_of_color[4];
};

typedef union rgb RGB;

static void unions_rgb()
{
    // designated initializer syntax
    RGB red = { .color = 0x00FF0000 };

    printf("Red:     0x%0X\n", red.color);

    unsigned char a = red.bytes_of_color[3];
    unsigned char r = red.bytes_of_color[2];
    unsigned char g = red.bytes_of_color[1];
    unsigned char b = red.bytes_of_color[0];

    RGB magenta =
    {
        .bytes_of_color[3] = 0,
        .bytes_of_color[2] = 255,
        .bytes_of_color[1] = 0,
        .bytes_of_color[0] = 255
    };

    printf("Magenta: 0x%0X\n", magenta.color);

    RGB yellow = { .color = 0x00FFFF00 };

    printf("Yellow:  Red=0x%02X - Green=0x%02X - Blue=0x%02X\n",
        yellow.bytes_of_color[2],
        yellow.bytes_of_color[1],
        yellow.bytes_of_color[0]
    );
}


// =========================================================

union ipAddress
{
    unsigned int  address;
    unsigned char octets[4];
};

typedef union ipAddress IPAddress;

void test_union_ip_address()
{
    IPAddress localHost = {
        .octets[0] = 1,
        .octets[1] = 0,
        .octets[2] = 0,
        .octets[3] = 127
    };

    unsigned int localHostAddress = localHost.address;

    printf("Localhost: %u.%u.%u.%u\n",
        localHost.octets[3],
        localHost.octets[2],
        localHost.octets[1],
        localHost.octets[1]
    );

    printf("Localhost: %u - %X\n", localHostAddress, localHostAddress);

    IPAddress anotherIPAddress = {
        .octets[0] = 1,
        .octets[1] = 254,
        .octets[2] = 16,
        .octets[3] = 172
    };

    printf("Another IPAddress: %u.%u.%u.%u\n",
        anotherIPAddress.octets[3],
        anotherIPAddress.octets[2],
        anotherIPAddress.octets[1],
        anotherIPAddress.octets[0]
    );

    unsigned int address = anotherIPAddress.address;

    printf("Another IPAddress: %u - %X\n", address, address);
}

// =================================

// Hinter den Kullissen: Umsetzung auf int

// int Medium = 123;   VORSICHT

enum level
{
    Low,
    Medium,
    High
};

// Java, C#:  Level::Medium

typedef enum level Level;

void test_enums()
{
    Level level = Medium;

    switch (level)
    {
    case Low:
        printf("Low Level\n");
        break;
    case Medium:                            // Stilistisch: NO !!!!!!!! NEVER !!!
        printf("Medium Level\n");
        break;
    case High:
        printf("High Level\n");
        break;
    }

    printf("Level: %d\n", level);
}




void test_bitfields_unions_enums_01()
{
    struct Status1 status1;
    status1.heightValidated = 1;

    struct Status2 status2;
    status2.heightValidated = 1;
}

void test_bitfields_unions_enums_02()
{
    unions_rgb();
}


void test_bitfields_unions_enums()
{
    test_enums();
}
