#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void dump(char (*p)[SIZE/2])
{
        
}

int main(int argc, char *argv[])
{
    char a[SIZE] = {
        0,1,2,3
    };

    char (*p)[SIZE] = &a;
    char (*p2)[SIZE] = p;
        //强制类型转换是可以这么写的
    char (*p3)[SIZE/2] = (char (*)[SIZE/2])p2;
        //这里如果这样声明,会报错
    char (*)[SIZE] p4;

    dump(p3);
    
    return 0;
}
