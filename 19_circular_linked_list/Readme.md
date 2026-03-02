# Circular Linked List

A comprehensive collection of **C++ programs** covering circular linked list operations, STL list operations, and template-based implementations.

---

## Programs by Category

### Circular Linked List Implementation
- `circularLinkedList.cpp` - Complete circular LL with insert/delete operations

### STL List Operations  
- `list.cpp` - C++ STL list with iterators, insert, erase operations

### Advanced C++ Features
- `templates.cpp` - Template-based generic node implementation

---

## Key Concepts

### Circular Structure
Last node points back to head (no NULL terminator)

```
Normal List:     1 -> 2 -> 3 -> NULL
Circular List:   1 -> 2 -> 3 ⤴
                 ↑____________|
```

### Circular Traversal (do-while required)
```cpp
do {
    cout << temp->val << "->";
    temp = temp->next;
} while (temp != head);
```

### Finding Tail
```cpp
Node* tail = head;
while (tail->next != head) {
    tail = tail->next;
}
```

---

## Operations

### circularLinkedList.cpp

**insertAtStart(val)** - O(n)
- Finds tail, updates tail->next, new_node->next, updates head

**insertAtEnd(val)** - O(n)  
- Finds tail, updates tail->next, new_node->next

**deleteAtStart()** - O(n)
- Finds tail, updates head, tail->next, frees old head

**deleteAtEnd()** - O(n)
- Finds second-last node, updates next pointer, frees last

**display()** - O(n)
- Uses do-while to print once around

**printCircular()** - O(k)
- Demonstrates infinite loop by printing k elements

### list.cpp

**Iterators**
- begin(), end() - forward iteration
- rbegin(), rend() - reverse iteration
- advance(itr, n) - move n positions

**Insertion**
- insert(itr, val) - single element
- insert(itr, count, val) - multiple copies
- insert(itr, start, end) - range

**Deletion**
- erase(itr) - single element
- erase(start, end) - range [start, end)

### templates.cpp

**Generic Node**
```cpp
template <typename T>
class Node {
    T val;
    Node* next;
};

// Usage
Node<int>* n1 = new Node<int>(3);
Node<char>* n2 = new Node<char>('a');
```

---

## Complexity Comparison

| Operation | Singly LL | Doubly LL | Circular LL | Circular (tail ptr) |
|-----------|-----------|-----------|-------------|---------------------|
| Insert head | O(1) | O(1) | O(n) | O(1) |
| Insert tail | O(n)* | O(1) | O(n) | O(1) |
| Delete head | O(1) | O(1) | O(n) | O(1) |
| Delete tail | O(n) | O(1) | O(n) | O(n) |

---

## Real-World Applications

1. **Round-Robin Scheduling** - CPU time allocation
2. **Circular Buffers** - Audio/video streaming  
3. **Gaming** - Turn-based games, player rotation
4. **Music Players** - Playlist with repeat
5. **Operating Systems** - Process management

---

## Best Practices

1. **Always use do-while for circular traversal**
2. **Handle empty list case** (new_node->next = new_node)
3. **Maintain circular property** (tail->next = head)
4. **Use STL for production** (tested, optimized)
5. **Templates for reusability** (type-safe generic code)

---

## Key Takeaways

✅ Circular structure: last points to first  
✅ do-while essential for single-node case  
✅ O(n) operations without tail pointer  
✅ STL provides tested implementation  
✅ Templates enable generic programming  
✅ Perfect for cyclic/round-robin data  

---

**Happy Coding! 🚀**