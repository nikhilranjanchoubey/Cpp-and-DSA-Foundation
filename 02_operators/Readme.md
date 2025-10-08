# OPERATORS

Comprehensive C++ programs demonstrating all types of operators with practical examples.

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
- [Key Concepts](#key-concepts)
- [Operator Precedence](#operator-precedence)
- [Common Pitfalls](#common-pitfalls)

## Overview

Programs covering arithmetic, relational, logical, bitwise, and special operators in C++.

## Programs

### 1. operators1.cpp - Arithmetic & Relational Operators
Demonstrates basic arithmetic, relational comparisons, and compound assignment operators.

**Operations:**
```cpp
6 + 3 = 9
6 - 3 = 3
6 * 3 = 18
6 / 3 = 2
6 % 3 = 0
6 == 3 → 0 (false)
6 != 3 → 1 (true)
6 >= 3 → 1 (true)
num1 += 3 → 9
num2 -= 2 → 1
```

**Learns:** `+`, `-`, `*`, `/`, `%`, `==`, `!=`, `>=`, `<=`, `>`, `<`, `+=`, `-=`

---

### 2. operators2.cpp - Logical Operators
Boolean logic with AND, OR, and NOT operators.

**Operations:**
```cpp
true && false → 0 (false)
true || false → 1 (true)
!true → 0 (false)
```

**Learns:** `&&` (AND), `||` (OR), `!` (NOT), boolean expressions

---

### 3. operators3.cpp - Bitwise Operators
Binary operations including shift and bitwise AND/OR.

**Operations:**
```cpp
5 << 1 → 10 (left shift, multiply by 2)
5 >> 1 → 2 (right shift, divide by 2)
5 & 8 → 0 (bitwise AND)
5 | 8 → 13 (bitwise OR)
```

**Binary:**
- 5 = 0101
- 8 = 1000
- 5 | 8 = 1101 = 13

**Learns:** `<<`, `>>`, `&`, `|`, `^`, `~`, binary operations

---

### 4. operators4.cpp - Special Operators
Sizeof, ternary, address-of, increment/decrement operators.

**Operations:**
```cpp
sizeof(int) → 4 bytes
sizeof(char) → 1 byte
condition ? true : false (ternary)
c++ → Post-increment: use then increment
--b → Pre-decrement: decrement then use
```

**Learns:** `sizeof`, `? :`, `&`, `++`, `--`, address operator

---

### 5. operators5.cpp - Short-Circuit Evaluation
Advanced logical operators with short-circuiting behavior.

**Behavior:**
```cpp
a || --b → Since a is true, --b is NOT evaluated
a-- && --b → Both sides evaluated, a post-decremented
```

**Output:** `a: 0, b: 0, c: 1, d: 1`

**Learns:** Short-circuit evaluation, operator evaluation order, side effects

---

## Key Concepts

### Arithmetic Operators
```cpp
a + b    // Addition
a - b    // Subtraction
a * b    // Multiplication
a / b    // Division (integer division if both int)
a % b    // Modulus (remainder)
```

### Relational Operators
```cpp
a == b   // Equal to (returns 1 or 0)
a != b   // Not equal to
a > b    // Greater than
a < b    // Less than
a >= b   // Greater than or equal to
a <= b   // Less than or equal to
```

### Logical Operators
```cpp
exp1 && exp2   // AND: true if both true
exp1 || exp2   // OR: true if at least one true
!exp           // NOT: inverts boolean value
```

**Truth Table:**
| A | B | A && B | A \|\| B | !A |
|---|---|--------|----------|-----|
| 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 |

### Bitwise Operators
```cpp
a & b    // AND: 1 if both bits 1
a | b    // OR: 1 if at least one bit 1
a ^ b    // XOR: 1 if bits different
~a       // NOT: inverts all bits
a << n   // Left shift: multiply by 2^n
a >> n   // Right shift: divide by 2^n
```

### Assignment Operators
```cpp
a = b     // Simple assignment
a += b    // a = a + b
a -= b    // a = a - b
a *= b    // a = a * b
a /= b    // a = a / b
a %= b    // a = a % b
```

### Increment/Decrement
```cpp
++a       // Pre-increment: increment then use
a++       // Post-increment: use then increment
--a       // Pre-decrement: decrement then use
a--       // Post-decrement: use then decrement
```

**Example:**
```cpp
int x = 5;
cout << x++;  // Prints 5, x becomes 6
cout << ++x;  // x becomes 7, prints 7
```

### Special Operators
```cpp
sizeof(var)        // Returns size in bytes
condition ? a : b  // Ternary: returns a if true, b if false
&var               // Address-of operator
```

## Operator Precedence

**High to Low:**
1. `()` - Parentheses
2. `++`, `--`, `!`, `~`, `&`, `sizeof` - Unary operators
3. `*`, `/`, `%` - Multiplicative
4. `+`, `-` - Additive
5. `<<`, `>>` - Shift
6. `<`, `<=`, `>`, `>=` - Relational
7. `==`, `!=` - Equality
8. `&` - Bitwise AND
9. `^` - Bitwise XOR
10. `|` - Bitwise OR
11. `&&` - Logical AND
12. `||` - Logical OR
13. `?:` - Ternary
14. `=`, `+=`, `-=`, etc. - Assignment

**Tip:** Use parentheses to make expressions clear: `(a + b) * c`

## Common Pitfalls

### Integer Division
```cpp
❌ int result = 5 / 2;        // result = 2 (not 2.5)
✅ double result = 5.0 / 2;   // result = 2.5
```

### Assignment vs Comparison
```cpp
❌ if (a = 5)     // Assignment (always true if non-zero)
✅ if (a == 5)    // Comparison
```

### Modulus with Negative Numbers
```cpp
-5 % 3 = -2  // Result takes sign of dividend
5 % -3 = 2
```

### Post vs Pre Increment
```cpp
int a = 5;
int b = a++;  // b = 5, a = 6
int c = ++a;  // a = 7, c = 7
```

### Short-Circuit Evaluation
```cpp
// If first condition is false, second is not evaluated
if (ptr != NULL && *ptr == 5)  // Safe
if (*ptr == 5 && ptr != NULL)  // May crash!
```

### Bitwise vs Logical
```cpp
5 & 3   // Bitwise AND → 1 (0101 & 0011 = 0001)
5 && 3  // Logical AND → 1 (true && true = true)
```

## Quick Reference

### Operator Categories
```cpp
// Arithmetic
+ - * / %

// Relational  
== != > < >= <=

// Logical
&& || !

// Bitwise
& | ^ ~ << >>

// Assignment
= += -= *= /= %=

// Other
++ -- ?: sizeof &
```

### Useful Patterns

**Even/Odd Check:**
```cpp
if (n % 2 == 0)  // Even
if (n % 2 != 0)  // Odd
```

**Swap Using XOR:**
```cpp
a ^= b;
b ^= a;
a ^= b;
```

**Power of 2:**
```cpp
n << 1  // n * 2
n << 2  // n * 4
n >> 1  // n / 2
```

**Ternary for Max/Min:**
```cpp
max = (a > b) ? a : b;
min = (a < b) ? a : b;
```

---

**Learning Path:** operators1.cpp → operators2.cpp → operators3.cpp → operators4.cpp → operators5.cpp

---

**Happy Coding! 🚀**
