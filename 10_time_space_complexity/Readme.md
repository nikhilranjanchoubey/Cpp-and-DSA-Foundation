# 📘 Time and Space Complexity 

A comprehensive reference for understanding algorithm complexity analysis, covering fundamental concepts, loop analysis patterns, and practical examples.

## 📚 Table of Contents

- [Introduction](#introduction)
- [Fundamental Concepts](#fundamental-concepts)
- [Asymptotic Notations](#asymptotic-notations)
- [Loop Analysis Patterns](#loop-analysis-patterns)
- [Nested Loop Patterns](#nested-loop-patterns)
- [Key Rules & Tips](#key-rules--tips)
- [Common Complexities Cheat Sheet](#common-complexities-cheat-sheet)

---

## 🔹Introduction

Understanding time and space complexity is crucial for writing efficient algorithms and making informed decisions about data structures and algorithm choices. This guide provides clear explanations and practical examples to help you analyze and optimize your code.

---

## 🔹Fundamental Concepts

### ⏱️ Time Complexity
**Definition:** The number of steps or operations an algorithm takes as the input size `n` grows.

**Why it matters:** Helps predict how your algorithm scales with larger inputs and allows comparison between different approaches.

###  💾 Space Complexity
**Definition:** The amount of memory used during execution, including variables, data structures, recursion stack, etc.

**Why it matters:** Critical for understanding memory constraints and optimizing for memory-limited environments.

---

## 🔹Asymptotic Notations

These notations help us express complexity by focusing on the growth rate rather than exact counts.

| Notation | Symbol | Meaning | Use Case |
|----------|--------|---------|----------|
| **Big-O** | O | Upper bound (≤) | Worst-case scenario |
| **Big-Omega** | Ω | Lower bound (≥) | Best-case scenario |
| **Big-Theta** | Θ | Tight bound (=) | Average-case scenario |

**Most commonly used:** Big-O notation, as we typically care about worst-case performance guarantees.

---

## 🔹Loop Analysis Patterns

### Pattern 1: Linear Increment

```cpp
for (int i = 0; i < n; i++) {
    // O(1) operation
}
```

**Analysis:**
- Loop runs from `i = 0` to `i = n-1`
- Total iterations: `n`
- **Time Complexity: O(n)**

---

### Pattern 2: Multiplicative Growth (Doubling)

```cpp
for (int i = 1; i < n; i *= 2) {
    // O(1) operation
}
```

**Analysis:**
- Values of `i`: 1, 2, 4, 8, 16, ..., until `i < n`
- Each iteration doubles, so we solve: `2^k < n` → `k < log₂(n)`
- Total iterations: `⌊log₂(n)⌋`
- **Time Complexity: O(log n)**

**Reverse pattern (Division):**
```cpp
for (int i = n; i > 0; i /= 2) {
    // O(1) operation
}
// Also O(log n)
```

---

### Pattern 3: Self-Incrementing

```cpp
for (int i = 1; i < n; i += i) {
    // Equivalent to i = i + i, which is i *= 2
}
```

**Analysis:**
- Values of `i`: 1, 2, 4, 8, 16, ...
- Same pattern as multiplicative growth
- **Time Complexity: O(log n)**

---

## 🔹 Nested Loop Patterns

### Pattern 1: Independent Nested Loops

```cpp
for (int i = 0; i < n; i++) {       // Outer: n times
    for (int j = 0; j < n; j++) {   // Inner: n times
        // O(1) operation
    }
}
```

**Analysis:**
- Outer loop: `n` iterations
- Inner loop: `n` iterations for each outer iteration
- Total operations: `n × n = n²`
- **Time Complexity: O(n²)**

---

### Pattern 2: Dependent Inner Loop

```cpp
for (int i = 0; i < n; i++) {        
    for (int j = 0; j < i; j++) {   // Runs i times
        // O(1) operation
    }
}
```

**Analysis:**
- When `i = 0`: 0 operations
- When `i = 1`: 1 operation
- When `i = 2`: 2 operations
- ...
- When `i = n-1`: n-1 operations
- Total: `0 + 1 + 2 + ... + (n-1) = n(n-1)/2 ≈ n²/2`
- **Time Complexity: O(n²)** (constants dropped)

---

### Pattern 3: Linear × Logarithmic

```cpp
for (int i = 0; i < n; i++) {        
    for (int j = 1; j < n; j *= 2) {   // O(log n)
        // O(1) operation
    }
}
```

**Analysis:**
- Outer loop: `n` iterations
- Inner loop: `log n` iterations
- Total operations: `n × log n`
- **Time Complexity: O(n log n)**

**Common in:** Efficient sorting algorithms (Merge Sort, Heap Sort)

---

## 🔹Key Rules & Tips

### ✅ Rule 1: Drop Constants
Constants don't affect growth rate for large `n`.

```
O(2n) = O(n)
O(n/2) = O(n)
O(100n) = O(n)
```

### ✅ Rule 2: Drop Lower-Order Terms
Focus on the dominant term.

```
O(n² + n) = O(n²)
O(n³ + n² + n) = O(n³)
O(n log n + n) = O(n log n)
```

### ✅ Rule 3: Logarithm Base Doesn't Matter
All logarithms are equivalent in Big-O notation.

```
log₂(n) ≈ log₁₀(n) ≈ logₑ(n) → All are O(log n)
```

**Why?** Change of base formula: `log_a(n) = log_b(n) / log_b(a)` (constant factor)

### ✅ Rule 4: Analyze Worst Case by Default
Unless specified otherwise, assume worst-case analysis using Big-O.

### ✅ Rule 5: Multiplication for Nested, Addition for Sequential

**Nested (multiplying):**
```cpp
for (i = 0; i < n; i++)      // O(n)
    for (j = 0; j < n; j++)  // O(n)
// Total: O(n × n) = O(n²)
```

**Sequential (adding):**
```cpp
for (i = 0; i < n; i++)  // O(n)
for (j = 0; j < n; j++)  // O(n)
// Total: O(n + n) = O(n)
```

---

## 🔹 Common Complexities Cheat Sheet

Ranked from fastest to slowest:

| Complexity | Name | Example |
|------------|------|---------|
| **O(1)** | Constant | Array access, hash table lookup |
| **O(log n)** | Logarithmic | Binary search, balanced tree operations |
| **O(n)** | Linear | Single loop through array |
| **O(n log n)** | Linearithmic | Merge sort, heap sort, quick sort (average) |
| **O(n²)** | Quadratic | Nested loops, bubble sort, selection sort |
| **O(n³)** | Cubic | Triple nested loops |
| **O(2ⁿ)** | Exponential | Recursive Fibonacci, subset generation |
| **O(n!)** | Factorial | Permutation generation, traveling salesman |

### 🔹Visual Growth Comparison

For `n = 1000`:
- O(1): 1 operation
- O(log n): ~10 operations
- O(n): 1,000 operations
- O(n log n): ~10,000 operations
- O(n²): 1,000,000 operations
- O(2ⁿ): More than atoms in universe!

---

## 🎯 Quick Practice Tips

1. **Identify loops:** Count how many times code executes
2. **Check increment pattern:** Linear (+) vs multiplicative (*)
3. **Nested loops:** Multiply complexities if dependent
4. **Recursive calls:** Use recurrence relations or recursion tree
5. **Always simplify:** Drop constants and lower-order terms

---

## 📖 Further Reading

- [Time and Space Complexity](https://www.geeksforgeeks.org/dsa/time-complexity-and-space-complexity/)
- [Big-O Cheat Sheet](http://bigocheatsheet.com/)


---


**Happy Coding! 🚀**