#include <iostream>

using namespace std;

/**
 * This program implements common doubly linked list operations (insert, delete, search, display) using a doubly linked list.
 */

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void insert(Node *&head, int element)
{
    Node *new_node = new Node;
    new_node->data = element;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->prev = temp;
    }
}   

void delete_element(Node *&head, int element)
{
    if (head == NULL)
    {
        cout << "\n\nList underflow!";
    }
    else
    {
        Node *temp = head;
        Node *prev = NULL;

        while (temp != NULL && temp->data != element)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "\n\nElement not found!";
        }
        else
        {
            if (prev == NULL)
            {
                head = head->next;
                head->prev = NULL;
            }
            else
            {
                prev->next = temp->next;
                if (temp->next != NULL)
                {
                    temp->next->prev = prev;
                }
            }

            delete temp;
        }
    }
}

void search(Node *head, int element)
{
    if (head == NULL)
    {
        cout << "\n\nList underflow!";
    }
    else
    {
        Node *temp = head;
        int position = 0;

        while (temp != NULL && temp->data != element)
        {
            temp = temp->next;
            position++;
        }

        if (temp == NULL)
        {
            cout << "\n\nElement not found!";
        }
        else
        {
            cout << "\n\nElement found at position " << position << ".";
        }
    }
}

void display(Node *head)
{
    if (head == NULL)
    {
        cout << "\n\nList underflow!";
    }
    else
    {
        Node *temp = head;

        cout << "\n\nThe elements of the list are: " << endl;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

int main()
{
    Node *head = NULL;
    int choice, element;

    do
    {
        cout << "\n\nChoose one of the following options: ";
        cout << "\n\n1. Insert an element into the list.";
        cout << "\n\n2. Delete an element from the list.";
        cout << "\n\n3. Search for an element in the list.";
        cout << "\n\n4. Display the elements of the list.";
        cout << "\n\n5. Exit.";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\n\nEnter the element to be inserted: ";
                cin >> element;
                insert(head, element);
                break;
            case 2:
                cout << "\n\nEnter the element to be deleted: ";
                cin >> element;
                delete_element(head, element);
                break;
            case 3:
                cout << "\n\nEnter the element to be searched: ";
                cin >> element;
                search(head, element);
                break;
            case 4:
                display(head);
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