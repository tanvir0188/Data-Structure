#include <iostream>
using namespace std;

struct array
{
    int A[10];
    int length;
    int size;
};

void pairOfSum(struct array a, int k)
{
    int l = a.length;
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (k == a.A[i] + a.A[j])
            {
                cout << a.A[i] << ", " << a.A[j] << ", " << k<<endl;
            }
        }
    }
}

int main()
{
    struct array arr;
    arr = {{2, 3, 5, 6, 4}, 5, 10};
    pairOfSum(arr, 10);
}