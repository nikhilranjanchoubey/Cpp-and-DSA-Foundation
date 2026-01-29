# Linked List 

A comprehensive collection of **C++ programs** covering fundamental to advanced linked list operations, algorithms, and problem-solving patterns.

---

## 📚 Table of Contents

1. [Overview](#overview)
2. [Programs by Category](#programs-by-category)
3. [Key Patterns & Techniques](#key-patterns--techniques)
4. [Program Details](#program-details)
6. [Learning Path](#learning-path)

---

## Overview

This folder contains a complete set of linked list implementations in C++, organized to help you master:
- **Basic Operations**: Creation, insertion, deletion, traversal
- **Advanced Algorithms**: Cycle detection, palindrome checking, list merging
- **Problem-Solving Patterns**: Two-pointer technique, recursion, dummy nodes
- **Real-World Applications**: Data manipulation, sorting, and optimization

All programs are implemented using a consistent `Node` and `LinkedList` class structure for easy understanding and modification.

---

## Programs by Category

### 🔨 Basic Operations
| Program | Description | Key Concepts |
|---------|-------------|--------------|
| `singlyLinkedList.cpp` | Basic node implementation | Node structure, memory allocation |
| `InsertionAndDeletioninSinglyLinkedList.cpp` | Complete CRUD operations | Insert/delete at head/tail/position |

### 🔄 List Reversal
| Program | Description | Algorithm |
|---------|-------------|-----------|
| `reverseTheList.cpp` | Reverse entire list | Iterative & recursive approaches |
| `reverseKtimes.cpp` | Reverse in groups of k | Recursive group reversal |
| `printTheReversedList.cpp` | Print list in reverse | Recursive traversal |

### 🧹 List Modification
| Program | Description | Pattern |
|---------|-------------|---------|
| `alternateDeletion.cpp` | Delete every alternate node | Skip-pointer technique |
| `deletingDuplicateElements.cpp` | Remove duplicates from sorted list | Sequential comparison |
| `removeKthNode.cpp` | Remove kth node from end | Two-pointer technique |
| `swapEveryTwoAdjacentNodes.cpp` | Swap adjacent pairs | Recursive pointer manipulation |

### 🔍 Detection & Validation
| Program | Description | Algorithm |
|---------|-------------|-----------|
| `cycle.cpp` | Detect and remove cycles | Floyd's Cycle Detection |
| `palindromeOrNot.cpp` | Check if list is palindrome | Middle finding + reversal |
| `EqualOrNot.cpp` | Compare two lists | Two-pointer comparison |
| `intersectNode.cpp` | Find intersection of two lists | Length calculation + alignment |

### 🔢 List Analysis
| Program | Description | Technique |
|---------|-------------|-----------|
| `middleElementofLL.cpp` | Find middle element | Slow-fast pointer |

### 🔀 List Rearrangement
| Program | Description | Approach |
|---------|-------------|----------|
| `oddEvenReorderedList.cpp` | Group odd/even indices | Two-list separation |
| `rearrangementOfNodes.cpp` | Rotate list by k positions | Circular connection |
| `reorderList.cpp` | Reorder as L0→Ln→L1→Ln-1 | Middle + reverse + merge |

### 🔗 List Merging
| Program | Description | Complexity |
|---------|-------------|------------|
| `mergeLinkedList.cpp` | Merge two sorted lists | O(n+m) |
| `mergingMultipleLinkedList.cpp` | Merge k sorted lists | Pairwise merging |

---

## Key Patterns & Techniques

### 1. **Two-Pointer Technique**
Used in: `EqualOrNot.cpp`, `removeKthNode.cpp`, `middleElementofLL.cpp`

**Slow-Fast Pointer** (Floyd's Algorithm):
```cpp
Node* slow = head;
Node* fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
// slow now points to middle
```

**Gap-Based Two Pointers**:
```cpp
// Move ptr2 k steps ahead
for(int i = 0; i < k; i++) ptr2 = ptr2->next;
// Move both until ptr2 reaches end
while(ptr2->next) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
}
```

### 2. **Dummy Node Pattern**
Used in: `mergeLinkedList.cpp`, `mergingMultipleLinkedList.cpp`

```cpp
Node* dummyHead = new Node(-1);
Node* current = dummyHead;
// Build new list
current->next = someNode;
return dummyHead->next; // Skip dummy
```

### 3. **Iterative Reversal**
Used in: `reverseTheList.cpp`, `palindromeOrNot.cpp`

```cpp
Node* prev = NULL;
Node* curr = head;
while(curr) {
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
return prev; // new head
```

### 4. **Recursive Reversal**
Used in: `reverseTheList.cpp`, `reverseKtimes.cpp`

```cpp
Node* reverseRecursive(Node* head) {
    if(!head || !head->next) return head;
    Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
```

### 5. **Floyd's Cycle Detection**
Used in: `cycle.cpp`

**Detection**:
```cpp
Node* slow = head;
Node* fast = head;
while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) return true; // Cycle found
}
return false;
```

**Removal**:
```cpp
// After detection, reset one pointer to head
fast = head;
while(slow->next != fast->next) {
    slow = slow->next;
    fast = fast->next;
}
slow->next = NULL; // Break cycle
```

---

## Program Details

### Basic Operations

#### `singlyLinkedList.cpp`
**Purpose**: Introduction to node structure  
**Key Concept**: Basic building block of linked lists
```cpp
class Node {
public:
    int val;
    Node* next;
    Node(int data) { val = data; next = NULL; }
};
```

#### `InsertionAndDeletioninSinglyLinkedList.cpp`
**Purpose**: Complete CRUD operations  
**Operations**:
- Insert at head: O(1)
- Insert at tail: O(n)
- Insert at position: O(n)
- Update at position: O(n)
- Delete at head: O(1)
- Delete at tail: O(n)
- Delete at position: O(n)

---

### List Reversal

#### `reverseTheList.cpp`
**Purpose**: Reverse entire linked list  
**Approaches**:
1. **Iterative**: Time O(n), Space O(1)
2. **Recursive**: Time O(n), Space O(n) for call stack

**Use Cases**: Data reversal, backtracking problems

#### `reverseKtimes.cpp`
**Purpose**: Reverse nodes in groups of k  
**Example**: `1→2→3→4→5→6` with k=2 becomes `2→1→4→3→6→5`  
**Complexity**: Time O(n), Space O(n/k) for recursion

#### `printTheReversedList.cpp`
**Purpose**: Display list in reverse without modifying it  
**Technique**: Recursive traversal reaches end, then prints on return path  
**Use Case**: Preview reversal without actual modification

---

### List Modification

#### `alternateDeletion.cpp`
**Purpose**: Delete every 2nd element  
**Example**: `1→2→3→4→5→6` becomes `1→3→5`  
**Pattern**: Skip one, delete one
```cpp
curr->next = curr->next->next; // Skip deletion node
curr = curr->next; // Move to next kept node
```

#### `deletingDuplicateElements.cpp`
**Purpose**: Remove duplicates from sorted list  
**Example**: `1→1→2→3→3→4` becomes `1→2→3→4`  
**Requirement**: List must be sorted  
**Complexity**: O(n) single pass

#### `removeKthNode.cpp`
**Purpose**: Remove kth node from end  
**Pattern**: Two-pointer with k-step gap  
**Edge Case**: Handles k = length (delete head)

#### `swapEveryTwoAdjacentNodes.cpp`
**Purpose**: Swap adjacent pairs  
**Example**: `1→2→3→4→5→6` becomes `2→1→4→3→6→5`  
**Approach**: Recursive pointer manipulation  
**Constraint**: Only node pointers changed, not values

---

### Detection & Validation

#### `cycle.cpp`
**Purpose**: Detect and remove cycles using Floyd's algorithm  
**Components**:
1. `detectCycle()`: Returns true if cycle exists
2. `removeCycle()`: Breaks the cycle

**How it works**:
- Slow pointer moves 1 step, fast moves 2 steps
- If they meet, cycle exists
- To remove: Find cycle start and break link

**Application**: Preventing infinite loops, data structure validation

#### `palindromeOrNot.cpp`
**Purpose**: Check if list is palindrome  
**Algorithm**:
1. Find middle using slow-fast pointers
2. Reverse second half
3. Compare both halves
4. Return true if equal

**Example**: `1→2→3→3→2→1` returns true  
**Complexity**: Time O(n), Space O(1)

#### `EqualOrNot.cpp`
**Purpose**: Compare two linked lists for equality  
**Checks**:
- Same length
- Same values in same order

**Pattern**: Simultaneous traversal with early termination

#### `intersectNode.cpp`
**Purpose**: Find intersection point of two lists  
**Method**:
1. Calculate lengths of both lists
2. Align pointers by moving longer list's pointer ahead
3. Move both simultaneously until they meet

**Example**:
```
List1: 1→2→3→4→5
List2: 6→7→4→5  (intersects at 4)
```

---

### List Analysis

#### `middleElementofLL.cpp`
**Purpose**: Find middle element efficiently  
**Pattern**: Slow-fast pointer  
**Behavior**:
- Odd length: Returns exact middle
- Even length: Returns second of two middles

**Example**: `1→2→3→4→5` returns 3

---

### List Rearrangement

#### `oddEvenReorderedList.cpp`
**Purpose**: Group nodes by index parity  
**Example**: `1→2→3→4→5→6` becomes `1→3→5→2→4→6`  
**Pattern**: Maintain two separate lists, then connect

```cpp
oddPtr->next = oddPtr->next->next;   // Skip even
evenPtr->next = evenPtr->next->next; // Skip odd
```

#### `rearrangementOfNodes.cpp`
**Purpose**: Rotate list right by k positions  
**Example**: `1→2→3→4→5→6` rotated by 3 becomes `4→5→6→1→2→3`  
**Algorithm**:
1. Find length n and tail
2. Connect tail to head (make circular)
3. Find (n-k)th node
4. Break link, return (n-k+1)th as new head

**Optimization**: `k = k % n` to handle k > n

#### `reorderList.cpp`
**Purpose**: Alternate nodes from start and end  
**Example**: `1→2→3→4→5→6` becomes `1→6→2→5→3→4`  
**Algorithm**:
1. Find middle
2. Reverse second half
3. Merge alternately

**Complexity**: O(n) time, O(1) space

---

### List Merging

#### `mergeLinkedList.cpp`
**Purpose**: Merge two sorted lists into one sorted list  
**Pattern**: Dummy node + comparison  
**Complexity**: O(n+m) time, O(1) space

```cpp
if(ptr1->val < ptr2->val) {
    result->next = ptr1;
    ptr1 = ptr1->next;
} else {
    result->next = ptr2;
    ptr2 = ptr2->next;
}
```

#### `mergingMultipleLinkedList.cpp`
**Purpose**: Merge k sorted lists  
**Approach**: Pairwise merging  
**Process**:
1. Merge first two lists
2. Add result to end of vector
3. Remove original two
4. Repeat until one list remains

**Complexity**: O(N log k) where N = total nodes, k = number of lists

---


## Learning Path

1. `singlyLinkedList.cpp` - Understand node structure
2. `InsertionAndDeletioninSinglyLinkedList.cpp` - Master basic operations
3. `reverseTheList.cpp` - Learn iterative algorithms
4. `EqualOrNot.cpp` - Practice two-pointer technique
5. `deletingDuplicateElements.cpp` - Handle sorted data
6. `middleElementofLL.cpp` - Slow-fast pointer pattern
7. `removeKthNode.cpp` - Advanced two-pointer
8. `mergeLinkedList.cpp` - Dummy node technique
9. `alternateDeletion.cpp` - Skip patterns
10. `cycle.cpp` - Floyd's algorithm
11. `palindromeOrNot.cpp` - Multi-step algorithms
12. `reverseKtimes.cpp` - Complex recursion
13. `reorderList.cpp` - Combining multiple techniques
14. `rearrangementOfNodes.cpp` - Circular manipulation
15. `intersectNode.cpp` - Length-based alignment
16. `oddEvenReorderedList.cpp` - Multi-list management
17. `swapEveryTwoAdjacentNodes.cpp` - Recursive pointer tricks
18. `printTheReversedList.cpp` - Non-destructive recursion
19. `mergingMultipleLinkedList.cpp` - K-way merging

---

## Common Patterns Summary

| Pattern | Programs | Key Insight |
|---------|----------|-------------|
| **Two-Pointer** | 6 programs | Solve in one pass without extra space |
| **Recursion** | 5 programs | Elegant for reversal and traversal |
| **Dummy Node** | 2 programs | Simplifies edge cases in list building |
| **Slow-Fast** | 4 programs | Find middle, detect cycles efficiently |
| **Multi-Step** | 3 programs | Break complex problems into phases |

---

## Time Complexity Reference

| Operation | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| Insert at head | O(1) | O(1) | O(1) |
| Insert at tail | O(1)* | O(n) | O(n) |
| Delete at head | O(1) | O(1) | O(1) |
| Search | O(1) | O(n) | O(n) |
| Reverse | O(n) | O(n) | O(n) |
| Find middle | O(n) | O(n) | O(n) |
| Merge 2 lists | O(n+m) | O(n+m) | O(n+m) |
| Detect cycle | O(n) | O(n) | O(n) |

*With tail pointer maintained

---

## Space Complexity Reference

| Technique | Space Complexity | Notes |
|-----------|------------------|-------|
| Iterative algorithms | O(1) | Constant extra space |
| Recursive algorithms | O(n) | Call stack depth |
| Dummy node | O(1) | Single extra node |
| Multi-list storage | O(k) | k separate lists |

---

## Key Takeaways

1. **Pointer Manipulation**: Core skill for linked list mastery
2. **Edge Cases**: Always consider empty list, single node, two nodes
3. **Memory Management**: Use `delete` or `free()` to prevent leaks
4. **Pattern Recognition**: Most problems combine 2-3 basic patterns
5. **Practice Visualization**: Draw diagrams for complex pointer operations

---

**Happy Coding! 🚀**