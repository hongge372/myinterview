/*
* 关键代码：构造函数是私有的，不能通过赋值运算，拷贝构造等方式实例化对象。
*/

//懒汉式一般实现：非线程安全，getInstance返回的实例指针需要delete
class Singleton
{
public:
    static Singleton* getInstance();
    ~Singleton(){}

private:
    Singleton(){}                                        //构造函数私有
    Singleton(const Singleton& obj) = delete;            //明确拒绝
    Singleton& operator=(const Singleton& obj) = delete; //明确拒绝
    
    static Singleton* m_pSingleton; // 静态(static)成员: 不是任意对象的组成部分,但由给定类的全体对象所共享的数据成员或函数成员。
};

Singleton* Singleton::m_pSingleton = NULL;

Singleton* Singleton::getInstance()
{
    if(m_pSingleton == NULL)
    {
        m_pSingleton = new Singleton;
    }
    return m_pSingleton;
}
