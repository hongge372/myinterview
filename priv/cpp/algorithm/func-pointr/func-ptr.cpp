#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>


char *(*fptr)();

char *function(){
  char *str = "hello world";
  char *ret = (char *)malloc(strlen(str));
  strcpy(ret, str);
  return ret;
}

int main(int argc, char* argv[])
{

  fptr = function;
  char *str = fptr();

  printf("final str in main: %s \n", str);
  return 0;
}
