# CONDITIONALS

C++ programs demonstrating conditional statements and decision-making logic.

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
- [Key Concepts](#key-concepts)
- [Common Patterns](#common-patterns)

## Overview

Thirteen programs covering if-else, nested if-else, switch-case, ternary operators, and logical operators for decision-making.

## Programs

### 1. oddEven.cpp - Basic If-Else
Checks if a number is odd or even.

**Logic:** `num % 2 == 0` → Even, else → Odd

**Learns:** Simple if-else, modulus operator for even/odd check

---

### 2. score.cpp - If-Else-If Ladder
Categorizes performance based on score ranges.

**Conditions:**
- Score > 80 → "Well done!"
- Score 50-80 → "Can improve"
- Score < 50 → "Poor performance"

**Learns:** Multiple conditions with if-else-if-else

---

### 3. agegroup.cpp - Age Classification
Divides people into age groups.

**Categories:**
- Age < 12 → Child
- Age 12-18 → Teenager
- Age > 18 → Adult

**Learns:** Range-based conditions, logical comparisons

---

### 4. divisibleBy3.cpp - Logical AND
Prints number if even AND divisible by 3.

**Condition:** `(num % 2 == 0) && (num % 3 == 0)`

**Learns:** AND operator (`&&`), multiple conditions

---

### 5. divisibleBy3or5.cpp - Logical OR
Prints number if divisible by 3 OR 5.

**Condition:** `(num % 3 == 0) || (num % 5 == 0)`

**Learns:** OR operator (`||`), alternative conditions

---

### 6. maximum.cpp - Finding Maximum
Finds maximum of three numbers using if-else.

**Logic:** Compares all three with logical AND

**Learns:** Multiple comparisons, logical AND in conditions

---

### 7. maximum2.cpp - Nested If-Else
Finds maximum using nested if-else statements.

**Logic:** Hierarchical comparisons

**Learns:** Nested conditionals, decision trees

---

### 8. profitLoss.cpp - Profit/Loss Calculator
Calculates profit or loss based on cost and selling price.

**Logic:**
- SP > CP → Profit = SP - CP
- CP > SP → Loss = CP - SP
- SP == CP → No profit/loss

**Learns:** Real-world application, variable scope in blocks

---

### 9. switch.cpp - Switch Statement
Prints day name based on day number (1-7).

**Example:**
```
Input: 1 → Monday
Input: 5 → Friday
Input: 8 → Invalid Number
```

**Learns:** Switch-case, break statements, default case

---

### 10. calculator.cpp - Calculator with Switch
Performs arithmetic operations based on operator input.

**Operations:** `+`, `-`, `*`, `/`, `%`

**Features:**
- Division by zero check
- Modulo by zero check
- Invalid operator handling

**Learns:** Switch with char, error handling, break statements

---

### 11. vowel.cpp / vowels.cpp - Vowel Checker
Checks if alphabet is vowel or consonant.

**Vowels:** a, e, i, o, u

**Learns:** Switch with characters, multiple cases with same output

---

### 12. ternaryoperator.cpp - Ternary Operator
Compares if-else with ternary operator for pass/fail check.

**Syntax:** `condition ? true_value : false_value`

**Example:** `marks > 33 ? "Pass" : "Fail"`

**Learns:** Ternary operator, concise conditional expressions

---

## Key Concepts

### If Statement
```cpp
if (condition) {
    // Code executes if condition is true
}
```

### If-Else Statement
```cpp
if (condition) {
    // Executes if true
} else {
    // Executes if false
}
```

### If-Else-If Ladder
```cpp
if (condition1) {
    // Code block 1
} else if (condition2) {
    // Code block 2
} else if (condition3) {
    // Code block 3
} else {
    // Default code block
}
```

### Nested If-Else
```cpp
if (condition1) {
    if (condition2) {
        // Nested condition
    }
} else {
    if (condition3) {
        // Another nested condition
    }
}
```

### Switch Statement
```cpp
switch (variable) {
    case value1:
        // Code
        break;
    case value2:
        // Code
        break;
    default:
        // Default code
}
```

**Important:** Always use `break` to prevent fall-through!

### Ternary Operator
```cpp
result = (condition) ? value_if_true : value_if_false;

// Example
int max = (a > b) ? a : b;
```

### Logical Operators in Conditions
```cpp
// AND - Both must be true
if (a > 0 && b > 0) { }

// OR - At least one must be true
if (a > 0 || b > 0) { }

// NOT - Inverts condition
if (!(a > 0)) { }
```

## Common Patterns

### Even/Odd Check
```cpp
if (num % 2 == 0) {
    cout << "Even";
} else {
    cout << "Odd";
}
```

### Range Check
```cpp
if (score >= 90) {
    cout << "A Grade";
} else if (score >= 80) {
    cout << "B Grade";
} else if (score >= 70) {
    cout << "C Grade";
} else {
    cout << "Fail";
}
```

### Multiple Conditions
```cpp
// Both conditions must be true
if (age >= 18 && hasLicense) {
    cout << "Can drive";
}

// At least one condition must be true
if (day == "Saturday" || day == "Sunday") {
    cout << "Weekend";
}
```

### Switch with Multiple Cases
```cpp
switch (day) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        cout << "Weekday";
        break;
    case 6:
    case 7:
        cout << "Weekend";
        break;
}
```

### Error Handling
```cpp
if (denominator != 0) {
    result = numerator / denominator;
} else {
    cout << "Error: Division by zero!";
}
```

## Decision-Making Flowchart

```
Input → Condition Check → True → Execute Code Block 1
                       ↓
                      False → Execute Code Block 2
```

## When to Use What?

| Scenario | Use |
|----------|-----|
| Two choices | if-else |
| Multiple ranges | if-else-if ladder |
| Single value matching | switch-case |
| Simple condition | Ternary operator |
| Complex nested logic | Nested if-else |
| Character/Integer matching | switch-case |

## Common Mistakes

### Missing Break in Switch
```cpp
❌ switch (day) {
    case 1:
        cout << "Monday";  // Falls through!
    case 2:
        cout << "Tuesday";
}

✅ switch (day) {
    case 1:
        cout << "Monday";
        break;  // Stops here
    case 2:
        cout << "Tuesday";
        break;
}
```

### Wrong Comparison Operator
```cpp
❌ if (a = 5)    // Assignment, not comparison
✅ if (a == 5)   // Comparison
```

### Incorrect Range Logic
```cpp
❌ if (age > 12 && age < 18)  // Doesn't include 12 and 18
✅ if (age >= 12 && age <= 18)  // Includes boundaries
```

### Unreachable Conditions
```cpp
❌ if (score > 50) {
    cout << "Pass";
} else if (score > 80) {  // Never reached!
    cout << "Excellent";
}

✅ if (score > 80) {
    cout << "Excellent";
} else if (score > 50) {
    cout << "Pass";
}
```

### Missing Default Case
```cpp
❌ switch (choice) {
    case 1: cout << "One"; break;
    case 2: cout << "Two"; break;
    // What if choice is 3?
}

✅ switch (choice) {
    case 1: cout << "One"; break;
    case 2: cout << "Two"; break;
    default: cout << "Invalid"; break;
}
```

## Quick Reference

### Comparison Operators
```cpp
==  // Equal to
!=  // Not equal to
>   // Greater than
<   // Less than
>=  // Greater than or equal to
<=  // Less than or equal to
```

### Logical Operators
```cpp
&&  // AND
||  // OR
!   // NOT
```

### Operator Precedence in Conditions
```cpp
!    // NOT (highest)
&&   // AND
||   // OR (lowest)

// Use parentheses for clarity
if ((a > 0) && (b > 0)) { }
```

---

**Learning Path:** oddEven.cpp → score.cpp → agegroup.cpp → divisibleBy3.cpp → divisibleBy3or5.cpp → maximum.cpp → maximum2.cpp → profitLoss.cpp → switch.cpp → calculator.cpp → vowel.cpp → ternaryoperator.cpp
