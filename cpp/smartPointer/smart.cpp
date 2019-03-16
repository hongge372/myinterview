#include <iostream>
#include <memory>

class Man{
};

void func(std::shared_ptr<Man> pM){
  printf("pm.count:= %lu \n", pM.use_count());
}


int main(){
  std::shared_ptr<Man> pM (new Man());
  printf("pm.count:= %lu \n", pM.use_count());
  func(pM);
  printf("pm.count:= %lu \n", pM.use_count());
}
