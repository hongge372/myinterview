#include<iostream>

class DEFAULT_PARA{
public:
    void func(int a, int b=1, int c=2){
        printf("defaut start from second \n");
    }
        //定一个就够了
#if 0
    void func(int a, int b, int c=2){
        printf("defaut start from second \n");
    }
#endif
};

int main(int argc, char *argv[])
{
    DEFAULT_PARA d;
    d.func(1);
    d.func(1, 2);
    d.func(1,2,3);

    return 0;
}
