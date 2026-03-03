# Queue Data Structure

A comprehensive collection of Queue data structure implementations and applications in C++.

## Table of Contents

- [Introduction](#introduction)
- [Queue Implementations](#queue-implementations)
- [Queue Using Stack](#queue-using-stack)
- [Queue Operations](#queue-operations)
- [Advanced Problems](#advanced-problems)
- [Complexity Analysis](#complexity-analysis)

## Introduction

A **Queue** is a linear data structure that follows the **FIFO (First In First Out)** principle. The first element added is the first one to be removed.

### Key Operations
- **Enqueue**: Add element to rear - O(1)
- **Dequeue**: Remove element from front - O(1)
- **Front/Peek**: View front element - O(1)
- **isEmpty**: Check if empty - O(1)
- **isFull**: Check if full (for array implementation)

### Queue vs Stack
| Queue | Stack |
|-------|-------|
| FIFO (First In First Out) | LIFO (Last In First Out) |
| Insert at rear, delete from front | Insert and delete from top |
| Used in: BFS, Scheduling | Used in: DFS, Expression Evaluation |

---

## Queue Implementations

### 1. Queue Using Arrays (Dynamic)
**File:** `queuesUsingArrays.cpp`

Dynamic array-based queue implementation using vectors.

**Features:**
- Dynamic sizing with vector
- Front and back pointers
- Automatic resizing

**Methods:**
```cpp
void enqueue(int data)    // Add to rear
void dequeue()            // Remove from front
int getFront()            // Get front element
bool isEmpty()            // Check if empty
```

**Time Complexity:**
- Enqueue: O(1)
- Dequeue: O(1)*
- Front: O(1)

*Note: Dequeue doesn't actually remove from vector, just moves front pointer

**Space Complexity:** O(n)

**Example Usage:**
```cpp
Queue q;
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.dequeue();        // Remove 10
cout << q.getFront(); // Output: 20
```

---

### 2. Circular Queue
**File:** `circularQueue.cpp`

Fixed-size circular queue to efficiently utilize space.

**Features:**
- Fixed capacity
- Wraps around using modulo operation
- No wasted space
- Both overflow and underflow handling

**Why Circular Queue?**
In linear queue, after multiple enqueue/dequeue operations, space at the beginning gets wasted. Circular queue solves this by wrapping around.

**Methods:**
```cpp
void enqueue(int data)
void dequeue()
int getFront()
bool isEmpty()
bool isFull()
```

**Key Concept:**
```cpp
// Circular increment
back = (back + 1) % totalsize
front = (front + 1) % totalsize
```

**Time Complexity:** All operations O(1)  
**Space Complexity:** O(n) - fixed size

**Example:**
```cpp
Queue q(3);  // Size 3
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);  // Queue full
q.dequeue();    // Remove 10
q.enqueue(40);  // Wraps to position 0
// Queue: [40, 20, 30]
```

---

### 3. Queue Using Linked List
**File:** `queuesUsingLinkedList.cpp`

Dynamic queue using linked nodes.

**Features:**
- No fixed size limit
- Dynamic memory allocation
- Head (front) and Tail (rear) pointers
- Efficient enqueue and dequeue

**Node Structure:**
```cpp
class Node {
    int data;
    Node* next;
};
```

**Methods:**
```cpp
void enqueue(int data)    // Add at tail
void dequeue()            // Remove from head
int front()               // Get head data
bool isEmpty()
int getSize()
```

**Time Complexity:** All operations O(1)  
**Space Complexity:** O(n)

**Advantages:**
- No overflow (until memory runs out)
- Efficient memory usage
- True deletion of elements

**Example:**
```cpp
Queue q;
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.dequeue();        // Remove 10
cout << q.front();  // Output: 20
```

---

### 4. Deque (Double-Ended Queue)
**File:** `deque.cpp`

Queue that allows insertion and deletion from both ends.

**STL Deque Features:**
- Insert/delete from both front and back
- Random access support
- Dynamic sizing

**Methods:**
```cpp
push_front(x)    // Add to front
push_back(x)     // Add to rear
pop_front()      // Remove from front
pop_back()       // Remove from rear
front()          // Get front element
back()           // Get rear element
empty()          // Check if empty
size()           // Get size
```

**Time Complexity:** All operations O(1)

**Example:**
```cpp
deque<int> dq;
dq.push_back(10);   // [10]
dq.push_back(20);   // [10, 20]
dq.push_front(5);   // [5, 10, 20]
dq.push_front(1);   // [1, 5, 10, 20]
```

**Use Cases:**
- Sliding window problems
- Browser history (forward/backward)
- Undo/Redo operations
- Palindrome checking

---

## Queue Using Stack

### 5. Queue Using Single Stack (Push Efficient)
**File:** `queueUsingStack.cpp`

Implement queue using one stack where push operation is efficient.

**Approach:**
- **Enqueue (push)**: Simply push to stack - O(1)
- **Dequeue (pop)**: Transfer all elements to temp stack, pop bottom, transfer back - O(n)
- **Front**: Similar to dequeue but don't pop - O(n)

**Algorithm:**
```cpp
// Dequeue operation
1. Transfer all elements except last to temp stack
2. Pop the last element (which was first inserted)
3. Transfer all elements back from temp to main stack
```

**Time Complexity:**
- Push: O(1)
- Pop: O(n)
- Front: O(n)

**Space Complexity:** O(n)

**Example:**
```cpp
Queue q;
q.push(10);   // Stack: [10]
q.push(20);   // Stack: [20, 10]
q.push(30);   // Stack: [30, 20, 10]
q.pop();      // Remove 10, Stack: [30, 20]
```

---

### 6. Queue Using Two Stacks (Pop Efficient)
**File:** `queueUsingTwoStacks.cpp`

Implement queue using two stacks where pop operation is efficient.

**Approach:**
- **Enqueue (push)**: Transfer all to temp, push new element, transfer back - O(n)
- **Dequeue (pop)**: Simply pop from stack - O(1)
- **Front**: Simply get top of stack - O(1)

**Algorithm:**
```cpp
// Enqueue operation
1. Transfer all elements to temp stack
2. Push new element to main stack
3. Transfer all elements back from temp to main
// This maintains queue order in stack
```

**Time Complexity:**
- Push: O(n)
- Pop: O(1)
- Front: O(1)

**Space Complexity:** O(n)

**Trade-off:**
- Push efficient version: Fast enqueue, slow dequeue
- Pop efficient version: Slow enqueue, fast dequeue

**Use Case:** Choose based on whether your application does more enqueues or dequeues.

---

## Queue Operations

### 7. Reverse Queue Elements
**File:** `reverseElements.cpp`

Reverse all elements in a queue using a stack.

**Algorithm:**
```
1. Dequeue all elements and push to stack
2. Pop all from stack and enqueue to queue
3. Result: Reversed queue
```

**Why it works:**
- Queue is FIFO
- Stack is LIFO
- Stack reverses the order

**Example:**
```
Original Queue: [10, 20, 30, 40]
After Reverse:  [40, 30, 20, 10]
```

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

**Code Flow:**
```cpp
queue<int> input;      // [10, 20, 30, 40]
stack<int> st;

// Step 1: Queue to Stack
while (!input.empty()) {
    st.push(input.front());
    input.pop();
}
// Stack (top to bottom): [40, 30, 20, 10]

// Step 2: Stack to Queue
while (!st.empty()) {
    input.push(st.top());
    st.pop();
}
// Queue: [40, 30, 20, 10]
```

**Applications:**
- Reverse order processing
- Undo operations
- Data transformation

---

## Advanced Problems

### 8. Sliding Window Maximum
**File:** `slidingWindowMax.cpp`

Find maximum element in every sliding window of size k.

**Problem:**
```
Input:  arr = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
Output: [3, 3, 5, 5, 6, 7]

Windows:
[1  3  -1] -3  5  3  6  7  → Max: 3
 1 [3  -1  -3] 5  3  6  7  → Max: 3
 1  3 [-1  -3  5] 3  6  7  → Max: 5
 1  3  -1 [-3  5  3] 6  7  → Max: 5
 1  3  -1  -3 [5  3  6] 7  → Max: 6
 1  3  -1  -3  5 [3  6  7] → Max: 7
```

**Naive Approach:** O(n*k)
- For each window, find maximum by scanning k elements

**Optimized Approach using Deque:** O(n)

**Algorithm:**
1. Use deque to store **indices** of useful elements
2. Deque maintains elements in decreasing order
3. Front of deque always has index of maximum element

**Key Operations:**
```cpp
// Remove elements outside current window
if (dq.front() == i - k)
    dq.pop_front();

// Remove smaller elements from back
while (!dq.empty() && arr[dq.back()] < arr[i])
    dq.pop_back();

// Add current element
dq.push_back(i);

// Front has maximum
max = arr[dq.front()];
```

**Why Deque?**
- Need to remove from both ends
- Remove expired elements from front
- Remove smaller elements from back

**Time Complexity:** O(n) - each element added and removed at most once  
**Space Complexity:** O(k) - deque stores at most k elements

## Complexity Analysis

| Operation/Implementation | Enqueue | Dequeue | Front | Space |
|-------------------------|---------|---------|-------|-------|
| Queue (Array) | O(1) | O(1)* | O(1) | O(n) |
| Circular Queue | O(1) | O(1) | O(1) | O(n) |
| Queue (Linked List) | O(1) | O(1) | O(1) | O(n) |
| Deque (STL) | O(1) | O(1) | O(1) | O(n) |
| Queue (1 Stack - Push Eff) | O(1) | O(n) | O(n) | O(n) |
| Queue (2 Stacks - Pop Eff) | O(n) | O(1) | O(1) | O(n) |
| Reverse Queue | - | - | - | O(n), Time: O(n) |
| Sliding Window Max | - | - | - | O(k), Time: O(n) |

*Array implementation: O(1) amortized, but doesn't actually free memory

---
## Common Patterns

### 1. Level Order Processing
**Used in:** BFS, Tree level order traversal
```cpp
queue<Node*> q;
q.push(root);
while (!q.empty()) {
    Node* curr = q.front();
    q.pop();
    // Process curr
    // Add children to queue
}
```

### 2. Sliding Window
**Used in:** Window maximum/minimum, substring problems
```cpp
deque<int> dq;
for (int i = 0; i < n; i++) {
    // Remove out of window
    // Remove useless elements
    // Add current element
    // Process window
}
```

### 3. Queue Reversal
**Used in:** Order reversal, Stack-Queue conversion
```cpp
stack<int> st;
while (!q.empty()) {
    st.push(q.front());
    q.pop();
}
while (!st.empty()) {
    q.push(st.top());
    st.pop();
}
```

### 4. Circular Buffer
**Used in:** Streaming data, fixed-size buffers
```cpp
front = (front + 1) % size;
back = (back + 1) % size;
```
## Important Notes

### Circular Queue Edge Cases
```cpp
// Full condition
if ((back + 1) % size == front)

// Empty condition  
if (front == -1 || currsize == 0)

// After dequeue last element
if (front == back) {
    front = back = -1;
}
```
### Queue Using Stack - Two Approaches

**Approach 1: Push Efficient**
- Push: O(1), Pop: O(n)
- Use when: More enqueues than dequeues

**Approach 2: Pop Efficient**
- Push: O(n), Pop: O(1)
- Use when: More dequeues than enqueues

---
Happy Coding! 🚀