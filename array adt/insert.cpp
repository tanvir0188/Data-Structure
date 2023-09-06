#include <iostream>
using namespace std;

struct Array
{
    int arr[10];
    int length;
    int size;
};

void insert(struct Array *arra, int value, int index)
{
    if (index >= 0 && index <= arra->length)

        for (int i = arra->length; i >= index; i--)
        {
            arra->arr[i] = arra->arr[i - 1];
        }
    arra->arr[index] = value;
    arra->length++;
}

// insert new element at the end
void Append(struct Array *arra, int x)
{
    if (arra->length < arra->size)
    {
        arra->arr[arra->length++] = x;
    }
}

void deletion(struct Array *arra, int index)
{
    if (index >= 0 && index <= arra->length)
        for (int i = index; i < arra->length; i++)
        {
            arra->arr[i] = arra->arr[i + 1];
        }
    arra->length--;
}

void display(struct Array arra)
{
    for (int i = 0; i < arra.length; i++)
    {
        cout << arra.arr[i] << " ";
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int linearsrch(struct Array *arrl, int key)
{
    for (int i = 0; i < arrl->length; i++)
    {
        if (key == arrl->arr[i])
        {
            swap(&arrl->arr[i], &arrl->arr[0]); // swaps the key with the first index value
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array *arrbi, int key)
{
    int l, mid, h;
    l = 0;
    h = arrbi->length;

    while (l < h)
    {
        mid = (l + h) / 2;
        if (arrbi->arr[mid] == key)
        {
            return mid;
        }
        else if (arrbi->arr[mid] < key)
            l = mid;
        else
            h = mid;
    }

    return -1;
}

int main()
{
    struct Array arr = {{5, 12, 14, 20, 30}, 5, 10};

    int ap, value, indx;

    // cout << "after deletion" << endl;
    // display(arr);

    int option;
    cout << "insertion, deletion, appending, linear search etc" << endl
         << endl;

    while (true)
    {
        cout << "-------------choose any option-----------------" << endl;
        cout << "             0. exit" << endl;
        cout << "             1. display" << endl;
        cout << "             2. append" << endl;
        cout << "             3. insert" << endl;
        cout << "             4. deletion" << endl;
        cout << "             5. use linear search" << endl;
        cout << "             6. use binary search" << endl;
        cout << "choose an option: ";
        cin >> option;
        if (option == 0)
        {
            cout << "exiting";
            break;
        }

        switch (option)
        {

        case 1:
            display(arr);

            break;

        case 2:
            cout << "enter the appending value: ";
            cin >> ap;
            Append(&arr, ap);
            break;

        case 3:
            cout << "insert: ";
            cin >> value;
            cout << "index: ";
            cin >> indx;
            insert(&arr, value, indx);
            break;

        case 4:
            int indxd;
            cout << "delete value of index: ";
            cin >> indxd;
            deletion(&arr, indxd);
            break;

        case 5:
            int k;
            cout << "enter the key: ";
            cin >> k;
            cout << "the value is at index no = " << linearsrch(&arr, k);
            break;

        case 6:
            int k_of_binary;
            cout << "enter the key: ";
            cin >> k_of_binary;
            cout << "index no = " << BinarySearch(&arr, k_of_binary);
            break;

        default:
            cout << endl
                 << "invalid option" << endl;
        }
    }
}