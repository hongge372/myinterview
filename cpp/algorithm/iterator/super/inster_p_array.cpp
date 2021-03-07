#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


int dataSize = 4;
  int i=0;
  int *beCopy = (int *)malloc(sizeof(int)*dataSize);

  vector<int> *vp= new vector<int>;
  vector<int>::iterator it;
  

int copyMem(){
  while(i<4){
    *(beCopy+i) = i*2; 
    i++;
  }

  i=0;
  while(i<4){
    printf("%d  ", *(beCopy+i));
    i++;
  }
  printf("\n");

  vp->insert(vp->end(), 1);

  printf("-->pt vec(size%lu): \n" ,vp->size());
  
  for(it = vp->begin(); it!=vp->end(); it++){
    printf("vp->data %d", *it);
  }
  printf("\n");

  /**
   * 第二个参数和第三个参数是起止指针。如果把第三个参数写成长度，则会出错。
   * 而且止指针是几，代表插入几个数值，（理解成指针就会犯错，因为指针从0起）。
   */
  //vp->insert(vp->end(), beCopy, 4);
  vp->insert(vp->end(), beCopy, beCopy+4);
  
  for(it = vp->begin(); it!=vp->end(); it++){
    printf("vp->data(%d) ", *it);
  }
  printf("\n");
  
  return 0;
}




int main(int argc, char* argv[]){
  copyMem();
  return 0;
}
