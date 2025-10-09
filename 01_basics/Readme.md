# BASICS OF C++

Essential C++ programs for beginners covering fundamental programming concepts.

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
- [Key Concepts](#key-concepts)
- [Common Mistakes](#common-mistakes)

## Overview

Programs teaching C++ basics: output, input, arithmetic, and variable manipulation.

## Programs

### 1. hello.cpp - Hello World
First C++ program displaying text to console.

**Output:** `Hello, World! in C++`

**Learns:** Program structure, `cout`, `main()` function, return statement

---

### 2. input.cpp - User Input
Takes user input and displays it.

**Example:**
```
Enter the No. Of Apples: 5
Number of Apples: 5
```

**Learns:** Variable declaration, `cin`, `cout`, `endl`

---

### 3. sum.cpp - Arithmetic Operations
Adds two numbers entered by user.

**Example:**
```
Enter two numbers: 10 20
Sum: 30
```

**Learns:** Multiple inputs, arithmetic operators, storing results

---

### 4. swap.cpp - Variable Swapping
Swaps values of two variables using temporary variable.

**Example:**
```
a: 5
b: 10
a: 10
b: 5
```

**Learns:** Swap algorithm, variable manipulation, assignment operations

---

## Key Concepts

### Program Structure
```cpp
#include<iostream>        // Include header for I/O
using namespace std;      // Use standard namespace

int main() {              // Entry point
    // Code here
    return 0;             // Successful execution
}
```

### Input/Output
```cpp
cout << "Text" << variable << endl;    // Output
cin >> variable;                        // Input
cin >> a >> b;                          // Multiple inputs
```

**Operators:**
- `<<` - Output (used with `cout`)
- `>>` - Input (used with `cin`)
- `endl` - New line

### Variables
```cpp
int x;              // Declaration
int y = 10;         // Declaration + Initialization
x = 5;              // Assignment
```

### Swap Algorithm
```cpp
int temp = a;       // Store first value
a = b;              // Copy second to first
b = temp;           // Copy stored value to second
```

## Common Mistakes

| Wrong ❌ | Correct ✅ |
|---------|----------|
| `cout << "Hello"` (no semicolon) | `cout << "Hello";` |
| `cout >> "Hello";` | `cout << "Hello";` |
| `cin << variable;` | `cin >> variable;` |
| Missing `#include<iostream>` | Always include at top |
| `int x; cout << x;` (uninitialized) | `int x = 0; cout << x;` |

**Swap without temp (wrong):**
```cpp
a = b;  // Lost value of a
b = a;  // Both are now b
```

## Quick Reference

### Basic Program Template:
```cpp
#include<iostream>
using namespace std;

int main() {
    // Your code
    return 0;
}
```

### Input/Output Pattern:
```cpp
int num;
cout << "Enter number: ";
cin >> num;
cout << "You entered: " << num << endl;
```

### Calculation Pattern:
```cpp
int a, b, result;
cin >> a >> b;
result = a + b;
cout << "Result: " << result << endl;
```

---

**Learning Path:** hello.cpp → input.cpp → sum.cpp → swap.cpp

**Resources:** [cplusplus.com](http://cplusplus.com) | [geeksforgeeks.org](https://geeksforgeeks.org/c-plus-plus/) | [learncpp.com](https://learncpp.com)

---

**Happy Coding! 🚀**
