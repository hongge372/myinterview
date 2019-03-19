#include<iostream>

class FatherClass{
public:
  static void ptlog(){
    printf("In class father \n");
  }
};

class ChildClass{
public:
  static void ptlog(){
    printf("In class child \n");
  }
};


void staticFunc(){
  FatherClass fath;
  ChildClass child;

  fath.ptlog();
  child.ptlog();
}


int main(int argc, char* argv[])
{
  staticFunc();
  return 0;
}
