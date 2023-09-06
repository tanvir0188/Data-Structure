#include<iostream>
using namespace std;


int main(){
    int a[5];
    int *p;
    p = new int(5);
    p[0]=4;
    cout<<p[0];

    delete []p;

}