模板模式：定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。模板方法使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。

当多个类有相同的方法，并且逻辑相同，只是细节上有差异时，可以考虑使用模板模式。具体的实现上可以将相同的核心算法设计为模板方法，具体的实现细节有子类实现。

缺点:每一个不同的实现都需要一个子类来实现，导致类的个数增加，使得系统更加庞大。

/*
* 关键代码：在抽象类实现通用接口，细节变化在子类实现。
*/

#include <iostream>

using namespace std;

class Product
{
public:
    void product()
    {
        installPartA();
        installPartB();
    }

protected:
    virtual void installPartA() = 0;
    virtual void installPartB() = 0;
};

class ProductA : public Product
{
protected:
    void installPartA() override
    {
        cout << "ProductA install Part1" << endl;
    }

    void installPartB() override
    {
        cout << "ProductA install Part2 << endl;
    }
};

class ProductB : public Product
{
protected:
    void installPartA() override
    {
        cout << "ProductB install Part1" << endl;
    }

    void installPartB() override
    {
        cout << "ProductB install Part2" << endl;
    }
};

int main()
{
    ProductB* p1 = new ProductB();
    p1->product();

    delete p1;
    p1 = nullptr;

    return 0;
}
