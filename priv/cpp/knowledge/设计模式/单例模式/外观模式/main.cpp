以下情形建议考虑外观模式：

设计初期阶段，应有意识的将不同层分离，层与层之间建立外观模式。
开发阶段，子系统越来越复杂，使用外观模式提供一个简单的调用接口。
一个系统可能已经非常难易维护和扩展，但又包含了非常重要的功能，可以为其开发一个外观类，使得新系统可以方便的与其交互。
优点：

实现了子系统与客户端之间的松耦合关系。
客户端屏蔽了子系统组件，减少了客户端所需要处理的对象数据，使得子系统使用起来更方便容易。
更好的划分了设计层次，对于后期维护更加的容易。


/*
* 关键代码：客户与系统之间加一个外观层，外观层处理系统的调用关系、依赖关系等。
*以下实例以电脑的启动过程为例，客户端只关心电脑开机的、关机的过程，并不需要了解电脑内部子系统的启动过程。
*/
#include <iostream>

using namespace std;

//抽象控件类，提供接口
class Control
{
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

//子控件， 主机
class Player : public Control
{
public:
    void start() override
    {
        cout << "Player start" << endl;
    }
    void stop() override
    {
        cout << "Player stop" << endl;
    }
};

class Sender : public Control
{
public:
    void start() override
    {
        cout << "Sender start" << endl;
    }
    void stop() override
    {
        cout << "Sender stop" << endl;
    }
};

class Manager
{
public:
    void start()
    {
        m_player.start();
        m_sender.start();
        cout << "Manager start" << endl;
    }
    void stop()
    {
        m_player.stop();
        m_sender.stop();
        cout << "Manager stop" << endl;
    }
private:
    Player   m_player;
    Sender m_sender;
};

int main()
{
    Manager manager;
    manager.start();

    //do something

    manager.stop();

    return 0;
}
