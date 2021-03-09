/*
 *参考： https://blog.csdn.net/liang19890820/article/details/61615495
 *
 */ 


#include "singleton1.h"


int main(int argc, char* argv[])
{
    Singleton::GetInstance().doSomething();

        //这里报错，因为会默认做拷贝构造
        //Singleton single = Singleton::GetInstance();
    Singleton &single = Singleton::GetInstance();
    single.doSomething();
    return 0;
}
