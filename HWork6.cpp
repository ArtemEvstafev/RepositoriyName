#include <iostream>
using namespace std;
template<typename T>
class Vector2D
{
private:
    T x, y;
public:
    // ������������
    Vector2D(): Vector2D(0,0){};
    Vector2D(T x, T y): x(x), y(y){};

    // ����������
    ~Vector2D(){};

    // ��������� ���������
    T getX() const
    {
        return x;
    }
    T getY() const
    {
        return y;
    }

    // ������� ���������
    void setX(T x)
    {
        this->x = x;
    }
    void setY(T y)
    {
        this->y = y;
    }

    // ������������� �������� - ��������� ���� �������� �� ���������

    bool operator== (const Vector2D<T>& v2) const
    {
        return (this->x == v2.x && this->y == v2.y);
    }

    // ��� ���� ������������� �������� - ����������� ��������
    // ��, ��� ��������� ��������! ���� - ��������� ������ ������ ��� != ������������ ��� ���������� ==

    bool operator!= (const Vector2D<T>& v2) const
    {
        return !((*this) == v2);
    }

    // ����� ���� ��������, �������� ������� �� ��������, ������������ ����� ������

    Vector2D<T> operator+ (const Vector2D<T>& v2) const
        {
            Vector2D<T> res(this->x + v2.getX(), this->y + v2.getY());
            return res;
        }

    // ��������� ��������, �������� ������� �� ��������, ������������ ����� ������

    Vector2D<T> operator- (const Vector2D<T>& v2) const
    {
        return (*this)+(v2 * -1);
    }

    // �������� ��������� ������� �� ������, �������� ������ �� ��������, ������������ ����� ������

    Vector2D<T> operator* (const int a) const
    {
        Vector2D<T> res(this->x * a, this->y * a);
        return res;

    }
};
// �������� ��������� ������� �� ������, �������� ������ �� ��������, ������������ ����� ������
// ����������, ������? ��������� ������� �� ������ - ��� ��������� ��������, ������ ��������� *���* ������.
template<typename T>
Vector2D<T> operator* (int a, const Vector2D<T>& v)
{
    return v * a;
}

// ����� �������, ��������� ������ � ������� (1; 1)
template<typename T>
ostream& operator<<(std::ostream& os, const Vector2D<T>& v)
{
    os << "(" << v.getX() << "; " << v.getY() << ")" ;
    return os;
}

// ������ �������, ������ ������ ��� ���������� ��� ���������
template<typename T>
istream& operator>>(std::istream &is, Vector2D<T> &v)
{
    T x , y;
    is >> x >> y ;
    v.setX(x);
    v.setY(y);
    return is;
}
int main()
{
    Vector2D<int> v1;
    cin >> v1;
    cout << "Read vector: " << v1 << endl;
    cout << "Vector multiplied by 42: " << v1 * 42 << endl;

    Vector2D<double> v2;
    cin >> v2;
    cout << "Read vector: " << v2 << endl;
    cout << "Vector multiplied by 42: " << 42 * v2 << endl;
}
