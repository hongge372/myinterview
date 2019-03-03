#include <stdio.h>
#include <stdlib.h>


#define FUNC_MACRO(flg)                                           \
    do{                                                           \
        int t_a = 10;                                             \
        if( !!flg)  {                                             \
            t_a ++;                                               \
            flg = t_a;                                            \
        }                                                         \
        printf("in macro, flg:= %d, t_a:= %d \n", flg, t_a);      \
    }while(0)


void func()
{
    int t_a =100;
    int flg =1;
    FUNC_MACRO(flg);
    printf("outof macro flg := %d \n", flg);
}


int main(int argc, char *argv[])
{
    func();
    return 0;
}
