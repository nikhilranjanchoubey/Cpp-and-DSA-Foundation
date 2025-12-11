# STRINGS

C++ programs demonstrating string manipulation, pattern matching, and algorithmic problem-solving techniques.

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
  - [Basics](#basics)
  - [String Functions](#string-functions)
  - [Pattern Matching](#pattern-matching)
  - [String Sorting](#string-sorting)
  - [Advanced Problems](#advanced-problems)
- [Key Concepts](#key-concepts)
- [String Techniques](#string-techniques)
- [Common Patterns](#common-patterns)

## Overview

Programs covering string basics, built-in functions, character manipulation, pattern matching, anagrams, isomorphic strings, and advanced algorithms.

## Programs

### Basics

#### 1. basic.cpp - String Declaration
Basic string creation and initialization.

**Methods:**
```cpp
string str = "college";      // Direct initialization
string str1("wallah");        // Constructor initialization
```

**Learns:** String declaration, initialization methods

---

#### 2. input.cpp - String Input
Different methods to take string input.

**Methods:**
```cpp
cin >> str;          // Reads until whitespace
getline(cin, str);   // Reads entire line with spaces
```

**Example:**
```
Input: "Hello World"
cin >> str       → "Hello"
getline(cin,str) → "Hello World"
```

**Learns:** Input methods, handling spaces in strings

---

#### 3. ascii.cpp - ASCII Values
Understanding character to integer conversion.

**Example:**
```cpp
char ch = 'a';
cout << int(ch);  // Output: 97
```

**ASCII Values:**
- 'a' to 'z': 97 to 122
- 'A' to 'Z': 65 to 90
- '0' to '9': 48 to 57

**Learns:** ASCII values, type casting, character encoding

---

### String Functions

#### 4. functions.cpp - Built-in String Functions
Comprehensive demonstration of C++ string functions.

**Functions Covered:**

**1. reverse()** - Reverses string
```cpp
string str = "hello";
reverse(str.begin(), str.end());  // "olleh"
```

**2. substr()** - Extracts substring
```cpp
string str = "survive";
str.substr(1, 4);  // "urvi" (start=1, length=4)
```

**3. + operator** - Concatenates strings
```cpp
string s1 = "college", s2 = "wallah";
s1 += s2;  // "collegewallah"
```

**4. strcat()** - Concatenates C-strings
```cpp
char s1[20] = "college", s2[20] = "wallah";
strcat(s1, s2);  // "collegewallah"
```

**5. push_back()** - Appends character
```cpp
string s1 = "abcd";
s1.push_back('e');  // "abcde"
```

**6. size() / length()** - Gets string length
```cpp
string str = "Nikhil";
str.size();    // 6
strlen(ch);    // For C-strings
```

**7. to_string()** - Converts number to string
```cpp
int num = 432;
string str = to_string(num);  // "432"
str += "1";  // "4321"
```

**Learns:** STL string functions, string manipulation

---

### Pattern Matching

#### 5. anagramCheck.cpp - Anagram Detection
Checks if two strings are anagrams (same letters, different order).

**Definition:** Rearrangement of letters using all letters exactly once

**Examples:**
- "listen" ↔ "silent" ✓
- "anagram" ↔ "nagaram" ✓
- "bank" ↔ "atm" ✗

**Algorithm:**
1. Check if lengths are equal
2. Create frequency array (size 26 for a-z)
3. Increment for s1 characters, decrement for s2
4. If all frequencies are 0, strings are anagrams

**Time:** O(n), **Space:** O(1) - constant 26 size

**Learns:** Frequency counting, character mapping

---

#### 6. isomorphic.cpp - Isomorphic Strings
Checks if two strings have same character pattern.

**Definition:** Each character in s maps to unique character in t, maintaining pattern

**Examples:**
- "egg" ↔ "add" ✓ (e→a, g→d)
- "foo" ↔ "bar" ✗ (o maps to both a and r)

**Algorithm:**
1. Track last occurrence index of each character
2. For both strings, indices must match at each position
3. Use two arrays (size 128 for ASCII)

**Time:** O(n), **Space:** O(1)

**Learns:** Pattern matching, index tracking

---

#### 7. longestCommonPrefix.cpp - Common Prefix
Finds longest common prefix among array of strings.

**Example:** `["flower", "flight", "flask"]` → `"fl"`

**Algorithm 1 (Sorting):**
1. Sort strings lexicographically
2. Compare first and last string (extremes)
3. Match characters until mismatch

**Algorithm 2 (Comparison):**
1. Take first string as reference
2. Compare with all other strings
3. Track minimum common length

**Time:** O(n × m) where m = average length

**Learns:** String comparison, prefix finding

---

### String Sorting

#### 8. sortString.cpp - Sort String Characters
Sorts characters in string using counting sort.

**Example:** "codingwallah" → "aacdghillnow"

**Algorithm:**
1. Create frequency array (size 26)
2. Count each character
3. Rebuild string in sorted order

**Time:** O(n), **Space:** O(1)

**Learns:** Counting sort on strings, character frequency

---

### Advanced Problems

#### 9. longestOnes.cpp - Sliding Window
Finds longest consecutive 1s after flipping at most k zeros.

**Example:** "0001101011", k=2 → Output: 7

**Sliding Window Technique:**
- Two pointers: start and end
- Expand window by moving end
- Shrink from start when zeros > k
- Track maximum valid window

**Algorithm:**
```cpp
1. Initialize start=0, zero_count=0, max_length=0
2. For each end position:
   - If str[end]='0', increment zero_count
   - While zero_count > k:
       * If str[start]='0', decrement zero_count
       * Increment start
   - Update max_length = max(max_length, end-start+1)
```

**Time:** O(n), **Space:** O(1)

**Learns:** Sliding window, two-pointer technique

---

#### 10. decodeString.cpp - String Decoding
Decodes encoded string with nested patterns.

**Pattern:** `k[string]` means repeat string k times

**Examples:**
- `1[b]` → `b`
- `3[a]` → `aaa`
- `3[b2[ca]]` → `bcacabcacabcaca`

**Algorithm (Stack-based):**
1. Traverse string character by character
2. If not `]`, push to result
3. If `]`:
   - Extract substring until `[`
   - Extract number before `[`
   - Repeat substring n times
   - Append to result

**Steps for "3[b2[ca]]":**
```
Process: 3 [ b 2 [ c a ] ]
After 'a': result = "3[b2[ca"
After first ']': result = "3[bcaca"
After second ']': result = "bcacabcacabcaca"
```

**Time:** O(maxK × n) where maxK = max repetition

**Learns:** Stack operations, string building, nested patterns

---

## Key Concepts

### String Basics

**Declaration:**
```cpp
string str;                  // Empty string
string str = "hello";        // Direct initialization
string str("hello");         // Constructor
string str(5, 'a');         // "aaaaa" (5 times 'a')
```

**Access:**
```cpp
str[0]          // First character
str[n-1]        // Last character
str.at(i)       // With bounds checking
str.front()     // First character
str.back()      // Last character
```

**Modification:**
```cpp
str[0] = 'A';               // Direct modification
str += "world";              // Concatenation
str.push_back('!');          // Append character
str.pop_back();              // Remove last character
```

### Character Operations

**Case Conversion:**
```cpp
char ch = 'a';
char upper = ch - 32;        // 'a' - 32 = 'A'
char lower = ch + 32;        // 'A' + 32 = 'a'

// Or using functions
char upper = toupper(ch);
char lower = tolower(ch);
```

**Character Checking:**
```cpp
isalpha(ch)     // Is alphabetic?
isdigit(ch)     // Is digit?
isalnum(ch)     // Is alphanumeric?
isupper(ch)     // Is uppercase?
islower(ch)     // Is lowercase?
isspace(ch)     // Is whitespace?
```

**Character to Index:**
```cpp
int index = ch - 'a';        // 'a'=0, 'b'=1, ..., 'z'=25
char ch = 'a' + index;       // Convert back
```

### String Comparison

```cpp
str1 == str2    // Equal
str1 != str2    // Not equal
str1 < str2     // Lexicographically smaller
str1 > str2     // Lexicographically greater

str1.compare(str2)  // Returns 0 if equal, <0 if less, >0 if greater
```

## String Techniques

### Frequency Counting
```cpp
vector<int> freq(26, 0);
for(char ch : str) {
    freq[ch - 'a']++;
}
```

### Two Pointer
```cpp
int i = 0, j = str.length() - 1;
while(i < j) {
    // Compare or process str[i] and str[j]
    i++;
    j--;
}
```

### Sliding Window
```cpp
int start = 0;
for(int end = 0; end < str.length(); end++) {
    // Expand window
    
    while(condition_violated) {
        // Shrink window
        start++;
    }
    
    // Update result
}
```

### String Building
```cpp
string result = "";
for(char ch : str) {
    if(condition) {
        result += ch;  // or result.push_back(ch)
    }
}
```

### Palindrome Check
```cpp
bool isPalindrome(string str) {
    int i = 0, j = str.length() - 1;
    while(i < j) {
        if(str[i] != str[j]) return false;
        i++; j--;
    }
    return true;
}
```

## Common Patterns

### Pattern 1: Character Frequency
```cpp
// Count frequency of all characters
vector<int> freq(26, 0);
for(char ch : str) {
    freq[ch - 'a']++;
}

// Check if all frequencies are same (anagram check)
for(int i = 0; i < 26; i++) {
    if(freq[i] != 0) {
        // Process
    }
}
```

### Pattern 2: String Reversal
```cpp
// Method 1: STL
reverse(str.begin(), str.end());

// Method 2: Two pointer
int i = 0, j = str.length() - 1;
while(i < j) {
    swap(str[i], str[j]);
    i++; j--;
}

// Method 3: New string
string reversed = "";
for(int i = str.length() - 1; i >= 0; i--) {
    reversed += str[i];
}
```

### Pattern 3: Substring Generation
```cpp
// All substrings
for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
        string sub = str.substr(i, j - i + 1);
        // Process substring
    }
}
```

### Pattern 4: String Comparison
```cpp
// Anagram check
sort(s1.begin(), s1.end());
sort(s2.begin(), s2.end());
return s1 == s2;

// Or use frequency array
vector<int> freq1(26, 0), freq2(26, 0);
for(char ch : s1) freq1[ch - 'a']++;
for(char ch : s2) freq2[ch - 'a']++;
return freq1 == freq2;
```

### Pattern 5: Sliding Window Template
```cpp
int start = 0, maxLen = 0;
unordered_map<char, int> count;

for(int end = 0; end < str.length(); end++) {
    // Add current character
    count[str[end]]++;
    
    // Shrink window if needed
    while(window_condition_violated) {
        count[str[start]]--;
        if(count[str[start]] == 0) 
            count.erase(str[start]);
        start++;
    }
    
    // Update result
    maxLen = max(maxLen, end - start + 1);
}
```

## String vs C-String

| Feature | string (C++) | char[] (C-string) |
|---------|-------------|-------------------|
| **Declaration** | `string str = "hello";` | `char str[] = "hello";` |
| **Size** | Dynamic | Fixed |
| **Functions** | `str.length()`, `str.size()` | `strlen(str)` |
| **Concatenation** | `str1 + str2` | `strcat(str1, str2)` |
| **Comparison** | `str1 == str2` | `strcmp(str1, str2)` |
| **Copy** | `str2 = str1` | `strcpy(str2, str1)` |
| **Safety** | Bounds checked | No bounds checking |
| **Memory** | Automatic management | Manual management |

## Time Complexity Reference

| Operation | Complexity |
|-----------|-----------|
| Access character | O(1) |
| Append character | O(1) amortized |
| Insert/Delete at end | O(1) |
| Insert/Delete at beginning | O(n) |
| Substring | O(k) where k = length |
| Concatenation | O(n + m) |
| Compare | O(min(n, m)) |
| Search | O(n × m) naive |
| Reverse | O(n) |
| Sort | O(n log n) |

## Common String Functions

### STL String Functions
```cpp
#include <string>
#include <algorithm>

str.length()              // Length
str.size()                // Size (same as length)
str.empty()               // Check if empty
str.clear()               // Clear string

str.substr(pos, len)      // Extract substring
str.find(substr)          // Find position
str.rfind(substr)         // Find from end

str.insert(pos, str2)     // Insert at position
str.erase(pos, len)       // Erase characters
str.replace(pos, len, str2) // Replace portion

reverse(str.begin(), str.end())  // Reverse
sort(str.begin(), str.end())     // Sort

to_string(num)            // Convert number to string
stoi(str)                 // Convert string to int
stoll(str)                // Convert string to long long
stod(str)                 // Convert string to double
```
---

**Happy Coding! 🚀**