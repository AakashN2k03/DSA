#include <iostream>
using namespace std;

int main() {
    // selection sort
    int n, i, j;
    cout << "Enter the limit: " << endl;
    cin >> n;
    
    int arr[n];  // Declare the array after taking the input size
    cout << "Enter the elements: " << endl;
    
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Sorting using selection sort
    for(i = 0; i < n - 1; i++) {
        int min = i;
        for(j = i + 1; j < n; j++) {  // Start from i + 1 to avoid comparing the element with itself
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    
    cout << "\nSorted array: ";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

