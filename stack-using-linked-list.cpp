#include <iostream>

using namespace std;

/**
 * This program implements common stack operations (push, pop, peek, display) using a linked list.
 */

struct Node
{
    int data;
    Node *next;
};

void push(Node *&top, int element)
{
    Node *new_node = new Node;
    new_node->data = element;
    new_node->next = NULL;

    if (top == NULL)
    {
        top = new_node;
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }
}

void pop(Node *&top)
{
    if (top == NULL)
    {
        cout << "\n\nStack underflow!";
    }
    else
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

int peek(Node *&top)
{
    if (top == NULL)
    {
        cout << "\n\nStack underflow!";
        return -1;
    }
    else
    {
        return top->data;
    }
}

void display(Node *&top)
{
    if (top == NULL)
    {
        cout << "\n\nStack underflow!";
    }
    else
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

int main()
{
    Node *top = NULL;
    int choice, element;

    do
    {
        cout << "\n\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n\nEnter the element to be pushed: ";
            cin >> element;
            push(top, element);
            break;

        case 2:
            pop(top);
            break;

        case 3:
            cout << "\n\nThe top element is: " << peek(top);
            break;

        case 4:
            cout << "\n\nThe stack is: ";
            display(top);
            break;

        case 5:
            cout << "\n\nExiting...";
            break;

        default:
            cout << "\n\nInvalid choice!";
            break;
        }
    } while (choice != 5);

    return 0;
}