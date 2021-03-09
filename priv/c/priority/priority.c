#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int func(){
  int be_cmp = 10;
  int status = -2;
  
  //这样写是错误的
  //  if(status = be_cmp){
  //这样写正确
  if(status == be_cmp){
    printf("It's right \n");
  }
  //先把be_cmp赋值给status,然后return status
  return status = be_cmp;
}

int main(int argc, char*argv[])
{
  int ret=100;
  ret = func();
  printf("ret:= %d \n", ret);
  return 0;
}
