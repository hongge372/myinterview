/*
* 关键代码：实现同一个接口。
* 以下代码实例中，以游戏角色不同的攻击方式为不同的策略，游戏角色即为执行不同策略的环境角色。
*/

#include <iostream>

using namespace std;

//抽象策略类，提供一个接口
class Dec
{
public:
    virtual void blood() = 0;
};

//具体的策略实现类，具体实现接口， Blade持续普通攻击
class BladeDec : public Dec
{
public:
    void blood() override
    {
        cout << "Blade hurt, Blood loss" << endl;
    }
};

//具体的策略实现类，具体实现接口， Sword技能攻击
class SwordDec : public Dec
{
public:
    void blood() override
    {
        cout << "Sword Dec, Blood loss" << endl;
    }
};

//环境角色类， 游戏角色战士，传入一个策略类指针参数。
class Warrior
{
public:
    Warrior(Dec* hurt):m_pDec(hurt)
    {
    }
    //在不同的策略下，该游戏角色表现出不同的攻击
    void attack()
    {
        m_pDec->blood();
    }
private:
    Dec* m_pDec;
};

//定义策略标签
typedef enum
{
    Dec_Type_Blade,
    Dec_Type_Sword,
    Dec_Type_Num
}DecType;

//环境角色类， 游戏角色法师，传入一个策略标签参数。
class Mage
{
public:
    Mage(DecType type)
    {
        switch(type)
        {
        case Dec_Type_Blade:
            m_pDec = new BladeDec();
            break;
        case Dec_Type_Sword:
            m_pDec = new SwordDec();
            break;
        default:
            break;
        }
    }
    ~Mage()
    {
        delete m_pDec;
        m_pDec = nullptr;
        cout << "~Mage()" << endl;
    }

    void attack()
    {
        m_pDec->blood();
    }
private:
    Dec* m_pDec;
};

//环境角色类， 游戏角色弓箭手，实现模板传递策略。
template<typename T>
class Archer
{
public:
    void attack()
    {
        m_hurt.blood();
    }
private:
    T m_hurt;
};

int main()
{
    Archer<SwordDec>* arc = new Archer<SwordDec>;
    arc->attack();

    delete arc;
    arc = nullptr;
    
    return 0;
}
