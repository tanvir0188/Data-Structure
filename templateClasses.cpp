#include<iostream>
using namespace std;

template <class T>
class arithmatic{
    T a;
    T b;
    public:
    arithmatic( T a, T b);
    T add();
    T sub();
};

template <class T>
arithmatic<T>::arithmatic(T a, T b)
{
    this->a=a;
    this->a=b;
}

template <class T>
T arithmatic<T>::add()
{
    T sum;
    sum=a+b;
    return sum;
}

template <class T>
T arithmatic<T>::sub()
{
    T subtraction;
    subtraction=a-b;
    return subtraction;
}

int main(){
    arithmatic<int> ar(10, 5);
    cout<<ar.add();


}


