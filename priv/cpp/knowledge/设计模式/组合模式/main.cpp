
!!! 抄前三个即可，第一个基础，第二个是头，第二个是后续的实现!!!!!!!

组合模式：将对象组合成树形结构以表示“部分-整体”的层次结构，组合模式使得客户端对单个对象和组合对象的使用具有一直性。

既然讲到以树形结构表示“部分-整体”，那可以将组合模式想象成一根大树，将大树分成树枝和树叶两部分，树枝上可以再长树枝，也可以长树叶，树叶上则不能再长出别的东西。

以下情况可以考虑使用组合模式：

希望表示对象的部分-整体层次结构。
希望客户端忽略组合对象与单个对象的不同，客户端将统一的使用组合结构中的所有对象。


#include <iostream>
#include <list>
#include <memory>

using namespace std;

//抽象类，提供组合和单个对象的一致接口
class Company
{
public:
    Company(const string& name): m_name(name){}
    virtual ~Company(){ cout << "~Company()" << endl;}

    virtual void add(Company* ) = 0;
    virtual void remove(const string&) = 0;
    virtual void show(int depth) = 0;

    virtual const string& name()
    {
        return m_name;
    }

protected:
    string m_name;
};

//具体的单个对象实现类，“树枝”类
class HeadCompany : public Company
{
public:
    HeadCompany(const string& name): Company(name){}
    virtual ~HeadCompany(){ cout << "~HeadCompany()" << endl;}

    void add(Company* company) override
    {
        shared_ptr<Company> temp(company);
        m_companyList.push_back(temp);
    }

    void remove(const string& strName) override
    {
        list<shared_ptr<Company>>::iterator iter = m_companyList.begin();
        for(; iter != m_companyList.end(); iter++)
        {
            if((*iter).get()->name() == strName)
            {
            //不应该在此处使用list<T>.erase(list<T>::iterator iter),会导致iter++错误，这里删除目               标元素之后，必须return。
                m_companyList.erase(iter);
                return;
            }
        }
    }

    void show(int depth) override
    {
        for(int i = 0; i < depth; i++)
        {
            cout << "-";
        }
        cout << this->name().data() << endl;
        list<shared_ptr<Company>>::iterator iter = m_companyList.begin();
        for(; iter!= m_companyList.end(); iter++)
        {
            (*iter).get()->show(depth + 1);
        }
    }

private:
    list<shared_ptr<Company>> m_companyList;
};

//具体的单个对象实现类，“树叶”类
class ACompany : public Company
{
public:
    ACompany(const string& name): Company(name){}
    virtual ~ACompany(){ cout << "~ACompany()" << endl;}

    void add(Company* ) override
    {
    }

    void remove(const string&) override
    {
    }

    void show(int depth) override
    {
        for(int i = 0; i < depth; i++)
        {
            cout << "-";
        }
        cout << m_name.data() << endl;
    }
};

//具体的单个对象实现类，“树叶”类
class BCompany : public Company
{
public:
    BCompany(const string& name): Company(name){}
    virtual ~BCompany(){ cout << "~BCompany()" << endl;}

    void add(Company* ) override
    {
    }

    void remove(const string&) override
    {
    }

    void show(int depth) override
    {
        for(int i = 0; i < depth; i++)
        {
            cout << "-";
        }
        cout << m_name.data() << endl;
    }
};

//具体的单个对象实现类，“树叶”类
class CCompany : public Company
{
public:
    CCompany(const string& name): Company(name){}
    virtual ~CCompany(){ cout << "~CCompany()" << endl;}

    void add(Company* ) override
    {
    }

    void remove(const string&) override
    {
    }

    void show(int depth) override
    {
        for(int i = 0; i < depth; i++)
        {
            cout << "-";
        }
        cout << m_name.data() << endl;
    }
};


int main()
{
    HeadCompany* headRoot = new HeadCompany("Head Root Company");

    HeadCompany* childRoot1 = new HeadCompany("Child Company A");
    ACompany* aC = new ACompany("Company A");
    BCompany* bC = new BCompany("Company B");
    CCompany* cC = new CCompany("Company C");
    
    childRoot1->add(aC);
    childRoot1->add(bC);
    childRoot1->add(cC);


    HeadCompany* childRoot2 = new HeadCompany("Child Company B");
    ACompany* aC2 = new ACompany("Company A");
    BCompany* bC2 = new BCompany("Company B");
    CCompany* cC2 = new CCompany("Company C");
    
    childRoot2->add(aC2);
    childRoot2->add(bC2);
    childRoot2->add(cC2);

    headRoot->add(childRoot1);
    headRoot->add(childRoot2);
    headRoot->show(1);

    childRoot1->remove("Company B");
    headRoot->show(1);

    delete headRoot;
    headRoot = nullptr;

    return 0;
}
