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
        unsigned char f1:4;
        unsigned short f2:5;
        unsigned char f3:7;
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

void bit_field4()
{
    typedef struct{
        unsigned short a:4;
        unsigned char b:5;
        unsigned char c:7;
    }FIELD_STRU4;
    printf("sizeof FIELD_STRU4 := %lu \n", sizeof(FIELD_STRU4));
}

void bit_field5()
{
    typedef struct{
        unsigned short a:4;
        unsigned short b:5;
    }FIELD_STRU5;
    printf("sizeof FIELD_STRU5 := %lu \n", sizeof(FIELD_STRU5));
}

void bit_field6()
{
    typedef struct{
        unsigned short a:4;
        unsigned char b:5;
    }FIELD_STRU6;
    printf("sizeof FIELD_STRU6 := %lu \n", sizeof(FIELD_STRU6));
}

void bit_field7()
{
    typedef struct{
        unsigned char a:4;
        unsigned int b:5;
        unsigned short c:7;
    }FIELD_STRU7;
    printf("sizeof FIELD_STRU7 := %lu \n", sizeof(FIELD_STRU7));
}
int main(int argc, char *argv[])
{

    bit_field();
    bit_field2();
    bit_field3();
    bit_field4();
    bit_field5();
    bit_field6();
    bit_field7();
    return 0;
}
