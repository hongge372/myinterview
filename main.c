#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

    int *p = NULL;
    int a = 3;

    p = &a;
//打印一个变量,输出的是这个变量的值
    printf(" a  %d \n",  a);
//打印一个变量的地址,输出的是存储这个变量的地址
    printf(" &a %p \n",  &a);
//指针也是变量,它存储的是一个变量的地址,学名是它指向一个变量的地址
//当我们打印一个指针时,输出的是这个指针的值,这个值是一个变量的地址
    printf(" p  %p \n",  p);  //输出就是a的地址
//当我们打印一个指针的地址时,输出的是存储这个指针的地址
    printf(" &p %p \n",  &p); //输出的是p的地址,这个地址所存储的值是a的地址
//如果我们想取出指针所指向的变量的值,要加 *
    printf(" *p %d \n",  *p); //p是一个指针,它的值是a的地址,p等价&a,*p是a的值
    return 0;
}
