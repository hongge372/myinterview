#include<stdio.h>
#include<stdlib.h>

void func(){
    static int t = 0;    
}

void func2(){
    t = 2;
}

int main(int argc, char *argv[])
{
    func();
    func2();
    return 0;
}
