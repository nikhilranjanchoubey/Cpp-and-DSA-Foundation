# LOOPS

C++ programs demonstrating loop structures and flow control statements.

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
- [Key Concepts](#key-concepts)
- [Loop Control Statements](#loop-control-statements)
- [Common Patterns](#common-patterns)

## Overview

Five programs covering for loops, while loops, do-while loops, break, and continue statements.

## Programs

### 1. forLoop.cpp - For Loop Basics
Calculates sum of first N natural numbers using for loop.

**Example:**
```
Input: 5
Output: Sum is: 15 (1+2+3+4+5)
```

**Syntax:**
```cpp
for(int i = 1; i <= num; i++) {
    sum += i;
}
```

**Learns:** For loop structure, initialization, condition, increment

---

### 2. whileLoop.cpp - While Loop Basics
Same problem as forLoop.cpp but using while loop.

**Example:**
```
Input: 5
Output: Sum is: 15
```

**Syntax:**
```cpp
int i = 1;
while(i <= num) {
    sum += i;
    i++;
}
```

**Learns:** While loop structure, loop variable management

---

### 3. doWhileLoop.cpp - Do-While Loop
Calculates sum of N integers from input stream.

**Example:**
```
Input: 3
       10 20 30
Output: Sum is: 60
```

**Syntax:**
```cpp
do {
    cin >> num;
    sum += num;
    n--;
} while(n > 0);
```

**Learns:** Do-while loop, executes at least once, post-condition check

---

### 4. break.cpp - Break Statement
Finds first multiple of 5 that's also divisible by 7.

**Output:** `35`

**Demonstrates:**
- Breaking infinite loop with `while(true)`
- Breaking for loop with empty condition `for(;;)`
- Exit loop immediately when condition met

**Learns:** Break statement, infinite loops, early exit

---

### 5. continue.cpp - Continue Statement
Prints numbers 1-50 except multiples of 3.

**Output:** `1 2 4 5 7 8 10 11 ... 49 50`

**Logic:** Skip iteration when `i % 3 == 0`

**Learns:** Continue statement, skip current iteration

---

## Key Concepts

### For Loop
Best when number of iterations is **known**.

```cpp
for(initialization; condition; increment/decrement) {
    // Code to execute
}
```

**Execution Order:**
1. Initialization (once)
2. Condition check
3. Execute body
4. Increment/decrement
5. Repeat from step 2

**Example:**
```cpp
for(int i = 1; i <= 10; i++) {
    cout << i << " ";
}
// Output: 1 2 3 4 5 6 7 8 9 10
```

### While Loop
Best when number of iterations is **unknown** and depends on condition.

```cpp
while(condition) {
    // Code to execute
    // Update loop variable
}
```

**Execution Order:**
1. Check condition
2. If true, execute body
3. Repeat from step 1

**Example:**
```cpp
int i = 1;
while(i <= 10) {
    cout << i << " ";
    i++;
}
```

### Do-While Loop
Executes **at least once**, then checks condition.

```cpp
do {
    // Code to execute
    // Update loop variable
} while(condition);
```

**Execution Order:**
1. Execute body (always runs first)
2. Check condition
3. If true, repeat from step 1

**Example:**
```cpp
int i = 1;
do {
    cout << i << " ";
    i++;
} while(i <= 10);
```

### Infinite Loops
Loops that run forever until broken.

```cpp
// While infinite loop
while(true) {
    // Code
    if(condition) break;
}

// For infinite loop
for(;;) {
    // Code
    if(condition) break;
}
```

## Loop Control Statements

### Break Statement
Exits the loop immediately.

```cpp
for(int i = 1; i <= 10; i++) {
    if(i == 5) {
        break;  // Loop stops when i is 5
    }
    cout << i << " ";
}
// Output: 1 2 3 4
```

**Use Cases:**
- Exit loop when specific condition met
- Break from infinite loops
- Early termination of search

### Continue Statement
Skips current iteration and moves to next.

```cpp
for(int i = 1; i <= 10; i++) {
    if(i % 2 == 0) {
        continue;  // Skip even numbers
    }
    cout << i << " ";
}
// Output: 1 3 5 7 9
```

**Use Cases:**
- Skip certain values
- Avoid nested if-else
- Filter data in loops

## Loop Comparison

| Feature | For | While | Do-While |
|---------|-----|-------|----------|
| **When to use** | Known iterations | Unknown iterations | At least one execution |
| **Condition check** | Before execution | Before execution | After execution |
| **Syntax complexity** | Compact | Simple | Medium |
| **Minimum executions** | 0 | 0 | 1 |
| **Common use** | Counting, arrays | User input, conditions | Menu systems, validation |

## Common Patterns

### Counting Pattern
```cpp
// Count up
for(int i = 1; i <= n; i++) { }

// Count down
for(int i = n; i >= 1; i--) { }

// Step by 2
for(int i = 0; i <= n; i += 2) { }
```

### Accumulation Pattern
```cpp
int sum = 0;
for(int i = 1; i <= n; i++) {
    sum += i;  // Add each number
}
```

### Input Validation
```cpp
int num;
do {
    cout << "Enter positive number: ";
    cin >> num;
} while(num <= 0);
```

### Menu-Driven Program
```cpp
int choice;
do {
    cout << "1. Add\n2. Exit\n";
    cin >> choice;
    
    if(choice == 1) {
        // Add logic
    }
} while(choice != 2);
```

### Nested Loops
```cpp
// Print multiplication table
for(int i = 1; i <= 10; i++) {
    for(int j = 1; j <= 10; j++) {
        cout << i * j << " ";
    }
    cout << endl;
}
```

### Search Pattern
```cpp
bool found = false;
for(int i = 0; i < n; i++) {
    if(arr[i] == target) {
        found = true;
        break;
    }
}
```

## Common Mistakes

### Infinite Loop (Unintentional)
```cpp
❌ for(int i = 1; i <= 10; i--) {  // i decreases, never reaches 10
    cout << i;
}

❌ int i = 1;
   while(i <= 10) {
       cout << i;  // Forgot to increment i
   }

✅ for(int i = 1; i <= 10; i++) {
    cout << i;
}
```

### Off-by-One Error
```cpp
❌ for(int i = 1; i < 10; i++) { }  // Runs 9 times, not 10

✅ for(int i = 1; i <= 10; i++) { }  // Runs 10 times
```

### Using Break/Continue Outside Loop
```cpp
❌ if(condition) {
    break;  // Error: not inside a loop
}

✅ for(int i = 0; i < n; i++) {
    if(condition) break;  // Correct
}
```

### Wrong Semicolon Placement
```cpp
❌ for(int i = 0; i < 10; i++);  // Empty loop!
   {
       cout << i;  // Executes only once
   }

✅ for(int i = 0; i < 10; i++) {
       cout << i;
   }
```

### Variable Scope Issues
```cpp
❌ for(int i = 0; i < 10; i++) { }
   cout << i;  // Error: i is out of scope

✅ int i;
   for(i = 0; i < 10; i++) { }
   cout << i;  // i is accessible
```

## Loop Patterns for Common Problems

### Factorial
```cpp
int fact = 1;
for(int i = 1; i <= n; i++) {
    fact *= i;
}
```

### Reverse Number
```cpp
int rev = 0;
while(num > 0) {
    int digit = num % 10;
    rev = rev * 10 + digit;
    num /= 10;
}
```

### Prime Check
```cpp
bool isPrime = true;
for(int i = 2; i <= sqrt(n); i++) {
    if(n % i == 0) {
        isPrime = false;
        break;
    }
}
```

### Fibonacci
```cpp
int a = 0, b = 1;
for(int i = 1; i <= n; i++) {
    cout << a << " ";
    int next = a + b;
    a = b;
    b = next;
}
```

## Quick Reference

### For Loop Variations
```cpp
// Standard
for(int i = 0; i < n; i++) { }

// Multiple variables
for(int i = 0, j = n; i < j; i++, j--) { }

// Infinite
for(;;) { }

// Nested
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) { }
}
```

### While Loop Variations
```cpp
// Standard
while(condition) { }

// Infinite
while(true) { }

// Input validation
while(cin >> num && num != -1) { }
```

### Do-While Usage
```cpp
// Menu
do {
    // Display menu
    // Get choice
} while(choice != exit_option);

// Validation
do {
    cout << "Enter positive: ";
    cin >> num;
} while(num <= 0);
```

---

**Learning Path:** forLoop.cpp → whileLoop.cpp → doWhileLoop.cpp → break.cpp → continue.cpp