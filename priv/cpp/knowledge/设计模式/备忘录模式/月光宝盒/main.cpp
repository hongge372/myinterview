https://jishuin.proginn.com/p/763bfbd2eb45


// 日期时间
class DateTime
{
public:
    DateTime(std::string dt) : m_dateTime(dt) {}
    ~DateTime() {}

    void SetDateTime(std::string dt) {
        m_dateTime = dt;
    }

    std::string GetDateTime() {
        return m_dateTime;
    }

private:
    std::string m_dateTime;
};


// 一生
class Progress
{
public:
    Progress() {}
    ~Progress() {}

    void SetDateTime(std::string dt) {
        std::cout << "Set date time to " << dt << std::endl;
        m_dateTime = dt;
    }

    // 仅用于打印
    std::string GetDateTime() {
        return m_dateTime;
    }

    // 恢复日期时间
    void SetMemento(DateTime *dt) {
        if (nullptr != dt)
            m_dateTime = dt->GetDateTime();
    }

    // 创建日期时间
    DateTime *CreateMemento() {
        return new DateTime(m_dateTime);
    }

private:
    std::string m_dateTime;
};

class Manager
{
public:
    Manager(Progress *progress) : m_MProgress(progress) {}
    ~Manager() {
        for (auto itr = m_history.begin(); itr != m_history.end(); ++itr) {
            delete *itr;
        }
        m_history.clear();
    }

    // 保存备份
    void Save() {
        m_history.push_back(m_MProgress->CreateMemento());
    }

    // 穿越至某一时刻（随机取时间）
    void Undo() {
        int index = rand() % m_history.size();
        m_MProgress->SetMemento(m_history[index]);
    }

private:
    Progress *m_MProgress;
    std::vector m_history;
};

int main()
{
    srand((unsigned)time(0));

    Progress *progress = new Progress();
    Manager *box = new Manager(progress);

    // 设置并保存一些历史时间
    for (int i = 0; i < 5; i++) {
        std::ostringstream buffer;
        buffer << "200" << i << "/10/01 00:00:00";
        std::string dt = buffer.str();

        progress->SetDateTime(dt);
        box->Save();
    }

    // 穿越多次
    for (int i = 0; i < 2; i++) {
        box->Undo();
        std::cout << "Current date time is " << progress->GetDateTime() << std::endl;
    }

    SAFE_DELETE(progress);
    SAFE_DELETE(box);

    getchar();

    return 0;
}




