#include<iostream>
using namespace std;

void array_right(int arr[], int n, int d)
{
    d = d % n;
    int temp[n];
    int i, k = 0;
    
    // Copy the last d elements to temp
    for (i = n - d; i < n; i++) //n=7 ,d =2
    {
        temp[k] = arr[i];
        k++;
    }

    // Copy the first n-d elements to temp
    for (i = 0; i < n - d; i++)
    {
        temp[k] = arr[i];
        k++;
    }

    // Copy elements from temp back to arr
    for (i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int n, a[100], i, d;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the value of d: ";
    cin >> d;
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    array_right(a, n, d);

    cout << "\nSorted array after right rotation: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

