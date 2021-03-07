#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class Basic{
private:
    int priData;
protected:
    int proData;
public:
    int pubData;
private:
    virtual void func(){
        cout<< "Private in basic, I'm ok" << endl;
    }
};

class PriChild:private Basic{
public:
        //编译器报错
        //using Basic::priData;
    using Basic::proData;
};

class ProChild:protected Basic{
public:
        //编译器报错
        //using Basic::priData;
    using Basic::proData;
};

//没有默认public
class PubChild:Basic{
//class PubChild:public Basic{
public:
    using Basic::pubData;
    virtual void func(){
        cout<< "Public child, I'm ok" << endl;
    }
};

int main(int argc, char* argv[])
{
        //变量----------------
    PriChild priChild;
    priChild.proData = 1;
    cout << "private is ok, change into public and data: " << priChild.proData << endl;
    ProChild proChild;
    proChild.proData = 2;
    cout << "protected is ok, change into public and data: " << proChild.proData << endl;
    
    PubChild pubChild;
    pubChild.pubData = 3;
    cout << "public is ok, and data: " << pubChild.pubData << endl;

        //方法----------------
    Basic basic;
        //basic.func(); //会报错
    PubChild child;
    child.func();
    return 0;
}
