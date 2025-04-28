LEETCODE: 70. Climbing Stairs ( DP)

// Dynamic Programming is a method for solving complex problems by breaking them down into smaller subproblems, solving each subproblem only once, 
// and storing the solution for future use (called memoization).
// It is mainly used for optimization problems where a solution depends on solutions to smaller subproblems.
// 🔵 In simple words:
// Instead of recalculating answers again and again, DP remembers answers and reuses them.

// There are mainly two types:

// 1. Top-Down (Memoization)	Solve bigger problem by solving smaller problems and saving their results in memory.
// (Use recursion + cache)
// 2. Bottom-Up (Tabulation)	Solve all small problems first, then build up the solution for the bigger problem.
// (Use iteration + table/array)

// MEMOIZATION (TOP DOWN)
class Solution {
public:
  int fibonacci(int n,vector<int>& dp)
  {
 // Base cases
    if (n <= 1) return n;

 if(dp[n]!=-1) return dp[n];

return dp[n]=fibonacci(n - 1,dp) + fibonacci(n - 2,dp);
  }
    int climbStairs(int n) {
      
        vector<int>dp(n+1,-1);
        return fibonacci(n,dp);
    }
};
TIME COMPELXITY: O(N)
SPACE COMPLEXITY: O(N)+O(N) -> STACK SPACE IS INVOLVED

// TABULATION (BOTTOM UP)
class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
TIME COMPELXITY: O(N)
SPACE COMPLEXITY: O(N)

// ✅ Quick Conditions to Use 1D DP:
// Condition	Explanation
// Problem asks about counting ways, finding min/max cost, computing nth term, etc. -> 	Ex: "How many ways to climb stairs", "Min cost to reach end", "Nth Fibonacci number".
// At any point, your answer only depends on previous one or few states.-> 	Ex: current step depends on dp[i-1], dp[i-2] only.
// State can be described by a single number (like i = step number, i = position)	-> No second variable (like i, j for grids needed).
// Recurrence relation exists — like: dp[i] = dp[i-1] + dp[i-2], or dp[i] = min(dp[i-1], dp[i-2]) + cost[i]-> 	Some formula connecting previous values to the current value.
// You can build answers sequentially from 0 to n. -> 	Ex: from step 0, to step 1, to step 2...
