# ARRAYS

C++ programs demonstrating array and vector operations including searching, sorting, manipulation, and advanced algorithms.

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
  - [Basics](#basics)
  - [Searching](#searching)
  - [Finding Elements](#finding-elements)
  - [Counting & Sum](#counting--sum)
  - [Sorting & Rearranging](#sorting--rearranging)
  - [Two Pointer Technique](#two-pointer-technique)
  - [Prefix Sum](#prefix-sum)
  - [Advanced Problems](#advanced-problems)
- [Key Concepts](#key-concepts)
- [Common Techniques](#common-techniques)

## Overview

Programs covering array basics, vectors, searching algorithms, sorting techniques, two-pointer approach, and advanced problem-solving.

## Programs

### Basics

#### 1. basic.cpp - Array Fundamentals
Demonstrates various ways to traverse and access arrays.

**Methods:** Normal indexing, for loop, for-each loop, while loop

**Learns:** Array declaration, `sizeof()`, array length, different loop types

---

#### 2. input.cpp - Array Input
Takes input for character array using different methods.

**Learns:** Taking input with loops, pass by reference in for-each (`char &element`)

---

#### 3. vector.cpp - Vector Operations
Shows vector size, capacity, and dynamic growth.

**Operations:** `push_back()`, `pop_back()`, `resize()`, size vs capacity

**Output Pattern:** Size and capacity changes as elements are added/removed

**Learns:** Dynamic arrays, memory management, vector growth strategy

---

#### 4. loopInVector.cpp - Vector Traversal
Demonstrates input/output with vectors using different loops.

**Operations:** `push_back()`, `insert()`, `erase()`, traversal methods

**Learns:** Vector manipulation, iterator basics, loop variations

---

### Searching

#### 5. linearSearch.cpp - Linear Search
Searches for element in array, returns index or -1.

**Example:** Find 11 in [3, 9, 18, 11, 7] → Returns index 3

**Learns:** Sequential search, early termination with `break`

---

#### 6. lastOccurence.cpp - Last Occurrence
Finds last occurrence of element using two methods.

**Method 1:** Forward scan, update index each time
**Method 2:** Backward scan, break on first match

**Learns:** Different search strategies, optimization

---

#### 7. queries.cpp - Frequency Queries
Handles multiple queries efficiently using frequency array.

**Technique:** Preprocessing with frequency array (size 10^5)

**Learns:** Query optimization, frequency counting, O(1) lookup

---

### Finding Elements

#### 8. maximum.cpp - Maximum Element
Finds maximum value in array.

**Logic:** Initialize with first element, compare with rest

**Learns:** Finding extremes, comparison logic

---

#### 9. secondLargest.cpp - Second Largest
Finds second largest element in array.

**Method:** Two-pass approach (find max, then find second max excluding max)

**Learns:** Multi-pass algorithms, conditional comparisons with `INT_MIN`

---

#### 10. arrayManipulation.cpp - Find Unique Element
Finds unique element where all others appear twice.

**Logic:** Mark duplicates as -1, print remaining positive

**Learns:** Nested loops for pair detection, array modification

---

### Counting & Sum

#### 11. sum.cpp - Array Sum
Calculates sum of all elements.

**Learns:** Accumulation pattern, array traversal

---

#### 12. countGreater.cpp - Count Greater Elements
Counts elements strictly greater than X.

**Learns:** Conditional counting, comparison operators

---

#### 13. numberOccurence.cpp - Count Occurrences
Counts occurrences of specific element.

**Learns:** Frequency counting, for-each loop usage

---

#### 14. difference.cpp - Even-Odd Index Difference
Finds difference between sum of even index and odd index elements.

**Formula:** Sum(even indices) - Sum(odd indices)

**Learns:** Index-based operations, conditional accumulation

---

### Sorting & Rearranging

#### 15. sortedOrNotArray.cpp - Check Sorted
Checks if array is sorted in non-decreasing order.

**Logic:** Compare each element with previous, flag if unsorted

**Learns:** Sorted array verification, boolean flags

---

#### 16. sortArrayOnly0and1.cpp - Sort 0s and 1s (Counting)
Sorts binary array by counting zeros.

**Method:** Count 0s, fill array with 0s first, then 1s

**Time:** O(n), **Space:** O(1)

**Learns:** Counting sort for binary values

---

#### 17. sortArrayOnly0and1byswaping.cpp - Sort 0s and 1s (Two Pointer)
Sorts binary array using two-pointer technique.

**Logic:** Left pointer finds 1s, right finds 0s, swap them

**Time:** O(n), **Space:** O(1)

**Learns:** Two-pointer approach, in-place sorting

---

#### 18. sortevenatStartandOddatEnd.cpp - Segregate Even/Odd
Moves all even numbers to start, odd to end.

**Logic:** Two-pointer swap when left is odd and right is even

**Learns:** Partitioning arrays, two-pointer segregation

---

#### 19. rotateArray.cpp - Rotate Array
Rotates array by K steps to the right.

**Method:** Create new array, copy last K elements first, then rest

**Example:** [1,2,3,4,5] with k=2 → [4,5,1,2,3]

**Learns:** Array rotation, modulo for k>n

---

#### 20. rotateArrayUsingVector.cpp - Rotate with Reverse
Rotates using triple reverse technique.

**Algorithm:**
1. Reverse entire array
2. Reverse first k elements
3. Reverse remaining elements

**Learns:** Reverse algorithm, optimal rotation

---

### Two Pointer Technique

#### 21. pairSum.cpp - Find Pair with Target Sum
Finds if pair exists with given sum in sorted array.

**Technique:** Two pointers from start and end

**Logic:** If sum < target, move left; if sum > target, move right

**Time:** O(n), **Space:** O(1)

**Learns:** Two-pointer on sorted arrays, optimal pair finding

---

#### 22. uniquePair.cpp - Count Unique Pairs
Counts unique pairs with target sum in sorted array.

**Logic:** Similar to pairSum, but counts and moves both pointers

**Learns:** Counting pairs, avoiding duplicates

---

#### 23. pairDifference.cpp - Find Pair with Target Difference
Finds pair with exact absolute difference in sorted array.

**Logic:** If diff < target, increase j; if diff > target, increase i

**Learns:** Two-pointer for difference problems

---

#### 24. targetSum.cpp - Count Pairs with Sum
Counts all pairs with target sum using brute force.

**Method:** Nested loops, check all pairs

**Time:** O(n²), **Space:** O(1)

**Learns:** Brute force pair counting, nested iterations

---

#### 25. tripletsSum.cpp - Count Triplets with Sum
Counts triplets with target sum.

**Method:** Triple nested loops

**Time:** O(n³), **Space:** O(1)

**Learns:** Triplet enumeration, three nested loops

---

### Prefix Sum

#### 26. prefixSum.cpp - Running Sum
Computes prefix sum in-place.

**Logic:** `v[i] = v[i] + v[i-1]`

**Example:** [1,2,3,4] → [1,3,6,10]

**Learns:** In-place transformation, cumulative sum

---

#### 27. prefixSumQueriesSolver.cpp - Range Sum Queries
Answers multiple range sum queries efficiently.

**Preprocessing:** Build prefix sum array

**Query:** Sum(l to r) = prefix[r] - prefix[l-1]

**Time:** O(n + q), where q = number of queries

**Learns:** Query optimization, 1-based indexing

---

#### 28. prefixSuffixsum.cpp - Equal Partition Check
Checks if array can be partitioned into two equal sum parts.

**Logic:** At any point, if prefix_sum == suffix_sum, partition exists

**Learns:** Partition problems, prefix-suffix technique

---

### Advanced Problems

#### 29. sortedSquare.cpp / sortarrayinSquareofNon-DecreasingOrder.cpp
Squares sorted array and returns sorted result.

**Challenge:** Array has negative numbers

**Technique:** Two pointers from ends, compare absolute values

**Logic:** Larger absolute value squared goes to end of result

**Example:** [-4,-3,-1,0,2,10] → [0,1,4,9,16,100]

**Learns:** Two-pointer on sorted arrays with negatives

---

#### 30. mergeArray.cpp - Merge Two Sorted Arrays
Merges two sorted arrays into one sorted array.

**Algorithm:**
1. Compare elements from both arrays
2. Add smaller to result
3. When one exhausted, add remaining from other

**Time:** O(m+n), **Space:** O(m+n)

**Learns:** Merge algorithm, two-pointer merging

---

## Key Concepts

### Array Basics

**Declaration:**
```cpp
int arr[5] = {1, 2, 3, 4, 5};  // Static array
int arr[5];                     // Uninitialized
```

**Size & Length:**
```cpp
sizeof(arr)                     // Total bytes
sizeof(arr)/sizeof(arr[0])      // Number of elements
```

**Access:**
```cpp
arr[0]                          // First element
arr[n-1]                        // Last element
```

### Vector Operations

**Declaration:**
```cpp
vector<int> v;                  // Empty vector
vector<int> v(10);              // Size 10, default values
vector<int> v(10, 5);           // Size 10, all elements = 5
```

**Common Operations:**
```cpp
v.push_back(x)                  // Add to end
v.pop_back()                    // Remove from end
v.size()                        // Current size
v.capacity()                    // Allocated capacity
v.resize(n)                     // Change size
v.clear()                       // Remove all elements
v.insert(v.begin()+i, x)        // Insert at position
v.erase(v.begin()+i)            // Erase at position
```

### Traversal Methods

**Index-based:**
```cpp
for(int i = 0; i < n; i++) {
    cout << arr[i];
}
```

**For-each (read-only):**
```cpp
for(int ele : arr) {
    cout << ele;
}
```

**For-each (modifiable):**
```cpp
for(int &ele : arr) {
    ele = ele * 2;  // Modifies original
}
```

**While loop:**
```cpp
int i = 0;
while(i < n) {
    cout << arr[i++];
}
```

## Common Techniques

### Linear Search
```cpp
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) return i;
    }
    return -1;
}
```

### Find Maximum
```cpp
int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}
```

### Two Pointer (Same Direction)
```cpp
int i = 0, j = 1;
while(j < n) {
    // Process arr[i] and arr[j]
    if(condition) i++;
    j++;
}
```

### Two Pointer (Opposite Direction)
```cpp
int i = 0, j = n-1;
while(i < j) {
    if(condition) {
        swap(arr[i], arr[j]);
    }
    i++; j--;
}
```

### Prefix Sum
```cpp
// Build prefix sum
for(int i = 1; i < n; i++) {
    arr[i] += arr[i-1];
}

// Range sum query
int rangeSum(int l, int r) {
    if(l == 0) return arr[r];
    return arr[r] - arr[l-1];
}
```

### Frequency Array
```cpp
vector<int> freq(MAX, 0);
for(int i = 0; i < n; i++) {
    freq[arr[i]]++;
}
// O(1) lookup for any element
```

### Array Rotation (Reverse Method)
```cpp
reverse(arr, arr+n);           // Reverse all
reverse(arr, arr+k);           // Reverse first k
reverse(arr+k, arr+n);         // Reverse rest
```

## Algorithm Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Linear Search | O(n) | O(1) |
| Find Max/Min | O(n) | O(1) |
| Sum/Count | O(n) | O(1) |
| Pair Sum (sorted) | O(n) | O(1) |
| Pair Sum (unsorted) | O(n²) | O(1) |
| Triplet Sum | O(n³) | O(1) |
| Merge Sorted Arrays | O(m+n) | O(m+n) |
| Prefix Sum Build | O(n) | O(1) |
| Range Query (with prefix) | O(1) | O(n) |
| Rotate Array | O(n) | O(1) or O(n) |
| Sort 0s and 1s | O(n) | O(1) |

## Common Patterns

### Counting Pattern
```cpp
int count = 0;
for(int i = 0; i < n; i++) {
    if(condition) count++;
}
```

### Sum Pattern
```cpp
int sum = 0;
for(int i = 0; i < n; i++) {
    sum += arr[i];
}
```

### Max/Min Pattern
```cpp
int max = INT_MIN;
for(int i = 0; i < n; i++) {
    if(arr[i] > max) max = arr[i];
}
```

### Frequency Pattern
```cpp
vector<int> freq(MAX, 0);
for(int ele : arr) {
    freq[ele]++;
}
```

### Two Sum Pattern (Sorted)
```cpp
int i = 0, j = n-1;
while(i < j) {
    int sum = arr[i] + arr[j];
    if(sum == target) return true;
    else if(sum < target) i++;
    else j--;
}
```

## Quick Reference

### Array Declaration
```cpp
int arr[5];                     // Fixed size
int arr[] = {1,2,3};           // Size inferred
vector<int> v(n);              // Dynamic, size n
```

### Common Operations
```cpp
// Size
int n = sizeof(arr)/sizeof(arr[0]);
int n = v.size();

// Access
arr[i]                          // O(1)
v[i]                            // O(1)
v.at(i)                         // O(1) with bounds check

// Modify
arr[i] = value;
v[i] = value;
v.push_back(value);

// Find
find(v.begin(), v.end(), value);
```

### Useful Algorithms
```cpp
#include<algorithm>

reverse(arr, arr+n);
sort(arr, arr+n);
max_element(arr, arr+n);
min_element(arr, arr+n);
accumulate(arr, arr+n, 0);
```

---

## Complete Learning Path

Follow this structured path to master arrays and vectors:

### Phase 1: Fundamentals 
1. **basic.cpp** - Array basics and traversal methods
2. **input.cpp** - Taking array input
3. **vector.cpp** - Vector size and capacity
4. **loopInVector.cpp** - Vector operations

### Phase 2: Basic Operations 
5. **sum.cpp** - Calculate sum
6. **maximum.cpp** - Find maximum
7. **secondLargest.cpp** - Find second largest
8. **difference.cpp** - Even-odd index difference
9. **countGreater.cpp** - Count elements greater than X

### Phase 3: Searching 
10. **linearSearch.cpp** - Basic search
11. **lastOccurence.cpp** - Find last occurrence
12. **numberOccurence.cpp** - Count occurrences
13. **queries.cpp** - Frequency-based queries

### Phase 4: Basic Sorting & Checking 
14. **sortedOrNotArray.cpp** - Check if sorted
15. **sortArrayOnly0and1.cpp** - Sort by counting
16. **sortArrayOnly0and1byswaping.cpp** - Sort with two-pointer
17. **sortevenatStartandOddatEnd.cpp** - Segregate even/odd

### Phase 5: Array Manipulation 
18. **arrayManipulation.cpp** - Find unique element
19. **rotateArray.cpp** - Rotate using extra array
20. **rotateArrayUsingVector.cpp** - Rotate using reverse
21. **mergeArray.cpp** - Merge sorted arrays

### Phase 6: Two Pointer Technique 
22. **pairSum.cpp** - Find pair with sum (sorted)
23. **pairDifference.cpp** - Find pair with difference
24. **uniquePair.cpp** - Count unique pairs
25. **targetSum.cpp** - Count pairs (brute force)
26. **tripletsSum.cpp** - Count triplets
27. **sortedSquare.cpp** - Square sorted array

### Phase 7: Prefix Sum 
28. **prefixSum.cpp** - Running sum
29. **prefixSumQueriesSolver.cpp** - Range queries
30. **prefixSuffixsum.cpp** - Equal partition

### Phase 8: Advanced 
31. **sortarrayinSquareofNon-DecreasingOrder.cpp** - Advanced square sorting

---

**Happy Coding! 🚀**