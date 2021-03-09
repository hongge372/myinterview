#include <stdio.h>
#include <iostream>
using namespace std;

int check_sys(){
    int a =0x1122;
    char *p =(char *) &a;
    return (int)*p;
}

int main(int argc, char *argv[]){
    int ret = check_sys();
    if(1 == ret){
        cout << hex << ret <<  " lettle sysm" << endl;
    }else{
        cout << hex << ret << " big sys" << endl;
    }
}
