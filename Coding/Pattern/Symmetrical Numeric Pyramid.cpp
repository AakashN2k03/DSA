#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    for (int row = 1; row <= n; row++) {
        // Print leading spaces
        for (int space = 1; space <= n - row; space++) {
            cout << "  "; // Two spaces for symmetry
        }

        // Print descending numbers from row to 1
        for (int num = row; num >= 1; num--) {
            cout << num << " ";
        }

        // Print ascending numbers from 2 to row
        for (int num = 2; num <= row; num++) {
            cout << num << " ";
        }

        cout << endl;
    }

    return 0;
}
