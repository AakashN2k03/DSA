#include<iostream>
using namespace std;

int main()
{
    int n, i, j, row, space, star;
    cout << "Enter the odd number: ";
    cin >> row;
    n = row / 2 + 1;

    // first half
    for (i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n - i; k++)
        {
            cout << "  ";
        }
        for (j = 1; j <= 2 * i - 1; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }

    // second half
    space = 1;
    star = row - 2;
    for (i = n - 1; i >= 1; i--)
    {
        for (j = 1; j <= space; j++)
        {
            cout << "  ";
        }
        for (int k = 1; k <= star; k++)
        {
            cout << "* ";
        }
        space++;
        star -= 2;
        cout << "\n";
    }
    return 0;
}

