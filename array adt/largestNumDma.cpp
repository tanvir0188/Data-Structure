#include <iostream>
using namespace std;

int main() {
    int n, *p;
    cout << "Enter the number of integers: ";
    cin >> n;

    p = new int[n];

    cout << "\nEnter the integers: ";
    for (int i = 0; i < n; i++) {
        cin >> *(p+i);
    }

    for (int i = 1; i < n; i++) {
        if (*p < *(p + i)) {
            *p = *(p + i);
        }
    }

    cout << "\nLargest number: " << *p << endl;

    delete[] p;

    return 0;
}
