建造者模式：将复杂对象的构建和其表示分离，使得相同的构建过程可以产生不同的表示。

以下情形可以考虑使用建造者模式：

对象的创建复杂，但是其各个部分的子对象创建算法一定。
需求变化大，构造复杂对象的子对象经常变化，但将其组合在一起的算法相对稳定。
建造者模式的优点：

将对象的创建和表示分离，客户端不需要了解具体的构建细节。
增加新的产品对象时，只需要增加其具体的建造类即可，不需要修改原来的代码，扩展方便。
产品之间差异性大，内部变化较大、较复杂时不建议使用建造者模式。

/*
*关键代码：建造者类：创建和提供实例； Director类：管理建造出来的实例的依赖关系。
*/

#include <iostream>
#include <string>

using namespace std;

//具体的产品类
class Order
{
public:
    void setProductA(const string& productA)
    {
        m_strProductA = productA;
    }

    const string& productA()
    {
        cout << m_strProductA.data() << endl;
        return m_strProductA;
    }
    
    void setProductB(const string& productB)
    {
        m_strProductB = productB;
    }

    const string& productB()
    {
        cout << m_strProductB << endl;
        return m_strProductB;
    }

private:
    string m_strProductA;
    string m_strProductB;
};

//抽象建造类，提供建造接口。
class OrderBuilder
{
public:
    virtual ~OrderBuilder()
    {
        cout << "~OrderBuilder()" << endl;
    }
    virtual void setOrderProductA() = 0;
    virtual void setOrderProductB() = 0;
    virtual Order* getOrder() = 0;
};

//具体的建造类
class VegetarianOrderBuilder : public OrderBuilder 
{
public:
    VegetarianOrderBuilder()
    {
        m_pOrder = new Order;
    }

    ~VegetarianOrderBuilder()
    {
        cout << "~VegetarianOrderBuilder()" << endl;
        delete m_pOrder;
        m_pOrder = nullptr;
    }

    void setOrderProductA() override
    {
        m_pOrder->setProductA("vegetable salad");
    }

    void setOrderProductB() override
    {
        m_pOrder->setProductB("water");
    }

    Order* getOrder() override
    {
        return m_pOrder;
    }

private:
    Order* m_pOrder;
};

//具体的建造类
class MeatOrderBuilder : public OrderBuilder
{
public:
    MeatOrderBuilder()
    {
        m_pOrder = new Order;
    }
    ~MeatOrderBuilder()
    {
        cout << "~MeatOrderBuilder()" << endl;
        delete m_pOrder;
        m_pOrder = nullptr;
    }

    void setOrderProductA() override
    {
        m_pOrder->setProductA("beef");
    }

    void setOrderProductB() override
    {
        m_pOrder->setProductB("beer");
    }

    Order* getOrder() override
    {
        return m_pOrder;
    }

private:
    Order* m_pOrder;
};

//Director类，负责管理实例创建的依赖关系，指挥构建者类创建实例
class Director
{
public:
    Director(OrderBuilder* builder) : m_pOrderBuilder(builder)
    {
    }
    void construct()
    {
        m_pOrderBuilder->setOrderProductA();
        m_pOrderBuilder->setOrderProductB();
    }

private:
    OrderBuilder* m_pOrderBuilder;
};


int main()
{
//  MeatOrderBuilder* mBuilder = new MeatOrderBuilder;
    OrderBuilder* mBuilder = new MeatOrderBuilder;  //注意抽象构建类必须有虚析构函数，解析时才会                                                      调用子类的析构函数
    Director* director = new Director(mBuilder);
    director->construct();
Order* order = mBuilder->getOrder();
order->productA();
order->productB();

delete director;
director = nullptr;

delete mBuilder;
mBuilder = nullptr;

return 0;
}
