#include <iostream>

using namespace std;

/**
 * This program implements common stack operations (push, pop, peek, display) using an array.
 */

void push(int stack[], int &top, int MAX_STACK_SIZE)
{
    if (top == MAX_STACK_SIZE - 1)
    {
        cout << "\n\nStack overflow!";
    }
    else
    {
        int element;
        cout << "\n\nEnter the element to be pushed: ";
        cin >> element;
        top++;
        stack[top] = element;
    }
}

int pop(int stack[], int &top)
{
    if (top == -1)
    {
        cout << "\n\nStack underflow!";
        return -1;
    }
    else
    {
        int element = stack[top];
        top--;
        return element;
    }
}

int peek(int stack[], int top)
{
    if (top == -1)
    {
        cout << "\n\nStack underflow!";
        return -1;
    }
    else
    {
        return stack[top];
    }
}

void display(int stack[], int top)
{
    if (top == -1)
    {
        cout << "\n\nStack underflow!";
    }
    else
    {
        cout << "\n\nThe elements of the stack are: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
    }
}

int main()
{
    int MAX_STACK_SIZE;
    cout << "\n\nEnter the maximum size of the stack: ";
    cin >> MAX_STACK_SIZE;

    int *stack = new int[MAX_STACK_SIZE];
    int top = -1;
    int choice;

    do
    {
        cout << "\n\n1. Push an element into the stack.";
        cout << "\n\n2. Pop an element from the stack.";
        cout << "\n\n3. Peek at the top of the stack.";
        cout << "\n\n4. Display the elements of the stack.";
        cout << "\n\n5. Exit.";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            push(stack, top, MAX_STACK_SIZE);
            break;

        case 2:
            cout << "\n\nThe popped element is: " << pop(stack, top);
            break;

        case 3:
            cout << "\n\nThe element at the top of the stack is: " << peek(stack, top);
            break;

        case 4:
            display(stack, top);
            break;

        case 5:
            cout << "\n\nExiting...";
            break;

        default:
            cout << "\n\nInvalid choice!";
            break;
        }
    } while (choice != 5);

    delete[] stack;

    return 0;
}