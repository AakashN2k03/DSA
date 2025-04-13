# Time Complexity in Data Structures and Algorithms (DSA)

Time complexity tells us how fast or slow an algorithm runs as the input size increases. Understanding time complexity helps you choose or design efficient algorithms for your problems.

Below is a list of **common time complexities** in **increasing order (fastest to slowest)**:

---

## ✅ 1. O(1) — Constant Time
- Time doesn't change with input size.
- 📌 **Example:** Accessing an array element `arr[5]`

---

## ✅ 2. O(log n) — Logarithmic Time
- Time grows slowly as input size increases.
- 📌 **Example:** Binary Search on a sorted array

---

## ✅ 3. O(√n) — Square Root Time
- Time grows with the square root of the input size.
- 📌 **Example:**
  - Prime number check up to √n
  - Jump Search
  - Factor counting

---

## ✅ 4. O(n) — Linear Time
- Time increases proportionally with input.
- 📌 **Example:** Traversing an array of size `n`

---

## ✅ 5. O(n log n) — Linearithmic Time
- Slightly more than linear but better than quadratic.
- 📌 **Example:** Merge Sort, Heap Sort

---

## ✅ 6. O(n²) — Quadratic Time
- Time increases as the square of input.
- 📌 **Example:** Bubble Sort, Selection Sort

---

## ✅ 7. O(n³) — Cubic Time
- Time increases as the cube of input.
- 📌 **Example:** 3 nested loops (e.g., matrix multiplication)

---

## ✅ 8. O(2^n) — Exponential Time
- Time doubles with each additional input unit.
- 📌 **Example:** Recursive Fibonacci (without memoization)

---

## ✅ 9. O(n!) — Factorial Time
- One of the slowest time complexities.
- 📌 **Example:** Solving the Traveling Salesman Problem with brute force

---

## → **Summary: Time Complexities in Increasing Order**
```
O(1) < O(log n) < O(√n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2^n) < O(n!)
```

Use this cheat sheet whenever you need to analyze or compare the efficiency of algorithms. It helps in both competitive programming and real-world problem solving!

