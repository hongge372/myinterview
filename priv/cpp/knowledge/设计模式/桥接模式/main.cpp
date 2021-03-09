桥接模式：将抽象部分与实现部分分离，使它们都可以独立变换。

以下情形考虑使用桥接模式：

当一个对象有多个变化因素的时候，考虑依赖于抽象的实现，而不是具体的实现。
当多个变化因素在多个对象间共享时，考虑将这部分变化的部分抽象出来再聚合/合成进来。
当一个对象的多个变化因素可以动态变化的时候。
优点：

将实现抽离出来，再实现抽象，使得对象的具体实现依赖于抽象，满足了依赖倒转原则。
更好的可扩展性。
可动态的切换实现。桥接模式实现了抽象和实现的分离，在实现桥接模式时，就可以实现动态的选择具体的实现。

/*
* 关键代码：将现实独立出来，抽象类依赖现实类。
* 以下示例中，将各类App、各类手机独立开来，实现各种App和各种手机的自由桥接。
*/
#include <iostream>

using namespace std;

//抽象App类，提供接口
class Product
{
public:
    virtual ~Product(){ cout << "~App()" << endl; }
    virtual void run() = 0;
};

//具体的Product实现类
class V1Product:public Product
{
public:
    void run()
    {
        cout << "V1Product Running" << endl;
    }
};

//具体的Product实现类
class V2Product:public Product
{
public:
    void run()
    {
        cout << "V2Product Running" << endl;
    }
};

//抽象手机类，提供接口
class Factory
{
public:
    virtual ~Factory(){ cout << "~Factory()" << endl;}
    virtual void productRun(Product* product) = 0;  //实现Product与手机的桥接
};

//具体的手机实现类
class AFactory:public Factory
{
public:
    void productRun(Product* product)
    {
        cout << "AFactory: ";
        product->run();
    }
};

//具体的手机实现类
class BFactory:public Factory
{
public:
    void productRun(Product* product)
    {
        cout << "BFactory: ";
        product->run();
    }
};

int main()
{
    Product* v1Product = new V1Product;
    Product* v2Product = new V2Product;
    Factory* af = new AFactory;
    Factory* bf = new BFactory;
    af->productRun(v1Product);
    af->productRun(v2Product);
    bf->productRun(v1Product);
    bf->productRun(v2Product);

    delete bf;
    bf = nullptr;
    delete af;
    af = nullptr;
    delete v1Product;
    v1Product = nullptr;
    delete v2Product;
    v2Product = nullptr;

    return 0;
}
