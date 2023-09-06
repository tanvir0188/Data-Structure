#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = new Node(); // here first was already declared as gloval value. so can't redeclare this value
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        Node *t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    cout << "linked list: ";
    while (p != nullptr)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL";
}

int count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        p = p->next;
        c++;
    }
    return c;
}

int sum(struct Node *p)
{
    int s = 0;
    while (p != NULL)
    {
        s = s + p->data;
        p = p->next;
    }
    return s;
}

int max(struct Node *p)
{
    int mx = p->data;
    while (p != NULL)
    {

        if (mx < p->data)
        {
            mx = p->data;
        }
        p = p->next;
    }
    return mx;
}

Node *search(struct Node *p, int key)
{
    while (p)
    {
        if (key == p->data)
        {
            return (p);
        }
        p = p->next;
    }
    return NULL;
}

Node *searchTran(Node *p, int key)
{
    Node *q = NULL;
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return first;
        }
        q = p;       // q moves to p
        p = p->next; // then p moves to next
    }
    return 0;
}

// pointers used for acces is called pointers
//.................. holding the next node is called linker
void insert(Node *p, int index, int key)
{
    Node *t = new Node;
    t->data = key;
    p = first;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next; // brings the p to index th node
    }
    t->next = p->next; // both are pointing to the same node.
    p->next = t;       // t should be pointed by p_next
}

void insertFirst(Node *p, int key)
{
    Node *t = new Node;
    t->data = key;
    t->next = first;
    first = t;
}

void insertEnd(int key, Node *p)
{
    Node *end = new Node;
    end->data = key;
    end->next = NULL;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = end;
}

void deleteFirst(Node *p)
{
    Node *temp = new Node;
    temp = first;
    first = first->next;
    free(temp);
}

void deleteLast(Node *p)
{
    Node *ppr;
    while (p->next != NULL)
    {
        ppr = p;
        p = p->next;
    }
    ppr->next = NULL;
    delete p;
}

void deleteByKey(Node *p, int key)
{
    Node *ppr = nullptr, *pl = nullptr, *temp;

    while (p->data != key)
    {
        ppr = p;
        p = p->next;
        pl = p->next;
    }
    if (p->data == key)
    {
        ppr->next = pl;
        delete p;
    }
}

int main()
{
    int A[] = {3, 5, 7, 19, 4};
    create(A, 5);
    display(first);

    cout << endl
         << "count: " << count(first) << endl;
    cout << "sum: " << sum(first) << endl;
    cout << "max: " << max(first) << endl;
    cout << "search with key 7: " << search(first, 7) << endl;
    cout << "transpose search key 7: " << searchTran(first, 7) << endl;
    display(first);
    cout << endl
         << "inserting" << endl;
    insert(first, 1, 12);
    display(first);
    cout << endl;
    insertFirst(first, 13);
    display(first);
    cout << endl;
    insertEnd(25, first);
    display(first);
    cout << endl;
    deleteFirst(first);
    display(first);
    cout << endl;
    deleteLast(first);
    display(first);
    cout << endl;
    deleteByKey(first, 7);
    display(first);
}