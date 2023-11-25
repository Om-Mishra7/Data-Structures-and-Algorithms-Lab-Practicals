#include <iostream>

using namespace std;

/**
 * This program implements binary search tree operations (insert, delete, search, display) using a binary search tree.
 */

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void insert(Node *&root, int element)
{
    Node *new_node = new Node;
    new_node->data = element;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL)
    {
        root = new_node;
    }
    else
    {
        Node *temp = root;
        Node *prev = NULL;

        while (temp != NULL)
        {
            prev = temp;
            if (element < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        if (element < prev->data)
        {
            prev->left = new_node;
        }
        else
        {
            prev->right = new_node;
        }
    }
}

void delete_element(Node *&root, int element)
{
    if (root == NULL)
    {
        cout << "\n\nTree underflow!";
    }
    else
    {
        Node *temp = root;
        Node *prev = NULL;

        while (temp != NULL && temp->data != element)
        {
            prev = temp;
            if (element < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        if (temp == NULL)
        {
            cout << "\n\nElement not found!";
        }
        else
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                if (prev == NULL)
                {
                    root = NULL;
                }
                else if (prev->left == temp)
                {
                    prev->left = NULL;
                }
                else
                {
                    prev->right = NULL;
                }

                delete temp;
            }
            else if (temp->left == NULL)
            {
                if (prev == NULL)
                {
                    root = temp->right;
                }
                else if (prev->left == temp)
                {
                    prev->left = temp->right;
                }
                else
                {
                    prev->right = temp->right;
                }

                delete temp;
            }
            else if (temp->right == NULL)
            {
                if (prev == NULL)
                {
                    root = temp->left;
                }
                else if (prev->left == temp)
                {
                    prev->left = temp->left;
                }
                else
                {
                    prev->right = temp->left;
                }

                delete temp;
            }
            else
            {
                Node *successor = temp->right;
                Node *successor_prev = temp;

                while (successor->left != NULL)
                {
                    successor_prev = successor;
                    successor = successor->left;
                }

                temp->data = successor->data;

                if (successor_prev->left == successor)
                {
                    successor_prev->left = successor->right;
                }
                else
                {
                    successor_prev->right = successor->right;
                }

                delete successor;
            }
        }
    }
}

bool search(Node *&root, int element)
{
    if (root == NULL)
    {
        return false;
    }
    else
    {
        Node *temp = root;

        while (temp != NULL && temp->data != element)
        {
            if (element < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        if (temp == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

void display(Node *&root)
{
    if (root == NULL)
    {
        cout << "\n\nTree underflow!";
    }
    else
    {
        cout << "\n\nTree: ";
        Node *temp = root;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->left;
        }
    }
}

int main()
{
    Node *root = NULL;

    int choice;
    int element;

    do
    {
        cout << "\n\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Search";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n\nEnter the element to be inserted: ";
            cin >> element;
            insert(root, element);
            break;
        case 2:
            cout << "\n\nEnter the element to be deleted: ";
            cin >> element;
            delete_element(root, element);
            break;
        case 3:
            cout << "\n\nEnter the element to be searched: ";
            cin >> element;
            if (search(root, element))
            {
                cout << "\n\nElement found!";
            }
            else
            {
                cout << "\n\nElement not found!";
            }
            break;
        case 4:
            display(root);
            break;
        case 5:
            break;
        default:
            cout << "\n\nInvalid choice!";
        }
    } while (choice != 5);

    return 0;
}
