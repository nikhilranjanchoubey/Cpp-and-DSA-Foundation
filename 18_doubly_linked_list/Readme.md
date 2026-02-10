# Doubly Linked List

A comprehensive collection of **C++ programs** covering fundamental to advanced doubly linked list operations, algorithms, and problem-solving patterns.

---

## 📚 Table of Contents

1. [Overview](#overview)
2. [Programs by Category](#programs-by-category)
3. [Key Patterns & Techniques](#key-patterns--techniques)
4. [Program Details](#program-details)
5. [Learning Path](#learning-path)
6. [Comparison with Singly Linked Lists](#comparison-with-singly-linked-lists)

---

## Overview

This folder contains a complete set of doubly linked list implementations in C++, organized to help you master:
- **Basic Operations**: Creation, insertion, deletion, bidirectional traversal
- **Advanced Algorithms**: Two-pointer techniques, palindrome checking, critical point detection
- **Problem-Solving Patterns**: Two-way traversal, reverse iteration, neighbor comparison
- **Real-World Applications**: Data manipulation with backward navigation capability

All programs are implemented using a consistent `Node` and `DoublyLinkedList` class structure with both `head` and `tail` pointers for efficient operations.

---

## Programs by Category

### 🔨 Basic Operations
| Program | Description | Key Concepts |
|---------|-------------|--------------|
| `doubleLinkedList.cpp` | Complete DLL implementation | Node structure with prev/next, bidirectional links |

**Operations Covered**:
- Insert at start: O(1)
- Insert at end: O(1) with tail pointer
- Insert at position: O(n)
- Delete at start: O(1)
- Delete at end: O(1) with tail pointer
- Delete at position: O(n)
- Display: O(n)

### 🔄 List Reversal
| Program | Description | Algorithm |
|---------|-------------|-----------|
| `reverse.cpp` | Reverse entire doubly linked list | Swap prev/next pointers + swap head/tail |

### 🔍 Detection & Validation
| Program | Description | Pattern |
|---------|-------------|---------|
| `palindrome.cpp` | Check if DLL is palindrome | Two-pointer from both ends |
| `pairSum.cpp` | Find pair with target sum | Two-pointer in sorted list |

### 🔢 List Analysis
| Program | Description | Technique |
|---------|-------------|-----------|
| `criticalPoints.cpp` | Find min/max distance between critical points | Local maxima/minima detection |

### 🧹 List Modification
| Program | Description | Pattern |
|---------|-------------|---------|
| `traverse.cpp` | Delete nodes with same neighbors | Reverse traversal + neighbor comparison |

---

## Key Patterns & Techniques

### 1. **Doubly Linked List Node Structure**
The fundamental building block with bidirectional pointers:

```cpp
class Node {
public:
    int val;
    Node* prev;  // Points to previous node
    Node* next;  // Points to next node
    
    Node(int data) {
        val = data;
        prev = NULL;
        next = NULL;
    }
};
```

### 2. **Two-Pointer from Both Ends**
Used in: `palindrome.cpp`, `pairSum.cpp`

**Pattern**: Start from head and tail, move towards center
```cpp
Node* left = head;
Node* right = tail;

while (left != right && right != left->prev) {
    // Process nodes
    if (condition) {
        left = left->next;
        right = right->prev;
    }
}
```

**Advantages**:
- O(n/2) comparisons instead of O(n²)
- No need for reversal in palindrome checking
- Efficient for sorted list operations

### 3. **Bidirectional Insertion**
Used in: `doubleLinkedList.cpp`

**Insert at End** (with tail pointer):
```cpp
void insertAtEnd(int val) {
    Node* new_node = new Node(val);
    
    if (tail == NULL) {
        head = tail = new_node;
        return;
    }
    
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
}
```

**Insert at Start**:
```cpp
void insertAtStart(int val) {
    Node* new_node = new Node(val);
    
    if (head == NULL) {
        head = tail = new_node;
        return;
    }
    
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}
```

**Insert at Position**:
```cpp
void insertAtPosition(int val, int k) {
    Node* temp = head;
    int count = 1;
    
    while (count < (k - 1)) {
        temp = temp->next;
        count++;
    }
    
    Node* new_node = new Node(val);
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next->prev = new_node;
}
```

### 4. **Bidirectional Deletion**
Used in: `doubleLinkedList.cpp`, `traverse.cpp`

**Delete at Start**:
```cpp
void deleteAtStart() {
    if (head == NULL) return;
    
    Node* temp = head;
    head = head->next;
    
    if (head == NULL) {  // Only one node existed
        tail = NULL;
    } else {
        head->prev = NULL;
    }
    
    free(temp);
}
```

**Delete at End**:
```cpp
void deleteAtEnd() {
    if (head == NULL) return;
    
    Node* temp = tail;
    tail = tail->prev;
    
    if (tail == NULL) {  // Only one node existed
        head = NULL;
    } else {
        tail->next = NULL;
    }
    
    free(temp);
}
```

**Delete at Position**:
```cpp
void deleteAtPosition(int k) {
    Node* temp = head;
    int counter = 1;
    
    while (counter < k) {
        temp = temp->next;
        counter++;
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
```

### 5. **Reverse Traversal**
Used in: `traverse.cpp`, `criticalPoints.cpp`

**Pattern**: Start from tail and move backward
```cpp
Node* currNode = tail;

while (currNode != NULL) {
    // Process current node
    currNode = currNode->prev;  // Move backward
}
```

**Use Cases**:
- Processing from right to left
- Finding patterns that require reverse order
- Avoiding recursion for reverse operations

### 6. **Reversal by Pointer Swap**
Used in: `reverse.cpp`

**Algorithm**:
```cpp
void reverseDll(Node* &head, Node* &tail) {
    Node* currPtr = head;
    
    while (currPtr != NULL) {
        // Swap next and prev pointers
        Node* nextPtr = currPtr->next;
        currPtr->next = currPtr->prev;
        currPtr->prev = nextPtr;
        
        // Move to next node (previous before swap)
        currPtr = nextPtr;
    }
    
    // Swap head and tail
    Node* temp = head;
    head = tail;
    tail = temp;
}
```

**Key Insight**: Just swap the direction of pointers, then swap head/tail

---

## Program Details

### Basic Operations

#### `doubleLinkedList.cpp`
**Purpose**: Complete implementation of doubly linked list with all CRUD operations

**Class Structure**:
```cpp
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }
};
```

**Operations Implemented**:
1. **insertAtStart(int val)**: Add node at beginning - O(1)
2. **insertAtEnd(int val)**: Add node at end - O(1)
3. **insertAtPosition(int val, int k)**: Insert at kth position - O(k)
4. **deleteAtStart()**: Remove first node - O(1)
5. **deleteAtEnd()**: Remove last node - O(1)
6. **deleteAtPosition(int k)**: Remove kth node - O(k)
7. **display()**: Print all elements - O(n)

**Key Features**:
- Maintains both head and tail pointers
- O(1) insertion/deletion at both ends
- Bidirectional traversal capability

**Edge Cases Handled**:
- Empty list operations
- Single node list
- Boundary position insertions/deletions

---

### List Reversal

#### `reverse.cpp`
**Purpose**: Reverse the entire doubly linked list

**Algorithm**:
1. Traverse the list
2. For each node, swap its `next` and `prev` pointers
3. After loop, swap `head` and `tail` pointers

**Example**:
```
Original: 1 ⇄ 2 ⇄ 3 ⇄ 4
Reversed: 4 ⇄ 3 ⇄ 2 ⇄ 1
```

**Complexity**: 
- Time: O(n) - single pass
- Space: O(1) - in-place reversal

**Why Different from Singly Linked List**:
- No need for three pointers (prev, curr, next)
- Just swap the pointers at each node
- Simpler implementation due to prev pointer

**Code Flow**:
```cpp
// Step 1: Swap pointers for each node
while (currPtr != NULL) {
    swap(currPtr->next, currPtr->prev);
    currPtr = currPtr->prev;  // Move forward (using old next)
}

// Step 2: Swap head and tail
swap(head, tail);
```

---

### Detection & Validation

#### `palindrome.cpp`
**Purpose**: Check if doubly linked list is a palindrome

**Algorithm**:
1. Use two pointers: one at head, one at tail
2. Compare values and move inward
3. Stop when pointers meet or cross

**Example**:
```
List: 1 ⇄ 2 ⇄ 3 ⇄ 3 ⇄ 2 ⇄ 1
Result: true (is palindrome)

List: 1 ⇄ 2 ⇄ 3 ⇄ 4
Result: false (not palindrome)
```

**Complexity**:
- Time: O(n/2) = O(n)
- Space: O(1)

**Stopping Conditions**:
```cpp
while (head != tail && tail != head->prev) {
    if (head->val != tail->val) return false;
    head = head->next;
    tail = tail->prev;
}
return true;
```

**Why `tail != head->prev`?**
- For even-length lists: stops when pointers cross
- For odd-length lists: stops when they meet

**Advantage over Singly Linked List**:
- No need to reverse half the list
- More efficient: O(n/2) vs O(n)
- Simpler implementation

---

#### `pairSum.cpp`
**Purpose**: Find two nodes in a sorted DLL whose values sum to target `x`

**Algorithm**:
1. Use two pointers: head (left) and tail (right)
2. Calculate sum of current pair
3. If sum matches target, return the pair
4. If sum > target, move right pointer left (decrease sum)
5. If sum < target, move left pointer right (increase sum)

**Example**:
```
List: 2 ⇄ 5 ⇄ 6 ⇄ 8 ⇄ 10
Target: 11
Process:
- 2 + 10 = 12 (> 11) → move tail left
- 2 + 8 = 10 (< 11) → move head right
- 5 + 8 = 13 (> 11) → move tail left
- 5 + 6 = 11 (= 11) → Found!
Result: [5, 6]
```

**Complexity**:
- Time: O(n) - single pass from both ends
- Space: O(1)

**Code Pattern**:
```cpp
while (head != tail) {
    int sum = head->val + tail->val;
    
    if (sum == x) {
        return {head->val, tail->val};
    }
    
    if (sum > x) {
        tail = tail->prev;  // Need smaller sum
    } else {
        head = head->next;  // Need larger sum
    }
}
return {-1, -1};  // No pair found
```

**Prerequisite**: List must be sorted
**Returns**: First valid pair or [-1, -1] if no pair exists

---

### List Analysis

#### `criticalPoints.cpp`
**Purpose**: Find minimum and maximum distance between critical points

**Definition**:
- **Critical Point**: A node that is either:
  - **Local Maxima**: `prev->val < curr->val > next->val`
  - **Local Minima**: `prev->val > curr->val < next->val`

**Algorithm**:
1. Traverse from second-last node backward (tail->prev)
2. Check each node if it's a critical point
3. Track first and last critical point positions
4. Calculate min distance (consecutive CPs) and max distance (first to last)

**Example**:
```
List: 1 ⇄ 5 ⇄ 2 ⇄ 6 ⇄ 3
      ↑   ↑   ↑   ↑   ↑
      0   1   2   3   4  (positions)

Critical Points:
- Position 1 (value 5): Local maxima (1 < 5 > 2)
- Position 2 (value 2): Local minima (5 > 2 < 6)
- Position 3 (value 6): Local maxima (2 < 6 > 3)

Distances:
- Min: 1 (between consecutive CPs at positions 1-2 or 2-3)
- Max: 2 (between first CP at 1 and last CP at 3)

Result: [1, 2]
```

**Helper Function**:
```cpp
bool isCriticalPoint(Node* &currNode) {
    // Local maxima
    if (currNode->prev->val < currNode->val && 
        currNode->next->val < currNode->val) {
        return true;
    }
    
    // Local minima
    if (currNode->prev->val > currNode->val && 
        currNode->next->val > currNode->val) {
        return true;
    }
    
    return false;
}
```

**Complexity**:
- Time: O(n) - single backward traversal
- Space: O(1) - only tracking positions

**Edge Cases**:
- Less than 2 critical points → return [-1, -1]
- No critical points → return [-1, -1]
- List too short (< 3 nodes) → no critical points possible

**Why Traverse Backward?**
- Demonstrates DLL's bidirectional capability
- Could work forward too; choice is arbitrary

---

### List Modification

#### `traverse.cpp`
**Purpose**: Delete nodes whose left and right neighbors have the same value

**Algorithm**:
1. Start from second-last node (tail->prev)
2. Traverse backward toward head
3. For each node, check if prev->val == next->val
4. If yes, delete current node by updating pointers

**Example**:
```
Original: 2 ⇄ 1 ⇄ 1 ⇄ 2 ⇄ 1

Process (right to left):
1. Node 2 (middle): prev=1, next=1 → DELETE (neighbors same)
2. Node 1 (2nd): prev=1, next=2 → KEEP (neighbors different)
3. Node 1 (1st): Skip (will become head)

Result: 2 ⇄ 1 ⇄ 1
```

**Code Pattern**:
```cpp
Node* currNode = tail->prev;  // Start from second-last

while (currNode != head) {
    Node* prevNode = currNode->prev;
    Node* nextNode = currNode->next;
    
    if (prevNode->val == nextNode->val) {
        // Delete current node
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        free(currNode);
    }
    
    currNode = prevNode;  // Move backward
}
```

**Complexity**:
- Time: O(n)
- Space: O(1)

**Why Traverse Right to Left?**
- Demonstrates DLL's backward traversal
- Safer deletion pattern (moving against deletion direction)
- No need to worry about lost next pointer

**Important Notes**:
- Doesn't check head or tail (they don't have both neighbors)
- Assumes list has at least 3 nodes
- Memory properly freed with `free()`

---

## Learning Path
1. **`doubleLinkedList.cpp`** 
2. **`reverse.cpp`**
3. **`palindrome.cpp`**
4. **`pairSum.cpp`**
5. **`criticalPoints.cpp`**
6. **`traverse.cpp`** 

---

## Comparison with Singly Linked Lists

### Structural Differences

| Aspect | Singly Linked List | Doubly Linked List |
|--------|-------------------|-------------------|
| **Node Structure** | `val`, `next` | `val`, `prev`, `next` |
| **Memory per Node** | 8-12 bytes | 12-16 bytes |
| **Pointers Maintained** | `head` only | `head` and `tail` |
| **Traversal** | Forward only | Bidirectional |

### Operation Complexity Comparison

| Operation | Singly LL | Doubly LL | Advantage |
|-----------|-----------|-----------|-----------|
| Insert at head | O(1) | O(1) | Equal |
| Insert at tail | O(n) or O(1)* | O(1) | DLL (with tail) |
| Delete at head | O(1) | O(1) | Equal |
| Delete at tail | O(n) | O(1) | DLL (with tail) |
| Reverse | O(n), complex | O(n), simple | DLL (simpler code) |
| Find middle | O(n) | O(n) | Equal |
| Palindrome check | O(n), needs reversal | O(n/2), no reversal | DLL (faster) |

*With tail pointer maintained

### Memory Trade-offs

**Doubly Linked List**:
- **Pros**: 
  - Faster tail operations
  - Bidirectional traversal
  - Simpler deletion (have prev pointer)
  - Easier to implement certain algorithms
  
- **Cons**:
  - More memory per node (~50% more)
  - More pointers to maintain
  - Slightly more complex insertion logic

**When to Use DLL**:
- Need backward traversal
- Frequent tail operations
- Implementing undo/redo functionality
- Browser history navigation
- Music/video playlists with prev/next

**When to Use SLL**:
- Memory is constrained
- Only forward traversal needed
- Simple stack/queue implementations

### Code Complexity Comparison

**Reversal Example**:

```cpp
// Singly Linked List - More complex
Node* reverseSLL(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

// Doubly Linked List - Simpler
void reverseDLL(Node* &head, Node* &tail) {
    Node* curr = head;
    
    while (curr) {
        swap(curr->next, curr->prev);
        curr = curr->prev;  // Old next
    }
    
    swap(head, tail);
}
```

**Deletion Example**:

```cpp
// Singly Linked List - Need to find previous
void deleteSLL(Node* &head, int val) {
    if (head->val == val) {
        head = head->next;
        return;
    }
    
    Node* temp = head;
    while (temp->next && temp->next->val != val) {
        temp = temp->next;
    }
    
    if (temp->next) {
        temp->next = temp->next->next;
    }
}

// Doubly Linked List - Direct access to previous
void deleteDLL(Node* &head, Node* target) {
    if (target == head) {
        head = head->next;
        if (head) head->prev = NULL;
        return;
    }
    
    target->prev->next = target->next;
    if (target->next) {
        target->next->prev = target->prev;
    }
    
    free(target);
}
```

---

## Common Patterns Summary

| Pattern | Programs | Key Insight |
|---------|----------|-------------|
| **Two-Pointer (Both Ends)** | `palindrome.cpp`, `pairSum.cpp` | Leverage tail pointer for O(n/2) operations |
| **Backward Traversal** | `traverse.cpp`, `criticalPoints.cpp` | Use prev pointer for reverse iteration |
| **Pointer Swapping** | `reverse.cpp` | Swap next/prev instead of rebuilding |
| **Neighbor Checking** | `criticalPoints.cpp`, `traverse.cpp` | Easy with both prev and next available |
| **Bidirectional CRUD** | `doubleLinkedList.cpp` | O(1) operations at both ends |

---

## Time Complexity Reference

| Operation | Best Case | Average Case | Worst Case | Notes |
|-----------|-----------|--------------|------------|-------|
| Insert at head | O(1) | O(1) | O(1) | Direct head manipulation |
| Insert at tail | O(1) | O(1) | O(1) | With tail pointer |
| Delete at head | O(1) | O(1) | O(1) | Update head only |
| Delete at tail | O(1) | O(1) | O(1) | With tail pointer |
| Search | O(1) | O(n) | O(n) | Linear search |
| Reverse | O(n) | O(n) | O(n) | Pointer swap |
| Palindrome check | O(n/2) | O(n/2) | O(n/2) | Two pointers |
| Find pair sum | O(n) | O(n) | O(n) | Two pointers in sorted list |
| Critical points | O(n) | O(n) | O(n) | Single traversal |

---

## Space Complexity Reference

| Technique | Space Complexity | Notes |
|-----------|------------------|-------|
| Basic operations | O(1) | In-place modification |
| Reversal | O(1) | In-place pointer swap |
| Palindrome check | O(1) | Two pointers only |
| Critical points | O(1) | Track positions only |
| Node structure | O(1) | 3 fields per node |

---

## Key Takeaways

1. **Bidirectional Power**: DLL's prev pointer enables efficient backward operations
2. **Tail Pointer**: Maintaining tail makes end operations O(1)
3. **Simpler Algorithms**: Many operations are simpler than SLL (reversal, palindrome)
4. **Memory Trade-off**: 50% more memory per node for extra functionality
5. **Pointer Discipline**: Always update both next and prev for consistency
6. **Edge Case Awareness**: Empty list, single node, and boundary operations need care
---
**Happy Coding! 🚀**
