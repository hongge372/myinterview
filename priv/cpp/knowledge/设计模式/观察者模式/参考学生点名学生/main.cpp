来自：
https://www.cnblogs.com/suzhou/p/dp16obsvr.html

 /*
  2  * 观察者模式
  3  * 情景：高数课，ABCD四位同学，A是好学生，去上课，B在寝室睡觉，C在网吧打游戏，D在学校外陪女友逛街
  4  * 他们约定，如果要点名了，A在QQ群里吼一声，他们立刻赶到教室去。
  5  * 采用观察者模式实现这个情景的应用。
  6  */
  7 
  8 #include <iostream>
  9 #include <string>
 10 #include <list>
 11 
 12 class Observer;
 13 
 14 class Subject{
 15 public:
 16     virtual ~Subject() {};
 17     virtual void registerObsvr(Observer* obsvr) = 0;
 18     virtual void removeObsvr(Observer* obsvr) = 0;
 19     virtual void notifyObsvrs(const std::string &msg) = 0;
 20 };
 21 class Observer {
 22 public:
 23     virtual ~Observer() {};
 24     virtual void Update(const std::string &msg)= 0;
 25     virtual std::string getName() = 0;
 26 protected:
 27     Observer(){};
 28 };
 29 
 30 // -------------------------------------------------
 31 class Notify : public Subject {
 32 public:
 33     Notify() { _observers = new std::list<Observer*>(); }
 34     void registerObsvr(Observer* obsvr);
 35     void removeObsvr(Observer* obsvr);
 36     void notifyObsvrs(const std::string &msg);
 37 private:
 38     std::list<Observer*> *_observers;
 39 };
 40 
 41 void Notify::registerObsvr(Observer* obsvr) {
 42     _observers->push_back(obsvr);
 43 }
 44 
 45 void Notify::removeObsvr(Observer* obsvr) {
 46     if (_observers->size() > 0)
 47         _observers->remove(obsvr);
 48 }
 49 void Notify::notifyObsvrs( const std::string &msg) {
 50     std::cout << "群消息：" << msg << std::endl;
 51     std::list<Observer*>::iterator iter
 52         = _observers->begin();
 53     for ( ;iter != _observers->end(); iter++ ) {
 54         (*iter)->Update(msg);
 55     }
 56 }
 57 
 58 // ------------------------------------------------
 59 class RoomMate : public Observer {
 60 public:
 61     RoomMate(std::string name, std::string own ,std::string action)
 62     {
 63         _name = name;
 64         _action = action;
 65         _own = own;
 66     };
 67     void Update( const std::string &msg);
 68     std::string getName();
 69 private:
 70     std::string _name;
 71     std::string _action;
 72     std::string _own;
 73 };
 74 
 75 std::string RoomMate::getName() {
 76     return _name;
 77 }
 78 
 79 void RoomMate::Update(const std::string &msg) {
 80     std::cout<< "This is " << _name << std::endl;
     //!!!!!!!!!!!!!!!-来通知了，干活
 81     if ( msg == "do some thing" )
 82         std::cout << "Action: " << _action
 83         << std::endl << std::endl;
 84     else
         //free,hahaha
 85         std::cout << "free" << _own
 86         << std::endl << std::endl ;
 87 }
 88 
 89 //测试代码
 90 int main()
 91 {
 92     RoomMate* rA = new RoomMate("rA",
 93         "do a",
 94         "prive a");
 95     RoomMate* rB = new RoomMate("rB",
 96         "do b",
 97         "prive b");
 98     RoomMate* rC = new RoomMate("rC",
 99         "do c",
100         "prive c");
101 
102     Notify* notify = new Notify();
103     notify->registerObsvr(rA);
104     notify->registerObsvr(rB);
105     notify->registerObsvr(rC);
106 
107     notify->notifyObsvrs("free");
108     notify->notifyObsvrs("do some thing");
109 
110     system("Pause");
111     return 0;
112 }
