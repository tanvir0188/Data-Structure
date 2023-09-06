#include <iostream>
using namespace std;

struct array
{
    int arr[10];
    int length;
    int size;
};

int get(struct array a, int index)
{
    if (index >= 0 && index < a.length)
    {
        return a.arr[index];
    }
    return -1;
}

// Here the array has to be modified, that's why pointer is used
void set(struct array *a_s, int index, int value)
{
    if (index >= 0 && index < a_s->length)
    {
        a_s->arr[index] = value;
    }
}

void display(struct array arra)
{
    for (int i = 0; i < arra.length; i++)
    {
        cout << arra.arr[i] << " ";
    }
}

int Max(struct array a_m)
{
    int max=0;
    int lngth = a_m.length;
    for (int i = 0; i < lngth; i++)
    {
        if (a_m.arr[i] > max)
        {
            max = a_m.arr[i];
        }
    }
    return max;
}

float Avg(struct array a_v){
    int sum =0;
    for (int i = 0; i < a_v.length; i++)
    {
        sum = a_v.arr[i]+sum;
    }
    return sum/a_v.length;
    
}

void reverse(struct array *A){
    int *B;
    int i, j;
    B= new int(A->length);
    for (i = A->length-1,j=0;i>=0;i--,j++)
    {
        B[j]=A->arr[i];
    }
    for (i = 0; i < A->length; i++)
    {
        A->arr[i]=B[i];
    }     

}

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a = *b;
    *b = temp;
}

void reverse_swap(struct array *A){
    for (int i = 0, j=A->length-1; i < j; i++, j--)
    {
        swap(A->arr[i], A->arr[j]);
    }
    
}

void InsertSort(struct array *A_i, int x){
    int i = A_i->length-1;
    if (A_i->length==A_i->size)
    {
        return;
    }
    while(i>=0 && A_i->arr[i]>x){
        A_i->arr[i+1]= A_i->arr[i];
        i--;
    }
    A_i->arr[i+1]=x;
    A_i->length++;
}

int isSort(struct array a){
    for(int i=0; i<a.length-1;i++){
        if(a.arr[i]>a.arr[i+1]){
            return 0;
        }
    }
    return 1;
    
}

void reArrange(struct array *rA){
    int i, j;
    i=0;
    j=rA->length-1;

    while (i<j)
    {
        while(rA->arr[i]<0)
            i++;
        while(rA->arr[j]>=0)
            j--;
        
        if(i<j)
        swap(rA->arr[i], rA->arr[j]);
    }
    
}

int main()
{
    struct array A = {{5, 12, -2, 14, 20,-12, 30}, 7, 14};
    int choice;

    while (true)
    {
        cout<< "0. exit" << endl;
        cout << "1. get()" << endl;
        cout << "2. set()" << endl;
        cout << "3. max()" << endl;
        cout << "4. display()" << endl;
        cout<< "5. avg()"<<endl;
        cout<<"6. reverse by using another array"<<endl;
        cout<<"7. reverse using swap"<<endl;
        cout<<"8. Insert sort"<<endl;
        cout<<"9. isSort()"<<endl;
        cout<<"10. reArrange()"<<endl;
        cout << "choose: ";
        

        cin >> choice;
        if (choice==0)
        {
            cout<<"exiting";
            break;
        }
        switch (choice)
        {
        
        case 1:
            int k;
            cout << "index: ";
            cin >> k;
            cout << get(A, k)<<endl;
            break;

        case 2:
            int i_s, val;
            cout << "index: ";
            cin >> i_s;
            cout << "value: ";
            cin >> val;
            set(&A, i_s, val);
            
            break;
        case 3:
            cout<<"Max value: "<<Max(A)<<endl;
            break;

        case 4:
            display(A);
            cout<<endl;
            break;

        case 5:
            cout<<"average: "<<Avg(A)<<endl;
            break;
        case 6:
            reverse(&A);
            cout<<"reversed"<<endl;
            break;
        
        case 7:
            reverse_swap(&A);
            cout<<"reversed using swap"<<endl;
            break;

        case 8:
            int value;
            cout<<"enter the value: ";
            cin>>value;
            InsertSort(&A, value);
            break;

        case 9:
            cout<< isSort(A)<<endl;
            break;

        case 10:
            reArrange(&A);
            break;

        default:
            cout<<"invalid choice"<<endl;
            break;
        }
    }
}