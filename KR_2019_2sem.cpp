#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

/*class Polyline {
private:

struct point
{
    double x;
    double y;
};
    double length = 0;
    vector<point> points;
public:
    // Конструктур и деструктор, если необходимы

    // Добавить очередную точку в ломаную
    void addPoint(double x, double y)
    {
        point p;
        p.x = x;
        p.y = y;
        if(points.size() != 0)
        {
            this->length += sqrt(pow((x - points.back().x), 2) + pow((y - points.back().y), 2));
        }
        points.push_back(p);

    }

    // Получить количесто точек в ломаной в данный момент
    unsigned int getNumberOfPoints() const
    {
        return points.size();
    }

    // Получить длину ломаной в данный момент
    double getLength() const
    {
        return length;
    }

    // Получить x-координату i-ой точки ломаной, точки нумеруются в порядке добавления
    // (Гарантируется, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
    double getX(unsigned int i) const
    {
        return points[i].x;
    }

    // Получить y-координату i-ой точки ломаной, точки нумеруются в порядке добавления
    // (Гарантируется, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
    double getY(unsigned int i) const
    {
        return points[i].y;
    }
};

int main()
{
    Polyline p;
    p.addPoint(0.0, 0.0);
    p.addPoint(1.0, 0.0);
    p.addPoint(1.0, 1.0);
    cout << "Length: " << p.getLength() << endl;
    cout << "Points:" << endl;
    for(unsigned int i = 0; i < p.getNumberOfPoints(); i++) {
        cout << p.getX(i) << " " << p.getY(i) << endl;
    }
    return 0;
}
class Rational {
    friend ostream& operator<< (ostream &os,const Rational &r);
private:
    int ch;
    int zn;
public:

    // Конструктор дроби, здесь a - числитель, b - знаменатель
    Rational(int a, int b)
    {
        this->ch = a;
        this->zn = b;
    }
    Rational operator+ (const Rational& r2)
    {
        int new_ch, new_zn;
        if(this->zn == r2.zn)
        {
            new_ch = this->ch+r2.ch;
            new_zn = this->ch;
        }
        else
        {
            new_ch = this->ch*r2.zn + r2.ch * this->zn;
            new_zn = zn*r2.zn;
        }
        Rational res(new_ch, new_zn);
        return res;
    }

    Rational operator* ( int a)
    {
        Rational res(this->ch * a, this->zn);
        return res;
    }
    Rational operator*(Rational& r2)
    {
        Rational res(this->ch * r2.ch, this->zn * r2.zn);
        return res;
    }

    Rational operator/ (int a)
    {
        Rational res(this->ch, this->zn * a);
        return res;
    }

    Rational operator/(Rational& r2)
    {
        int new_ch = this->ch*r2.zn;
        int new_zn = this->zn*r2.ch;
        Rational res(new_ch, new_zn);
        return res;
    }

    Rational operator-(Rational& r2)
    {
        return (*this) + (r2 * -1);
    }

};

Rational operator* (int a, Rational& r)
{
    return r * a;
}

ostream& operator<< (ostream &os,const Rational &r)
{
    cout<<r.ch<<"/"<<r.zn;
    return os;
}
int main()
{
    Rational a(1, 2);
    Rational b(2, 3);

    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << 3 * a << endl;
    cout << b * 4 << endl;

    return 0;
}
class Vehicle {
public:
    // Может ли ездить по суще
    virtual bool canDrive() const {
        return false;
    }

    // Может ли плавать
    virtual bool canSail() const {
        return false;
    }

    // Может ли летать
    virtual bool canFly() const {
        return false;
    }

    virtual ~Vehicle() {};
};

class Car: public Vehicle
{
public:
    bool canDrive() const
    {
        return true;
    }
};
class Ship: public Vehicle
{
public:
    bool canSail() const
    {
        return true;
    }
};
class Plane:public Vehicle
{
public:
    bool canFly() const
    {
        return true;
    }
};
class Truck: public Car
{
public:
};
int main()
{
    cout << boolalpha;
    Vehicle* v;

    v = new Car();
    cout << "Car can drive: " << v->canDrive() << endl;
    cout << "Car can sail: " << v->canSail() << endl;
    cout << "Car can fly: " << v->canFly() << endl;
    delete v;

    v = new Ship();
    cout << "Ship can drive: " << v->canDrive() << endl;
    cout << "Ship can sail: " << v->canSail() << endl;
    cout << "Ship can fly: " << v->canFly() << endl;
    delete v;

    v = new Plane();
    cout << "Plane can drive: " << v->canDrive() << endl;
    cout << "Plane can sail: " << v->canSail() << endl;
    cout << "Plane can fly: " << v->canFly() << endl;
    delete v;

    Car* c = new Truck();
    cout << "Truck can drive: " << c->canDrive() << endl;
    cout << "Truck can sail: " << c->canSail() << endl;
    cout << "Truck can fly: " << c->canFly() << endl;
    delete c;

    return 0;
}

class Module {
public:
    // Получить имя модуля
    virtual string getName() const = 0;

    // Запустить модуль
    virtual void run() = 0;
};
class ModuleA : public Module {
public:
    string getName() const {
        return "moduleA";
    }

    void run() {
        cout << "ModuleA runs" << endl;
    }
};

class ModuleB : public Module {
public:
    string getName() const {
        return "moduleB";
    }

    void run() {
        cout << "ModuleB runs" << endl;
    }
};
class Dispatcher {
private:
    map<string, Module*> modules;
public:
    // Зарегистрировать переданный модуль
    void registerModule(Module* m)
    {
        modules[m->getName()] = m;
    }

    // Вызвать метод run для модуля с именем moduleName
    // Если такого модуля не зарегистрировано, ничего не делать (но не падать)
    void runModule(const string moduleName) const
    {
         auto it = modules.find(moduleName);
         if(it != modules.end())
            {
                it->second->run();
            }
    }
};

int main()
{
    Module* m1 = new ModuleA();
    Module* m2 = new ModuleB();

    Dispatcher d;
    d.registerModule(m1);
    d.registerModule(m2);
    d.runModule("moduleA");
    d.runModule("moduleB");
    d.runModule("moduleC");

    delete m1;
    delete m2;

    return 0;
}

class Handler
{
public:
    virtual ~Handler(){};
    virtual void preProcess(){};
    virtual void postProcess(){};
    virtual bool accessAllowed(string username)
    {
        return true;
    }
    virtual void run()=0;

};

// Должен не работать, так как не предоставляет run
class BadHandler : public Handler {
};

// Должен технически корректно работать
class DummyHandler : public Handler {
public:
    void run() {
        cout << "DummyHandler runs" << endl;
    }
};

// Должен технически корректно работать
// и использовать собственные реализации всех методов
class SmartHandler : public Handler {
public:
    void preProcess() {
        cout << "SmartHandler preprocess" << endl;
    }

    void postProcess() {
        cout << "SmartHandler postprocess" << endl;
    }

    bool accessAllowed(string username) {
        return "admin" == username;
    }

    void run() {
        cout << "SmartHandler runs" << endl;
    }
};

// Должен технически корректно работать
// и очистить память за собой
class HeavyHandler : public Handler {
protected:
    int* data;
public:
    HeavyHandler() {
        data = new int[1000];
    }
    ~HeavyHandler() {
        delete[] data;
    }

    void run() {
        cout << "HeavyHandler runs" << endl;
    }
};
int main()
{
    string username = "admin";
    Handler* h = new SmartHandler();
    h->preProcess();
    if(h->accessAllowed(username)) {
        h->run();
    }
    h->postProcess();
    delete h;

    return 0;
};

bool CompareWords(string s1, string s2)
    {
        return (s1.size() <= s2.size());
    }
int main()
{
    vector<string> words;
    int n;
    cin>>n;
    string a;
    for(int i = 0; i < n; ++i)
    {
        cin>>a;
        if(i==0)
            words.push_back(a);
        bool add = true;
        for(int j=0; j<words.size(); j++)
        {

            if(words[j] == a)
            {
                add = false;
                break;
            }
        }
        if(add)
            words.push_back(a);

    }
    sort(words.begin(), words.end(), CompareWords);
    reverse(words.begin(), words.end());
    for(int i=0; i < words.size(); i++)
    {
        cout<<words[i]<<endl;
    }

    return 0;
}
*/
class Dat
{
private:
    map<string, vector<int>> values;
    vector<int> show;
public:
    void AddResult(string name, int value)
    {
        auto it = values.find(name);
        if(it==values.end())
        {
            values[name] = {value};
        }
        else
        {
            it->second.push_back(value);
        }

    }
    void MediumResult(string name)
    {

        auto it = values.find(name);
        if(it == values.end())
            show.push_back(1337);
        else
        {
            sort(values[name].begin(), values[name].end());
            int numbers = it->second.size();
            if(numbers%2 == 1)
                show.push_back(it->second[numbers/2]);
            else
                show.push_back(it->second[numbers/2 - 1]);
        }
    }
    void show_results()
    {
        for(int i=0; i<show.size(); i++)
        {
            if(show[i]==1337)
                cout<<"no data";
            else
                cout<<show[i]<<endl;
        }

    }
};
int main()
{
    Dat datchiki;
    int a;
    cin>>a;
    for(int i=0; i<a; i++)
    {
        string name;
        int value;
        cin>>name>>value;
        datchiki.AddResult(name, value);
    }
    cin>>a;
    for(int i=0; i<a; i++)
    {
        string name;
        cin>>name;
        datchiki.MediumResult(name);
    }
    datchiki.show_results();
    return 0;

}
