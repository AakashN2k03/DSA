// CODE360:  Ninja’s Training (DP , MEMOIZATION )

int ninja(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if (dp[day][last] != -1)
        return dp[day][last];

    if (day == 0) {
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int point = points[day][task] + ninja(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, -1)); // last = 0,1,2,3
    return ninja(n - 1, 3, points, dp);
}

// TIME COMPLEXITY: O(n×4×3)=O(n)
// SPACE COMPLEXITY:Space=O(n)+O(n)=O(n)
// ​
// ​
