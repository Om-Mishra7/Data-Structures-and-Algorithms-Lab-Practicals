#include <iostream>

using namespace std;

/**
 * This program implements common queue operations (enqueue, dequeue, peek, display) using an array.
 */

void enqueue(int queue[], int &front, int &rear, int MAX_QUEUE_SIZE)
{
    if (rear == MAX_QUEUE_SIZE - 1)
    {
        cout << "\n\nQueue overflow!";
    }
    else
    {
        int element;
        cout << "\n\nEnter the element to be enqueued: ";
        cin >> element;
        rear++;
        queue[rear] = element;
    }
}

int dequeue(int queue[], int &front, int &rear)
{
    if (front == rear)
    {
        cout << "\n\nQueue underflow!";
        return -1;
    }
    else
    {
        int element = queue[front + 1];
        front++;
        return element;
    }
}

int peek(int queue[], int front, int rear)
{
    if (front == rear)
    {
        cout << "\n\nQueue underflow!";
        return -1;
    }
    else
    {
        return queue[front + 1];
    }
}

void display(int queue[], int front, int rear)
{
    if (front == rear)
    {
        cout << "\n\nQueue underflow!";
    }
    else
    {
        cout << "\n\nThe elements of the queue are: ";
        for (int i = front + 1; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
}

int main()
{
    int MAX_QUEUE_SIZE;
    cout << "\n\nEnter the maximum size of the queue: ";
    cin >> MAX_QUEUE_SIZE;

    int *queue = new int[MAX_QUEUE_SIZE];
    int front = -1, rear = -1;
    int choice;

    do
    {
        cout << "\n\nEnter 1 to enqueue an element into the queue.";
        cout << "\nEnter 2 to dequeue an element from the queue.";
        cout << "\nEnter 3 to peek at the front element of the queue.";
        cout << "\nEnter 4 to display the elements of the queue.";
        cout << "\nEnter 5 to exit.";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enqueue(queue, front, rear, MAX_QUEUE_SIZE);
            break;
        case 2:
            cout << "\n\nThe dequeued element is: " << dequeue(queue, front, rear);
            break;
        case 3:
            cout << "\n\nThe front element of the queue is: " << peek(queue, front, rear);
            break;
        case 4:
            display(queue, front, rear);
            break;
        case 5:
            cout << "\n\nExiting...";
            break;
        default:
            cout << "\n\nInvalid choice!";
        }
    } while (choice != 5);

    delete[] queue;

    return 0;
}