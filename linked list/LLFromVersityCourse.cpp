#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int inf;
    struct node* next;
};

struct node* start = NULL;
struct node* tail = NULL;

void create() {
    struct node* temp, * p;
    temp = new struct node;
    if (temp == NULL) {
        cout << "Out of memory space" << endl;
        exit(0);
    }
    cout << "Enter the value for the node: ";
    cin >> temp->inf;
    temp->next = NULL;
    if (start == NULL) {
        start = temp;
    }
    else {
        p = start;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void display() {
    struct node* p;
    if (start == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        p = start;
        cout << "Elements: ";
        while (p != NULL) {
            cout << p->inf << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void insert_at_begin() {
    struct node* newnode, * temp;
    newnode = new struct node;
    cin >> newnode->inf;
    newnode->next = NULL;
    if (start == NULL) {
        start = newnode;
        tail = newnode;
    }
    else {
        newnode->next = start;
        start = newnode;
    }
}

void insert_at_end() {
    struct node* newnode, * temp;
    newnode = new struct node;
    cin >> newnode->inf;
    newnode->next = NULL;
    if (start == NULL) {
        start = newnode;
        tail = newnode;
    }
    else {
        tail->next = newnode;
        tail = newnode;
    }
}

void ins_on_specif_pos() {
    int pos;
    struct node* newnode, * temp, * temp1;
    newnode = new struct node;
    cout << "Enter the node: ";
    cin >> newnode->inf;
    cout << "Enter the position: ";
    cin >> pos;
    if (start == NULL) {
        start = newnode;
        tail = newnode;
    }
    else {
        temp = start;
        for (int i = 1; i < pos; i++) {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = newnode;
        newnode->next = temp;
    }
}

void del_fast() {
    struct node* temp;
    temp = start;
    start = start->next;
    delete temp;
}

void del_last() {
    struct node* temp, * temp1;
    if (start != NULL) {
        temp = start;
        while (temp->next != NULL) {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        delete temp;
    }
}

void del_positionwise() {
    struct node* temp, * temp1;
    int key;
    if (start == NULL) {
        cout << "The list is empty." << endl;
    }
    else {
        cout << "Enter the key: ";
        cin >> key;
    }
    temp1 = start;
    for (int i = 0; i < key; i++) {
        temp = temp1;
        temp1 = temp1->next;
        if (temp1 == NULL) {
            cout << "The given position isn't right" << endl;
        }
    }
    temp->next = temp1->next;
    delete temp1;
}

void reverse_list() {
    struct node* next, * prev;
    struct node* temp = start;
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    start = prev;
}

void remove_dupl_num() {
    struct node* temp, * temp1, * dup;
    temp = start;
    while (temp != NULL) {
        temp1 = temp;
        while (temp1->next != NULL) {
            if (temp->inf == temp1->next->inf) {
                dup = temp1->next;
                temp1->next = temp1->next->next;
                delete dup;
            }
            else {
                temp1 = temp1->next;
            }
        }
        temp = temp->next;
    }
}

int main() {
    while (true) {
        cout << "Menu" << endl;
        cout << "(1) Create" << endl;
        cout << "(2) Display" << endl;
        cout << "(3) Insert at the beginning" << endl;
        cout << "(4) Insert at the end" << endl;
        cout << "(5) Insert at the specified position" << endl;
        cout << "(6) Delete from the beginning" << endl;
        cout << "(7) Delete from the last" << endl;
        cout << "(8) Delete from the specified position" << endl;
        cout << "(9) Reverse the list" << endl;
        cout << "(10) Delete duplicate numbers" << endl;
        cout << "(11) Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            create();
            break;

        case 2:
            display();
            break;

        case 3:
            insert_at_begin();
            break;

        case 4:
            insert_at_end();
            break;

        case 5:
            ins_on_specif_pos();
            break;

        case 6:
            del_fast();
            break;

        case 7:
            del_last();
            break;

        case 8:
            del_positionwise();
            break;

        case 9:
            reverse_list();
            break;

        case 10:
            remove_dupl_num();
            break;

        case 11:
            exit(0);
            break;
        }
    }
    return 0;
}
