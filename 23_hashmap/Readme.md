# HashMap and Hashing 

A comprehensive collection of HashMap, Hashing, and Hash Table implementations and applications.

## Table of Contents

- [Introduction](#introduction)
- [Map Variations in C++ STL](#map-variations-in-c-stl)
- [Hash Table Implementation](#hash-table-implementation)
- [String Problems Using HashMap](#string-problems-using-hashmap)
- [Array Problems Using HashMap](#array-problems-using-hashmap)

## Introduction

A **HashMap** (Hash Table) is a data structure that stores key-value pairs and provides fast access using a hash function. It maps keys to values for efficient lookup, insertion, and deletion.

### Key Characteristics
- **Key-Value Storage**: Each key maps to exactly one value
- **Fast Operations**: O(1) average time for insert, delete, search
- **Hash Function**: Converts keys to array indices
- **Collision Handling**: Separate chaining or open addressing

### HashMap vs Other Data Structures

| Feature | HashMap | Set | Array | Tree Map |
|---------|---------|-----|-------|----------|
| Storage | Key-Value | Values only | Index-Value | Key-Value |
| Ordering | ❌ No | ❌ No | ✅ Yes | ✅ Sorted |
| Search | O(1) avg | O(1) avg | O(n) | O(log n) |
| Duplicates | Keys: No, Values: Yes | ❌ No | ✅ Yes | Keys: No |
| Use Case | Fast lookup | Membership | Sequential | Sorted mapping |

---

## Map Variations in C++ STL

### 1. Map (Ordered Map)
**File:** `mapSTL.cpp`

Stores key-value pairs in **sorted order** by key using Red-Black Tree.

**Implementation:** Red-Black Tree (self-balancing BST)

**Header:** `#include <map>`

**Key Features:**
- Keys stored in sorted order
- Unique keys only
- Logarithmic time operations
- Bidirectional iterators

**Declaration:**
```cpp
map<string, int> m;
map<int, string, greater<int>> m;  // Descending order by key
```

**Common Operations:**
```cpp
map<string, int> directory;

// Insertion - Method 1 (using [])
directory["Naman"] = 3876;
directory["Animesh"] = 74529;
directory["Ritu"] = 265289;

// Insertion - Method 2 (using insert)
directory.insert(make_pair("John", 12345));
directory.insert({"Jane", 67890});

// Access
cout << directory["Naman"];  // 3876

// Update
directory["Naman"] = 9999;

// Search
if (directory.find("Naman") != directory.end()) {
    cout << "Found";
}

// Delete
directory.erase("Naman");

// Traversal (sorted by key)
for (auto element : directory) {
    cout << element.first << " - " << element.second << endl;
}

// Iterator traversal
map<string, int>::iterator itr;
for (itr = directory.begin(); itr != directory.end(); itr++) {
    cout << itr->first << " - " << itr->second << endl;
}

// Size
cout << directory.size();

// Empty check
if (directory.empty()) {
    cout << "Map is empty";
}
```

**Example Output:**
```
Animesh - 74529
Naman - 3876
Ritu - 265289
(Sorted alphabetically by key)
```

**Time Complexity:**
- Insert: O(log n)
- Delete: O(log n)
- Search: O(log n)
- Access by key: O(log n)

**Space Complexity:** O(n)

**Use Cases:**
- Phone directory (sorted names)
- Dictionary (word -> definition)
- Symbol tables in compilers
- Database indexing

---

### 2. Multimap (Ordered Multimap)
**File:** `multiMap.cpp`

Allows **duplicate keys** while maintaining sorted order.

**Implementation:** Red-Black Tree

**Header:** `#include <map>`

**Key Features:**
- Multiple values per key allowed
- Keys stored in sorted order
- Cannot use [] operator
- Must use insert() method

**Declaration:**
```cpp
multimap<string, int> mm;
```

**Operations:**
```cpp
multimap<string, int> directory;

// Insertion - ONLY using insert()
directory.insert(make_pair("Nikhil", 345628));
directory.insert(make_pair("Urvi", 743628));
directory.insert(make_pair("Sanket", 695028));
directory.insert(make_pair("Urvi", 8925028));  // Duplicate key allowed

// directory["Urvi"] = 278192;  // ❌ NOT ALLOWED in multimap

// Traversal
for (auto pair : directory) {
    cout << "Name - " << pair.first << endl;
    cout << "Phone no. - " << pair.second << endl;
}

// Count occurrences of a key
int count = directory.count("Urvi");  // Returns 2

// Find all values for a key
auto range = directory.equal_range("Urvi");
for (auto it = range.first; it != range.second; it++) {
    cout << it->second << " ";
}

// Erase all entries with key
directory.erase("Urvi");  // Removes all Urvi entries

// Erase single entry
auto it = directory.find("Urvi");
directory.erase(it);  // Removes only one entry
```

**Example Output:**
```
Name - Nikhil
Phone no. - 345628
Name - Sanket
Phone no. - 695028
Name - Urvi
Phone no. - 743628
Name - Urvi
Phone no. - 8925028
```

**Time Complexity:** Same as map - O(log n)

**Use Cases:**
- Multiple phone numbers per person
- Students with same name
- Email addresses per user
- Tags per article

---

### 3. Unordered Map (Hash Map)
**File:** `unorderedMap.cpp`

Stores key-value pairs in **no particular order** using **hash table**.

**Implementation:** Hash Table

**Header:** `#include <unordered_map>`

**Key Features:**
- No ordering of keys
- Fast average-case operations O(1)
- Unique keys only
- Uses hash function

**Declaration:**
```cpp
unordered_map<int, string> um;
```

**Operations:**
```cpp
unordered_map<int, string> record;

// Insertion - Method 1
record[1] = "Nikhil";
record[2] = "Animesh";

// Insertion - Method 2
record.insert(make_pair(3, "Ria"));

// Update using []
record[3] = "Payal";  // Updates value for key 3

// Insert doesn't update if key exists
record.insert(make_pair(3, "Someone"));  // No change, key 3 already exists

// Traversal (order not guaranteed)
for (auto pair : record) {
    cout << "Roll no. - " << pair.first << endl;
    cout << "Name - " << pair.second << endl;
}

// Access
cout << record[1];  // "Nikhil"

// Search
if (record.find(2) != record.end()) {
    cout << "Found";
}

// Delete
record.erase(1);

// Check if key exists
if (record.count(3)) {
    cout << "Key 3 exists";
}
```
---

### 4. Unordered Multimap (Hash Multimap)
**File:** `unorderedMultimap.cpp`

Allows **duplicate keys** with **no ordering** using hash table.

**Implementation:** Hash Table

**Header:** `#include <unordered_map>`

**Key Features:**
- Multiple values per key
- No ordering
- Fast average operations
- Cannot use [] operator

**Declaration:**
```cpp
unordered_multimap<string, int> umm;
```

**Operations:**
```cpp
unordered_multimap<string, int> fruitcount;

// Insertion - ONLY using insert()
fruitcount.insert(make_pair("apple", 6));
fruitcount.insert(make_pair("banana", 9));
fruitcount.insert(make_pair("apple", 3));  // Duplicate key allowed

// Traversal (no guaranteed order)
for (auto pair : fruitcount) {
    cout << "Fruit - " << pair.first << endl;
    cout << "Count - " << pair.second << endl;
}

// Count occurrences
int count = fruitcount.count("apple");  // Returns 2

// Find all values for key
auto range = fruitcount.equal_range("apple");
for (auto it = range.first; it != range.second; it++) {
    cout << it->second << " ";  // 6 3
}
```

**Time Complexity:**
- Average: O(1)
- Worst: O(n)

**Use Cases:**
- Event logging (timestamp -> event)
- Shopping cart (item -> quantities)
- Graph adjacency lists
- Fast multi-value lookups

---

## Hash Table Implementation

### 5. Hash Table with Closed Addressing (Separate Chaining)
**File:** `hashTableClosedAddressing.cpp`

Custom implementation of hash table using **separate chaining** for collision resolution.

**Collision Resolution:** Separate Chaining (using linked lists)

**Data Structure:**
```cpp
class Hashing {
    vector<list<int>> hashtable;  // Array of linked lists
    int buckets;                  // Number of buckets
    
    int hashvalue(int key) {
        return key % buckets;      // Division method
    }
};
```

**Key Concepts:**

1. **Hash Function**: `h(key) = key % buckets`
   - Maps key to bucket index
   - Simple division method

2. **Separate Chaining**:
   - Each bucket contains a linked list
   - Colliding keys stored in same bucket's list
   - No limit on elements per bucket

**Operations:**

```cpp
Hashing h(7);  // 7 buckets

// Add elements
h.add(10);     // 10 % 7 = 3 → Bucket 3
h.add(20);     // 20 % 7 = 6 → Bucket 6
h.add(15);     // 15 % 7 = 1 → Bucket 1
h.add(7);      // 7 % 7 = 0  → Bucket 0
h.add(32);     // 32 % 7 = 4 → Bucket 4

// Display
h.display();
/*
0 -> 7
1 -> 15
2 ->
3 -> 10
4 -> 32
5 ->
6 -> 20
*/

// Search
auto it = h.searchkey(15);
if (it != hashtable[1].end()) {
    cout << "Found";
}

// Delete
h.deletekey(15);
```

**Complete Implementation:**
```cpp
void add(int key) {
    int idx = hashvalue(key);
    hashtable[idx].push_back(key);
}

list<int>::iterator searchkey(int key) {
    int idx = hashvalue(key);
    return find(hashtable[idx].begin(), hashtable[idx].end(), key);
}

void deletekey(int key) {
    int idx = hashvalue(key);
    auto it = searchkey(key);
    
    if (it != hashtable[idx].end()) {
        hashtable[idx].erase(it);
        cout << "Key deleted successfully\n";
    } else {
        cout << "Key not found\n";
    }
}
```

**Time Complexity:**
- Average: O(1 + α) where α = n/m (load factor)
- Worst: O(n) - all keys in one bucket
- Best: O(1) - uniform distribution

**Space Complexity:** O(n + m) where m = buckets

**Advantages:**
- Simple implementation
- No clustering
- Easy deletion
- Never fills up

**Disadvantages:**
- Extra space for pointers
- Cache performance issues
- Not cache-friendly

**Load Factor:**
```
α = n / m
where n = number of elements
      m = number of buckets

Good α: 0.5 to 1.0
```

---

## String Problems Using HashMap

### 6. Check Anagram
**File:** `checkAnagram.cpp`

Check if two strings are anagrams (same characters, different order).

**Problem:**
```
Input: "triangle", "integral"
Output: True

Input: "anagram", "grams"
Output: False
```

**Approach 1: Using HashMap (Frequency Count)**

```cpp
bool checkAnagram(string s1, string s2) {
    // Length check
    if (s1.length() != s2.length()) {
        return false;
    }
    
    // Count frequency in s1
    unordered_map<char, int> m;
    for (char c : s1) {
        m[c]++;
    }
    
    // Reduce frequency using s2
    for (char c : s2) {
        m[c]--;
    }
    
    // Check if all frequencies are zero
    for (auto ele : m) {
        if (ele.second != 0) {
            return false;
        }
    }
    
    return true;
}
```

**Algorithm:**
1. Check if lengths are equal
2. Create frequency map for string 1
3. Decrease frequencies using string 2
4. If all frequencies become 0 → Anagram

**Alternative Approach: Sorting**
```cpp
bool checkAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    return s1 == s2;
}
```

**Comparison:**

| Method | Time | Space |
|--------|------|-------|
| HashMap | O(n) | O(k) k=unique chars |
| Sorting | O(n log n) | O(1) or O(n) |

**Time Complexity:** O(n) where n = string length  
**Space Complexity:** O(1) - at most 26 characters

---

### 7. Check Isomorphic Strings
**File:** `checkIsomorphic.cpp`

Check if two strings are isomorphic (one-to-one character mapping).

**Definition:** Two strings are isomorphic if there's a bijective (one-to-one and onto) mapping between characters.

**Problem:**
```
Input: "aab", "xxy"
Output: True
Mapping: a→x, b→y

Input: "foo", "bar"
Output: False
(o maps to both o and a - not one-to-one)

Input: "abcdec", "viouog"
Output: False
```

**Key Concept:**
- Each character in s1 must map to exactly ONE character in s2
- Each character in s2 must map to exactly ONE character in s1
- Need to check mapping in BOTH directions

**Approach:**
```cpp
bool checkNoOneToManyMapping(string s1, string s2) {
    unordered_map<char, char> m;
    
    for (int i = 0; i < s1.length(); i++) {
        // If character already mapped
        if (m.find(s1[i]) != m.end()) {
            // Check if mapping is consistent
            if (m[s1[i]] != s2[i]) {
                return false;  // Conflict!
            }
        } else {
            // Create new mapping
            m[s1[i]] = s2[i];
        }
    }
    
    return true;
}

bool checkIsomorphic(string s1, string s2) {
    // Length check
    if (s1.length() != s2.length()) {
        return false;
    }
    
    // Check s1 → s2 mapping
    bool s1s2 = checkNoOneToManyMapping(s1, s2);
    
    // Check s2 → s1 mapping (reverse)
    bool s2s1 = checkNoOneToManyMapping(s2, s1);
    
    // Both must be valid
    return s1s2 && s2s1;
}
```

**Why Check Both Directions?**

Example: s1 = "ab", s2 = "cc"
- s1→s2: a→c, b→c ✓ (one-to-many is allowed in this direction)
- s2→s1: c→a, c→b ✗ (one-to-many NOT allowed!)

**Time Complexity:** O(n)  
**Space Complexity:** O(k) where k = unique characters

**Use Cases:**
- Pattern matching
- String encoding/decoding
- Cipher detection
- Template matching

---

### 8. Make Strings Equal
**File:** `makeStringsEqual.cpp`

Check if characters can be redistributed to make all strings equal.

**Problem:**
```
Input: ["collegeee", "coll", "collegge"]
Output: Yes
Explanation: Can redistribute to make all equal

Input: ["wall", "ah", "wallahah"]
Output: No
Explanation: Not enough characters
```

**Approach:**
```cpp
bool canMakeEqual(vector<string>& v) {
    unordered_map<char, int> m;
    
    // Count total frequency of each character
    for (auto str : v) {
        for (char c : str) {
            m[c]++;
        }
    }
    
    int n = v.size();
    
    // Check if each character count is divisible by n
    for (auto ele : m) {
        if (ele.second % n != 0) {
            return false;
        }
    }
    
    return true;
}
```

**Logic:**
- If we have 3 strings, each character must appear in multiples of 3
- Example: 'e' appears 6 times → 6÷3 = 2 ✓ (each string can have 2)
- Example: 'l' appears 7 times → 7÷3 = not divisible ✗

**Detailed Example:**
```
Strings: ["abc", "bca", "cab"]

Character counts:
a: 3 (3÷3 = 1) ✓
b: 3 (3÷3 = 1) ✓
c: 3 (3÷3 = 1) ✓

Each string can have: 1a, 1b, 1c
Result: Yes
```

**Time Complexity:** O(n×m) where n=strings, m=avg length  
**Space Complexity:** O(k) where k=unique characters

**Use Cases:**
- Resource distribution
- Load balancing
- Inventory management
- Fair division problems

---

## Array Problems Using HashMap

### 9. Target Sum (Two Sum)
**File:** `targetSum.cpp`

Find two numbers in an array that sum to a target value.

**Problem:**
```
Input: [1, 4, 5, 11, 13, 10, 2], Target = 13
Output: [3, 6] (indices of 11 and 2)

Input: [9, 10, 2, 3, 5], Target = 15
Output: [1, 4] (indices of 10 and 5)
```

**Naive Approach:** O(n²)
```cpp
for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
        if (arr[i] + arr[j] == target) {
            return {i, j};
        }
    }
}
```

**Optimized Approach using HashMap:** O(n)
```cpp
vector<int> targetSumPair(vector<int>& v, int targetsum) {
    unordered_map<int, int> m;  // value -> index
    vector<int> ans(2, -1);
    
    for (int i = 0; i < v.size(); i++) {
        int complement = targetsum - v[i];
        
        // Check if complement exists
        if (m.find(complement) != m.end()) {
            ans[0] = m[complement];  // Index of complement
            ans[1] = i;              // Current index
            return ans;
        }
        
        // Store current value and index
        m[v[i]] = i;
    }
    
    return ans;  // {-1, -1} if not found
}
```

**Algorithm:**
1. Iterate through array
2. For each element x, calculate complement = target - x
3. Check if complement exists in hashmap
4. If yes → found pair
5. If no → store current element in hashmap

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

**Extensions:**
- **Three Sum**: Use HashMap + two pointers
- **Four Sum**: Nested loops + HashMap
- **Count pairs**: Count instead of returning indices

**Use Cases:**
- Stock trading (buy/sell to reach target profit)
- Budget planning (two items that fit budget)
- Chemistry (compounds that react)
- Game development (item combinations)

---

### 10. Sum of Repetitive Elements
**File:** `sumOfRepetitiveElements.cpp`

Find sum of elements that appear more than once.

**Problem:**
```
Input: [1, 1, 2, 1, 3, 3, 3]
Output: 4
Explanation: Repetitive elements are 1 and 3, sum = 1+3 = 4
```

**Approach:**
```cpp
map<int, int> m;

// Count frequency
for (int i = 0; i < n; i++) {
    m[input[i]]++;
}

int sum = 0;

// Sum elements with frequency > 1
for (auto pair : m) {
    if (pair.second > 1) {
        sum += pair.first;  // Add element, not frequency
    }
}
```

**Important:** Add the **element itself**, not frequency!
```
Wrong: sum += pair.second  (adds frequency)
Right: sum += pair.first   (adds element)
```

**Example:**
```
Array: [1, 1, 2, 1, 3, 3, 3]

Frequency map:
1 → 3 (repetitive ✓)
2 → 1 (not repetitive)
3 → 3 (repetitive ✓)

Sum: 1 + 3 = 4
```

**Time Complexity:** O(n)  
**Space Complexity:** O(k) where k=unique elements

---

### 11. Longest Zero Sum Subarray
**File:** `longestZeroSumSubarray.cpp`

Find length of longest subarray with sum equal to 0.

**Problem:**
```
Input: [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: Subarray [-2, 2, -8, 1, 7] has sum = 0

Input: [1, 2, 3]
Output: 0 (no zero-sum subarray)
```

**Key Concept: Prefix Sum**

If `prefixSum[i] == prefixSum[j]`, then sum of elements between i and j is 0.

**Why?**
```
prefixSum[j] - prefixSum[i] = sum(i+1 to j)
If prefixSum[i] == prefixSum[j]
Then sum(i+1 to j) = 0
```

**Approach:**
```cpp
int maxLengthZeroSumSubarray(vector<int>& v) {
    unordered_map<int, int> m;  // prefixSum -> first index
    int prefixsum = 0;
    int maxlen = INT_MIN;
    
    for (int i = 0; i < v.size(); i++) {
        prefixsum += v[i];
        
        // Case 1: Prefix sum is 0
        if (prefixsum == 0) {
            maxlen = i + 1;  // Subarray from 0 to i
        }
        
        // Case 2: Same prefix sum seen before
        if (m.find(prefixsum) != m.end()) {
            int length = i - m[prefixsum];
            maxlen = max(maxlen, length);
        } else {
            // Store first occurrence
            m[prefixsum] = i;
        }
    }
    
    return maxlen;
}
```
**Time Complexity:** O(n)  
**Space Complexity:** O(n)

---
### Load Factor

```
α = n / m
where n = number of elements
      m = number of buckets

Ideal: 0.5 ≤ α ≤ 1.0
```
**Rehashing:**
When α > threshold (usually 0.75):
1. Create new table with 2×m buckets
2. Rehash all elements
3. Insert into new table
---
Happy Coding! 🚀