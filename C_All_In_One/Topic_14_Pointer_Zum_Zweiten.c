#include <stdio.h>
#include <stdlib.h>

void func_01(int n)
{
    printf("n: %d\n", n);
}

void func_02(int* ip)
{
    int value = *ip;

    printf("Value: %d\n", value);
}

void func_03(int** ptr)
{
    int value = **ptr;

    printf("Value: %d\n", value);
}

void func_04(int*** ptr)
{
    int value = ***ptr;

    printf("*** Value: %d\n", value);
}

void pointer_zum_zweiten_01()
{
    int x = 1;

    int* px = &x;

    int** pxx = &px;

    int*** pxxx = &pxx;

    func_01(x);

    func_02(&x);

    func_03(pxx);  // 1030

    func_04(pxxx);  // 1040
}

void pointer_zum_zweiten_02()
{
    int x = 1;
    int* px = &x;
    int** pxx = &px;
    int*** pxxx = &pxx;
    int**** pxxxx = &pxxx;

    // int**** pxxxx2 = & & & & x;   // no !!!

    // ohne den Namen x und px und pxx zu verwenden
    int value = ****pxxxx;
}

void malloc_behind_the_scenes()
{
   // printf("sizeof(int): %d\n", sizeof(int));

    int* ptr = malloc(500);    
    if (ptr == NULL)
        return;

    *ptr = 123;

    // int n = *ptr;    *(ptr+0)
    int n = ptr[0];
    printf("n: %d\n", n);

    n = -1[ptr];   // ptr + (-1) // (-1) +  ptr
    printf("n-1: %d\n", n);

    //n = ptr[-2];
    //printf("n-2: %d\n", n);

    //n = ptr[-3];
    //printf("n-3: %d\n", n);

    //n = ptr[-4];
    n =  (-4)[ptr];
    printf("n-4: %d\n", n);

    //n = *(ptr - 1);
    //printf("n-1: %d\n", n);

    //n = *(ptr - 2);
    //printf("n-2: %d\n", n);

    //n = *(ptr - 3);
    //printf("n-3: %d\n", n);

    //n = *(ptr - 4);
    //printf("n-4: %d\n", n);

    free(ptr);
}


void pointer_zum_zweiten()
{
    malloc_behind_the_scenes();
}