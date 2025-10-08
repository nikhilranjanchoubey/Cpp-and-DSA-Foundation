# FUNCTIONS

C++ programs demonstrating function concepts including parameters, return types, scope, and function overloading.

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
- [Key Concepts](#key-concepts)
- [Function Types](#function-types)
- [Common Patterns](#common-patterns)

## Overview

Programs covering function basics, parameter passing, scope, overloading, and practical applications.

## Programs

### Basic Functions

#### 1. square.cpp - Simple Function
Prints squares of first 5 natural numbers.

**Output:** `1 4 9 16 25`

**Function:**
```cpp
int square(int n) {
    return n * n;
}
```

**Learns:** Function definition, return statement, calling functions in loops

---

#### 2. output2.cpp - Function with Return
Demonstrates function that returns doubled value.

**Output:** `Twice of 24 is: 48`

**Learns:** Passing arguments, returning values, using function results

---

#### 3. output.cpp - Pass by Value
Shows pass by value behavior with formal and actual parameters.

**Output:**
```
25:11
26:13
```

**Learns:** Pass by value (changes don't affect originals), formal vs actual parameters

---

### Mathematical Functions

#### 4. circle.cpp - Multiple Functions
Calculates area and circumference of a circle.

**Functions:**
```cpp
float area(float r) { return 3.14 * r * r; }
float circumference(float r) { return 2 * 3.14 * r; }
```

**Learns:** Multiple functions, float return type, mathematical calculations

---

#### 5. primeNumbers.cpp - Boolean Functions
Prints prime numbers in a range with two implementations.

**Functions:**
- `isPrime()` - Basic approach (checks till n-1)
- `isPrimeBtr()` - Optimized (checks till √n)

**Learns:** Boolean return type, optimization techniques, loop efficiency

---

#### 6. odd.cpp - Boolean Check Function
Prints all odd numbers between two numbers.

**Function:**
```cpp
bool isodd(int num) {
    return (num % 2 != 0);
}
```

**Learns:** Boolean functions, conditional return, using functions as conditions

---

### Conditional Functions

#### 7. age.cpp - Eligibility Check
Checks voting eligibility based on age.

**Function:**
```cpp
bool checkEligibility(int age, int limit) {
    return (age >= limit);
}
```

**Learns:** Boolean logic, conditional returns, function parameters

---

### Parameter Passing

#### 8. passbyvalue.cpp - Pass by Value
Demonstrates that swap doesn't work with pass by value.

**Output:** `6 4` (values unchanged)

**Learns:** Pass by value creates copies, original variables unaffected

---

#### 9. passbyreference.cpp - Pass by Reference
Demonstrates successful swap using references.

**Output:** `1 9` (values swapped)

**Function:**
```cpp
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
```

**Learns:** Pass by reference (`&`), modifying original variables, references

---

### Scope

#### 10. localVariable.cpp - Local Scope
Demonstrates local variable scope within functions and blocks.

**Key Points:**
- Variables exist only within their block
- Loop variables are local to loop
- Accessing outside scope causes error

**Learns:** Local scope, block scope, variable lifetime

---

#### 11. globalVariable.cpp - Global Scope
Shows global variable accessible across functions.

**Output:**
```
Nikhil
Ranjan
```

**Learns:** Global variables, scope across functions, modifying global state

---

### Advanced Features

#### 12. defaultValue.cpp - Default Parameters
Function with default parameter values.

**Function:**
```cpp
void fun(int x, int y = 100, int z = 30)
```

**Output:** `10 100 30`

**Learns:** Default parameters, optional arguments, parameter defaults

---

#### 13. add.cpp - Function Overloading
Multiple functions with same name but different parameters.

**Overloads:**
```cpp
int add(int, int)
int add(int, int, int)
float add(float, float)
float add(float, float, float)
```

**Learns:** Function overloading, compile-time polymorphism, type matching

---

#### 14. standardLibraryFunctions.cpp - Built-in Functions
Using C++ math library functions.

**Functions:** `pow()`, `sqrt()`

**Output:**
```
8
4.89898
4
4.89898
```

**Learns:** `<cmath>` library, type casting, standard functions

---

## Key Concepts

### Function Structure

```cpp
return_type function_name(parameter_list) {
    // Function body
    // Statements
    return value;  // if return_type is not void
}
```

**Components:**
- **Return type**: Data type of returned value (`int`, `float`, `void`, `bool`)
- **Function name**: Identifier following naming rules
- **Parameters**: Input values (optional)
- **Function body**: Code to execute
- **Return statement**: Value to return (not needed for `void`)

### Function Declaration vs Definition

**Declaration (Prototype):**
```cpp
int add(int a, int b);  // Tells compiler function exists
```

**Definition:**
```cpp
int add(int a, int b) {  // Actual implementation
    return a + b;
}
```

### Calling Functions

```cpp
// Without return value
printMessage();

// With return value
int result = add(5, 3);

// Direct use in expression
cout << square(4);
```

## Function Types

### By Return Type

**1. Void Functions (No return)**
```cpp
void printHello() {
    cout << "Hello";
    // No return statement
}
```

**2. Value-Returning Functions**
```cpp
int getSum(int a, int b) {
    return a + b;
}
```

### By Parameters

**1. No Parameters**
```cpp
void greet() {
    cout << "Welcome!";
}
```

**2. With Parameters**
```cpp
int multiply(int x, int y) {
    return x * y;
}
```

**3. Default Parameters**
```cpp
void display(int x, int y = 10) {
    cout << x << " " << y;
}
// Can call: display(5) or display(5, 20)
```

### By Parameter Passing

**1. Pass by Value**
```cpp
void modify(int x) {
    x = 100;  // Changes only local copy
}
```

**2. Pass by Reference**
```cpp
void modify(int &x) {
    x = 100;  // Changes original variable
}
```

## Parameter Passing

### Pass by Value
- **Copies** value to function
- Original variable **not affected**
- Safe but slower for large data

```cpp
void change(int x) {
    x = 10;  // Only changes copy
}

int main() {
    int num = 5;
    change(num);
    cout << num;  // Prints 5 (unchanged)
}
```

### Pass by Reference
- Passes **reference** to original variable
- Original variable **modified**
- Efficient for large data

```cpp
void change(int &x) {
    x = 10;  // Changes original
}

int main() {
    int num = 5;
    change(num);
    cout << num;  // Prints 10 (changed)
}
```

### Comparison Table

| Feature | Pass by Value | Pass by Reference |
|---------|--------------|-------------------|
| Syntax | `void f(int x)` | `void f(int &x)` |
| Modification | No | Yes |
| Memory | Creates copy | Uses original |
| Speed | Slower | Faster |
| Safety | Safe | Can accidentally modify |
| Use for | Small data, read-only | Large data, modify needed |

## Variable Scope

### Local Variables
- Declared inside function/block
- Accessible only within that scope
- Destroyed when scope ends

```cpp
void func() {
    int local = 10;  // Local to func()
}
// 'local' doesn't exist here
```

### Global Variables
- Declared outside all functions
- Accessible anywhere in program
- Exists throughout program execution

```cpp
int global = 100;  // Global variable

void func() {
    cout << global;  // Can access
}

int main() {
    cout << global;  // Can access
}
```

### Scope Priority
When local and global have same name, local takes priority.

```cpp
int x = 10;  // Global

void func() {
    int x = 20;  // Local (shadows global)
    cout << x;  // Prints 20 (local)
}
```

## Function Overloading

Multiple functions with **same name** but **different parameters**.

**Rules:**
1. Different number of parameters
2. Different types of parameters
3. Different order of parameter types

**Valid Overloading:**
```cpp
int add(int a, int b);
int add(int a, int b, int c);
float add(float a, float b);
```

**Invalid Overloading:**
```cpp
int add(int a, int b);
float add(int a, int b);  // ❌ Only return type differs
```

## Common Patterns

### Mathematical Functions
```cpp
int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int power(int base, int exp) {
    int result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
```

### Boolean Functions
```cpp
bool isEven(int n) {
    return (n % 2 == 0);
}

bool isPositive(int n) {
    return (n > 0);
}

bool inRange(int n, int min, int max) {
    return (n >= min && n <= max);
}
```

### Void Functions with Side Effects
```cpp
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
```

## Common Mistakes

### Missing Return Statement
```cpp
❌ int add(int a, int b) {
    int sum = a + b;
    // Missing return!
}

✅ int add(int a, int b) {
    return a + b;
}
```

### Wrong Return Type
```cpp
❌ void getValue() {
    return 42;  // void can't return value
}

✅ int getValue() {
    return 42;
}
```

### Returning Local Variable Address
```cpp
❌ int* getPointer() {
    int x = 10;
    return &x;  // Dangerous! x is destroyed
}
```

### Not Using Return Value
```cpp
int square(int n) {
    return n * n;
}

❌ square(5);  // Result ignored

✅ int result = square(5);
   cout << square(5);
```

### Pass by Value When Modification Needed
```cpp
❌ void increment(int x) {
    x++;  // Only changes copy
}

✅ void increment(int &x) {
    x++;  // Changes original
}
```

## Quick Reference

### Function Templates

**Basic function:**
```cpp
int add(int a, int b) {
    return a + b;
}
```

**Boolean function:**
```cpp
bool isValid(int x) {
    return (x > 0 && x < 100);
}
```

**Void function:**
```cpp
void printMessage() {
    cout << "Hello World";
}
```

**Pass by reference:**
```cpp
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
```

**Default parameters:**
```cpp
void greet(string name = "User") {
    cout << "Hello, " << name;
}
```

**Overloaded function:**
```cpp
int max(int a, int b) { return (a > b) ? a : b; }
float max(float a, float b) { return (a > b) ? a : b; }
```

---

**Learning Path:** 
square.cpp → output2.cpp → output.cpp → circle.cpp → odd.cpp → age.cpp → primeNumbers.cpp → passbyvalue.cpp → passbyreference.cpp → localVariable.cpp → globalVariable.cpp → defaultValue.cpp → add.cpp → standardLibraryFunctions.cpp

---

**Happy Coding! 🚀**

