#include <iostream>


class MyClass{
  //public必须，如果没有，默认private
public:
  int &mref;
  MyClass(int &ref):mref(ref){
  }
  void pt(){
    printf("my ref:= %d \n", mref);
  }
};


int main(int arg, char *argv[])
{
  int a=3;
  int &refa=a;
  MyClass my(refa);
  my.pt();
  a=4;
  my.pt();

  return 0;
}
