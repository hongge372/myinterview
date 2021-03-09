//缺点：产品类数据较多时，需要实现大量的工厂类，这无疑增加了代码量。

/*
关键代码：创建过程在其子类执行。
*/

#include <iostream>

using namespace std;

//产品抽象类
class Product
{
public:
    virtual const string& type() = 0;
};

//具体的产品类
class ProductPa : public Product
{
public:
    ProductPa():Product(),m_strType("ProductPa")
    {
    }

    const string& type() override
    {
        cout << m_strType.data() << endl;
        return m_strType;
    }
private:
    string m_strType;
};

//具体的产品类
class ProductPb : public Product
{
public:
    ProductPb():Product(),m_strType("ProductPb")
    {
    }
    const string& type() override
    {
        cout << m_strType.data() << endl;
        return m_strType;
    }

private:
    string m_strType;
}; 

//抽象工厂类，提供一个创建接口
class ProductFactory
{
public:
    //提供创建产品实例的接口，返回抽象产品类
    virtual Product* createProduct() = 0;
};

//具体的创建工厂类，使用抽象工厂类提供的接口，去创建具体的产品实例
class ProductPaFactory : public ProductFactory
{
public:
    Product* createProduct() override
    {
        return new ProductPa();
    }
};

//具体的创建工厂类，使用抽象工厂类提供的接口，去创建具体的产品实例
class ProductPbFactory : public ProductFactory
{
public:
    Product* createProduct() override
    {
        return new ProductPb();
    }
};


int main()
{
    ProductFactory* factoryPa = new ProductPaFactory();
    Product* productPa = factoryPa->createProduct();
    productPa->type();
    
    ProductFactory* factoryPb = new ProductPbFactory();
    Product* productPb = factoryPb->createProduct();
    productPb->type();

    delete productPb;
    productPb = nullptr;
    delete factoryPb;
    factoryPb = nullptr;

    delete productPa;
    productPa = nullptr;
    delete factoryPa;
    factoryPa = nullptr;

    return 0;
}
