#include<iostream>

template <class T>
class STU{
public:
    STU(){
        
    }
        //T is real class to crate.
    STU(T *sptr){
        mSptr = sptr;
    }
    
    STU(const T &sptr){
        mSptr = sptr;
    }

    int setPtr(T *sptr){
        mSptr=sptr;
        return 0;
    }

    int add(T *sptr){
        sptr->addRef();
        return 0;
    }

    T* operator->(){
        return mSptr;
    }
    
private:
    T *mSptr;
};

class BeCreate{
public:
    int data;  
};


int main(int argc, char*argv[])
{
    
        //create mode1, create pointer, and set into smart pointer
    BeCreate *clasPtr = new BeCreate();
    STU<BeCreate> sptr1(clasPtr);
    
        //create mode 2, create when creating smart pointer
    STU<BeCreate> sptr2(new BeCreate()) ;

        //create mode3
    BeCreate *clasPtr2 = new BeCreate();
    STU<BeCreate> sptr3;
        //class behavior
    sptr3.setPtr(clasPtr2); //use .

        //use
    sptr3->data = 1;
    printf("sptr1->data:= %d \n", sptr3->data);
    
    return 0;
}
