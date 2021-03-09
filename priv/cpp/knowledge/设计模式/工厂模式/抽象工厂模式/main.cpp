//抽象工厂模式提供创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。
//当存在多个产品系列，而客户端只使用一个系列的产品时，可以考虑使用抽象工厂模式。
//缺点：当增加一个新系列的产品时，不仅需要现实具体的产品类，还需要增加一个新的创建接口，扩展相对困难。


/*
* 关键代码：在一个工厂里聚合多个同类产品。
* 以下代码以白色衣服和黑色衣服为例，白色衣服为一个产品系列，黑色衣服为一个产品系列。白色上衣搭配白色裤子，   黑色上衣搭配黑色裤字。每个系列的衣服由一个对应的工厂创建，这样一个工厂创建的衣服能保证衣服为同一个系列。
*/

//抽象上衣类
class ProductA
{
public:
    virtual const string& color() = 0;
};

//黑色上衣类
class BlackProductA : public ProductA
{
public:
    BlackProductA():ProductA(),m_strColor("Black ProductA")
    {
    }

    const string& color() override
    {
        cout << m_strColor.data() << endl;
        return m_strColor;
    }
private:
    string m_strColor;
};

//白色上衣类
class WhiteProductA : public ProductA
{
public:
    WhiteProductA():ProductA(),m_strColor("White ProductA")
    {
    }
    const string& color() override
    {
        cout << m_strColor.data() << endl;
        return m_strColor;
    }

private:
    string m_strColor;
}; 

//抽象裤子类
class ProductB
{
public:
    virtual const string& color() = 0;
};

//黑色裤子类
class BlackProductB : public ProductB
{
public:
    BlackProductB():ProductB(),m_strColor("Black ProductB")
    {
    }
    const string& color() override
    {
        cout << m_strColor.data() << endl;
        return m_strColor;
    }

private:
    string m_strColor;
};

//白色裤子类
class WhiteProductB : public ProductB
{
public:
    WhiteProductB():ProductB(),m_strColor("White ProductB")
    {
    }
    const string& color() override
    {
        cout << m_strColor.data() << endl;
        return m_strColor;
    }

private:
    string m_strColor;
};

//抽象工厂类，提供衣服创建接口
class Factory
{
public:
    //上衣创建接口，返回抽象上衣类
    virtual ProductA* createProductA() = 0;
    //裤子创建接口，返回抽象裤子类
    virtual ProductB* createProductB() = 0;
};

//创建白色衣服的工厂类，具体实现创建白色上衣和白色裤子的接口
class WhiteFactory : public Factory
{
public:
    ProductA* createProductA() override
    {
        return new WhiteProductA();
    }

    ProductB* createProductB() override
    {
        return new WhiteProductB();
    }
};

//创建黑色衣服的工厂类，具体实现创建黑色上衣和白色裤子的接口
class BlackFactory : public Factory
{
    ProductA* createProductA() override
    {
        return new BlackProductA();
    }

    ProductB* createProductB() override
    {
        return new BlackProductB();
    }
};
