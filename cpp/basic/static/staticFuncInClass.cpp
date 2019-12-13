#include<iostream>

class FatherClass{
public:
    static void ptlog(){
        printf("In class father \n");
    }
};

class ChildClass{
public:
    static void ptlog(){
        printf("In class child \n");
            //静态方法不能调用非静态方法，报错
            //normalBeCall();
    }

    void normalCall(){
            //非静态方法可以调用静态方法
        ptlog();        
    }

    void normalBeCall(){
        printf("if ok? \n");
    }
};


void callStatic(){
    FatherClass fath;
    ChildClass child;

    fath.ptlog();
    child.ptlog();
}


int main(int argc, char* argv[])
{
    callStatic();
    return 0;
}
