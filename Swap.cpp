#include <iostream>
using namespace std;
template<typename T>
T Swap(T &a, T &b)
{
    T tmp;
    tmp=a;
    a=b;
    b=tmp;
}
int main()
{

    int a=10, b=20;
    cout<<"Enter two values";
    cin>>a>>b;

    cout<<a<<" "<<b<<endl;
    Swap(a, b);
    cout<<a<<" "<<b<<endl;
    return 0;
}
