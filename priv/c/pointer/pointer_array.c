#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int a;
    char *next;
}STU;

#define SIZE 10

int malloc_func(STU *array)
{
    int i = 0;
    for(i =0; i<SIZE; i++){
        STU *stu = (STU *)malloc(sizeof(STU));
        memset(stu, 0, sizeof(STU));
        stu->a = i<<4;
        printf("after remove stu->a:= %d \n", stu->a);
        array[i] = *stu; 
        memset(&array[i], 0, sizeof(STU));
        array[i].a = i;
        printf("after array[i] stu->a:= %d \n", stu->a);
        printf("after array[i].a:= %d \n", array[i].a);
        printf("\n");
    }
    return 0;
}

int malloc_func2(STU *array)
{
    int i = 0;
    for(i =0; i<SIZE; i++){
        STU *stu = (STU *)malloc(sizeof(STU));
        array = stu; 
        memset(array, 0, sizeof(STU));
        array->a = i*3;
        array++;
    }
    return 0;
}

int malloc_func3(STU *array)
{
    int i = 0;
    for(i =0; i<SIZE; i++){
//        STU *stu = (STU *)malloc(sizeof(STU));
//        array = stu; 
        memset(array, 0, sizeof(STU));
        array->a = i*3;
        array++;
    }
    return 0;
}

void dump(STU *array)
{
    int i=0;
    for(i=0; i<SIZE; i++){
        printf("\n%dth array data is : %d", i, array->a);
        array++;
    }        
}

int main(int argc, char* argv[])
{
    STU *array;
    STU *array2;
    STU *array3;
    
    array = (STU *)malloc(sizeof(STU ) * SIZE);
    array2 = (STU *)malloc(sizeof(STU ) * SIZE);
    array3 = (STU *)malloc(sizeof(STU ) * SIZE);
    
    malloc_func(array);
    dump(array);
    printf("\n\n");

    malloc_func2(array);
    dump(array);
    printf("\n\n");

    malloc_func3(array);
    dump(array);
    printf("\n\n");

    return 0;
}
