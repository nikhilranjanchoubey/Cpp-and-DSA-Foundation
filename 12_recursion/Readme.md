# RECURSION

C++ programs demonstrating recursive problem-solving techniques from basic to advanced levels.

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
  - [Basic Recursion](#basic-recursion)
  - [Mathematical Problems](#mathematical-problems)
  - [Array Recursion](#array-recursion)
  - [String Recursion](#string-recursion)
  - [Backtracking & Subsequences](#backtracking--subsequences)
  - [Dynamic Programming Problems](#dynamic-programming-problems)
- [Key Concepts](#key-concepts)
- [Recursion Patterns](#recursion-patterns)
- [Complete Learning Path](#complete-learning-path)

## Overview

Twenty-one programs covering recursive techniques including basic recursion, mathematical calculations, array/string operations, backtracking, and dynamic programming foundations.

## Programs

### Basic Recursion

#### 1. increasingSequence.cpp - Print Numbers 1 to N
Prints numbers in increasing order using recursion.

**Logic:** Recurse first, then print (backtracking)

**Example:** `number(5)` → Output: `1 2 3 4 5`

**Key Concept:** Recursion + backtracking for ascending order

**Learns:** Base case, recursive call before action

---

#### 2. multiples.cpp - Multiplication Table
Prints multiplication table using recursion.

**Example:** `printMultiples(5, 7)` → Output: `5 10 15 20 25 30 35`

**Logic:** Recurse to multiplier 1, then print on backtrack

**Learns:** Recursion with two parameters, backtracking for order

---

### Mathematical Problems

#### 3. factorial.cpp - Factorial Calculation
Calculates factorial of N recursively.

**Formula:** `n! = n × (n-1)!`

**Base Case:** `factorial(1) = 1`

**Example:** `factorial(5) = 5 × 4 × 3 × 2 × 1 = 120`

**Learns:** Simple recursion, single base case

---

#### 4. fibonacci.cpp - Fibonacci Number
Finds nth Fibonacci number.

**Formula:** `fib(n) = fib(n-1) + fib(n-2)`

**Base Cases:** `fib(0) = 0`, `fib(1) = 1`

**Example:** `fib(6) = 8` (0, 1, 1, 2, 3, 5, 8)

**Time:** O(2^n) - exponential

**Learns:** Multiple recursive calls, multiple base cases

---

#### 5. power.cpp - Basic Exponentiation
Calculates base^exponent using simple recursion.

**Formula:** `power(b, e) = b × power(b, e-1)`

**Base Case:** `power(b, 0) = 1`

**Time:** O(n)

**Learns:** Linear recursion, single recursive call

---

#### 6. power2.cpp - Optimized Exponentiation
Fast exponentiation using binary exponentiation (exponentiation by squaring).

**Formulas:**
- Even: `power(b, e) = power(b, e/2)²`
- Odd: `power(b, e) = b × power(b, (e-1)/2)²`

**Time:** O(log n)

**Example:** `power(2, 10)` - only 4 recursive calls instead of 10

**Learns:** Optimization technique, divide-and-conquer

---

#### 7. sumofdigits.cpp - Sum of Digits
Calculates sum of all digits in a number.

**Formula:** `sum(n) = (n % 10) + sum(n / 10)`

**Base Case:** Single digit returns itself

**Example:** `sum(1234) = 1 + 2 + 3 + 4 = 10`

**Learns:** Digit extraction, simple recursion

---

#### 8. alternateSignSum.cpp - Alternating Sum
Calculates sum with alternating signs: 1 - 2 + 3 - 4 + ...

**Logic:** Add if odd, subtract if even

**Example:** `alternatingSum(5) = 1 - 2 + 3 - 4 + 5 = 3`

**Learns:** Conditional recursion, pattern-based problems

---

#### 9. calculateGCD.cpp - Greatest Common Divisor
Finds GCD using Euclidean algorithm.

**Formula:** `gcd(a, b) = gcd(b, a % b)`

**Base Case:** `gcd(a, 0) = a`

**Example:** `gcd(48, 18) = 6`

**Learns:** Euclidean algorithm, mathematical recursion

---

#### 10. palindrome.cpp - Palindrome Check
Checks if a number is palindrome recursively.

**Logic:** Compare first and last digits, recurse on middle

**Example:** `12621` → Palindrome

**Learns:** Pointer usage in recursion, digit comparison

---

#### 11. armstrongNumber.cpp - Armstrong Number
Checks if number equals sum of its digits raised to power of digit count.

**Example:** `153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153` ✓

**Uses:** Optimized power function (power2.cpp logic)

**Learns:** Combining multiple recursive functions

---

### Array Recursion

#### 12. array.cpp - Print Array
Prints array elements recursively.

**Logic:** Print current, recurse on rest

**Learns:** Array traversal with recursion, index management

---

#### 13. sumofarray.cpp - Array Sum
Calculates sum of array elements.

**Formula:** `sum(arr, i) = arr[i] + sum(arr, i+1)`

**Base Case:** Last element

**Learns:** Array recursion, accumulation

---

#### 14. maxfromarray.cpp - Find Maximum
Finds maximum element in array.

**Logic:** Compare current with max of rest

**Formula:** `max(arr, i) = max(arr[i], max(arr, i+1))`

**Learns:** Recursive comparison, divide-and-conquer

---

#### 15. isArraySorted.cpp - Search in Array
Checks if target exists in array (despite filename).

**Logic:** Check current or search in rest

**Formula:** `found = (arr[i] == target) || search(arr, i+1)`

**Learns:** Boolean recursion, OR logic in recursion

---

### String Recursion

#### 16. removeOccurenceOfA.cpp - Remove Character
Removes all occurrences of 'a' from string.

**Logic:** Skip 'a', include others, recurse

**Example:** `"abcax"` → `"bcx"`

**Learns:** String building in recursion, conditional inclusion

---

#### 17. stringSubsequence.cpp - Generate Subsequences
Generates all subsequences of a string.

**Logic:** Include or exclude each character (2 choices per char)

**Example:** `"abc"` → `a, ab, abc, ac, b, bc, c`

**Total:** 2^n subsequences

**Learns:** Backtracking, include/exclude pattern

---

#### 18. subsetSum.cpp - Subset Sums
Generates all possible subset sums from array.

**Logic:** Include or exclude each element

**Example:** `[2, 4, 5]` → `0, 2, 4, 5, 6, 7, 9, 11`

**Total:** 2^n subsets

**Learns:** Subset generation, accumulator parameter

---

### Backtracking & Subsequences

#### 19. letterCombinations.cpp - Phone Number Combinations
Generates all letter combinations for digit string (phone keypad).

**Example:** `"23"` → `ad, ae, af, bd, be, bf, cd, ce, cf`

**Mapping:** 2→abc, 3→def, 4→ghi, etc.

**Learns:** Backtracking with choices, multi-way recursion

---

### Dynamic Programming Problems

#### 20. frogJumpProblem.cpp - Minimum Cost Path
Frog jumps 1 or 2 stones forward, minimize cost.

**Cost:** `|height[i] - height[j]|`

**Formula:** `minCost(i) = min(cost(i+1) + |h[i]-h[i+1]|, cost(i+2) + |h[i]-h[i+2]|)`

**Example:** `[10, 30, 40, 20]` → Output: `30`

**Note:** Exponential without memoization (DP foundation)

**Learns:** Choice-based recursion, optimization problems

---

#### 21. grid.cpp - Grid Paths
Counts paths from top-left to bottom-right (only right/down moves).

**Formula:** `paths(i,j) = paths(i, j+1) + paths(i+1, j)`

**Example:** 2×3 grid → 3 paths

**Time:** O(2^(m+n)) without memoization

**Learns:** 2D recursion, path counting

---

## Key Concepts

### What is Recursion?

A function that calls itself to solve smaller instances of the same problem.

**Components:**
1. **Base Case**: Stopping condition (prevents infinite recursion)
2. **Recursive Case**: Function calls itself with modified parameters
3. **Progress**: Each call moves toward base case

### Basic Structure

```cpp
returnType function(parameters) {
    // Base case
    if(baseCondition) {
        return baseValue;
    }
    
    // Recursive case
    return function(modifiedParameters);
}
```

### Call Stack

Each recursive call is pushed onto the call stack:
```
factorial(3)
  → factorial(2)
    → factorial(1)
      → returns 1
    → returns 2
  → returns 6
```

### Types of Recursion

**1. Linear Recursion** (single recursive call)
```cpp
int factorial(int n) {
    if(n == 1) return 1;
    return n * factorial(n - 1);
}
```

**2. Binary Recursion** (two recursive calls)
```cpp
int fibonacci(int n) {
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
```

**3. Tail Recursion** (recursive call is last operation)
```cpp
void print(int n) {
    if(n == 0) return;
    cout << n << " ";
    print(n - 1);  // Last operation
}
```

**4. Non-Tail Recursion** (operations after recursive call)
```cpp
int factorial(int n) {
    if(n == 1) return 1;
    return n * factorial(n - 1);  // Multiplication after call
}
```

## Recursion Patterns

### Pattern 1: Simple Recursion
```cpp
// Calculate sum of first n natural numbers
int sum(int n) {
    if(n == 0) return 0;
    return n + sum(n - 1);
}
```

### Pattern 2: Backtracking Print
```cpp
// Print numbers 1 to n
void print(int n) {
    if(n == 0) return;
    print(n - 1);      // Recurse first
    cout << n << " ";  // Print on backtrack
}
```

### Pattern 3: Divide and Conquer
```cpp
// Binary exponentiation
int power(int base, int exp) {
    if(exp == 0) return 1;
    int half = power(base, exp / 2);
    if(exp % 2 == 0)
        return half * half;
    else
        return base * half * half;
}
```

### Pattern 4: Array Recursion
```cpp
// Find maximum in array
int findMax(int arr[], int n) {
    if(n == 1) return arr[0];
    return max(arr[n-1], findMax(arr, n-1));
}
```

### Pattern 5: Include/Exclude (Subset Generation)
```cpp
void generateSubsets(string str, int i, string current, vector<string> &result) {
    if(i == str.length()) {
        result.push_back(current);
        return;
    }
    // Include current character
    generateSubsets(str, i+1, current + str[i], result);
    // Exclude current character
    generateSubsets(str, i+1, current, result);
}
```

### Pattern 6: Multiple Choices (Backtracking)
```cpp
// Generate all letter combinations
void generate(string digits, int i, string current, vector<string> &result) {
    if(i == digits.length()) {
        result.push_back(current);
        return;
    }
    // Try all letters mapped to current digit
    for(char c : mapping[digits[i]]) {
        generate(digits, i+1, current + c, result);
    }
}
```

## Recursion vs Iteration

| Aspect | Recursion | Iteration |
|--------|-----------|-----------|
| **Structure** | Function calls itself | Loops (for, while) |
| **Memory** | Uses call stack | Uses variables |
| **Space** | O(n) stack space | O(1) space |
| **Readability** | Often cleaner for complex problems | Can be verbose |
| **Performance** | Overhead of function calls | Generally faster |
| **Use Cases** | Tree/graph traversal, backtracking | Simple repetitive tasks |

## Common Pitfalls

### Missing Base Case
```cpp
❌ int factorial(int n) {
    return n * factorial(n - 1);  // Infinite recursion!
}

✅ int factorial(int n) {
    if(n == 1) return 1;  // Base case
    return n * factorial(n - 1);
}
```

### Wrong Base Case
```cpp
❌ int fibonacci(int n) {
    if(n == 1) return 1;  // Missing fib(0)
    return fibonacci(n-1) + fibonacci(n-2);
}

✅ int fibonacci(int n) {
    if(n == 0 || n == 1) return n;  // Both base cases
    return fibonacci(n-1) + fibonacci(n-2);
}
```

### Not Making Progress
```cpp
❌ int sum(int n) {
    if(n == 0) return 0;
    return n + sum(n);  // Doesn't move toward base case!
}

✅ int sum(int n) {
    if(n == 0) return 0;
    return n + sum(n - 1);  // Reduces n
}
```

### Stack Overflow
```cpp
// For very large n, stack overflows
factorial(100000);  // Too many recursive calls

// Solution: Use iteration or tail recursion optimization
```

## Time Complexity Analysis

| Problem | Recurrence | Time Complexity |
|---------|------------|-----------------|
| Factorial | T(n) = T(n-1) + O(1) | O(n) |
| Fibonacci | T(n) = T(n-1) + T(n-2) + O(1) | O(2^n) |
| Binary Search | T(n) = T(n/2) + O(1) | O(log n) |
| Power (basic) | T(n) = T(n-1) + O(1) | O(n) |
| Power (optimized) | T(n) = T(n/2) + O(1) | O(log n) |
| Merge Sort | T(n) = 2T(n/2) + O(n) | O(n log n) |
| Subsequences | T(n) = 2T(n-1) + O(1) | O(2^n) |

## Optimization Techniques

### Memoization (Top-Down DP)
```cpp
// Fibonacci with memoization
int memo[100];
int fib(int n) {
    if(n <= 1) return n;
    if(memo[n] != -1) return memo[n];
    return memo[n] = fib(n-1) + fib(n-2);
}
```

### Tail Recursion
```cpp
// Tail recursive factorial
int factorialHelper(int n, int acc) {
    if(n == 1) return acc;
    return factorialHelper(n-1, n * acc);
}

int factorial(int n) {
    return factorialHelper(n, 1);
}
```

## Complete Learning Path

Follow this structured path to master recursion:

### Phase 1: Fundamentals 
1. **increasingSequence.cpp** - Understand call stack
2. **multiples.cpp** - Backtracking concept
3. **factorial.cpp** - Simple recursion
4. **sumofdigits.cpp** - Digit manipulation

### Phase 2: Mathematical 
5. **fibonacci.cpp** - Multiple recursive calls
6. **power.cpp** - Linear recursion
7. **power2.cpp** - Optimization technique
8. **calculateGCD.cpp** - Euclidean algorithm
9. **alternateSignSum.cpp** - Conditional recursion
10. **palindrome.cpp** - Complex logic
11. **armstrongNumber.cpp** - Combining functions

### Phase 3: Arrays 
12. **array.cpp** - Array traversal
13. **sumofarray.cpp** - Array accumulation
14. **maxfromarray.cpp** - Finding extremes
15. **isArraySorted.cpp** - Boolean recursion

### Phase 4: Strings 
16. **removeOccurenceOfA.cpp** - String building
17. **stringSubsequence.cpp** - Subsequence generation
18. **subsetSum.cpp** - Subset problems

### Phase 5: Backtracking 
19. **letterCombinations.cpp** - Multi-way choices

### Phase 6: DP Foundations 
20. **frogJumpProblem.cpp** - Choice-based DP
21. **grid.cpp** - 2D recursion


**Tips for Learning:**
- Draw recursion tree for each problem
- Trace execution with small inputs
- Identify base case first
- Practice writing recurrence relations
- Start with iterative solutions, then convert to recursive

---
**Happy Coding! 🚀**