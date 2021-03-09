代理模式：为其它对象提供一种代理以控制这个对象的访问。在某些情况下，一个对象不适合或者不能直接引用另一个对象，而代理对象可以在客户端和目标对象之间起到中介作用。

优点：

职责清晰。真实的角色只负责实现实际的业务逻辑，不用关心其它非本职责的事务，通过后期的代理完成具体的任务。这样代码会简洁清晰。
代理对象可以在客户端和目标对象之间起到中介的作用，这样就保护了目标对象。
扩展性好。



/*
* 关键代码：一个是真正的你要访问的对象(目标类)，一个是代理对象,真正对象与代理对象实现同一个接口,先访问代理*         类再访问真正要访问的对象。
*/
#include <iostream>

using namespace std;

class DoClass
{
public:
    DoClass(const string& name = "doclass"):m_string(name){}
    string getName()
    {
        return m_string;
    }
private:
    string m_string;
};

class Profession
{
public:
    virtual ~Profession(){}
    virtual void profess() = 0;
};

class RunMain : public Profession
{
public:
    RunMain(const DoClass& doclass):m_doclass(doclass){}
    void profess()
    {
        cout << "Run main  " << m_doclass.getName().data() << endl;
    }

private:
    DoClass m_doclass;
};

class MainProxy : public Profession
{
public:
    MainProxy(const DoClass& doclass):m_pMain(new RunMain(doclass)){}
    ~MainProxy()
    {
        delete m_pMain;
        m_pMain = nullptr;
    }
    void profess()
    {
        m_pMain->profess();
    }
private:
    RunMain* m_pMain;
};

int main(int argc, char *argv[])
{
    DoClass doclass("heihei");
    MainProxy* proxy = new MainProxy(doclass);
    proxy->profess();

    delete proxy;
    proxy = nullptr;
    return 0;
}
