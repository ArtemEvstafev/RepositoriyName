#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
class Task
{
protected:
    unsigned int cpuNum;
    unsigned int size;

public:
    Task(unsigned int cpuNum, unsigned int size) {
        this->cpuNum = cpuNum;
        this->size = size;
    }

    // На каком ядре процессора выполняется задача
    unsigned int getCPU() const {
        return cpuNum;
    }

    // Оценка сложности задачи (в попугаях)
    unsigned int getSize() const {
        return size;
    }
};


class Analyzer
{
private:
    vector<int> Difficulty;
public:
    // Создать анализатор для системы с numCores ядер
    Analyzer(unsigned int numCores)
    {
        Difficulty.resize(numCores);
        for(int i =0 ;i<numCores; i++)
        {
            Difficulty[i] = 0;
        }
    }

    // Проанализировать текущие задачи
    void analyze(const vector<Task>& tasks)
    {
        vector<int>:: iterator it ;
        for ( int i =0; i<tasks.size(); i++)
        {
            Difficulty[tasks[i].getCPU()] += tasks[i].getSize();
        }
    }

    // Сообщить общую нагрузку на заданное ядро
    int getLoadForCPU(unsigned int cpuNum)
    {
        return Difficulty[cpuNum];
    }
};


int main()
{
    unsigned numberOfCores = 4;
    vector<Task> data = { {0, 1}, {1, 10}, {0, 6}, {2, 12}, {3, 5} };
    Analyzer a(numberOfCores);
    a.analyze(data);
    for(unsigned i = 0; i < numberOfCores; i++)
        cout << a.getLoadForCPU(i) << endl;
}

class ResultsTable
{
private:
    vector<unsigned int> results;
public:
    // Зарегистрировать новый результат,
    // нас волнуют только баллы, имена пользователей не важны
    void addResult(unsigned int score)
    {
        results.push_back(score);
        sort(results.begin(), results.end());
    }

    // Получить минимальный балл из всех результатов за всё время
    unsigned int getMinScore() const
    {
        return *(min_element(results.begin(), results.end()));
    }

    // Получить, сколько баллов у игрока на заданном месте.
    // Внимание: места нумеруются так, как это принято на турнирах, то есть
    // лучший результат - 1-ое место, за ним 2-ое место и т.д.
    unsigned int getScoreForPosition(unsigned int positionNumber) const
    {
        return results[results.size() - positionNumber];
    }
};
int main()
{
    ResultsTable t;

    t.addResult(30);
    t.addResult(85);
    t.addResult(12);
    t.addResult(31);

    cout << "1st place score: " << t.getScoreForPosition(1) << endl;
    cout << "2nd place score: " << t.getScoreForPosition(2) << endl;
    cout << "3rd place score: " << t.getScoreForPosition(3) << endl;
    cout << "Min score during the tournament: " << t.getMinScore() << endl;
    return 0;
}
*/
class Person
{
public:
    string surname;
    string name;
    string middleName;
    // Создать человека с ФИО
    Person(string surname, string name, string middleName)
    {
        this->surname = surname;
        this->name = name;
        this->middleName = middleName;
    }
    Person()
    {

    }
    bool operator <(const Person& p) const
    {
        if(this->surname == p.surname)
            {
                if(this->name == p.name)
                {
                    if(this->middleName == p.middleName)
                    {
                        return false;
                    }
                    if(this->middleName[0] < p.middleName[0])
                        return true;
                    else
                        return false;
                }
                if(this->name[0] < p.name[0])
                    return true;
                else
                    return false;
            }
        if(this->surname[0] < p.surname[0])
            return true;
        else
            return false;
    }

};
ostream& operator<<(ostream& os, const Person& p)
    {
          os << p.surname <<" "<< p.name<<" "<<p.middleName;
          return os;
    }
istream& operator>>(istream& is,Person& p)
    {
          string s;
          string n;
          string m;
          is >> s >> n >> m;
          p.name = n;
          p.surname = s;
          p.middleName = m;
          return is;
    }
int main()
{
    cout << "Testing I/O" << endl;
    Person p;
    cin >> p;
    cout << p << endl;

    cout << "Testing sorting" << endl;
    vector<Person> people;
    people.push_back(Person("Ivanov", "Ivan", "Ivanovich"));
    people.push_back(Person("Petrov", "Petr", "Petrovich"));
    people.push_back(Person("Ivanov", "Ivan", "Petrovich"));
    people.push_back(Person("Ivanov", "Petr", "Ivanovich"));

    sort(people.begin(), people.end());
    for(vector<Person>::const_iterator it = people.begin(); it < people.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
