# Time Complexity Guide for Coding Platforms

In coding platforms like LeetCode, Codeforces, or HackerRank, time constraints are very important. Understanding the input size helps you determine the best algorithm to use based on its time complexity.

---

## ✅ Estimating Time Complexity Based on Input Size

Most online judges can handle about **10^8 operations per second**. Use the following table to estimate the maximum acceptable time complexity for a given input size:

| Input Size (n) | Maximum Acceptable Time Complexity |
|----------------|------------------------------------|
| ≤ 10           | O(n!) or O(2^n) is fine             |
| ≤ 20           | O(2^n) is acceptable                |
| ≤ 100          | O(n^3) or better                    |
| ≤ 1,000        | O(n^2) or better                    |
| ≤ 10^5         | O(n log n) or better               |
| ≤ 10^6         | O(n) or O(n log n)                 |
| ≥ 10^7         | O(n) only                          |

---




## 🔹 Pro Tips

- ✅ Use **binary search** on sorted arrays → O(log n)
- ✅ Use **hashmaps/sets** for constant time lookup → O(1)
- ✅ Use **prefix sum**, **sliding window**, or **two pointers** to reduce time
- ✅ Use **sieve of Eratosthenes** for precomputing primes efficiently
- ❌ Avoid **nested loops** when `n > 1000`
- ✅ Prefer **sorting (O(n log n))** if necessary, but not repeatedly
- ✅ Always **analyze edge cases** (e.g., large values of `n`)

---

## ✅ Example Use Cases

### Example 1:
> Constraint: 1 ≤ n ≤ 10^5
- Best to aim for **O(n log n)** or **O(n)**.
- Sorting, Hashing, Prefix Sum, etc.

### Example 2:
> Constraint: 1 ≤ n ≤ 15
- Brute force algorithms like **O(2^n)** or **O(n!)** can work here.

---

By estimating the time complexity correctly, you can avoid TLE (Time Limit Exceeded) errors and write efficient solutions confidently!

### NOTE:
- 📌 Why 1e9 is safer than INT_MAX in DP:
Suppose you write:
int res = grid[i][j] + INT_MAX;
You risk overflow — because INT_MAX + x exceeds the limit of int, which causes undefined behavior.

- But: int res = grid[i][j] + 1e9;
is safer because 1e9 is much less than INT_MAX, so addition won’t cause overflow in 99.9% of competitive programming scenarios.

#### 1e9     ->	1,000,000,000 (	A large safe constant)
#### INT_MAX -> 2,147,483,647  (Maximum value for 32-bit int)

