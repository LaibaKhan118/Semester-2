// Q4: create a function named unique that takes an array, removes the duplicate alues, and returns an updated array wth inly unique elements.

#include <iostream>
using namespace std;

int unique(int *arr, int n);

int main()
{
    int n;
    cout << "Enter the number of elements of the array: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter the elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    n = unique(arr, n);

    cout << "\nUpdated Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    delete[] arr;

    return 0;
}

int unique(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < n; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }
    return n;
}
