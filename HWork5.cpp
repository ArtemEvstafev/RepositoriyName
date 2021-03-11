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
    // ������ ��� ��������
    void setName(string name){
        this->name = name;}

    // ������� ���������� ������ �� �����������
    void setScore(unsigned int score){
        this->score = score;}

    // �������� ��� ��������
    string getName() const{
        return name;}

    // �������� ���������� ������ ��������
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
    // ������������
    Vector2D(): Vector2D(0,0){};
    Vector2D(int x, int y): x(x), y(y){};

    // ����������
    ~Vector2D(){};

    // ��������� ���������
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }

    // ������� ���������
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }

    // ������������� �������� - ��������� ���� �������� �� ���������
    bool operator== (const Vector2D& v2) const
    {
        return (this->x == v2.x && this->y == v2.y);
    }

    // ��� ���� ������������� �������� - ����������� ��������
    // ��, ��� ��������� ��������! ���� - ��������� ������ ������ ��� != ������������ ��� ���������� ==
    bool operator!= (const Vector2D& v2) const
    {
        return !((*this) == v2);
    }

    // ����� ���� ��������, �������� ������� �� ��������, ������������ ����� ������
    Vector2D operator+ (const Vector2D& v2) const
        {
            Vector2D res(this->x + v2.getX(), this->y + v2.getY());
            return res;
        }

    // ��������� ��������, �������� ������� �� ��������, ������������ ����� ������
    Vector2D operator- (const Vector2D& v2) const
    {
        return (*this)+(v2 * -1);
    }

    // �������� ��������� ������� �� ������, �������� ������ �� ��������, ������������ ����� ������
    Vector2D operator* (const int a) const
    {
        Vector2D res(this->x * a, this->y * a);
        return res;

    }
};
// �������� ��������� ������� �� ������, �������� ������ �� ��������, ������������ ����� ������
// ����������, ������? ��������� ������� �� ������ - ��� ��������� ��������, ������ ��������� *���* ������.
Vector2D operator* (int a, const Vector2D& v)
{
    return v * a;
}

// ����� �������, ��������� ������ � ������� (1; 1)
std::ostream& operator<<(std::ostream& os, const Vector2D& v)
{
    os << "(" << v.getX() << "; " << v.getY() << ")" ;
    return os;
}

// ������ �������, ������ ������ ��� ���������� ��� ���������
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
    // ����������� ������� ����������� n
    VectorN(unsigned int n)
    {
        this->n = n;
        this->coord = new int[n];
    }

    // ����������
    ~VectorN()
    {
        delete[] coord;
    }

    // ��������� ����������� �������
    unsigned int getSize() const
    {
        return n;
    }

    // ��������� �������� i-�� ���������� �������,
    // i ��������� � ��������� �� 0 �� n-1
    int getValue(unsigned int i) const
    {
        return coord[i];
    }

    // ������� �������� i-�� ���������� ������� ������ value,
    // i ��������� � ��������� �� 0 �� n-1
    void setValue(unsigned int i, int value)
    {
        coord[i] = value;
    }

    /*
     * ����� ���������� ������������� ���������
     */

    // �������� == ��������� ��� ������� �� ���������,
    // ����� ���, ���� ������ ����� ���� �� ����������
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

    // �������� != ��������� ��� ������� �� �����������,
    // ��� �� �����, ���� ���� �� ���� ���������� ����������
    bool operator!= (const VectorN& v2) const
    {
        return !((*this) == v2);
    }

    // �������� + ���������� ��� ������� �������������,
    // ���������� ��������� ��� ����� ��������� �������
    VectorN operator+ (const VectorN& v2) const
        {
            VectorN res(this->n);
            for(unsigned int i =0; i<this->n; i++)
            {
                res.setValue(i, this->coord[i] + v2.getValue(i));
            }
            return res;
        }

    // �������� * �������� ������ �� ������ ���� int �������������,
    // ���������� ��������� ��� ����� ��������� �������.
    // ��������� ������ �������� ��� ����� ������� ���������.
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
