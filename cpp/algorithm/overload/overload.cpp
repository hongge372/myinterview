#include<iostream>

class Base1{
    
};

class Base2{
    
};

class Base3{
    
};


class TestStu{
public:
    void test(Base1 base1, Base2 base2, Base3 base3){
        printf("normal call \n");
    }

    void test(Base3 base3, Base2 base2, Base1 base1){
        printf("reverse call \n");
    }        
};



int main(int argc, char* argv[]){
    Base1 b1;
    Base2 b2;
    Base3 b3;

    TestStu test;
    test.test(b1, b2, b3);
    test.test(b3, b2, b1);

        //编译报错，没有这个方法
        //test.test(b2, b3, b1);
}

    
