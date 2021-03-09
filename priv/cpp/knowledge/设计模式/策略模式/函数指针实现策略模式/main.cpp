#include <iostream>
#include <functional> 

void bladeHurt()
{
    std::cout << "Blade Hurt" << std::endl;
}

//剑
void swordHurt()
{
    std::cout << "Sword Hurt" << std::endl;
}

//环境角色类， 使用传统的函数指针
class Warrior
{
public:
    typedef void (*Function)();
    Warrior(Function fun): m_fun(fun)
    {
    }
    void attack()
    {
        m_fun();
    }
private:
    Function m_fun;
};

//环境角色类， 使用std::function<>
class Mage
{
public:
    typedef std::function<void()> Function;

    Mage(Function fun): m_fun(fun)
    {
    }
    void attack()
    {
        m_fun();
    }
private:
    Function m_fun;
};

int main()
{
    Warrior* warrior = new Warrior(bladeHurt);
    warrior->attack();
    delete warrior;
    soldier = nullptr;
    return 0;
}
