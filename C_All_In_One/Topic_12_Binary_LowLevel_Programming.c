
#include <stdio.h>


void low_level_01_bitwise_and()
{
    unsigned short word1 = 0b1011'0011;

    unsigned short word2 = 0b1100'1101;

    unsigned short word = word1 & word2;

    printf("%08lX\n", word1);
    printf("%08lX\n", word2);
    printf("%08lX\n", word);
}

void low_level_01_bitwise_or()
{
    unsigned short word1 = 0b1011'0001;

    unsigned short word2 = 0b1100'1101;

    unsigned short word = word1 | word2;

    printf("%08lX\n", word1);
    printf("%08lX\n", word2);
    printf("%08lX\n", word);
}

void low_level_01_bitwise_xor()
{
    unsigned short word1 = 0b1011'0001;

    unsigned short word2 = 0b1100'1101;

    unsigned short word = word1 ^ word2;

    printf("%08lX\n", word1);
    printf("%08lX\n", word2);
    printf("%08lX\n", word);
}

void low_level_01_right_shift()
{
    signed short s = 0b1000'1010'1100'0011;

    signed short s2 = s >> 2;

    printf("%08lX\n", s2);
}

void low_level_01_left_shift()
{
    signed short s = 0b1000'1010'1100'0011;

    signed short s2 = s << 2;

    printf("%08lX\n", s2);
}

void setBit(unsigned int value, int pos)
{
    unsigned int mask = 1 << pos;

    value = value | mask;
}

void clearBit(unsigned int value, int pos)
{
    unsigned int mask = ~(1 << pos);

    value = value & mask;
}

void low_level_programming()
{
    low_level_01_left_shift();
}
