//缺点：工厂类集中了所有产品类的创建逻辑，如果产品量较大，会使得工厂类变的非常臃肿。

#include <iostream>

using namespace std;

//定义产品类型信息
typedef enum
{
    Product_Type_Pa,
    Product_Type_Pb,
    Product_Type_Num
}Product_Type;

//抽象产品类
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
    // 在派生类的成员函数中使用override时，如果基类中无此函数，或基类中的函数并不是虚函数，编译器会给出相关错误信息。
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

//工厂类
class ProductFactory
{
public:
    //根据产品信息创建具体的产品类实例，返回一个抽象产品类
    Product* createProduct(Product_Type type)
    {
        switch(type)
        {
        case Product_Type_Pa:
            return new ProductPa();
        case Product_Type_Pb:
            return new ProductPb();
        default:
            return nullptr;
        }
    }
};


int main()
{
    ProductFactory* factory = new ProductFactory();
    Product* productPa = factory->createProduct(Product_Type_Pa);
    productPa->type();
    Product* productPb = factory->createProduct(Product_Type_Pb);
    productPb->type();

    delete productPb;
    productPb = nullptr;
    delete productPa;
    productPa = nullptr;
    delete factory;
    factory = nullptr;

    return 0;
}
