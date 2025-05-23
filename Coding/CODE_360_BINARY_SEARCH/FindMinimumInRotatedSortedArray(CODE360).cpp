// CODE 360: Find Minimum in Rotated Sorted Array

// METHOD 1

#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int>& arr)
{
	// Write your code here.
	return *min_element(arr.begin(),arr.end()); // this method passes 78/80 testcases, two are not passed due to time complexity
}

//  METHOD 2 (BETTER APPROACH)

#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int>& arr)
{
	 int low,high,mid,ans;
	 low=0;
	 ans=INT_MAX;
	 high=arr.size()-1;
	 while(low<=high)
	 {  mid=(low+high)/2;
		 if(arr[low]<=arr[mid])
		 {
         ans=min(ans,arr[low]);
				 low=mid+1;
		 }
		 else{
			 ans=min(ans,arr[mid]);
			 high=mid-1;
		 }
	 }
	 return ans;
}
// Time Complexity
// Best case: O(log n) — when no duplicates  
// Worst case: O(n) — when all elements are duplicates and you only shrink by 1 each time
// SPACE COMPLEXITY: O(1)
