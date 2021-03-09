#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct BiTree{
    int data;
    BiTree *lchild;
    BiTree *rchild;
}BiTree;

void firstOrder(BiTree *t, int level){
    if(t == NULL){
        return;
    }
    level++;    
    printf("get data:%d,  at %d", t->data, level);
    
    firstOrder(t->lchild, level);
    firstOrder(t->rchild, level);
}


void middleOrder(BiTree *t, int level){
    if(t == NULL){
        return;
    }
    level++;
    
    middleOrder(t->lchild, level);
    printf("get data:%d,  at %d", t->data, level);
    middleOrder(t->rchild, level);
}

void lastOrder(BiTree *t, int level){
    if(t == NULL){
        return;
    }
    level++;
    
    lastOrder(t->lchild, level);
    lastOrder(t->rchild, level);
    printf("get data:%d,  at %d", t->data, level);
}

int main(int argc, char* argv[])
{    
}
