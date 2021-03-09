#include <iostream>
using namespace std;

class cbase{
    
};

struct base{
    cbase b;
    void pt(string para){
        printf("I'm comming, %s \n", para.c_str());
    }
};

//加上typedef后，再次使用 base_stru会报错。
//typedef struct base_stru{
struct base_stru{
    int baseData;
    virtual void vpt()=0;
    base_stru(){
        
    }
    virtual ~base_stru(){
        
    }
};

typedef struct child_stru : base_stru{
    int data;
    child_stru(){
        data = 1;
    }
    ~child_stru(){
        printf("you delete me \n");
    }
    virtual void vpt(){
        printf("child vpt \n");
    }

    void pt(){
        printf("child pt \n");
    }
}CHILD_STRU;


int main(int argc, char*argv[])
{
    string para = "auto";
    struct base base;
    base.pt(para);
    para = "pointer";
    struct base *pBase = (struct base *)malloc(sizeof(base));
    pBase->pt(para);
    

    CHILD_STRU *m_child = (CHILD_STRU *)malloc(sizeof(CHILD_STRU));
    m_child->pt();
        //malloc不能调用虚函数
//    m_child->vpt();
    
    CHILD_STRU *child =new CHILD_STRU();
    child->vpt();
    child->pt();

        //变量，继承的父结构体默认共有
    printf("child->data:= %d \n", child->data);
    child->data = child->baseData = 666;
    printf("child->data:= %d \n", child->data);

        //free不会调用析构函数
    free(m_child);
    delete(child);
    return 0;
}
