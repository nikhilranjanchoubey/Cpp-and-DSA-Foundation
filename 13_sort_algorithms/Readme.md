# SORTING ALGORITHMS

C++ programs demonstrating various sorting algorithms from basic comparison-based sorts to advanced non-comparison sorts.

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
  - [Bubble Sort](#bubble-sort)
  - [Selection Sort](#selection-sort)
  - [Insertion Sort](#insertion-sort)
  - [Merge Sort](#merge-sort)
  - [Quick Sort](#quick-sort)
  - [Counting Sort](#counting-sort)
  - [Radix Sort](#radix-sort)
  - [Bucket Sort](#bucket-sort)
  - [Applications](#applications)
- [Algorithm Comparison](#algorithm-comparison)
- [When to Use Which Algorithm](#when-to-use-which-algorithm)
- [Complete Learning Path](#complete-learning-path)

## Overview

Programs covering all major sorting algorithms including bubble, selection, insertion, merge, quick, counting, radix, and bucket sort with various optimizations and applications.

## Programs

### Bubble Sort

#### 1. bubbleSort.cpp - Basic Bubble Sort (Ascending)
Sorts array by repeatedly swapping adjacent elements if they're in wrong order.

**Algorithm:**
- Compare adjacent elements
- Swap if left > right
- Repeat until array is sorted

**Example:** `[5, 2, 8, 1]` → `[1, 2, 5, 8]`

**Time:** O(n²) worst/average, O(n²) best
**Space:** O(1)

**Learns:** Nested loops, adjacent comparisons, basic sorting

---

#### 2. bubbleSort2.cpp - Bubble Sort (Descending)
Same logic but sorts in descending order.

**Change:** Swap if `left < right` instead of `left > right`

**Example:** `[5, 2, 8, 1]` → `[8, 5, 2, 1]`

**Learns:** Modifying comparison logic for different orders

---

#### 3. bubbleSort3.cpp - Optimized Bubble Sort
Uses flag to detect early completion.

**Optimization:** If no swaps occur in a pass, array is sorted

**Best Case:** O(n) for already sorted arrays

**Learns:** Early termination, optimization techniques

---

### Selection Sort

#### 4. selectionSort.cpp - Basic Selection Sort (Ascending)
Finds minimum element and places it at the beginning.

**Algorithm:**
1. Find minimum in unsorted portion
2. Swap with first unsorted element
3. Move boundary forward

**Example Pass:** `[5, 2, 8, 1]` → `[1, 2, 8, 5]` (after finding min=1)

**Time:** O(n²) all cases
**Space:** O(1)

**Learns:** Finding minimum, in-place sorting

---

#### 5. selectionSort2.cpp - Selection Sort (Descending)
Finds maximum element and places at beginning.

**Change:** Find max instead of min

**Learns:** Dual approach to selection sort

---

#### 6. selectionSort3.cpp - Selection Sort (Max to End)
Places maximum element at end in each pass.

**Approach:** Work backwards, place max at current end position

**Learns:** Alternative implementation strategy

---

#### 7. lexicographicalOrder.cpp - String Selection Sort
Sorts strings in lexicographical (dictionary) order.

**Uses:** `strcmp()` for string comparison

**Example:** `["papaya", "lime", "apple"]` → `["apple", "lime", "papaya"]`

**strcmp() returns:**
- Negative: first < second
- Zero: equal
- Positive: first > second

**Learns:** String comparison, sorting non-numeric data

---

### Insertion Sort

#### 8. insertionSort.cpp - Insertion Sort
Builds sorted array by inserting elements at correct position.

**Algorithm:**
1. Start from 2nd element
2. Compare with sorted portion
3. Shift larger elements right
4. Insert at correct position

**Example:** Insert 3 into `[1, 2, 5, 8]` → `[1, 2, 3, 5, 8]`

**Time:** O(n²) worst, O(n) best (sorted)
**Space:** O(1)

**Best for:** Nearly sorted data, small arrays

**Learns:** Building sorted sequence incrementally

---

### Merge Sort

#### 9. mergeArray.cpp - Merging Two Sorted Arrays
Helper function for merge sort - merges two sorted arrays.

**Algorithm:**
- Two pointers approach
- Compare elements, add smaller to result
- Copy remaining elements

**Example:**
```
arr1: [5, 8, 10]
arr2: [2, 7, 8]
result: [2, 5, 7, 8, 8, 10]
```

**Time:** O(n + m)

**Learns:** Two-pointer technique, merging logic

---

#### 10. mergeSort.cpp - Merge Sort
Divide-and-conquer sorting algorithm.

**Algorithm:**
1. Divide array into two halves
2. Recursively sort both halves
3. Merge sorted halves

**Example:**
```
[10, 28, 24, 6]
  ↓ divide
[10, 28] [24, 6]
  ↓ sort
[10, 28] [6, 24]
  ↓ merge
[6, 10, 24, 28]
```

**Time:** O(n log n) all cases
**Space:** O(n)

**Learns:** Divide-and-conquer, recursion, stable sorting

---

### Quick Sort

#### 11. quickSort.cpp - Quick Sort
Efficient divide-and-conquer sorting using pivot.

**Algorithm:**
1. Choose pivot (last element)
2. Partition: smaller left, larger right
3. Recursively sort partitions

**Partition Logic:**
- Maintain boundary for smaller elements
- Swap elements smaller than pivot to left side
- Place pivot at correct position

**Time:** O(n log n) average, O(n²) worst
**Space:** O(log n) stack space

**Best for:** Large datasets, general purpose

**Learns:** Partitioning, pivot selection, in-place sorting

---

#### 12. smallestElement.cpp - Kth Smallest Element
Uses QuickSort partition to find Kth smallest element.

**Algorithm:**
- Partition array
- If pivot is Kth position, return
- Else recurse on left or right partition

**Example:** Find 5th smallest in `[3, 5, 2, 1, 4, 7, 8, 6]` → `5`

**Time:** O(n) average, O(n²) worst

**Learns:** QuickSelect algorithm, partition applications

---

### Counting Sort

#### 13. countSort.cpp - Counting Sort
Non-comparison sort using frequency counting.

**Algorithm:**
1. Find maximum element
2. Create frequency array
3. Convert to prefix sum (cumulative count)
4. Build sorted array using frequencies

**Example:**
```
Input: [4, 2, 2, 8, 3, 3, 1]
Freq:  [0, 1, 2, 2, 1, 0, 0, 0, 1]
Prefix:[0, 1, 3, 5, 6, 6, 6, 6, 7]
Output:[1, 2, 2, 3, 3, 4, 8]
```

**Time:** O(n + k) where k = range
**Space:** O(k)

**Best for:** Small range of integers

**Learns:** Non-comparison sorting, frequency arrays, stable sort

---

### Radix Sort

#### 14. radixSort.cpp - Radix Sort
Sorts numbers digit by digit using counting sort.

**Algorithm:**
1. Find maximum to know digit count
2. Sort by each digit (1s, 10s, 100s, etc.)
3. Use stable counting sort for each digit

**Example:**
```
[170, 45, 75, 90, 2, 802, 24, 66]
After 1s: [170, 90, 2, 802, 24, 45, 75, 66]
After 10s:[2, 802, 24, 45, 66, 170, 75, 90]
After 100s:[2, 24, 45, 66, 75, 90, 170, 802]
```

**Time:** O(d × (n + k)) where d = digits, k = radix (10)
**Space:** O(n + k)

**Best for:** Large numbers with limited digits

**Learns:** Digit-by-digit processing, stable sorting importance

---

### Bucket Sort

#### 15. bucketSort.cpp - Bucket Sort (Range [0,1))
Distributes elements into buckets, sorts individually, concatenates.

**Algorithm:**
1. Create n empty buckets
2. Distribute elements: `bucket[element × n]`
3. Sort each bucket
4. Concatenate all buckets

**Example:** `[0.13, 0.45, 0.89, 0.75]` → sorted by bucket distribution

**Time:** O(n + k) average
**Space:** O(n)

**Best for:** Uniformly distributed floating-point numbers

**Learns:** Distribution-based sorting, bucket concept

---

#### 16. bucketSort2.cpp - Bucket Sort (Any Range)
Handles floating-point numbers in any range.

**Enhancement:**
- Find min and max
- Calculate bucket range: `(max - min) / n`
- Distribute: `bucket[(element - min) / range]`

**Example:** Works with `[6.13, 8.45, 0.12, 10.39]`

**Learns:** Range normalization, generalized bucket sort

---

### Applications

#### 17. zeroTotheEnd.cpp - Move Zeros to End
Uses bubble sort logic to push all zeros to end.

**Algorithm:**
- Swap zero with next non-zero
- Use flag for early termination

**Example:** `[5, 0, 2, 0, 3]` → `[5, 2, 3, 0, 0]`

**Time:** O(n²) worst, O(n) best

**Learns:** Applying sorting concepts to array manipulation

---

## Algorithm Comparison

### Comparison-Based Sorts

| Algorithm | Best | Average | Worst | Space | Stable | In-Place |
|-----------|------|---------|-------|-------|--------|----------|
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) | No | Yes |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes | No |
| **Quick Sort** | O(n log n) | O(n log n) | O(n²) | O(log n) | No | Yes |

### Non-Comparison Sorts

| Algorithm | Time | Space | Constraints |
|-----------|------|-------|-------------|
| **Counting Sort** | O(n + k) | O(k) | Small range integers |
| **Radix Sort** | O(d(n + k)) | O(n + k) | Fixed-size integers |
| **Bucket Sort** | O(n + k) | O(n) | Uniform distribution |

### Key Properties

**Stable Sort:** Preserves relative order of equal elements
- Bubble, Insertion, Merge, Counting, Radix, Bucket

**In-Place:** Uses O(1) extra space
- Bubble, Selection, Insertion, Quick

**Adaptive:** Performs better on partially sorted data
- Bubble (optimized), Insertion

## When to Use Which Algorithm

### Small Arrays (n < 50)
**Use:** Insertion Sort
- Simple implementation
- Low overhead
- Good for nearly sorted data

### Large Arrays - General Purpose
**Use:** Quick Sort or Merge Sort
- Quick Sort: Faster average case, in-place
- Merge Sort: Guaranteed O(n log n), stable

### Nearly Sorted Data
**Use:** Insertion Sort or Bubble Sort (optimized)
- O(n) for sorted data
- Adaptive to existing order

### Limited Memory
**Use:** Quick Sort, Selection Sort, Insertion Sort
- In-place algorithms
- O(1) extra space

### Stability Required
**Use:** Merge Sort, Insertion Sort, Bubble Sort
- Preserves order of equal elements
- Important for multi-key sorting

### Integer Data with Small Range
**Use:** Counting Sort
- O(n) time complexity
- No comparisons needed

### Large Integers with Limited Digits
**Use:** Radix Sort
- Sorts digit by digit
- Better than O(n log n) for large n

### Uniformly Distributed Floats
**Use:** Bucket Sort
- O(n) average case
- Works well with uniform distribution

## Sorting Algorithm Selection Tree

```
Need to sort?
├─ Small array (n < 50)?
│  └─ Use: Insertion Sort
│
├─ Need stability?
│  ├─ Limited memory?
│  │  └─ Use: Insertion Sort
│  └─ Large array?
│     └─ Use: Merge Sort
│
├─ Integer data with small range?
│  └─ Use: Counting Sort
│
├─ Large integers, limited digits?
│  └─ Use: Radix Sort
│
├─ Uniformly distributed floats?
│  └─ Use: Bucket Sort
│
└─ General purpose, large array?
   ├─ Average case priority?
   │  └─ Use: Quick Sort
   └─ Worst case guarantee?
      └─ Use: Merge Sort
```

## Common Patterns

### Swap Pattern
```cpp
// Basic swap
int temp = a;
a = b;
b = temp;

// Using STL
swap(a, b);
```

### Two-Pointer Merge
```cpp
int i = 0, j = 0, k = 0;
while(i < n1 && j < n2) {
    if(arr1[i] < arr2[j])
        result[k++] = arr1[i++];
    else
        result[k++] = arr2[j++];
}
// Copy remaining
while(i < n1) result[k++] = arr1[i++];
while(j < n2) result[k++] = arr2[j++];
```

### Partition Pattern (Quick Sort)
```cpp
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
```

### Frequency Count Pattern (Counting Sort)
```cpp
// Build frequency
vector<int> freq(max_val + 1, 0);
for(int x : arr) freq[x]++;

// Convert to prefix sum
for(int i = 1; i <= max_val; i++)
    freq[i] += freq[i-1];

// Build sorted array
for(int i = n-1; i >= 0; i--)
    sorted[--freq[arr[i]]] = arr[i];
```

## Quick Reference

### Basic Sort Template
```cpp
void sort(vector<int>& arr) {
    // Choose appropriate algorithm
    // Bubble/Selection/Insertion for n < 50
    // Merge/Quick for large n
}
```

### Comparison Function
```cpp
// Ascending
if(a < b) // swap/compare

// Descending  
if(a > b) // swap/compare

// Custom
bool compare(int a, int b) {
    return a < b; // your logic
}
```

### STL Sorting
```cpp
#include <algorithm>

sort(arr.begin(), arr.end());              // Ascending
sort(arr.begin(), arr.end(), greater<int>()); // Descending
sort(arr.begin(), arr.end(), compare);     // Custom

stable_sort(arr.begin(), arr.end());       // Stable sort
partial_sort(arr.begin(), arr.begin()+k, arr.end()); // Partial
```

## Complete Learning Path

Follow this structured path to master sorting algorithms:

### Phase 1: Simple Sorts 
1. **bubbleSort.cpp** - Basic sorting concept
2. **bubbleSort2.cpp** - Reverse order
3. **bubbleSort3.cpp** - Optimization with flag
4. **selectionSort.cpp** - Finding minimum
5. **selectionSort2.cpp** - Finding maximum (descending)
6. **selectionSort3.cpp** - Alternative approach
7. **insertionSort.cpp** - Building sorted sequence

### Phase 2: String Sorting 
8. **lexicographicalOrder.cpp** - String comparison

### Phase 3: Divide and Conquer 
9. **mergeArray.cpp** - Merging logic
10. **mergeSort.cpp** - Complete merge sort
11. **quickSort.cpp** - Partitioning and recursion
12. **smallestElement.cpp** - QuickSelect application

### Phase 4: Non-Comparison Sorts 
13. **countSort.cpp** - Frequency-based sorting
14. **radixSort.cpp** - Digit-by-digit sorting
15. **bucketSort.cpp** - Distribution sorting (0-1 range)
16. **bucketSort2.cpp** - Distribution sorting (any range)

### Phase 5: Applications 
17. **zeroTotheEnd.cpp** - Array manipulation

**Learning Tips:**
- Implement each algorithm from scratch
- Trace execution with small arrays on paper
- Compare time taken for different algorithms
- Test with sorted, reverse sorted, and random data
- Visualize sorting process

**Happy Coding! 🚀**