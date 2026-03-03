# Stack Data Structure 

A comprehensive collection of Stack data structure implementations and applications.

## Table of Contents

- [Introduction](#introduction)
- [Stack Implementations](#stack-implementations)
- [Basic Operations](#basic-operations)
- [Expression Evaluation](#expression-evaluation)
- [Array Problems](#array-problems)
- [Bracket Problems](#bracket-problems)
- [Advanced Problems](#advanced-problems)
- [Complexity Analysis](#complexity-analysis)

## Introduction

A **Stack** is a linear data structure that follows the **LIFO (Last In First Out)** principle.

### Key Operations
- **Push**: Add element to top - O(1)
- **Pop**: Remove top element - O(1)
- **Top/Peek**: View top element - O(1)
- **isEmpty**: Check if empty - O(1)

## Stack Implementations

### 1. Stack Using Arrays
**File:** `stacksUsingArrays.cpp`

Fixed-size stack implementation using arrays.

**Features:**
- Fixed capacity
- Overflow/Underflow handling
- All operations in O(1)

**Methods:**
```cpp
void push(int data)
int pop()
int getTop()
bool isEmpty()
bool isFull()
int size()
```

### 2. Stack Using Linked List
**File:** `stackUsingLinkedList.cpp`

Dynamic stack using linked nodes.

**Features:**
- Dynamic sizing
- No fixed capacity limit
- All operations in O(1)

### 3. Stack STL
**File:** `stackSTL.cpp`

Using C++ Standard Template Library.

**STL Methods:**
```cpp
push(), pop(), top(), empty(), size()
```

## Basic Operations

### 4. Insert at Bottom
**File:** `insertAtBottom.cpp`

Insert element at the bottom of stack.

**Approaches:**
1. **Iterative**: Using temporary stack - O(n) time, O(n) space
2. **Recursive**: Using call stack - O(n) time, O(n) space

### 5. Insert at Any Index
**File:** `insertAtAnyIndex.cpp`

Insert element at specified index.

**Time:** O(n) | **Space:** O(n)

### 6. Remove from Bottom
**File:** `removeFromBottom.cpp`

Remove the bottom element using recursion.

**Time:** O(n) | **Space:** O(n)

### 7. Remove at Any Index
**File:** `removeAtAnyIndex.cpp`

Remove element at specific index.

**Time:** O(n) | **Space:** O(n)

### 8. Copy Stack
**File:** `copyStack.cpp`

Copy one stack to another maintaining order.

**Approaches:**
1. Iterative with two temp stacks
2. Recursive approach

**Time:** O(n) | **Space:** O(n)

### 9. Reverse Stack
**File:** `reverseStack.cpp`

Reverse all elements in stack.

**Approaches:**
1. Iterative: Two additional stacks - O(n) time
2. Recursive: Using insertAtBottom - O(n²) time

## Expression Evaluation

### 10. Evaluate Postfix
**File:** `evaluatePostfixExpression.cpp`

Evaluate Reverse Polish Notation.

**Example:** `231*+9-` evaluates to `-4`

**Algorithm:**
1. Scan left to right
2. Push operands to stack
3. For operators: pop two operands, compute, push result

**Time:** O(n) | **Space:** O(n)

### 11. Evaluate Prefix
**File:** `evaluatePrefixExpression.cpp`

Evaluate Polish Notation.

**Example:** `-+2*319` evaluates to `-4`

**Algorithm:**
1. Scan **right to left**
2. Push operands to stack
3. For operators: pop two operands, compute, push result

**Time:** O(n) | **Space:** O(n)

### 12. Evaluate Infix
**File:** `evaluateInfixExpression.cpp`

Evaluate standard notation with precedence.

**Example:** `1+(2*(3-1))+2` = `7`

**Features:**
- Handles operator precedence: `^` > `*, /` > `+, -`
- Parentheses support
- Two stacks: numbers and operators

**Time:** O(n) | **Space:** O(n)

### 13. Convert Prefix to Postfix
**File:** `convertPrefixToPostfix.cpp`

Convert prefix to postfix notation.

**Example:** `*+31-15` → `31+15-*`

**Time:** O(n) | **Space:** O(n)

## Array Problems

### 14. Next Greater Element - NGE
**File:** `nextGreaterElement.cpp`

Find next greater element to the right for each element.

**Example:**
```
Input:  [4, 5, 2, 10, 8]
Output: [5, 10, 10, -1, -1]
```

**Algorithm:** Monotonic stack storing indices

**Time:** O(n) | **Space:** O(n)

### 15. Next Smaller Element - NSE
**File:** `nextSmallerElements.cpp`

Find next smaller element to the right.

**Example:**
```
Input:  [4, 5, 2, 10, 8]
Output: [2, 2, -1, 8, -1]
```

**Time:** O(n) | **Space:** O(n)

### 16. Previous Greater Element - PGE
**File:** `prevGreaterElements.cpp`

Find previous greater element to the left.

**Example:**
```
Input:  [4, 5, 2, 10, 8]
Output: [-1, -1, 5, -1, 10]
```

**Time:** O(n) | **Space:** O(n)

### 17. Previous Smaller Element - PSE
**File:** `prevSmallerElements.cpp`

Find previous smaller element to the left.

**Example:**
```
Input:  [4, 5, 2, 10, 8]
Output: [-1, 4, -1, 2, 2]
```

**Time:** O(n) | **Space:** O(n)

### 18. Stock Span Problem
**File:** `stockSpan.cpp`

Calculate consecutive days where price was less than or equal to current.

**Example:**
```
Input:  [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]
```

**Algorithm:** Based on previous greater element

**Time:** O(n) | **Space:** O(n)

## Bracket Problems

### 19. Balanced Bracket Sequence
**File:** `balancedBracketSequence.cpp`

Check if brackets are properly matched: `()`, `{}`, `[]`

**Examples:**
- `[({})()[](({}))]` → Valid ✓
- `[({)}]` → Invalid ✗

**Algorithm:**
1. Push opening brackets
2. Match closing with stack top
3. Stack empty at end = balanced

**Time:** O(n) | **Space:** O(n)

### 20. Minimum Brackets Removal
**File:** `minimumBracketsRemoval.cpp`

Find minimum brackets to remove for balance.

**Example:**
```
Input: "())(()"`
Output: 2
```

**Algorithm:** Stack size after matching = unmatched brackets

**Time:** O(n) | **Space:** O(n)

## Advanced Problems

### 21. Largest Rectangle in Histogram
**File:** `largestRectangleinHistogram.cpp`

Find maximum rectangular area in histogram.

**Example:**
```
Input:  [2, 1, 5, 6, 2, 3]
Output: 10 (height 5, width 2)
```

**Algorithm:**
1. For each bar find:
   - Previous Smaller Index (PSI)
   - Next Smaller Index (NSI)
2. Area = height × (NSI - PSI - 1)
3. Use stack for efficient PSI/NSI finding

**Time:** O(n) | **Space:** O(n)

### 22. MinStack
**File:** `minStack.cpp`

Stack with O(1) minimum retrieval.

**Implementation:** Two parallel stacks
- Main stack: normal operations
- Min stack: tracks current minimum

**Operations:**
```cpp
void push(int val)    // O(1)
void pop()            // O(1)
int top()             // O(1)
int getMin()          // O(1)
```

## Complexity Analysis

| Operation/Problem | Time | Space |
|-------------------|------|-------|
| Basic Stack Ops | O(1) | O(1) |
| Insert/Remove at Index | O(n) | O(n) |
| Reverse (Recursive) | O(n²) | O(n) |
| Expression Evaluation | O(n) | O(n) |
| NGE/NSE/PGE/PSE | O(n) | O(n) |
| Balanced Brackets | O(n) | O(n) |
| Largest Rectangle | O(n) | O(n) |
| Stock Span | O(n) | O(n) |
| MinStack All Ops | O(1) | O(n) |

## Program Categories

### Implementations (3 programs)
- Stack using Arrays
- Stack using Linked List
- Stack STL

### Basic Operations (6 programs)
- Insert at Bottom/Any Index
- Remove from Bottom/Any Index
- Copy Stack
- Reverse Stack

### Expression Evaluation (4 programs)
- Evaluate Postfix
- Evaluate Prefix
- Evaluate Infix
- Convert Prefix to Postfix

### Array Problems (5 programs)
- Next Greater Element
- Next Smaller Element
- Previous Greater Element
- Previous Smaller Element
- Stock Span Problem

### Bracket Problems (2 programs)
- Balanced Bracket Sequence
- Minimum Brackets Removal

### Advanced Problems (2 programs)
- Largest Rectangle in Histogram
- MinStack (Get Min in O(1))

## Key Concepts

### When to Use Stack?

1. **Expression Evaluation** - Infix, Prefix, Postfix
2. **Parentheses Matching** - Balanced brackets
3. **Monotonic Stack Problems** - NGE, NSE, PGE, PSE
4. **Histogram Problems** - Largest rectangle
5. **Backtracking** - DFS, maze solving
6. **Undo/Redo** - Text editors, browsers
7. **Function Calls** - Call stack simulation

### Common Patterns

**1. Monotonic Stack**
- Used in: NGE, NSE, PGE, PSE, Stock Span
- Maintains elements in increasing/decreasing order
- O(n) time for finding next/previous greater/smaller

**2. Two Stacks**
- Used in: MinStack, Expression evaluation
- One for main operations
- One for auxiliary info (min values, operators)

**3. Recursion + Stack**
- Used in: Reverse stack, Insert at bottom
- Recursion implicitly uses call stack
- Can achieve complex transformations

**4. Stack + Other Data Structures**
- Used in: Balanced brackets, Histogram
- Combines stack with arrays/strings
- Efficient problem solving

---

Happy Coding! 🚀