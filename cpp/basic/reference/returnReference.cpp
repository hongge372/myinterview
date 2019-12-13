#include <iostream>
using namespace std;

class CPPSTU{
public:
    int a;
};

CPPSTU &func()
{
    CPPSTU *stu = new CPPSTU();
    stu->a = 10;
    return *stu;
}

int main(int argc, char*argv[])
{
    CPPSTU st = func();
    cout << "a is " << st.a << endl;
    return 0;
}
