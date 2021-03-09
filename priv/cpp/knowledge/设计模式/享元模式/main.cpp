article: (报刊上的)文章，论文，报道; (协议、契约的)条款，项; 物件，物品(尤指整套中的一件);

享元模式：运用共享技术有效地支持大量细粒度的对象。在有大量对象时，把其中共同的部分抽象出来，如果有相同的业务请求，直接返回内存中已有的对象，避免重新创建。

以下情况可以考虑使用享元模式：

系统中有大量的对象，这些对象消耗大量的内存，且这些对象的状态可以被外部化。
对于享元模式，需要将对象的信息分为两个部分：内部状态和外部状态。内部状态是指被共享出来的信息，储存在享元对象内部且不随环境变化而改变；外部状态是不可以共享的，它随环境改变而改变，是由客户端控制的。


/*
* 关键代码：将内部状态作为标识，进行共享。
*/
#include <iostream>
#include <map>
#include <memory>

using namespace std;

//抽象享元类，提供享元类外部接口。
class AbstractConsumer
{
public:
    virtual ~AbstractConsumer(){}
    virtual void setArticle(const string&) = 0;
    virtual const string& article() = 0;
};

//具体的享元类
class Consumer : public AbstractConsumer
{
public:
    Consumer(const string& strName) : m_user(strName){}
    ~Consumer()
    {
        cout << " ~Consumer()" << endl;
    }

    void setArticle(const string& info) override
    {
        m_article = info;
    }

    const string& article() override
    {
        return m_article;
    }

private:
    string m_user;
    string m_article;
};

//享元工厂类
class Trusteeship
{
public:
    ~Trusteeship()
    {
         m_consumerMap.clear();
    }
//producing 生产，制造
    
    void producing(const string& user, const string& article)
    {
        if(m_consumerMap.count(user))
        {
            cout << "A customer named " << user.data() << " already exists" << endl;
            Consumer* consumer = m_consumerMap.at(user).get();
            consumer->setArticle(article);
        }
        else
        {
            shared_ptr<Consumer> consumer(new Consumer(user));
            consumer.get()->setArticle(article);
            m_consumerMap.insert(pair<string, shared_ptr<Consumer>>(user, consumer));
        }
    }

    void show()
    {
        map<string, shared_ptr<Consumer>>::iterator iter = m_consumerMap.begin();
        for(; iter != m_consumerMap.end(); iter++)
        {
            cout << iter->first.data() << " : "<< iter->second.get()->article().data() << endl;
        }
    }

private:
    map<string, shared_ptr<Consumer>> m_consumerMap;
};


int main()
{
    Trusteeship* ts = new Trusteeship;
    ts->producing("maker1", "pa");
    ts->producing("maker2", "pb");

    ts->show();
    delete ts;
    ts = nullptr;

    return 0;
}
