#include <iostream>
#include <string>
using namespace std;
/*
class Student
{
private:
    string name;
    unsigned int score;
public:
    Student() = default;
    // Задать имя студента
    void setName(string name){
        this->name = name;}

    // Указать количество баллов за контрольную
    void setScore(unsigned int score){
        this->score = score;}

    // Получить имя студента
    string getName() const{
        return name;}

    // Получить количество баллов студента
    unsigned int getScore() const{
        return score;}

};
istream& operator>>(istream& is, Student& s)
{
    string name;
    getline(is, name);
    s.setName(name);
    s.setScore(0);
    return is;
}
ostream& operator<<(ostream& os, Student& s)
{
    os << "'" << s.getName() << "': " << s.getScore() ;
    return os;
}

int main()
{
    Student s;
    cin >> s;
    s.setScore(10);
    cout << s << endl;

    return 0;
}

class Vector2D
{
private:
    int x, y;
public:
    // Конструкторы
    Vector2D(): Vector2D(0,0){};
    Vector2D(int x, int y): x(x), y(y){};

    // Деструктор
    ~Vector2D(){};

    // Получение координат
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }

    // Задание координат
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }

    // Перегруженный оператор - сравнение двух векторов на равенство
    bool operator== (const Vector2D& v2) const
    {
        return (this->x == v2.x && this->y == v2.y);
    }

    // Ещё один перегруженный оператор - неравенство векторов
    // Да, это отдельный оператор! Хинт - настоящие джедаи смогут для != использовать уже написанное ==
    bool operator!= (const Vector2D& v2) const
    {
        return !((*this) == v2);
    }

    // Сумма двух векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator+ (const Vector2D& v2) const
        {
            Vector2D res(this->x + v2.getX(), this->y + v2.getY());
            return res;
        }

    // Вычитание векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator- (const Vector2D& v2) const
    {
        return (*this)+(v2 * -1);
    }

    // Оператор умножения вектора на скаляр, исходный вектор не меняется, возвращается новый вектор
    Vector2D operator* (const int a) const
    {
        Vector2D res(this->x * a, this->y * a);
        return res;

    }
};
// Оператор умножения скаляра на вектор, исходный вектор не меняется, возвращается новый вектор
// Неожиданно, правда? Умножение скаляра на вектор - это отдельный оператор, причём описанный *вне* класса.
Vector2D operator* (int a, const Vector2D& v)
{
    return v * a;
}

// Вывод вектора, ожидается строго в формате (1; 1)
std::ostream& operator<<(std::ostream& os, const Vector2D& v)
{
    os << "(" << v.getX() << "; " << v.getY() << ")" ;
    return os;
}

// Чтение вектора, читает просто две координаты без хитростей
std::istream& operator>>(std::istream &is, Vector2D &v)
{
    int x , y;
    is >> x >> y ;
    v.setX(x);
    v.setY(y);
    return is;
}
int main()
{
    Vector2D v1;
    cin >> v1;
    cout << v1 << endl;
    Vector2D v2;
    cin >> v2;
    cout << v2 << endl;
    cout << boolalpha << (v1 == v2) << endl;
    cout << boolalpha << (v1 != v2) << endl;
    Vector2D v3 = v1 - v2;
    cout << v3 << endl;
    cout << v3 * 42 << endl;
    cout << 42 * v3 << endl;
    return 0;
}
*/
class VectorN
{
private:
    int* coord;
    unsigned int n;
public:
    // Конструктор вектора размерности n
    VectorN(unsigned int n)
    {
        this->n = n;
        this->coord = new int[n];
    }

    // Деструктор
    ~VectorN()
    {
        delete[] coord;
    }

    // Получение размерности вектора
    unsigned int getSize() const
    {
        return n;
    }

    // Получение значения i-ой координаты вектора,
    // i находится в диапазоне от 0 до n-1
    int getValue(unsigned int i) const
    {
        return coord[i];
    }

    // Задание значения i-ой координаты вектора равным value,
    // i находится в диапазоне от 0 до n-1
    void setValue(unsigned int i, int value)
    {
        coord[i] = value;
    }

    /*
     * Далее реализуйте перегруженные операторы
     */

    // Оператор == проверяет два вектора на равенство,
    // равны они, если строго равны всех их координаты
    bool operator== (const VectorN& v2) const
    {
        bool yes = true;
        for(unsigned int i = 0; i<n; i++)
        {
            if(this->coord[i] != v2.getValue(i))
            {
                yes = false;
                break;
            }
        }
        return yes;

    }

    // Оператор != проверяет два вектора на неравенство,
    // они не равны, если хотя бы одна координата отличается
    bool operator!= (const VectorN& v2) const
    {
        return !((*this) == v2);
    }

    // Оператор + складывает два вектора покоординатно,
    // возвращает результат как новый экземпляр вектора
    VectorN operator+ (const VectorN& v2) const
        {
            VectorN res(this->n);
            for(unsigned int i =0; i<this->n; i++)
            {
                res.setValue(i, this->coord[i] + v2.getValue(i));
            }
            return res;
        }

    // Оператор * умножает вектор на скаляр типа int покоординатно,
    // возвращает результат как новый экземпляр вектора.
    // Умножение должно работать при любом порядке операндов.
    VectorN operator* (const int a) const
        {
            VectorN res(this->n);
            for(unsigned int i =0; i<this->n; i++)
            {
                res.setValue(i, this->coord[i] * a);
            }
            return res;
        }

};
VectorN operator* (int a, const VectorN& v)
{
    return v * a;
}
int main()
{
     VectorN a(4);
    a.setValue(0, 0);
    a.setValue(1, 1);
    a.setValue(2, 2);
    a.setValue(3, 3);

    VectorN b(4);
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);
    b.setValue(3, -3);

    cout << (a == b) << endl;
    cout << (a != b) << endl;

    VectorN c = a + b;
    VectorN d = 5 * c;

    for(unsigned int i = 0; i < a.getSize(); ++i)
        cout << d.getValue(i) << endl;
    return 0;
}
