#include <iostream>

using namespace std;

/**
 * This program implements the bubble sort algorithm.
 */

void bubble_sort(int array[], int size)
{
    if (size == 1)
    {
        return;
    }

    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }

    bubble_sort(array, size - 1);

    return;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int array[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    bubble_sort(array, size);

    cout << "The sorted array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}