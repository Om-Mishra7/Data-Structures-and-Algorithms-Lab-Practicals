#include <iostream>

using namespace std;

/**
 * This program implements the selection sort algorithm.
 */

void selection_sort(int array[], int size)
{
    if (size == 1)
    {
        return;
    }

    int min_index = 0;
    for (int i = 1; i < size; i++)
    {
        if (array[i] < array[min_index])
        {
            min_index = i;
        }
    }

    int temp = array[0];
    array[0] = array[min_index];
    array[min_index] = temp;

    selection_sort(array + 1, size - 1);

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

    selection_sort(array, size);

    cout << "The sorted array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}
