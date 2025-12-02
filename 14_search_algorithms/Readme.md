# SEARCHING ALGORITHMS

C++ programs demonstrating binary search and its variations for solving complex search problems efficiently.

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
  - [Basic Binary Search](#basic-binary-search)
  - [Binary Search Variations](#binary-search-variations)
  - [Peak Finding Problems](#peak-finding-problems)
  - [Rotated Array Problems](#rotated-array-problems)
  - [Binary Search on Answer](#binary-search-on-answer)
  - [2D Matrix Search](#2d-matrix-search)
  - [Mathematical Applications](#mathematical-applications)
- [Algorithm Comparison](#algorithm-comparison)
- [Binary Search Patterns](#binary-search-patterns)
- [When to Use Binary Search](#when-to-use-binary-search)
- [Complete Learning Path](#complete-learning-path)

## Overview

Programs covering binary search fundamentals and advanced applications including bounds finding, peak detection, rotated arrays, optimization problems, and 2D searches.

## Programs

### Basic Binary Search

#### 1. binarySearch.cpp - Iterative Binary Search
Classic binary search on sorted array (iterative approach).

**Algorithm:**
1. Start with `lo = 0`, `hi = n-1`
2. Find middle: `mid = lo + (hi - lo) / 2`
3. If `arr[mid] == target`, found
4. If `arr[mid] < target`, search right half
5. If `arr[mid] > target`, search left half

**Example:** Search 7 in `[2, 4, 5, 7, 15, 24, 45, 50]` → Index 3

**Time:** O(log n)
**Space:** O(1)

**Key Point:** `lo + (hi - lo) / 2` prevents integer overflow

**Learns:** Basic binary search template, iterative approach

---

#### 2. binarySearch2.cpp - Recursive Binary Search
Same functionality using recursion.

**Recursive Logic:**
- Base case: `lo > hi` → not found
- Recursive case: Search left or right half

**Time:** O(log n)
**Space:** O(log n) - recursion stack

**Learns:** Recursive implementation, function call overhead

---

### Binary Search Variations

#### 3. firstOccurrence.cpp - First Occurrence
Finds first occurrence of target in sorted array with duplicates.

**Key Modification:**
- When `arr[mid] == target`, don't stop
- Store answer and search left: `hi = mid - 1`

**Example:** Find first 5 in `[2, 5, 5, 5, 6, 6, 8, 9]` → Index 1

**Pattern:** Modified binary search that continues after finding match

**Learns:** Lower bound concept, handling duplicates

---

#### 4. firstAndlastOccurrence.cpp - First and Last Occurrence
Finds both first and last positions of target.

**Uses Two Functions:**
- **lowerBound()**: First index where `arr[i] >= target`
- **upperBound()**: First index where `arr[i] > target`

**Result:** `[lowerBound, upperBound - 1]`

**Example:** Find 3 in `[1, 2, 3, 3, 3, 5, 11]` → `[2, 4]`

**Time:** O(log n) × 2 calls

**Learns:** Lower and upper bound functions, range finding

---

### Peak Finding Problems

#### 5. mountainArray.cpp - Peak in Mountain Array
Finds peak index in mountain array (increases then decreases).

**Mountain Array:** `arr[0] < arr[1] < ... < arr[peak] > ... > arr[n-1]`

**Algorithm:**
- If `arr[mid] < arr[mid+1]`, peak is right
- Else, peak is left or at mid

**Example:** `[0, 4, 1, 0]` → Peak at index 1 (value 4)

**Time:** O(log n)

**Learns:** Modified binary search on special arrays

---

#### 6. peakElement.cpp - Peak Element (General)
Finds any peak element (greater than neighbors).

**Peak Definition:** `arr[i] > arr[i-1]` AND `arr[i] > arr[i+1]`

**Edge Cases:**
- First element: Check only right neighbor
- Last element: Check only left neighbor

**Example:** `[1, 2, 1, 2, 6, 10, 3]` → Index 1 or 5

**Time:** O(log n)

**Learns:** Handling edge cases, multiple valid answers

---

### Rotated Array Problems

#### 7. rotatedSortedArray.cpp - Find Minimum in Rotated Array
Finds minimum element in rotated sorted array.

**Rotated Array:** `[3, 4, 5, 1, 2]` (originally `[1, 2, 3, 4, 5]`)

**Key Insight:**
- One half is always sorted
- Minimum is at rotation point

**Algorithm:**
- If `arr[mid] > arr[mid+1]`, minimum is `arr[mid+1]`
- If `arr[mid] < arr[mid-1]`, minimum is `arr[mid]`
- Else, search unsorted half

**Time:** O(log n)

**Learns:** Rotation point detection, pivot finding

---

#### 8. rotatedSortedArray2.cpp - Search in Rotated Array
Searches target in rotated sorted array (distinct elements).

**Algorithm:**
1. Identify which half is sorted
2. Check if target lies in sorted half
3. Search appropriate half

**Example:** Find 4 in `[3, 4, 5, 1, 2]` → Index 1

**Time:** O(log n)

**Learns:** Binary search on rotated arrays, range checking

---

#### 9. rotatedSortedArray3.cpp - Search with Duplicates
Handles duplicates in rotated array.

**Challenge:** Duplicates make it unclear which half is sorted

**Solution:**
- If `arr[lo] == arr[mid] == arr[hi]`, shrink both ends
- Else, proceed like normal rotated search

**Example:** Find 2 in `[0, 0, 0, 1, 1, 1, 2, 0, 0, 0]` → Found

**Time:** O(log n) average, O(n) worst case

**Learns:** Handling ambiguity, worst-case scenarios

---

### Binary Search on Answer

#### 10. chocolateDistributionProblem.cpp - Minimize Maximum
Distributes chocolate boxes to students, minimizing maximum chocolates per student.

**Problem:** Allocate `n` boxes to `m` students (contiguous allocation), minimize max allocation

**Binary Search on Answer:**
- **Search Space:** `[max_box, sum_all_boxes]`
- **Check:** Can we distribute with max = mid?

**Example:** `[12, 34, 67, 90]`, 2 students → Answer: 113

**Time:** O(n log(sum))

**Learns:** Binary search on answer range, feasibility check

---

#### 11. racingTrack.cpp - Maximize Minimum
Places students at positions, maximizing minimum distance between them.

**Problem:** Choose `m` positions from `n` spots, maximize minimum distance

**Binary Search on Answer:**
- **Search Space:** `[1, max_position - min_position]`
- **Check:** Can we place students with distance ≥ mid?

**Example:** Positions `[1, 2, 4, 8, 9]`, 3 students → Answer: 3

**Greedy Check:** Place greedily, if possible with distance ≥ mid, return true

**Time:** O(n log(range))

**Learns:** Maximize minimum problems, greedy checking

---

### 2D Matrix Search

#### 12. searchTargetIn2dmatrix.cpp - Search in 2D Matrix
Searches in row-wise and column-wise sorted matrix.

**Matrix Properties:**
- Each row sorted left to right
- First element of row > last element of previous row

**Algorithm:** Treat 2D matrix as 1D sorted array
- Index conversion: `row = mid / columns`, `col = mid % columns`

**Example:** Find 3 in `[[1,3,5,7], [10,11,16,20], [23,30,34,60]]` → Found

**Time:** O(log(n × m))

**Learns:** 1D to 2D index mapping, matrix as array

---

### Mathematical Applications

#### 13. squareRoot.cpp - Integer Square Root
Finds floor of square root (largest integer whose square ≤ x).

**Binary Search on Answer:**
- **Search Space:** `[1, x]`
- **Check:** If `mid * mid ≤ x`, try larger; else try smaller

**Example:** `sqrt(11)` → 3 (since 3² = 9 ≤ 11, 4² = 16 > 11)

**Time:** O(log x)

**Learns:** Binary search for mathematical functions

---

## Algorithm Comparison

### Search Algorithms

| Algorithm | Array Type | Time | Space | Use Case |
|-----------|------------|------|-------|----------|
| **Linear Search** | Any | O(n) | O(1) | Unsorted, small arrays |
| **Binary Search** | Sorted | O(log n) | O(1) | Sorted arrays |
| **Binary Search (Recursive)** | Sorted | O(log n) | O(log n) | Educational, tree-like |
| **Lower/Upper Bound** | Sorted with duplicates | O(log n) | O(1) | Find range |
| **Rotated Array Search** | Rotated sorted | O(log n) | O(1) | Modified sorted |
| **2D Binary Search** | Row-col sorted matrix | O(log(n×m)) | O(1) | 2D sorted data |

## Binary Search Patterns

### Pattern 1: Standard Binary Search
```cpp
int binarySearch(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

### Pattern 2: Lower Bound (First Occurrence)
```cpp
int lowerBound(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1;
    int ans = -1;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if(arr[mid] >= target) {
            ans = mid;
            hi = mid - 1;  // Continue searching left
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
```

### Pattern 3: Upper Bound (First Greater)
```cpp
int upperBound(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1;
    int ans = -1;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if(arr[mid] > target) {
            ans = mid;
            hi = mid - 1;  // Continue searching left
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
```

### Pattern 4: Binary Search on Answer
```cpp
int binarySearchOnAnswer(/* problem parameters */) {
    int lo = min_possible_answer;
    int hi = max_possible_answer;
    int ans = -1;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if(isFeasible(mid)) {
            ans = mid;
            // For minimize: hi = mid - 1
            // For maximize: lo = mid + 1
        } else {
            // Adjust search space
        }
    }
    return ans;
}
```

### Pattern 5: Peak Finding
```cpp
int findPeak(vector<int>& arr) {
    int lo = 0, hi = arr.size() - 1;
    
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        
        if(arr[mid] < arr[mid + 1]) {
            lo = mid + 1;  // Peak is right
        } else {
            hi = mid;  // Peak is left or at mid
        }
    }
    return lo;
}
```

### Pattern 6: Rotated Array Search
```cpp
int searchRotated(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if(arr[mid] == target) return mid;
        
        // Identify sorted half
        if(arr[lo] <= arr[mid]) {  // Left sorted
            if(target >= arr[lo] && target < arr[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        } else {  // Right sorted
            if(target > arr[mid] && target <= arr[hi])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
    }
    return -1;
}
```

## When to Use Binary Search

### Classic Binary Search
**Use when:**
- Array is sorted
- Need O(log n) search
- Random access available

### Lower/Upper Bound
**Use when:**
- Finding first/last occurrence
- Range queries on sorted array
- Need boundary positions

### Binary Search on Answer
**Use when:**
- Optimization problem (minimize/maximize)
- Can verify answer in O(n) or better
- Answer space is monotonic

**Examples:**
- Minimize maximum allocation
- Maximize minimum distance
- Find minimum/maximum value satisfying condition

### Peak Finding
**Use when:**
- Need local maximum
- Mountain array problems
- Bitonic arrays

### Rotated Array
**Use when:**
- Array is sorted but rotated
- Need to find element or pivot
- Partial sorting present

## Common Mistakes and Solutions

### Mistake 1: Integer Overflow
```cpp
❌ int mid = (lo + hi) / 2;  // May overflow

✅ int mid = lo + (hi - lo) / 2;  // Safe
```

### Mistake 2: Infinite Loop
```cpp
❌ while(lo < hi) {
    mid = (lo + hi) / 2;
    if(check) lo = mid;  // Can create infinite loop
}

✅ while(lo < hi) {
    mid = (lo + hi) / 2;
    if(check) lo = mid + 1;  // Always makes progress
}
```

### Mistake 3: Wrong Bounds
```cpp
❌ int lo = 0, hi = n;  // hi should be n-1

✅ int lo = 0, hi = n - 1;
```

### Mistake 4: Not Checking if Element Exists
```cpp
❌ int lb = lowerBound(arr, target);
   return lb;  // May return wrong index

✅ int lb = lowerBound(arr, target);
   if(lb != -1 && arr[lb] == target)
       return lb;
   return -1;
```

## Binary Search Decision Tree

```
Need to search?
├─ Sorted array?
│  ├─ Find exact element?
│  │  └─ Use: Standard Binary Search
│  │
│  ├─ Find first occurrence?
│  │  └─ Use: Lower Bound
│  │
│  ├─ Find last occurrence?
│  │  └─ Use: Upper Bound - 1
│  │
│  └─ Find range?
│     └─ Use: Lower + Upper Bound
│
├─ Rotated sorted array?
│  ├─ Find element?
│  │  └─ Use: Rotated Array Search
│  │
│  └─ Find minimum?
│     └─ Use: Find Rotation Point
│
├─ Mountain/Peak array?
│  └─ Use: Peak Finding
│
├─ Optimization problem?
│  └─ Use: Binary Search on Answer
│
└─ 2D sorted matrix?
   └─ Use: 2D Binary Search
```

## Time Complexity Analysis

| Operation | Array Size | Time | Comparisons |
|-----------|------------|------|-------------|
| **Linear Search** | 1000 | O(n) | ~500 avg |
| **Binary Search** | 1000 | O(log n) | ~10 |
| **Linear Search** | 1,000,000 | O(n) | ~500,000 avg |
| **Binary Search** | 1,000,000 | O(log n) | ~20 |

**Key Insight:** Binary search reduces 1 million comparisons to just 20!

## STL Functions

```cpp
#include <algorithm>

// Binary search (returns bool)
bool found = binary_search(arr.begin(), arr.end(), target);

// Lower bound (first >= target)
auto lb = lower_bound(arr.begin(), arr.end(), target);

// Upper bound (first > target)
auto ub = upper_bound(arr.begin(), arr.end(), target);

// Count occurrences
int count = upper_bound(arr.begin(), arr.end(), target) - 
            lower_bound(arr.begin(), arr.end(), target);

// Equal range (pair of lower and upper bound)
auto range = equal_range(arr.begin(), arr.end(), target);
```

## Complete Learning Path

Follow this structured path to master binary search:

### Phase 1: Fundamentals 
1. **binarySearch.cpp** - Iterative approach
2. **binarySearch2.cpp** - Recursive approach
3. **firstOccurrence.cpp** - Handle duplicates
4. **firstAndlastOccurrence.cpp** - Find range

### Phase 2: Peak Problems 
5. **mountainArray.cpp** - Mountain peak
6. **peakElement.cpp** - General peak

### Phase 3: Rotated Arrays 
7. **rotatedSortedArray.cpp** - Find minimum
8. **rotatedSortedArray2.cpp** - Search element
9. **rotatedSortedArray3.cpp** - Handle duplicates

### Phase 4: Advanced Applications 
10. **chocolateDistributionProblem.cpp** - Minimize maximum
11. **racingTrack.cpp** - Maximize minimum
12. **squareRoot.cpp** - Mathematical application

### Phase 5: 2D Search 
13. **searchTargetIn2dmatrix.cpp** - Matrix search
---
**Happy Coding! 🚀**