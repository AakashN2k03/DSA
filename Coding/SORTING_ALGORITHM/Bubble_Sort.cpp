#include <iostream>
using namespace std;

int main() {
    // bubble sort
    int n, i, j;
    cout << "Enter the limit: " << endl;
    cin >> n;
    
    int arr[n];  // Declare the array after taking the input size
    cout << "Enter the elements: " << endl;
    
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Sorting using bubble sort
    // find maximum and pushes to last
    // swap adjacent elements
    for(i = n-1; i >=0;i--) {
        for(j = 0; j < i; j++) {  
            if(arr[j]>arr[j+1]) {
               swap(arr[j], arr[j+1]);
            }
        }

    }
    
    cout << "\nSorted array: ";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

