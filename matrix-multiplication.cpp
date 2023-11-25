#include <iostream>

using namespace std;

/**
 * This program performs matrix multiplication.
 * It takes input for the number of rows and columns of the matrices,
 * as well as the elements of the matrices.
 * It then multiplies the corresponding elements of the matrices and displays the resultant matrix.
 */
int main()
{
    int row_size_one, col_size_one, row_size_two, col_size_two;

    cout << "\n\nEnter the number of rows for the first matrix: ";
    cin >> row_size_one;

    cout << "\n\nEnter the number of columns for the first matrix: ";
    cin >> col_size_one;

    row_size_two = col_size_one; // For matrix multiplication, the number of columns of the first matrix should be equal to the number of rows of the second matrix.

    cout << "\n\nEnter the number of columns for the second matrix: ";
    cin >> col_size_two;

    int matrix_one[row_size_one][col_size_one], matrix_two[row_size_two][col_size_two], resultant_matrix[row_size_one][col_size_two];

    cout << "\n\nEnter the elements of the first matrix: " << endl;

    for (int i = 0; i < row_size_one; i++)
    {
        for (int j = 0; j < col_size_one; j++)
        {
            cout << "\nEnter the element at position (" << i << ", " << j << "): ";
            cin >> matrix_one[i][j];
        }
    }

    cout << "\n\nEnter the elements of the second matrix: " << endl;

    for (int i = 0; i < row_size_two; i++)
    {
        for (int j = 0; j < col_size_two; j++)
        {
            cout << "\nEnter the element at position (" << i << ", " << j << "): ";
            cin >> matrix_two[i][j];
        }
    }

    for (int i = 0; i < row_size_one; i++)
    {
        for (int j = 0; j < col_size_two; j++)
        {
            resultant_matrix[i][j] = 0;
            for (int k = 0; k < col_size_one; k++)
            {
                resultant_matrix[i][j] += matrix_one[i][k] * matrix_two[k][j];
            }
        }
    }

    cout << "\n\nThe resultant matrix is: \n" << endl;

    for (int i = 0; i < row_size_one; i++)
    {
        for (int j = 0; j < col_size_two; j++)
        {
            cout << resultant_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}

