#include <stdio.h>
#include <stdlib.h>

typedef struct{
    long a:64;
}STU;

typedef struct{
    int data;
    char *p;
    short short_data;
    char char_array[2];
    short shor_array[4];
}STU_SIZE_STRU;

void test_size()
{
    int a = 99;
    char *p =(char *) &a;
    int *p_int;
        
    printf("sizeof(char): %lu\n", sizeof(char));
    printf("sizeof(short):%lu\n", sizeof(short));
    printf("sizeof(int):  %lu\n", sizeof(int));
    printf("sizeof(long): %lu\n", sizeof(long));
    printf("sizeof(long int): %lu\n ", sizeof(long int));
    printf("sizeof(long long): %lu\n ", sizeof(long long));
    printf("sizeof(long long int): %lu\n ", sizeof(long long int));

    printf("sizeof(*p(*char)): %lu\n ", sizeof(*p));
    printf("sizeof(p):  %lu\n ", sizeof(p));

    printf("sizeof(STU_SIZE_STRU) %lu\n  ", sizeof(STU_SIZE_STRU));

    printf("sizeof(*int):= %lu \n", sizeof(*p_int));
}


int main(int argc, char *argv[])
{
    test_size();
    return 0;
}
