#pragma once
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Linklist
{
    struct node
    {
        int data;
        node *next;
    };

public:
    node *head;

    Linklist() : head(nullptr){}; // empty linklist

    void insert(int n, int i)
    {
        node *temp1 = new node;
        temp1->data = i;
        temp1->next = nullptr;
        node *temp2;
        int j;

        if (n == 1)
        { // insert 1th
            temp1->data = i;
            head = temp1;
            return;
        }

        temp2 = head;
        for (j = 1; j < n - 1; j++)
        { // traverse until (n-1)th element
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
        // logic error:: adress of next element is lost!!!
        // temp2->next = temp1;
        // temp1->next = temp2->next->next; // or "temp2=temp2->next; temp1=temp2->next;"
        // delete temp2;  // didn't allcate memory for temp2

        return;
    };

    void del(int n)
    {
        int i;
        node *temp1, *temp2;

        if (head == nullptr)
        {
            cout << "empty list!" << endl;
            return;
        }

        temp1 = head;
        for (i = 0; i < n - 2; i++) // n-2,not(n-1)!
            temp1 = temp1->next;
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2; // release the memory of n-th element
        return;
    };
    
    // using iterative to traverse for implementation
    void reverse()
    { 
        node *prev, *current, *next;
        if (head == nullptr)
        {
            cout << "The list is empty!" << endl;
            return;
        }

        prev = nullptr;
        current = head;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    };

    void print()
    {
        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    };

    // using recursion to implement reversion
    void reverseB(node* p)
    {
        if (p->next == nullptr)
        {
            head = p;
            return;
        }
        reverseB(p->next);
        node *temp1 = p->next;
        temp1->next = p;
        p->next = nullptr;
    };
    
    //to print the elements backwards by using recursion
    void printB(node *head)
    {
        if (head == nullptr)
        {
            return;
        }
        printB(head->next);
        cout << head->data << endl;
    };

    ~Linklist(){};
};
