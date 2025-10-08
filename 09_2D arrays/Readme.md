# 2D ARRAYS

C++ programs demonstrating two-dimensional array operations including matrix manipulation, traversal, and advanced algorithms.

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
  - [Basics](#basics)
  - [Matrix Operations](#matrix-operations)
  - [Prefix Sum Techniques](#prefix-sum-techniques)
  - [Advanced Patterns](#advanced-patterns)
- [Key Concepts](#key-concepts)
- [Common Techniques](#common-techniques)
- [Complete Learning Path](#complete-learning-path)

## Overview

Programs covering 2D array basics, matrix operations, prefix sum optimizations, and advanced traversal patterns.

## Programs

### Basics

#### 1. input.cpp - 2D Array Input/Output
Basic 2D array declaration, input, and display.

**Operations:**
- Taking matrix dimensions
- Input elements row by row
- Display matrix in grid format

**Learns:** 2D array syntax, nested loops for I/O, matrix representation

---

#### 2. transposeMatrix.cpp - Matrix Transpose
Transposes a matrix (swap rows and columns).

**Example:**
```
Original:     Transpose:
1 2 3         1 4
4 5 6    →    2 5
              3 6
```

**Logic:** `transpose[j][i] = matrix[i][j]`

**Learns:** Row-column interchange, matrix dimensions change (n×m → m×n)

---

### Matrix Operations

#### 3. matricesMultiplication.cpp - Matrix Multiplication
Multiplies two matrices with dimension validation.

**Condition:** Columns of Matrix1 must equal Rows of Matrix2

**Formula:** `result[i][j] = Σ(A[i][k] * B[k][j])`

**Dimensions:** (r1×c1) × (r2×c2) = (r1×c2)

**Time:** O(r1 × c2 × c1)

**Learns:** Triple nested loops, matrix multiplication rules, dimension checks

---

#### 4. rotation.cpp - 90° Clockwise Rotation
Rotates square matrix 90° clockwise without extra space.

**Algorithm:**
1. Transpose matrix (swap across diagonal)
2. Reverse each row

**Example:**
```
1 2 3       1 4 7       7 4 1
4 5 6   →   2 5 8   →   8 5 2
7 8 9       3 6 9       9 6 3
```

**Time:** O(n²), **Space:** O(1)

**Learns:** In-place rotation, transpose + reverse technique

---

#### 5. pascalsTriangle.cpp - Pascal's Triangle
Generates first N rows of Pascal's Triangle.

**Rule:**
- Edge elements = 1
- Middle elements = sum of two elements above

**Example (n=5):**
```
       1
      1 1
     1 2 1
    1 3 3 1
   1 4 6 4 1
```

**Formula:** `pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]`

**Learns:** Dynamic 2D vector, triangular arrays, combinatorics

---

### Prefix Sum Techniques

#### 6. prefixSum1.cpp - Brute Force Rectangle Sum
Calculates sum of rectangle using direct iteration.

**Method:** Iterate through all elements in the range

**Time:** O(n×m) per query

**Learns:** Rectangle sum basics, coordinate system

---

#### 7. prefixSum2.cpp - Row-wise Prefix Sum
Optimizes using horizontal prefix sums.

**Preprocessing:** Build prefix sum for each row

**Query:** `sum[i] = prefix[i][r2] - prefix[i][r1-1]` for each row

**Time:** O(n×m) preprocessing, O(n) per query

**Learns:** Row-wise optimization, partial prefix sums

---

#### 8. prefixSum3.cpp - 2D Prefix Sum (Optimal)
Most efficient method using 2D prefix sum array.

**Preprocessing:**
1. Build row-wise prefix sums
2. Build column-wise prefix sums

**Query Formula:**
```cpp
sum = prefix[l2][r2] 
    - prefix[l1-1][r2]      // top rectangle
    - prefix[l2][r1-1]      // left rectangle
    + prefix[l1-1][r1-1]    // top-left (added twice, subtract once)
```

**Time:** O(n×m) preprocessing, O(1) per query

**Learns:** 2D prefix sum, inclusion-exclusion principle

---

### Advanced Patterns

#### 9. spiralOrder1.cpp - Spiral Traversal (Print)
Prints matrix elements in spiral order.

**Pattern:** Right → Down → Left → Up → (repeat)

**Example:**
```
1 2 3       Output: 1 2 3 6 9 8 7 4 5
4 5 6
7 8 9
```

**Algorithm:**
- Use four boundaries: top, bottom, left, right
- Four directions: 0(right), 1(down), 2(left), 3(up)
- Shrink boundaries after each direction

**Learns:** Boundary-based traversal, direction cycling

---

#### 10. spiralOrder2.cpp - Generate Spiral Matrix
Creates n×n matrix filled with 1 to n² in spiral order.

**Example (n=3):**
```
1 2 3
8 9 4
7 6 5
```

**Algorithm:** Same as spiralOrder1, but fill values instead of print

**Learns:** Matrix generation, spiral filling pattern

---

#### 11. maximum1s.cpp - Row with Maximum 1s
Finds row with most 1s in row-sorted binary matrix.

**Method 1 (Basic):** Count 1s in each row

**Method 2 (Optimized):** Start from top-right, move left when 1 found

**Time:** O(n×m) vs O(n+m)

**Learns:** Sorted matrix optimization, staircase search

---

## Key Concepts

### 2D Array Basics

**Declaration:**
```cpp
int arr[3][4];                          // Static 3x4 array
int arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

vector<vector<int>> v(n, vector<int>(m));  // Dynamic nxm vector
```

**Access:**
```cpp
arr[i][j]                               // Element at row i, column j
```

**Size:**
```cpp
rows = sizeof(arr) / sizeof(arr[0]);
cols = sizeof(arr[0]) / sizeof(arr[0][0]);

rows = v.size();                        // For vectors
cols = v[0].size();
```

### Traversal Patterns

**Row-major (Normal):**
```cpp
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cout << arr[i][j] << " ";
    }
}
```

**Column-major:**
```cpp
for(int j = 0; j < m; j++) {
    for(int i = 0; i < n; i++) {
        cout << arr[i][j] << " ";
    }
}
```

**Diagonal:**
```cpp
// Main diagonal (top-left to bottom-right)
for(int i = 0; i < n; i++) {
    cout << arr[i][i];
}

// Anti-diagonal (top-right to bottom-left)
for(int i = 0; i < n; i++) {
    cout << arr[i][n-1-i];
}
```

### Matrix Operations

**Transpose:**
```cpp
for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
}
```

**Multiplication:**
```cpp
// C = A × B
for(int i = 0; i < r1; i++) {
    for(int j = 0; j < c2; j++) {
        C[i][j] = 0;
        for(int k = 0; k < c1; k++) {
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}
```

**90° Rotation:**
```cpp
// Step 1: Transpose
for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
}

// Step 2: Reverse each row
for(int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
}
```

## Common Techniques

### Spiral Traversal Template
```cpp
int top = 0, bottom = n-1, left = 0, right = m-1;
int dir = 0;

while(top <= bottom && left <= right) {
    if(dir == 0) {  // Right
        for(int i = left; i <= right; i++)
            process(matrix[top][i]);
        top++;
    }
    else if(dir == 1) {  // Down
        for(int i = top; i <= bottom; i++)
            process(matrix[i][right]);
        right--;
    }
    else if(dir == 2) {  // Left
        for(int i = right; i >= left; i--)
            process(matrix[bottom][i]);
        bottom--;
    }
    else {  // Up
        for(int i = bottom; i >= top; i--)
            process(matrix[i][left]);
        left++;
    }
    dir = (dir + 1) % 4;
}
```

### 2D Prefix Sum Template
```cpp
// Build prefix sum
void buildPrefix(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    
    // Row-wise prefix
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
            matrix[i][j] += matrix[i][j-1];
        }
    }
    
    // Column-wise prefix
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            matrix[i][j] += matrix[i-1][j];
        }
    }
}

// Query rectangle sum
int rectangleSum(int l1, int r1, int l2, int r2) {
    int total = prefix[l2][r2];
    int top = (l1 > 0) ? prefix[l1-1][r2] : 0;
    int left = (r1 > 0) ? prefix[l2][r1-1] : 0;
    int topLeft = (l1 > 0 && r1 > 0) ? prefix[l1-1][r1-1] : 0;
    
    return total - top - left + topLeft;
}
```

### Search in Sorted Matrix
```cpp
// Search in row and column sorted matrix
bool search(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int row = 0, col = m - 1;  // Start top-right
    
    while(row < n && col >= 0) {
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] > target) col--;
        else row++;
    }
    return false;
}
```

## Algorithm Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Input/Output | O(n×m) | O(1) |
| Transpose | O(n×m) | O(1) in-place |
| Multiplication | O(n×m×p) | O(n×p) |
| 90° Rotation | O(n²) | O(1) |
| Spiral Traversal | O(n×m) | O(1) |
| Rectangle Sum (Brute) | O(n×m) per query | O(1) |
| Rectangle Sum (Row prefix) | O(n) per query | O(n×m) |
| Rectangle Sum (2D prefix) | O(1) per query | O(n×m) |
| Pascal's Triangle | O(n²) | O(n²) |
| Max 1s Row (Basic) | O(n×m) | O(1) |
| Max 1s Row (Optimized) | O(n+m) | O(1) |

## Common Patterns

### Matrix Search
```cpp
// Linear search
bool find(int key) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(matrix[i][j] == key) return true;
    return false;
}
```

### Find Maximum/Minimum
```cpp
int findMax() {
    int maxVal = INT_MIN;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            maxVal = max(maxVal, matrix[i][j]);
    return maxVal;
}
```

### Wave Traversal
```cpp
// Print in wave pattern (column-wise zigzag)
for(int j = 0; j < m; j++) {
    if(j % 2 == 0) {
        for(int i = 0; i < n; i++)
            cout << matrix[i][j] << " ";
    } else {
        for(int i = n-1; i >= 0; i--)
            cout << matrix[i][j] << " ";
    }
}
```

## Quick Reference

### Matrix Declaration
```cpp
// Static array
int arr[3][4];

// Dynamic vector
vector<vector<int>> v(n, vector<int>(m));
vector<vector<int>> v(n, vector<int>(m, value));
```

### Common Operations
```cpp
// Dimensions
int rows = v.size();
int cols = v[0].size();

// Access
v[i][j]                    // Element at (i, j)

// Resize
v.resize(n);
for(auto &row : v) row.resize(m);
```

### Matrix Transformations
```cpp
// Transpose
for(int i = 0; i < n; i++)
    for(int j = 0; j < i; j++)
        swap(matrix[i][j], matrix[j][i]);

// Reverse rows
for(int i = 0; i < n; i++)
    reverse(matrix[i].begin(), matrix[i].end());

// Reverse columns
for(int j = 0; j < m; j++)
    for(int i = 0; i < n/2; i++)
        swap(matrix[i][j], matrix[n-1-i][j]);
```

### Useful STL Algorithms
```cpp
#include <algorithm>

reverse(matrix[i].begin(), matrix[i].end());  // Reverse row
swap(matrix[i][j], matrix[j][i]);             // Swap elements
```

## Complete Learning Path

Follow this structured path to master 2D arrays:

### Phase 1: Basics 
1. **input.cpp** - 2D array I/O fundamentals
2. **transposeMatrix.cpp** - Basic transformation

### Phase 2: Matrix Operations 
3. **matricesMultiplication.cpp** - Matrix multiplication rules
4. **rotation.cpp** - In-place rotation technique

### Phase 3: Pattern Generation
5. **pascalsTriangle.cpp** - Triangle patterns

### Phase 4: Prefix Sum
6. **prefixSum1.cpp** - Brute force approach
7. **prefixSum2.cpp** - Row-wise optimization
8. **prefixSum3.cpp** - 2D prefix sum mastery

### Phase 5: Advanced Patterns 
9. **spiralOrder1.cpp** - Spiral traversal
10. **spiralOrder2.cpp** - Spiral generation
11. **maximum1s.cpp** - Sorted matrix optimization

**Tips:**
- Draw matrices on paper to visualize
- Test with small matrices (2×2, 3×3) first
- Pay attention to boundary conditions
- Use 0-based indexing consistently

---


**Happy Coding! 🚀**