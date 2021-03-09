中介者模式：用一个中介对象来封装一系列的对象交互，中介者使各对象不需要显示地相互引用，从而使其耦合松散，而且可以独立地改变它们之前的交互。

如果对象与对象之前存在大量的关联关系，若一个对象改变，常常需要跟踪与之关联的对象，并做出相应的处理，这样势必会造成系统变得复杂，遇到这种情形可以考虑使用中介者模式。当多个对象存在关联关系时，为它们设计一个中介对象，当一个对象改变时，只需要通知它的中介对象，再由它的中介对象通知每个与它相关的对象。


/*
* 关键代码：将相关对象的通信封装到一个类中单独处理。
*/
#include <iostream>

using namespace std;

class Mediator;

//抽象同事类。
class Businessman
{
public:
    Businessman(){}
    Businessman(Mediator* mediator) : m_pMediator(mediator){}

    virtual ~Businessman(){}

    virtual void setMediator(Mediator* m)
    {
        m_pMediator = m;
    }

    virtual void sendMessage(const string& msg) = 0;
    virtual void getMessage(const string& msg) = 0;

protected:
    Mediator* m_pMediator;
};

//抽象中介者类。
class  Mediator
{
public:
    virtual ~Mediator(){}
    virtual void setTo(Businessman* to) = 0;
    virtual void setFrom(Businessman* from) = 0;
    virtual void send(const string& msg, Businessman* man) = 0;
};

//具体同事类
class To : public Businessman
{
public:
    To() : Businessman(){}
    To(Mediator* mediator) : Businessman(mediator){}

    void sendMessage(const string& msg) override
    {
        m_pMediator->send(msg, this);
    }

    void getMessage(const string& msg)
    {
        cout << "To recv: " << msg.data() << endl;
    }
};

//具体同事类
class From : public Businessman
{
public:
    From() : Businessman(){}
    From(Mediator* mediator) : Businessman(mediator){}

    void sendMessage(const string& msg) override
    {
        m_pMediator->send(msg, this);
    }

    void getMessage(const string& msg)
    {
        cout << "From recv: " << msg.data() << endl;
    }
};

//具体中介者类
class HouseMediator : public Mediator
{
public:
    void setTo(Businessman* to) override
    {
        m_pTo = to;
    }

    void setFrom(Businessman* from) override
    {
        m_pFrom = from;
    }

    void send(const string& msg, Businessman* man) override
    {
        if(man == m_pTo)
        {
            m_pFrom->getMessage(msg);
        }
        else if(man == m_pFrom)
        {
            m_pTo->getMessage(msg);
        }
    }

private:
    Businessman* m_pTo;
    Businessman* m_pFrom;
};

int main()
{
    HouseMediator* hMediator = new HouseMediator;
    To* to = new To(hMediator);
    From* from = new From(hMediator);

    hMediator->setTo(to);
    hMediator->setFrom(from);

    to->sendMessage("using my product ?");
    from->sendMessage("Yes!");

    delete to;
    to = nullptr;

    delete from;
    from = nullptr;

    delete hMediator;
    hMediator = nullptr;


    return 0;
}
