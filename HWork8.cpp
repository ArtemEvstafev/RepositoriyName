#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
/*
class Animal {
public:
    virtual string getType() const = 0;
    virtual ~Animal() {}
};

class ZooKeeper {
private:
    map<string,int> animals;
public:
    // Создаём смотрителя зоопарка
    ZooKeeper(){}

    // Смотрителя попросили обработать очередного зверя.
    void handleAnimal(const Animal& a)
    {
        this->animals[a.getType()]++;
    }

    // Возвращает, сколько зверей такого типа было обработано.
    // Если таких не было, возвращает 0.
    int getAnimalCount(const string& type) const{
        map<string,int>::const_iterator found = this->animals.find(type);
        if(found != this->animals.end())
            return found->second;
        else
            return 0;
    }
};


class Monkey : public Animal
{
private:
    string type = "monkey";
public:
    string getType() const
    {
        return type;
    }

};
class Lion : public Animal
{
private:
    string type = "lion";
public:
    string getType() const
    {
        return type;
    }

};
int main()
{


 ZooKeeper z;
    Animal *a = new Monkey();
    z.handleAnimal(*a);
    delete a;
    a = new Monkey();
    z.handleAnimal(*a);
    delete a;
    a = new Lion();
    z.handleAnimal(*a);
    delete a;
    cout << z.getAnimalCount("monkey") << endl;
    cout << z.getAnimalCount("lion") << endl;
    cout << z.getAnimalCount("cat") << endl;
    return 0;
}

class SessionManager
{
private:
    map<string, int> users;
public:
    // Вход пользователя.
    // Один пользователь может войти несколько раз подряд,
    // считать его при этом нужно один раз.
    void login(const string& username)
    {
        users[username]++;
    }

    // Выход пользователя.
    // Пользователь может выйти несколько раз подряд,
    // падать при этом не нужно.
    void logout(const string& username)
    {
        auto it = users.find(username);
        if (it != users.end())
            users.erase(username);
    }

    // Сколько сейчас пользователей залогинено.
    int getNumberOfActiveUsers() const
    {
        return users.size();
    }
};
int main()
{
    SessionManager m;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("bob");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("whoever");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("bob");
    cout << m.getNumberOfActiveUsers() << endl;
    return 0;
}

class Tracker
{
private:
    map<string, vector<unsigned long long>> users;
public:
    // При любом действии пользователя вызывается этот метод.
    // Методу передаётся:
    // - какой пользователь совершил действие (username);
    // - когда (timestamp - для простоты условные секунды от начала времён).
    // Внимание: не гарантируется, что timestamp расположены строго по
    // возрастанию, в них может быть любой бардак.
    void click(const string& username, unsigned long long timestamp)
    {
        auto it = users.find(username);
        if(it == users.end())
            users[username]={timestamp};
        else
            it->second.push_back(timestamp);
        auto it1 = users.find(username);
        sort(it1->second.begin(), it1->second.end());

    }

    // По имени пользователя нужно вернуть, сколько всего было кликов
    unsigned long long getClickCount(const string& username) const
    {
        auto it = users.find(username);
        return it->second.size();
    }

    // Когда был первый клик
    unsigned long long getFirstClick(const string& username) const
    {
        auto it = users.find(username);
        return it->second.front();
    }

    // Когда был последний клик
    unsigned long long getLastClick(const string& username) const
    {
        auto it = users.find(username);
        return it->second.back();
    }
};
int main()
{
    Tracker t;
    t.click("alice", 1000);
    t.click("bob", 1100);
    t.click("alice", 1001);
    t.click("alice", 1200);
    t.click("alice", 1002);
    cout << t.getClickCount("alice") << endl;
    cout << t.getClickCount("bob") << endl;
    cout << t.getFirstClick("alice") << endl;
    cout << t.getFirstClick("bob") << endl;
    cout << t.getLastClick("alice") << endl;
    cout << t.getLastClick("bob") << endl;
    return 0;
}
class TelemetryController
{
private:
    map<string, vector<long>> devices;
public:
    // Получить и обработать событие. Параметрами передаются:
    // - device - идентификатор устройства, с которого пришло значение;
    // - value - собственно значение некоторой величины, переданное устройством.
    void handleEvent(const string& device, long value)
    {
        auto it = devices.find(device);
        if(it == devices.end())
            devices[device]={1,value, value};
        else
        {
            it->second[0]++;
            if(value < it->second[1])
                it->second[1] = value;
            if(value > it->second[2])
                it->second[2] = value;
        }

    }

    // По идентификатору устройства возвращает,
    // сколько всего значений от него пришло за всё время
    unsigned int getEventsCount(const string& device) const
    {
        auto it = devices.find(device);
        return it->second[0];
    }

    // По идентификатору устройства возвращает
    // минимальное значение за всё время, пришедшее от данного устройства
    long getMinValue(const string& device) const
    {
        auto it = devices.find(device);
        return it->second[1];
    }

    // По идентификатору устройства возвращает
    // максимальное значение за всё время, пришедшее от данного устройства
    long getMaxValue(const string& device) const
    {
        auto it = devices.find(device);
        return it->second[2];
    }
};
int main()
{
    TelemetryController tc;

    tc.handleEvent("d1", 42);
    tc.handleEvent("d1", -42);
    tc.handleEvent("d2", 100);


    cout << "Events count for d1: " << tc.getEventsCount("d1") << endl;
    cout << "Min value for d1: " << tc.getMinValue("d1") << endl;
    cout << "Max value for d1: " << tc.getMaxValue("d1") << endl;
}
*/
class Connection
{
protected:
    string source;
    unsigned short int port;
    unsigned long long timestamp;

public:
    Connection(string source, unsigned short int port, unsigned long long timestamp) {
        this->source = source;
        this->port = port;
        this->timestamp = timestamp;
    }
    ~Connection() {}

    string getSource() const {
        return source;
    }

    unsigned short int getPort() const {
        return port;
    }

    unsigned long long getTimestamp() const {
        return timestamp;
    }
};
class IntrusionDetector
{
private:
    unsigned short int timeThreshold;
    unsigned short int portLimit;
    map<string, map<unsigned short int, unsigned long long>> sources;

public:
    // Задать временное окно для анализа (см. описание логики выше)
    void setTimeThreshold(unsigned short int timeThreshold)
    {
        this->timeThreshold = timeThreshold;
    }

    // Задать минимальное количество портов для срабатывания (см. описание логики выше)
    void setPortLimit(unsigned short int portLimit)
    {
        this->portLimit = portLimit;
    }

    // Вызов этого метода уведомляет анализатор о новом подключении.
    void handleConnection(const Connection& c)
    {
        auto it = sources.find(c.getSource());
        if(it == sources.end())
        {
            map<unsigned short int, unsigned long long> new_source;
            new_source[c.getPort()] = c.getTimestamp();
            sources[c.getSource()]=new_source;
        }
        else
        {
            it->second[c.getPort()] = c.getTimestamp();
        }

    }

    // Проверить, является ли указанный адрес нарушителем
    bool isIntruder(const string& source) const
    {
        auto it = sources.find(source);
        if(it == sources.end())
        {
            return false;
        }
        if(it->second.size() > portLimit)
        {
           vector<unsigned long long> times;
            for (auto jt = it->second.begin(); jt != it->second.end(); ++jt)
            {
                times.push_back(jt->second);
            }
            sort(times.begin(), times.end());
            /*if(times.back() - times.front() < timeThreshold )
                return true;
            else
                return false;*/
            unsigned short int portlim;
            portlim = this->portLimit - 1;
            int size_times = times.size();
            for(int i = 0; i < size_times - 1; i++)
            {
                if(times[i+1] - times[i] <= 1)
                    if(portlim!=0)
                        portlim = portlim - 1;
            }
            if(portlim == 0)
            {
                return true;
            }

            else
                return false;
        }
        else
            return false;
    }
};

int main()
{
     IntrusionDetector id;
    id.setTimeThreshold(5);
    id.setPortLimit(3);

    id.handleConnection({"evil.com", 21, 100504});
    id.handleConnection({"evil.com", 22, 100501});
    id.handleConnection({"evil.com", 23, 100502});
    id.handleConnection({"evil.com", 24, 100503});
    id.handleConnection({"evil.com", 25, 100500});
    cout << boolalpha << "Checking if evil.com is intruder: " << id.isIntruder("evil.com") << endl;

    id.handleConnection({"load.com", 80, 100504});
    id.handleConnection({"load.com", 80, 100501});
    id.handleConnection({"load.com", 80, 100502});
    id.handleConnection({"load.com", 80, 100503});
    id.handleConnection({"load.com", 80, 100500});
    cout << boolalpha << "Checking if load.com is intruder: " << id.isIntruder("load.com") << endl;
    return 0;
}
