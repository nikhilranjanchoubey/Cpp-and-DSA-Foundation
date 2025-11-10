# PATTERN PRINTING

Programs demonstrating nested loops through various pattern printing problems and mathematical computations.

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
  - [Mathematical Problems](#mathematical-problems)
  - [Star Patterns](#star-patterns)
  - [Numerical Patterns](#numerical-patterns)
  - [Advanced Patterns](#advanced-patterns)
- [Key Concepts](#key-concepts)
- [Pattern Logic](#pattern-logic)
- [Common Patterns](#common-patterns)

## Overview

Programs covering mathematical problems, star patterns, numerical patterns, and advanced designs using nested loops.

## Programs

### Mathematical Problems

#### 1. digits.cpp - Count Digits
Counts the number of digits in a number.

**Example:** Input: 12345 → Output: 5 digits

**Logic:** Divide by 10 until number becomes 0

---

#### 2. sumDigits.cpp - Sum of Digits
Finds sum and count of digits.

**Example:** Input: 123 → Digits: 3, Sum: 6

**Logic:** Extract last digit using `%10`, add to sum, divide by 10

---

#### 3. reverseDigits.cpp - Reverse Number
Reverses the digits of a number.

**Example:** Input: 1234 → Output: 4321

**Logic:** `reverse = reverse * 10 + lastdigit`

---

#### 4. factorial.cpp - Factorial
Calculates factorial of N.

**Example:** Input: 5 → Output: 120 (5×4×3×2×1)

**Logic:** Multiply all numbers from 1 to N

---

#### 5. power.cpp - Exponentiation
Calculates a^b (a raised to power b).

**Example:** Input: 2, 3 → Output: 8

**Logic:** Multiply base 'a' by itself 'b' times

---

#### 6. sumOfSeries.cpp - Alternating Sum
Finds sum of series: 1-2+3-4+...+n

**Example:** Input: 4 → Output: -2 (1-2+3-4)

**Logic:** Add if odd index, subtract if even

---

### Star Patterns

#### 7. rectangularPattern.cpp / starRectangle.cpp
Prints rectangular pattern of stars.

**Pattern (4×6):**
```
******
******
******
******
```

**Logic:** Nested loops - outer for rows, inner for columns

---

#### 8. triangularPattern.cpp - Right Triangle
Prints increasing triangle.

**Pattern (n=5):**
```
*
**
***
****
*****
```

**Logic:** Inner loop runs from 1 to i (current row)

---

#### 9. triangularPattern2.cpp - Inverted Triangle
Prints decreasing triangle.

**Pattern (n=5):**
```
*****
****
***
**
*
```

**Logic:** Outer loop decrements from n to 1

---

#### 10. triangularPattern3.cpp - Pyramid
Prints centered pyramid.

**Pattern (n=5):**
```
    *
   ***
  *****
 *******
*********
```

**Logic:** 
- Spaces: `(n-i)`
- Stars: `(2*i-1)`

---

#### 11. hollowRectangularPattern.cpp - Hollow Rectangle
Prints hollow rectangle with stars only on borders.

**Pattern (4×6):**
```
******
*    *
*    *
******
```

**Logic:** Print stars if first/last row OR first/last column

---

#### 12. starPlus.cpp - Plus Pattern
Prints plus (+) sign pattern.

**Pattern (5×5):**
```
  *
  *
*****
  *
  *
```

**Logic:** Print star if center row OR center column

---

### Numerical Patterns

#### 13. numericalPattern.cpp - Number Rectangle
Prints numbers in rectangular format.

**Pattern (n=3):**
```
123
123
123
```

**Logic:** Inner loop prints numbers 1 to n

---

#### 14. numericalTriangle.cpp - Number Triangle
Prints increasing number triangle.

**Pattern (n=5):**
```
1
12
123
1234
12345
```

**Logic:** Inner loop prints numbers 1 to i

---

#### 15. numericalPattern2.cpp - Checkerboard Pattern
Alternating 1 and 2 based on position sum.

**Pattern (4×5):**
```
12121
21212
12121
21212
```

**Logic:** Print 1 if `(i+j)` is even, else 2

---

#### 16. numericalRectangularPattern.cpp - Continuous Numbers
Numbers wrap around in each row.

**Pattern (n=4):**
```
1234
2341
3412
4123
```

**Logic:** First loop from i to n, then 1 to (i-1)

---

#### 17. hollowNumericalPattern.cpp - Hollow Number Rectangle
Border shows column numbers, inside is hollow.

**Pattern (4×6):**
```
123456
1    6
1    6
123456
```

**Logic:** Print column number on borders, space inside

---

#### 18. numericalPattern3.cpp - Palindrome Number Pyramid
Pyramid with palindromic numbers.

**Pattern (n=5):**
```
    1
   121
  12321
 1234321
123454321
```

**Logic:**
- Spaces: `(n-i)`
- Ascending: 1 to i
- Descending: (i-1) to 1

---

### Advanced Patterns

#### 19. alphabetDiamondPattern.cpp - Alphabet Diamond
Diamond pattern using alphabets.

**Pattern (n=5):**
```
    A
   ABC
  ABCDE
 ABCDEFG
ABCDEFGHI
 ABCDEFG
  ABCDE
   ABC
    A
```

**Logic:**
- Upper half: spaces decrease, chars increase
- Lower half: spaces increase, chars decrease
- Use `(char)('A' + j)` for alphabets

---

## Key Concepts

### Nested Loops Basics
```cpp
for(int i = 1; i <= rows; i++) {        // Outer loop - rows
    for(int j = 1; j <= cols; j++) {    // Inner loop - columns
        cout << "*";
    }
    cout << endl;                        // New line after each row
}
```

### Pattern Components

**1. Spaces (for alignment)**
```cpp
for(int k = 0; k < spaces; k++) {
    cout << " ";
}
```

**2. Stars/Characters**
```cpp
for(int j = 0; j < stars; j++) {
    cout << "*";
}
```

**3. Newline**
```cpp
cout << endl;  // Move to next line
```

### Number Manipulation Techniques

**Extract Last Digit:**
```cpp
int lastDigit = num % 10;
```

**Remove Last Digit:**
```cpp
num = num / 10;
```

**Build Number from Digits:**
```cpp
reverse = reverse * 10 + digit;
```

**Count Digits:**
```cpp
while(num > 0) {
    count++;
    num /= 10;
}
```

## Pattern Logic

### Rectangle Pattern
```cpp
for(int i = 1; i <= n; i++) {           // n rows
    for(int j = 1; j <= m; j++) {       // m columns
        cout << "*";
    }
    cout << endl;
}
```

### Right Triangle
```cpp
for(int i = 1; i <= n; i++) {           // n rows
    for(int j = 1; j <= i; j++) {       // i stars in row i
        cout << "*";
    }
    cout << endl;
}
```

### Inverted Triangle
```cpp
for(int i = n; i >= 1; i--) {           // n rows (decreasing)
    for(int j = 1; j <= i; j++) {       // i stars in row
        cout << "*";
    }
    cout << endl;
}
```

### Pyramid
```cpp
for(int i = 1; i <= n; i++) {
    // Print (n-i) spaces
    for(int j = 1; j <= n-i; j++) {
        cout << " ";
    }
    // Print (2*i-1) stars
    for(int j = 1; j <= 2*i-1; j++) {
        cout << "*";
    }
    cout << endl;
}
```

### Hollow Pattern Logic
```cpp
if(i == 1 || i == n || j == 1 || j == m) {
    cout << "*";  // Border
} else {
    cout << " ";  // Inside
}
```

### Diamond Pattern
```cpp
// Upper half (including middle)
for(int i = 1; i <= n; i++) {
    spaces, stars increasing
}

// Lower half (excluding middle)
for(int i = n+1; i <= 2*n-1; i++) {
    spaces, stars decreasing
}
```

## Common Patterns

### Formulas

| Pattern | Rows | Spaces | Characters |
|---------|------|--------|------------|
| Rectangle | n | 0 | m (constant) |
| Right Triangle | n | 0 | i |
| Inverted Triangle | n | 0 | (n-i+1) |
| Pyramid | n | (n-i) | (2*i-1) |
| Diamond Upper | n | (n-i) | (2*i-1) |
| Diamond Lower | n-1 | i | (2*(n-i)-1) |

### Character Generation

**Numbers:**
```cpp
cout << j;                    // Print j directly
cout << (i+j);                // Based on sum
```

**Alphabets:**
```cpp
char ch = 'A' + j;            // A, B, C, ...
cout << ch;
```

**Alternating:**
```cpp
if((i+j) % 2 == 0) 
    cout << "1";
else 
    cout << "2";
```

## Quick Reference

### Essential Loop Patterns

**Fixed columns:**
```cpp
for(int j = 1; j <= n; j++)
```

**Increasing columns:**
```cpp
for(int j = 1; j <= i; j++)
```

**Decreasing columns:**
```cpp
for(int j = i; j >= 1; j--)
```

**Spaces for alignment:**
```cpp
for(int j = 1; j <= n-i; j++)
```

**Odd number sequence:**
```cpp
for(int j = 1; j <= 2*i-1; j++)
```

### Common Calculations

```cpp
// Last digit
digit = num % 10

// Remove last digit  
num = num / 10

// Reverse
rev = rev * 10 + digit

// Count digits
while(num > 0) { count++; num /= 10; }

// Sum of digits
while(num > 0) { sum += num % 10; num /= 10; }

// Factorial
fact = 1
for(i = 1 to n) { fact *= i }

// Power
pow = 1
for(i = 1 to exp) { pow *= base }
```

### Pattern Debugging Tips

1. **Print row and column indices** to understand loop flow
2. **Start with simple rectangle** before complex patterns
3. **Draw pattern on paper** with row/column numbers
4. **Identify spaces and characters separately**
5. **Test with small values** (n=3 or n=4)

---

**Learning Path:** 
1. Mathematical problems (digits → sum → reverse → factorial → power)
2. Basic patterns (rectangle → triangle → inverted)
3. Hollow patterns (hollow rectangle → plus)
4. Number patterns (simple → checkerboard → palindrome)
5. Advanced patterns (pyramid → diamond)

---

**Happy Coding! 🚀**
