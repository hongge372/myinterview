#include <iostream>
using namespace std;

class father{
public:
  //  static int static_inter = -1;
  static int static_inter;
public:
  static int get_static_inter(){
    return static_inter;
  }

  static void set_static_inter(int i){
    static_inter = i;
  }

  void print(){
    cout << "Father print " << endl;
  }
};

class child:public father{
public:
  static int static_inter;
  void print(){
    cout << "Child print " << endl;
  }
  
  static void set_static_inter(int i){
    static_inter = i;
  }

};

int father::static_inter = 50;
int child::static_inter = 100;

int main(int argc, char *argv[])
{
  child ch;
  
  father::set_static_inter(5);
  child::set_static_inter(101);
  
  cout << "fa static: " << father::get_static_inter() << endl;
  cout << "fa static inter: " << father::static_inter << endl;
  cout << "ch static: " <<  child::static_inter << endl;
  cout << "ch static: " <<  child::father::static_inter << endl;
  cout << "ch static: " <<  father::child::static_inter << endl;
}
