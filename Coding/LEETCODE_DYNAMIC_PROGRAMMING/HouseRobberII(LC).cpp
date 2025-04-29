// LEETCODE: House Robber II (DP)\

//solve it using memoization and tabulation
//NOTE:This code is a solution for Leetcode 213: House Robber II, which is a circular version of the original House Robber problem (198).

class Solution {
public:
    int house_robber_II(vector<int>&nums)
      { 
        int n=nums.size();
        int prev=nums[0];
        int prev2=0; // to avoid negative
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notpick=0+prev;
            int maxi=max(pick,notpick);
            prev2=prev;
            prev=maxi;

        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(house_robber_II(temp1),house_robber_II(temp2));
    }
};

 Time Complexity: O(N)
Space Complexity: O(1)
