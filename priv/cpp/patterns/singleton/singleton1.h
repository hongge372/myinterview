#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include<iostream>
using namespace std;

class Singleton
{
  public:
    static Singleton& GetInstance(){
        static Singleton instance;
        return instance;
    }

    void doSomething(){
        cout << "Do something" << endl;
    }

  private:
    Singleton(){
        
    }

    Singleton(Singleton const&);
    Singleton& operator = (const Singleton &);
};


#endif //__SINGLETON_H__
