#include <iostream>

using namespace std;

/**
 * This program performs matrix addition.
 * It takes input for the number of rows and columns of the matrices,
 * as well as the elements of the matrices.
 * It then adds the corresponding elements of the matrices and displays the resultant matrix.
 */
int main()
{
    int row_size, col_size;

    cout << "\n\nEnter the number of rows for the matrix: ";
    cin >> row_size;

    cout << "\n\nEnter the number of columns for the matrix: ";
    cin >> col_size;

    int matrix_one[row_size][col_size], matrix_two[row_size][col_size], resultant_matrix[row_size][col_size]; // For matrix addition the order of the matrices should be same.

    cout << "\n\nEnter the elements of the first matrix: " << endl;

    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            cout << "\nEnter the element at position (" << i << ", " << j << "): ";
            cin >> matrix_one[i][j];
        }
    }

    cout << "\n\nEnter the elements of the second matrix: "
         << endl;

    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            cout << "\nEnter the element at position (" << i << ", " << j << "): ";
            cin >> matrix_two[i][j];
        }
    }

    cout << "\n\nThe resultant matrix is: \n"
         << endl;

    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            resultant_matrix[i][j] = matrix_one[i][j] + matrix_two[i][j];
            cout << resultant_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}