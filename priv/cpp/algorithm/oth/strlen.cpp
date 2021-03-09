#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[])
{
  int aa =10;
  const char *p="abcde";
  char a[]={'a', 'b', 'c', 'd', 'e', '\0'};
  char b[]="abcde";

  //printf("strlen(p):=%ld \n", strlen(p));
  printf("strlen(a):=%ld \n", strlen(a));
  printf("strlen(b):=%ld \n", strlen(b));

  printf("sizeof(char):= %ld \n", sizeof(char));
  return 0;
}
