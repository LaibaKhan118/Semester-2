  // Q3: 2D-Array
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
int **allocateMatrix(int rows, int cols);
void randomElements(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);
int sumElements(int **matrix, int rows, int cols);
void sumRowsCols(int **matrix, int rows, int cols, int *rowSums, int *colSums);
void findMaxSumRowCol(int *rowSums, int *colSums, int rows, int cols);
void transposeMatrix(int **matrix, int rows, int cols);
void deallocateMatrix(int **matrix, int rows);

int main()
{
    srand(time(0));
    int cols, rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int **matrix = allocateMatrix(rows, cols);
    randomElements(matrix, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    int sum = sumElements(matrix, rows, cols);
    cout << "\nSum of All Elements: " << sum << endl;

    int *rowSums = new int[rows];
    int *colSums = new int[cols];
    sumRowsCols(matrix, rows, cols, rowSums, colSums);

    cout << endl;
    findMaxSumRowCol(rowSums, colSums, rows, cols);

    cout << endl;
    transposeMatrix(matrix, rows, cols);

    deallocateMatrix(matrix, rows);
    delete[] rowSums;
    delete[] colSums;
}

int **allocateMatrix(int rows, int cols)
{
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void randomElements(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
}

void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int sumElements(int **matrix, int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

void sumRowsCols(int **matrix, int rows, int cols, int *rowSums, int *colSums)
{
    for (int i = 0; i < rows; i++)
    {
        rowSums[i] = 0;
    }
    for (int i = 0; i < rows; i++)
    {
        colSums[i] = 0;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            rowSums[i] += matrix[i][j];
            colSums[j] += matrix[i][j];
        }
    }

    cout << "\nSum of Rows: " << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << ": " << rowSums[i] << endl;
    }

    cout << "\nSum of Columns: " << endl;
    for (int i = 0; i < cols; i++)
    {
        cout << "Col " << i + 1 << ": " << colSums[i] << endl;
    }
}

void findMaxSumRowCol(int *rowSums, int *colSums, int rows, int cols)
{
    int MaxRow = 0, MaxCol = 0;
    for (int i = 1; i < rows; i++)
    {
        if (rowSums[i] > rowSums[MaxRow])
        {
            MaxRow = i;
        }
    }
    for (int i = 1; i < cols; i++)
    {
        if (colSums[i] > colSums[MaxCol])
        {
            MaxCol = i;
        }
    }

    cout << "The Row with max sum is: " << rowSums[MaxRow] << endl;
    cout << "The Column with max sum is: " << colSums[MaxCol] << endl;
}

void transposeMatrix(int **matrix, int rows, int cols)
{
    int **transpose = allocateMatrix(cols, rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "Transpose of the original Matrix: " << endl;
    printMatrix(transpose, rows, cols);

    deallocateMatrix(transpose, rows);
}

void deallocateMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
