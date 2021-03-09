Adapter适配器模式
作用：将一个类的接口转换成客户希望的另外一个接口。Adapter模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。

分为类适配器模式和对象适配器模式。

系统的数据和行为都正确，但接口不符时，我们应该考虑使用适配器，目的是使控制范围之外的一个原有对象与某个接口匹配。适配器模式主要应用于希望复用一些现存的类，但是接口又与复用环境要求不一致的情况。

想使用一个已经存在的类，但如果它的接口，也就是它的方法和你的要求不相同时，就应该考虑用适配器模式。

比如购买的第三方开发组件，该组件接口与我们自己系统的接口不相同，或者由于某种原因无法直接调用该组件，可以考虑适配器。


在Adapter模式的两种模式中，有一个很重要的概念就是接口继承和实现继承的区别和联系。接口继承和实现继承是面向对象领域的两个重要的概念，接口继承指的是通过继承，子类获得了父类的接口，而实现继承指的是通过继承子类获得了父类的实现（并不统共接口）。在C++中的public继承既是接口继承又是实现继承，因为子类在继承了父类后既可以对外提供父类中的接口操作，又可以获得父类的接口实现。当然我们可以通过一定的方式和技术模拟单独的接口继承和实现继承，例如我们可以通过private继承获得实现继承的效果（private继承后，父类中的接口都变为private，当然只能是实现继承了。），通过纯抽象基类模拟接口继承的效果，但是在C++中pure virtual function也可以提供默认实现，因此这是不纯正的接口继承，但是在Java中我们可以interface来获得真正的接口继承了。

using namespace std;

//目标接口类，客户需要的接口
class Target
{
public:
    Target();
    virtual ~Target();
    virtual void Request();//定义标准接口
};

    //需要适配的类
class Adaptee
{
public:
    Adaptee();
    ~Adaptee();
    void SpecificRequest();
};
 
    //类模式，适配器类，通过public继承获得接口继承的效果，通过private继承获得实现继承的效果
class Adapter:public Target,private Adaptee
{
public:
    Adapter();
    ~Adapter();
    virtual void Request();//实现Target定义的Request接口
};
 
    //对象模式，适配器类，继承Target类，采用组合的方式实现Adaptee的复用
class Adapter1:public Target
{
public:
    Adapter1(Adaptee* adaptee);
    Adapter1();
    ~Adapter1();
    virtual void Request();//实现Target定义的Request接口
private:
    Adaptee* _adaptee;
};



Target::Target()
{}

Target::~Target()
{}

void Target::Request()
{
    cout << "Target::Request()" << endl;
}

Adaptee::Adaptee()
{
}
 
Adaptee::~Adaptee()
{
}

void Adaptee::SpecificRequest()
{
    cout << "Adaptee::SpecificRequest()" << endl;
}
 
    //类模式的Adapter
Adapter::Adapter()
{
}
 
Adapter::~Adapter()
{
}
 
void Adapter::Request()
{
    cout << "Adapter::Request()" << endl;
    this->SpecificRequest();
    cout << "----------------------------" <<endl;
}

    //对象模式的Adapter
Adapter1::Adapter1():_adaptee(new Adaptee)
{
}

Adapter1::Adapter1(Adaptee* _adaptee)
{
    this->_adaptee = _adaptee;
}
 
Adapter1::~Adapter1()
{
}

void Adapter1::Request()
{
    cout << "Adapter1::Request()" << endl;
    this->_adaptee->SpecificRequest();
    cout << "----------------------------" <<endl;
}

 int main()
 {
         //类模式Adapter
     Target* pTarget = new Adapter();
     pTarget->Request();
     
         //对象模式Adapter1
     Adaptee* ade = new Adaptee();
     Target* pTarget1= new Adapter1(ade);
     pTarget1->Request();
 
         //对象模式Adapter2
     Target* pTarget2 = new Adapter1();
     pTarget2->Request();
     
     return 0;
}
