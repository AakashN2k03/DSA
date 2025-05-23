// CODE 360:  Search In A Rotated Sorted Array II (BS)

bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    // Write your code here
    int low,high,mid;
    low=0;
    high=A.size()-1;
    while(low<=high)
    {
        mid=(low+high)/2;

        if(A[mid]==key)
        {
            return true;
        }

        if(A[low]==A[mid]&& A[mid]==A[high]) // this condition is for duplicates in sorted rotated array
        {
            low=low+1;
            high=high-1;
           // continue; //it is better to use continue but without continue also all testcases passes.
        }

        if(A[low]<=A[mid])
        {
            if(A[low]<=key && key <=A[mid])
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        else{
            if(A[mid]<=key && key<=A[high])
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return false;
}
// TIME COMPLEXITY:
// Best case (with no duplicates): O(log n)
// Worst case (with duplicates): O(n)

// SPACE COMPLEXITY: O(1)

// it can also performed by linear search but it is not an optimized one according to constraints provided by th code 360.
