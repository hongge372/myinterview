#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
        //only success on 64bit mode
        //32 bit node will err
    long a:64;
}STRU;

void bit_field()
{
    typedef struct{
        char f1:3;
        short f2:4;
        char f3:5;
    }FIELD_STRU;

    printf("sizeof(FIELD_STRU):= %lu \n", sizeof(FIELD_STRU));
}

void bit_field2(){
    typedef struct{
        unsigned short a:4;
        unsigned short b:5;
        unsigned short c:7;
     }FIELD_STRU2;

    int i;
    FIELD_STRU2 test;
    memset(&test, 0, sizeof(FIELD_STRU2));
    test.a=2;
    test.b=3;
    test.c=0;
    i=*((short*)&test);
    printf("short filed stru cast short %d \n", i);
}

void bit_field3()
{
    typedef struct{
        unsigned char a:4;
        unsigned char b:5;
        unsigned char c:7;
    }FIELD_STRU3;

    printf("sizeof(FIELD_STRU3):= %lu \n", sizeof(FIELD_STRU3));
}

int main(int argc, char *argv[])
{

    bit_field();
    bit_field2();
    bit_field3();
    return 0;
}
