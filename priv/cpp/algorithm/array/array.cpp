#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


void fun()
{
  int i=0;
  int a[5]={1,};
  for(i=0;i<5;i++){
    printf("a[%d]:= %d   ", i, a[i]);
  }

  printf("\n");
  //  printf("sizeof(double float):= %d \n", sizeof(double float));
  printf("sizeof(double):= %d \n", sizeof(double));
  printf("sizeof(float):= %d \n", sizeof(float));
  printf("sizeof(long long int):= %d \n", sizeof(long long int));
  printf("sizeof(long int):= %d \n", sizeof(long int));
  printf("sizeof(int):= %d \n", sizeof(int));
  printf("sizeof(char):= %d \n", sizeof(char));
}


int main(int argc, char*argv[])
{
  fun();

  return 0;
}
