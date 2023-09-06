#include<iostream>
using namespace std;

int fun(int n){
    if (n>0)
    {
        return fun(n-1) +1;
    }
    return 0;
    
}

int main(){
    int r;
    cout<<"value of r ";
    cin>>r;


}