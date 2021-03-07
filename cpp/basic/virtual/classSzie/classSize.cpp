#include<stdio.h>
#include<iostream>
using namespace std;

//!!!!!!!!!!!!!!!!!!!!!!!!!
//32位指针4字节，64指针8字节
//!!!!!!!!!!!!!!!!!!!!!!!!!

void funStru(){
        //对齐，char占用4字节
    typedef struct{
        char a;
        int b;
    }CHAR_INT;
    cout << "sizeof(CHAR_INT): " << sizeof(CHAR_INT) << endl;

        //对齐，两个char占用4字节
    typedef struct{
        char a;
        char a2;
        int b;
    }CHAR_CHAR_INT;
    cout << "sizeof(CHAR_CHAR_INT): " << sizeof(CHAR_CHAR_INT) << endl;

        //对齐，第一个char占用4字节，第三个char占用4字节
    typedef struct{
        char a;
        int b;
        char a2;
    }CHAR_INT_CHAR;
    cout << "sizeof(CHAR_INT_CHAR): " << sizeof(CHAR_INT_CHAR) << endl;
}

void funClass(){
        //空class，占一位，长度为1
    class Blank{
    
    };
    cout << "sizeof blank: " << sizeof(Blank) << endl;
    
//普通函数不占位
//int占用4字节，内部有数据，之前占位取消，长度为4
    class FuncClass{
        int data; 
        void func(){
        
        }
    };
    cout << "sizeof func class: " << sizeof(FuncClass) << endl;

//两个int，共8位
    class FuncClass2{
        int data; 
        int data2;
        void func(){
        
        }
    };
    cout << "sizeof func class 2: " << sizeof(FuncClass2) << endl;

//虚函数表，占八位
    class VirtualFunClass{
        virtual void func(){
        
        }
    };
    cout << "sizeof virtual Func class: " << sizeof(VirtualFunClass) << endl;

//最长对齐原则，共16位
    class VirtualFunClassWithData{
        int data;
        virtual void func(){
        
        }
    };
    cout << "sizeof virtual Func class with data: " << sizeof(VirtualFunClassWithData) << endl;

//最长对齐原则，共16位
    class VirtualFunClassWithData2{
        int data;
        int data2;
        virtual void func(){
        
        }
    };
    cout << "sizeof virtual Func class with data 2: " << sizeof(VirtualFunClassWithData2) << endl;

//变量自动对齐，对齐方式与虚函数表无关
//最长对齐原则，共16位
    class VirtualFunClassWithData3{
        int data;
        virtual void func(){
        
        }
        int data2;
    };
    cout << "sizeof virtual Func class with data 3: " << sizeof(VirtualFunClassWithData3) << endl;

//不论多少个虚函数，都只有一个虚函数表。占用8位
    class VirtualFunClassWithData4{
        int data;
        virtual void func(){
        
        }
        virtual void func2(){
        
        }
    };
    cout << "sizeof virtual Func class with data 4: " << sizeof(VirtualFunClassWithData4) << endl;
}

int main(int argc, char* argv[]){
    cout << "-------------------->" << endl;
    funStru();
    cout << "-------------------->" << endl;
    funClass();
    return 0;
}
