#include<iostream>


//我们可以简单多以为，默认参数以一当二,相当于两个函数的合集
class DefaultPara_Overload_Stu{
    void func(int a){
        printf("on para only \n");
    }
//我们可以简单多以为，默认参数以一当二
#if 0
    void func(int a, int b=0, int c=0){
        printf("three para and two default \n");
    }
#endif
    void func(int a, int b, int c){
        printf("three para no default \n");
    }
};

//默认参数和非默认参数不能共存,多和少的都不行
class DefaultPara_Overload_Stu2{
        //默认参数和非默认参数不能共存
#if 0
    void func(int a){
        printf("on para only \n");
    }
#else
    void func(int a, int b=0, int c=0){
        printf("three para and two default \n");
    }
#endif
};


class DefaultPara_Overload_Stu3{
        //默认参数和非默认参数不能共存
#if 0
    void func(int a, int b=0, int c=0){
        printf("three para and two default \n");
    }
#else
    void func(int a, int b, int c){
        printf("three para no default \n");
    }
#endif
};



int main(int argc, char *argv[])
{

    return 0;
}
