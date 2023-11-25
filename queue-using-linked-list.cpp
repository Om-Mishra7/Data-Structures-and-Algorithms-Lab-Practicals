#include <iostream>

using namespace std;

/**
 * This program implements common queue operations (enqueue, dequeue, peek, display) using a linked list.
 */

struct Node
{
    int data;
    Node *next;
};

void enqueue(Node *&front, int element)
{
    Node *new_node = new Node;
    new_node->data = element;
    new_node->next = NULL;

    if (front == NULL)
    {
        front = new_node;
    }
    else
    {
        Node *temp = front;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_node;
    }
}

void dequeue(Node *&front)
{
    if (front == NULL)
    {
        cout << "\n\nQueue underflow!";
    }
    else
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
}

int peek(Node *&front)
{
    if (front == NULL)
    {
        cout << "\n\nQueue underflow!";
        return -1;
    }
    else
    {
        return front->data;
    }
}

void display(Node *&front)
{
    if (front == NULL)
    {
        cout << "\n\nQueue underflow!";
    }
    else
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

int main()
{
    Node *front = NULL;

    int choice, element;

    do
    {
        cout << "\n\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n\nEnter the element to be enqueued: ";
            cin >> element;
            enqueue(front, element);
            break;

        case 2:
            dequeue(front);
            break;

        case 3:
            cout << "\n\nThe front element is: " << peek(front);
            break;

        case 4:
            cout << "\n\nThe queue is: ";
            display(front);
            break;

        case 5:
            cout << "\n\nExiting...";
            break;

        default:
            cout << "\n\nInvalid choice!";
        }
    } while (choice != 5);

    return 0;
}