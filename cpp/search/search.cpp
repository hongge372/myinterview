#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int search(int *array, int size, int key)
{
  if(!array){
    return -1;
  }
  int low =0, high = size, midle;

  //<= ,等号不能少
  while(low <= high){
    //移动到这里
    midle = (low + high)/2;
    if( *(array+midle) == key ){
      return midle;
    }
    else if(*(array+midle) < key ){
      //key大，向后
      low = midle + 1;
    }
    else{
      //key小，向前
      high = midle - 1;
    }
  }

  return -1;
}


int main(int argc, char* argv[])
{
  int array[10];
  int i;

  for(i=0; i<10; i++){
    array[i]=i;
  }

  for(i=0;i<10;i++)
    cout << "be find: " << search(array, 10, i) << endl;  

  return 0;
}
