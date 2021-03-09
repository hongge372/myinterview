#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;


class Test{
public:
  Test(int a){
    this->value = a;
  }
  
  ~Test(){
  }

  void setValue(int value){
    this->value = value;
  }
  
  const int *getValue()const&{
    const int *tmp = &value;
    return tmp;
  }

private:
  int value;
};


int main(int argc, char* argv[])
{
  Test test(5);
  const int *rValue = test.getValue();
  cout << "this->value:= " << *rValue << endl;

  return 0;
}
