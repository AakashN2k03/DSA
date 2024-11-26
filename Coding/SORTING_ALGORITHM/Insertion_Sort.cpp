#include <iostream>
using namespace std;

int main() {
    // insertion sort
    /* arr=[4,12,14,15,6,13]
     4,12,14,15,6,13
     4,12,14,15,6,13
     4,12,14,15,6,13
     4,12,14,6,15,13
     4,12,6,14,15,13
     4,6,12,14,15,13
     4,6,12,14,13,15
     4,6,12,13,14,15
    */
    int n, i, j;
    cout << "Enter the limit: " << endl;
    cin >> n;
    
    int arr[n];  // Declare the array after taking the input size
    cout << "Enter the elements: " << endl;
    
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Sorting using insertion sort
    // takes an element and fixes it in a current location
  
    for(i =0;i<n;i++) {
           j=i;
           
            while(j>0 && arr[j-1]>arr[j])
            {  
               swap(arr[j-1], arr[j]);
			   j--;
        }
    }
    
    cout << "\nSorted array: ";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

