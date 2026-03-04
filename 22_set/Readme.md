# Set Data Structure

A comprehensive collection of Set data structure implementations and applications.

## Table of Contents

- [Introduction](#introduction)
- [Set Variations in C++ STL](#set-variations-in-c-stl)
- [Set Operations and Methods](#set-operations-and-methods)
- [Set Problems and Applications](#set-problems-and-applications)
- [Complexity Analysis](#complexity-analysis)

## Introduction

A **Set** is a container that stores **unique elements** in a specific order. Sets are typically implemented using balanced binary search trees (like Red-Black Trees) or hash tables.

### Key Characteristics
- **Unique Elements**: No duplicates allowed
- **Ordered/Unordered**: Depends on set type
- **Fast Lookup**: O(log n) for ordered, O(1) average for unordered
- **Automatic Sorting**: Ordered sets maintain sorted order

### Set vs Other Containers

| Feature | Set | Multiset | Unordered Set | Vector |
|---------|-----|----------|---------------|--------|
| Duplicates | ❌ No | ✅ Yes | ❌ No | ✅ Yes |
| Ordering | ✅ Sorted | ✅ Sorted | ❌ No | ❌ No |
| Insertion | O(log n) | O(log n) | O(1) avg | O(1) amortized |
| Search | O(log n) | O(log n) | O(1) avg | O(n) |
| Use Case | Unique sorted | Sorted duplicates | Unique fast | Sequential |

---

## Set Variations in C++ STL

### 1. Set (Ordered Set)
**File:** `set.cpp`

Stores unique elements in **sorted order** (ascending by default).

**Implementation:** Red-Black Tree (self-balancing BST)

**Header:** `#include <set>`

**Key Features:**
- Elements stored in sorted order
- No duplicate values
- Logarithmic time operations
- Bidirectional iterators

**Declaration:**
```cpp
set<int> s;
set<int, greater<int>> s;  // Descending order
```

**Common Operations:**
```cpp
// Insertion
s.insert(10);        // O(log n)
s.insert(20);
s.insert(10);        // Ignored (duplicate)

// Deletion
s.erase(10);         // Erase by value - O(log n)
s.erase(itr);        // Erase by iterator - O(1)
s.erase(start, end); // Erase range

// Search
if (s.find(10) != s.end()) {
    cout << "Found";
}

// Traversal (always sorted)
for (auto val : s) {
    cout << val << " ";
}

// Size
cout << s.size();

// Clear
s.clear();

// Empty check
if (s.empty()) {
    cout << "Set is empty";
}
```

**Example from code:**
```cpp
set<int> set1;
set1.insert(3);
set1.insert(2);
set1.insert(1);
set1.insert(4);
set1.insert(5);
set1.insert(3);  // Duplicate - ignored

// Output: 1 2 3 4 5 (sorted, unique)
```

**Iterator Operations:**
```cpp
auto itr = s.begin();    // First element
auto itr = s.end();      // Past-the-end
advance(itr, 3);         // Move iterator 3 positions
```

**Time Complexity:**
- Insert: O(log n)
- Delete: O(log n)
- Search: O(log n)
- Traversal: O(n)

**Space Complexity:** O(n)

---

### 2. Multiset (Ordered Multiset)
**File:** `multiSet.cpp`

Stores elements in **sorted order** allowing **duplicates**.

**Implementation:** Red-Black Tree

**Header:** `#include <set>`

**Key Features:**
- Maintains sorted order
- Allows duplicate values
- Same operations as set
- Duplicates stored contiguously

**Declaration:**
```cpp
multiset<int> ms;
```

**Operations:**
```cpp
multiset<int> ms;
ms.insert(1);
ms.insert(3);
ms.insert(2);
ms.insert(3);  // Duplicate allowed

// Output: 1 2 3 3 (sorted with duplicates)
```

**Special Methods:**
```cpp
// Count occurrences
int count = ms.count(3);  // Returns 2

// Equal range (all elements with value x)
auto range = ms.equal_range(3);
for (auto it = range.first; it != range.second; it++) {
    cout << *it << " ";
}

// Erase all occurrences
ms.erase(3);  // Removes all 3s

// Erase single occurrence
auto itr = ms.find(3);
ms.erase(itr);  // Removes only one 3
```

**Use Cases:**
- Frequency counting with sorting
- Maintaining sorted collection with duplicates
- Priority-based systems with ties

**Time Complexity:** Same as set - O(log n) for insert/delete/search

---

### 3. Unordered Set (Hash Set)
**File:** `unorderedSet.cpp`

Stores unique elements in **no particular order** using **hash table**.

**Implementation:** Hash Table

**Header:** `#include <unordered_set>`

**Key Features:**
- No ordering guarantee
- Fast average-case operations O(1)
- No duplicate values
- Uses hash function

**Declaration:**
```cpp
unordered_set<int> us;
```

**Operations:**
```cpp
unordered_set<int> s1;
s1.insert(3);
s1.insert(1);
s1.insert(2);
s1.insert(1);  // Duplicate ignored

// Output: 2 1 3 (unordered, may vary)
```

**Comparison with Set:**

| Feature | set | unordered_set |
|---------|-----|---------------|
| Ordering | Sorted | No order |
| Implementation | Red-Black Tree | Hash Table |
| Insert/Search | O(log n) | O(1) average |
| Worst Case | O(log n) | O(n) |
| Memory | Lower overhead | Higher overhead |
| When to use | Need sorted order | Need fast lookup |

**Time Complexity:**
- Average: O(1) for insert/delete/search
- Worst: O(n) (hash collisions)

**Space Complexity:** O(n)

**Use Cases:**
- Fast membership testing
- Removing duplicates quickly
- When order doesn't matter

---

### 4. Unordered Multiset (Hash Multiset)
**File:** `unorderedMultiSet.cpp`

Stores elements in **no particular order** allowing **duplicates** using hash table.

**Implementation:** Hash Table

**Header:** `#include <unordered_set>`

**Key Features:**
- No ordering
- Allows duplicates
- Fast average operations
- Hash-based storage

**Declaration:**
```cpp
unordered_multiset<int> ums;
```

**Operations:**
```cpp
unordered_multiset<int> ms1;
ms1.insert(4);
ms1.insert(8);
ms1.insert(3);
ms1.insert(1);
ms1.insert(4);  // Duplicate allowed

// Output: 1 4 4 3 8 (unordered with duplicates)
```

**Methods:**
```cpp
// Count occurrences
int count = ms1.count(4);  // Returns 2

// Find
auto itr = ms1.find(4);

// Erase all
ms1.erase(4);  // Removes all 4s

// Erase single
auto it = ms1.find(4);
ms1.erase(it);  // Removes one 4
```

**Time Complexity:**
- Average: O(1)
- Worst: O(n)

---

## Set Operations and Methods

### Common Methods for All Set Types

```cpp
// Insertion
insert(value)        // Add element
insert(itr, value)   // Insert with hint

// Deletion  
erase(value)         // Remove by value
erase(itr)           // Remove by iterator
erase(start, end)    // Remove range
clear()              // Remove all

// Search
find(value)          // Returns iterator (or end())
count(value)         // Returns count (0 or 1 for set, 0+ for multiset)

// Capacity
size()               // Number of elements
empty()              // Check if empty
max_size()           // Maximum possible size

// Iterators
begin()              // First element
end()                // Past-the-end
rbegin()             // Reverse begin
rend()               // Reverse end

// Bounds (ordered sets only)
lower_bound(value)   // First element >= value
upper_bound(value)   // First element > value
equal_range(value)   // Range of elements equal to value
```

### Iterator Examples

```cpp
set<int> s = {1, 2, 3, 4, 5};

// Forward iteration
for (auto itr = s.begin(); itr != s.end(); itr++) {
    cout << *itr << " ";
}

// Range-based (recommended)
for (auto val : s) {
    cout << val << " ";
}

// Reverse iteration (ordered sets)
for (auto itr = s.rbegin(); itr != s.rend(); itr++) {
    cout << *itr << " ";
}

// Advance iterator
auto itr = s.begin();
advance(itr, 3);  // Move to 4th element
```

---

## Set Problems and Applications

### 1. Check Pangram (All Alphabets)
**File:** `checkPangram.cpp`

Check if a string contains all 26 English alphabets (a-z).

**Problem:**
```
Input: "abcdEfGHIJKLMnopqrstuvWXYZ"
Output: YES (has all 26 letters)

Input: "PhysicsWallah"
Output: NO (missing some letters)
```

**Approach:**
1. Convert string to lowercase
2. Insert all characters into set
3. If set size == 26, all alphabets present

**Algorithm:**
```cpp
bool checkAllAlphabets(string s) {
    if (s.length() < 26) return false;
    
    // Convert to lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    set<char> alphabets;
    for (auto ch : s) {
        alphabets.insert(ch);
    }
    
    return (alphabets.size() == 26);
}
```

**Why Set?**
- Automatically removes duplicate characters
- Easy size check for 26 unique letters

**Time Complexity:** O(n) where n = string length  
**Space Complexity:** O(26) = O(1) - at most 26 characters

**Edge Cases:**
- Empty string → NO
- String with less than 26 characters → NO
- Special characters/numbers → Ignored (only letters counted)

---

### 2. Second Smallest Integer
**File:** `secondSmallestInteger.cpp`

Find the second smallest unique integer from an array (with possible duplicates).

**Problem:**
```
Input: [1, 2, 2, -4]
Output: 1 (smallest: -4, second: 1)

Input: [1, 2, 3, 1, 1]
Output: 2 (smallest: 1, second: 2)

Input: [5, 5, 5, 5]
Output: -1 (only one unique element)
```

**Approach:**
1. Insert all elements into set (removes duplicates)
2. Set automatically sorts elements
3. Get second element using iterator

**Algorithm:**
```cpp
set<int> s;
for (auto val : v) {
    s.insert(val);
}

if (s.size() < 2) {
    cout << -1;  // Not enough unique elements
} else {
    auto itr = s.begin();
    itr++;  // Move to second element
    cout << *itr;
}
```

**Why Set?**
- Automatic sorting
- Automatic duplicate removal
- Easy iterator navigation

**Time Complexity:** O(n log n) - insertion  
**Space Complexity:** O(k) where k = unique elements

---

### 3. Sum of Common Elements
**File:** `sumOfCommonElements.cpp`

Find sum of common unique elements between two vectors.

**Problem:**
```
V1 = {1, 1, 2, 3, 3, 3}
V2 = {5, 6, 7, 5, 2, 3, 6}

Common unique elements: 2, 3
Sum: 2 + 3 = 5
```

**Approach:**
1. Insert all elements of V1 into set (gets unique elements)
2. For each element in V2, check if it exists in set
3. If exists, add to sum once

**Algorithm:**
```cpp
set<int> s1;
for (auto ele : v1) {
    s1.insert(ele);  // Unique elements from v1
}

int ans_sum = 0;
set<int> counted;  // To avoid counting duplicates in v2

for (auto ele : v2) {
    if (s1.find(ele) != s1.end() && counted.find(ele) == counted.end()) {
        ans_sum += ele;
        counted.insert(ele);  // Mark as counted
    }
}
```

**Why Set?**
- Fast lookup O(log n)
- Automatic duplicate handling
- Clean membership testing

**Time Complexity:** O(n log n + m log n) where n=|V1|, m=|V2|  
**Space Complexity:** O(n)

**Alternative:** Use `unordered_set` for O(1) average lookup

---

### 4. Unique Invite List
**File:** `uniqueInviteList.cpp`

Create a unique, sorted invitation list from names that may have duplicates.

**Problem:**
```
Input:
5
Aashi
Bob
Aashi
Charlie
Bob

Output (sorted, unique):
Aashi
Bob
Charlie
```

**Approach:**
1. Use set<string> to store names
2. Set automatically removes duplicates
3. Set automatically sorts lexicographically
4. Print all names

**Algorithm:**
```cpp
set<string> invitelist;

int n;
cin >> n;

while (n--) {
    string name;
    cin >> name;
    invitelist.insert(name);
}

// Already sorted and unique
for (auto name : invitelist) {
    cout << name << endl;
}
```

**Why Set?**
- Automatic lexicographical sorting
- Automatic duplicate removal
- Simple and clean code

**Time Complexity:** O(n log n)  
**Space Complexity:** O(k) where k = unique names

**Real-world Use:**
- Guest list management
- User registration systems
- Email list cleanup
- Tag management

---

### 5. Different Possible Marks
**File:** `differentPossibleMarks.cpp`

Count all possible unique scores in an exam.

**Problem:**
```
n = 2 (questions)
p = 1 (correct marks)
q = -1 (wrong marks)
unattended = 0 marks

Possible combinations:
- Both correct: 2*1 = 2
- One correct, one wrong: 1*1 + 1*(-1) = 0
- Both wrong: 2*(-1) = -2
- One correct, one unattended: 1*1 = 1
- One wrong, one unattended: 1*(-1) = -1
- Both unattended: 0

Unique scores: {-2, -1, 0, 1, 2} → Count: 5
```

**Approach:**
1. Try all combinations of correct, incorrect, unattended
2. Calculate score for each valid combination
3. Insert scores into set (automatically removes duplicates)
4. Return set size

**Algorithm:**
```cpp
unordered_set<int> s;

for (int correct = 0; correct <= n; correct++) {
    for (int incorrect = 0; incorrect <= n; incorrect++) {
        int unattended = n - (correct + incorrect);
        
        if (unattended >= 0) {
            int score = correct * p + incorrect * q;
            s.insert(score);
        }
    }
}

cout << s.size();  // Count of unique scores
```

**Why Unordered Set?**
- Don't need sorting
- Just need count of unique values
- O(1) average insertion

**Time Complexity:** O(n²)  
**Space Complexity:** O(n²) worst case

**Optimization:** Can be solved in O(n) using mathematical approach, but set makes it simple.

---

## Complexity Analysis

### Time Complexity Comparison

| Operation | set/multiset | unordered_set/unordered_multiset |
|-----------|--------------|----------------------------------|
| Insert | O(log n) | O(1) average, O(n) worst |
| Delete | O(log n) | O(1) average, O(n) worst |
| Search | O(log n) | O(1) average, O(n) worst |
| Traversal | O(n) | O(n) |
| Count | O(log n + k)* | O(1) average |
| Lower/Upper bound | O(log n) | Not available |
| Min/Max element | O(1)** | O(n) |

*k = number of elements with that value (multiset)  
**Using begin() or rbegin()

### Space Complexity

All set types: **O(n)** where n = number of elements

Additional overhead:
- `set/multiset`: Tree pointers (3 pointers per node typically)
- `unordered_set`: Hash table buckets + linked lists

---

## Program Categories

### STL Implementations (4 programs)
1. **Set** - Ordered unique elements
2. **Multiset** - Ordered with duplicates
3. **Unordered Set** - Unordered unique elements
4. **Unordered Multiset** - Unordered with duplicates

### Applications (5 programs)
5. **Check Pangram** - String has all alphabets
6. **Second Smallest Integer** - Find second minimum
7. **Sum of Common Elements** - Common elements sum
8. **Unique Invite List** - Sorted unique names
9. **Different Possible Marks** - Count unique scores

**Total Programs: 9**

---

## Key Concepts

### When to Use Each Set Type?

**Use `set` when:**
- Need unique elements
- Need sorted order
- Need range queries (lower_bound, upper_bound)
- Memory is moderate concern
- Example: Leaderboard, sorted unique IDs

**Use `multiset` when:**
- Need sorted order
- Allow duplicates
- Need frequency with sorting
- Example: Priority queue with duplicates, event scheduling

**Use `unordered_set` when:**
- Need unique elements
- Don't need sorting
- Need fastest possible lookup
- Example: Visited nodes, membership testing, duplicate removal

**Use `unordered_multiset` when:**
- Allow duplicates
- Don't need sorting  
- Need fast operations
- Example: Word frequency (fast), cache with duplicates

### Common Patterns

**1. Duplicate Removal**
```cpp
vector<int> v = {1, 2, 2, 3, 3, 3, 4};
set<int> s(v.begin(), v.end());
v.assign(s.begin(), s.end());  // v = {1, 2, 3, 4}
```

**2. Finding Kth Smallest**
```cpp
set<int> s = {5, 2, 8, 1, 9};
auto itr = s.begin();
advance(itr, k-1);  // kth smallest (0-indexed)
cout << *itr;
```

**3. Membership Testing**
```cpp
unordered_set<int> s = {1, 2, 3, 4, 5};
if (s.find(3) != s.end()) {
    cout << "Present";
}
// Or: if (s.count(3))
```

**4. Range Queries**
```cpp
set<int> s = {1, 2, 3, 4, 5, 6, 7, 8, 9};
auto low = s.lower_bound(4);   // >= 4 → 4
auto high = s.upper_bound(7);  // > 7 → 8

for (auto it = low; it != high; it++) {
    cout << *it << " ";  // 4 5 6 7
}
```

**5. Frequency Counting**
```cpp
multiset<int> ms = {1, 2, 2, 3, 3, 3};
cout << ms.count(3);  // Output: 3
```

---

## Set vs Unordered Set: Quick Decision Guide

| Requirement | Use |
|-------------|-----|
| Need sorted data | `set` or `multiset` |
| Fastest lookup, no order needed | `unordered_set` |
| Range queries (between x and y) | `set` |
| Find min/max quickly | `set` (use begin/rbegin) |
| Memory constrained | `set` (less overhead) |
| Mostly lookups, few insertions | `unordered_set` |
| Need lower_bound/upper_bound | `set` |
| Just checking existence | `unordered_set` |
| Need duplicates + sorted | `multiset` |
| Need duplicates + fast | `unordered_multiset` |

---
Happy Coding! 🚀