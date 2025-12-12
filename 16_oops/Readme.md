# OBJECT-ORIENTED PROGRAMMING (OOPs)

C++ programs demonstrating Object-Oriented Programming concepts including classes, objects, inheritance, polymorphism, and encapsulation.

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
  - [Basics](#basics)
  - [Constructors and Destructors](#constructors-and-destructors)
  - [Encapsulation](#encapsulation)
  - [Inheritance Types](#inheritance-types)
  - [Polymorphism](#polymorphism)
  - [Advanced Concepts](#advanced-concepts)
- [OOP Principles](#oop-principles)
- [Access Specifiers](#access-specifiers)
- [Inheritance Types Summary](#inheritance-types-summary)

## Overview

Programs covering fundamental OOP concepts: classes, objects, constructors, inheritance , polymorphism, encapsulation, and operator overloading.

## Programs

### Basics

#### 1. classAndObjects.cpp - Classes and Objects
Introduction to classes and object creation.

**Class:** Blueprint or template for creating objects
**Object:** Instance of a class

**Two Ways to Create Objects:**

**Stack Allocation:**
```cpp
Fruit apple;
apple.name = "Apple";
apple.color = "Red";
```

**Heap Allocation (Dynamic):**
```cpp
Fruit *mango = new Fruit();
mango->name = "Mango";
mango->color = "Yellow";
```

**Access:**
- `.` operator for stack objects
- `->` operator for pointer objects

**Learns:** Class structure, object creation, member access

---

### Constructors and Destructors

#### 2. constructorAndDestructor.cpp - Constructor Types
Demonstrates all constructor types and destructor.

**1. Default Constructor** - No parameters
```cpp
Rectangle() {
    length = 0;
    breadth = 0;
}
```

**2. Parameterized Constructor** - With parameters
```cpp
Rectangle(int x, int y) {
    length = x;
    breadth = y;
}
```

**3. Copy Constructor** - Initialize from another object
```cpp
Rectangle(Rectangle &r) {
    length = r.length;
    breadth = r.breadth;
}
```

**4. Destructor** - Cleanup when object destroyed
```cpp
~Rectangle() {
    cout << "Destructor is Called" << endl;
}
```

**Usage:**
```cpp
Rectangle r1;              // Default constructor
Rectangle r2(5, 6);        // Parameterized constructor
Rectangle r3 = r2;         // Copy constructor
// Destructor called automatically when objects go out of scope
```

**Learns:** Constructor overloading, copy constructor, automatic cleanup

---

### Encapsulation

#### 3. encapsulation.cpp - Data Hiding
Demonstrates encapsulation using private data and public methods.

**Principle:** Hide internal data, provide controlled access

**Implementation:**
```cpp
class ABC {
private:
    int x;  // Private data member
    
public:
    void set(int n) { x = n; }  // Setter
    int get() { return x; }      // Getter
};
```

**Benefits:**
- Data protection
- Controlled access
- Validation possible in setters
- Implementation hiding

**Learns:** Private members, getter/setter pattern, data protection

---

### Inheritance Types

#### 4. singleInheritance.cpp - Single Inheritance
One child inherits from one parent.

**Structure:** Parent → Child

```cpp
class Parent {
    Parent() { cout << "Parent Class" << endl; }
};

class Child : public Parent {
    Child() { cout << "Child Class" << endl; }
};
```

**Constructor Order:** Parent → Child

**Learns:** Basic inheritance, constructor calling sequence

---

#### 5. multiLevelinheritance.cpp - Multilevel Inheritance
Chain of inheritance: Grandparent → Parent → Child.

**Structure:** Parent → Child → GrandChild

```cpp
class Parent { ... };
class Child : public Parent { ... };
class GrandChild : public Child { ... };
```

**Constructor Order:** Parent → Child → GrandChild

**Learns:** Inheritance chain, sequential construction

---

#### 6. multipleInheritance.cpp - Multiple Inheritance
One child inherits from multiple parents.

**Structure:** Parent1, Parent2 → Child

```cpp
class Parent1 { ... };
class Parent2 { ... };
class Child : public Parent1, public Parent2 { ... };
```

**Constructor Order:** Parent1 → Parent2 → Child (left to right)

**Learns:** Multiple base classes, diamond problem potential

---

#### 7. hierarchicalinheritance.cpp - Hierarchical Inheritance
Multiple children inherit from one parent.

**Structure:** 
```
        Parent
       /      \
   Child1    Child2
```

```cpp
class Parent { ... };
class Child1 : public Parent { ... };
class Child2 : public Parent { ... };
```

**Learns:** One-to-many inheritance, code reusability

---

#### 8. hybridinheritance.cpp - Hybrid Inheritance
Combination of multiple inheritance types.

**Structure:**
```
Parent1    Parent2
   |          |
Child1     Child2
    \       /
   GrandChild
```

```cpp
class Child1 : public Parent1 { ... };
class Child2 : public Parent2 { ... };
class GrandChild : public Child1, public Child2 { ... };
```

**Constructor Order:** Parent1 → Child1 → Parent2 → Child2 → GrandChild

**Learns:** Complex inheritance hierarchies, multiple paths

---

#### 9. inheritance.cpp - Access Specifiers in Inheritance
Demonstrates how access specifiers affect inherited members.

**Parent Class Members:**
- `public int x` - Accessible everywhere
- `protected int y` - Accessible in derived classes
- `private int z` - Only in parent class

**Inheritance Modes:**

**Public Inheritance:**
```cpp
class Child1 : public Parent {
    // public → public
    // protected → protected
    // private → inaccessible
};
```

**Private Inheritance:**
```cpp
class Child2 : private Parent {
    // public → private
    // protected → private
    // private → inaccessible
};
```

**Protected Inheritance:**
```cpp
class Child3 : protected Parent {
    // public → protected
    // protected → protected
    // private → inaccessible
};
```

**Learns:** Access control in inheritance, visibility rules

---

### Polymorphism

#### 10. functionOverloading.cpp - Compile-Time Polymorphism
Same function name with different parameters.

**Types:**
```cpp
void add(int x, int y)           // 2 integers
void add(int x, int y, int z)    // 3 integers
void add(float x, float y)       // 2 floats
```

**Resolved:** At compile time based on arguments

**Learns:** Function overloading, compile-time resolution

---

#### 11. functionOverridding.cpp - Runtime Polymorphism
Child class overrides parent's virtual function.

**Key Concept:** Virtual functions enable runtime polymorphism

```cpp
class Parent {
    virtual void print() { cout << "parent class"; }
    void show() { cout << "parent class"; }
};

class Child : public Parent {
    void print() { cout << "child class"; }  // Override
    void show() { cout << "child class"; }   // Hiding
};

Parent *p = &c;
p->print();  // Calls Child::print() - virtual
p->show();   // Calls Parent::show() - not virtual
```

**With `virtual`:** Runtime polymorphism (dynamic binding)
**Without `virtual`:** Function hiding (static binding)

**Learns:** Virtual functions, dynamic binding, polymorphism

---

#### 12. operatorOverloading.cpp - Operator Overloading
Gives custom meaning to operators for user-defined types.

**Example:** Adding complex numbers

```cpp
class Complex {
    int real, img;
    
    Complex operator+(Complex &c) {
        Complex ans(0, 0);
        ans.real = real + c.real;
        ans.img = img + c.img;
        return ans;
    }
};

Complex c3 = c1 + c2;  // Uses overloaded operator
```

**Learns:** Operator overloading, custom operators

---

### Advanced Concepts

#### 13. friendFunction.cpp - Friend Functions
Non-member function that can access private members.

```cpp
class Number {
private:
    int x;
public:
    friend void showValue(Number n);  // Friend declaration
};

void showValue(Number n) {
    cout << n.x;  // Can access private member
}
```

**Use Cases:**
- When function needs access to private data of multiple classes
- Operator overloading (non-member operators)
- Bridge between classes

**Learns:** Friend functions, special access privileges

---

## OOP Principles

### 1. Encapsulation
**Definition:** Bundling data and methods that operate on data within a single unit (class).

**Benefits:**
- Data hiding (private members)
- Controlled access (getters/setters)
- Implementation changes don't affect users
- Validation and constraints

**Example:**
```cpp
class BankAccount {
private:
    double balance;
public:
    void deposit(double amount) {
        if(amount > 0) balance += amount;
    }
    double getBalance() { return balance; }
};
```

---

### 2. Abstraction
**Definition:** Hiding complex implementation details, showing only essential features.

**Implementation:**
- Abstract classes (with pure virtual functions)
- Interfaces
- Public methods hide internal complexity

**Example:**
```cpp
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
    virtual double area() = 0;
};
```

---

### 3. Inheritance
**Definition:** Mechanism where new class derives properties from existing class.

**Benefits:**
- Code reusability
- Hierarchical classification
- Method overriding
- Extensibility

**Syntax:**
```cpp
class Derived : access_specifier Base {
    // Additional members
};
```

---

### 4. Polymorphism
**Definition:** Ability to take many forms - same interface, different implementations.

**Types:**

**Compile-Time (Static):**
- Function overloading
- Operator overloading

**Runtime (Dynamic):**
- Function overriding (virtual functions)
- Achieved through pointers/references

**Example:**
```cpp
Shape *s = new Circle();
s->draw();  // Calls Circle::draw() at runtime
```

---

## Access Specifiers

### Public
- Accessible everywhere
- Outside class, in derived classes, anywhere

```cpp
class MyClass {
public:
    int x;  // Accessible everywhere
};
```

### Protected
- Accessible in class and derived classes
- Not accessible outside class hierarchy

```cpp
class MyClass {
protected:
    int y;  // Accessible in derived classes
};
```

### Private
- Accessible only within the class
- Not accessible in derived classes or outside

```cpp
class MyClass {
private:
    int z;  // Only in this class
};
```

### Access Specifier Table

| Specifier | Same Class | Derived Class | Outside Class |
|-----------|-----------|---------------|---------------|
| **public** | ✓ | ✓ | ✓ |
| **protected** | ✓ | ✓ | ✗ |
| **private** | ✓ | ✗ | ✗ |

---

## Inheritance Types Summary

### Visual Representation

```
1. Single Inheritance
   Parent → Child

2. Multilevel Inheritance
   Parent → Child → GrandChild

3. Multiple Inheritance
   Parent1 ↘
              Child
   Parent2 ↗

4. Hierarchical Inheritance
        Parent
       /      \
   Child1    Child2

5. Hybrid Inheritance
   Parent1    Parent2
      |          |
   Child1     Child2
       \       /
      GrandChild
```

### Comparison Table

| Type | Parents | Children | Example |
|------|---------|----------|---------|
| **Single** | 1 | 1 | Animal → Dog |
| **Multilevel** | Chain | Chain | Animal → Mammal → Dog |
| **Multiple** | 2+ | 1 | Father, Mother → Child |
| **Hierarchical** | 1 | 2+ | Parent → Child1, Child2 |
| **Hybrid** | Mixed | Mixed | Combination of above |

---

## Constructor and Destructor Rules

### Constructor Rules
1. **Same name** as class
2. **No return type** (not even void)
3. **Called automatically** when object created
4. Can be **overloaded**
5. **Cannot be virtual**

### Destructor Rules
1. **Same name** with `~` prefix
2. **No parameters** (cannot be overloaded)
3. **No return type**
4. **Called automatically** when object destroyed
5. Can be **virtual** (important for inheritance)

### Constructor Calling Order

**Single Inheritance:**
```
Parent → Child
```

**Multiple Inheritance:**
```
Parent1 → Parent2 → Child (left to right order)
```

**Multilevel Inheritance:**
```
Grandparent → Parent → Child (top to bottom)
```

---

## Virtual Functions and Polymorphism

### Virtual Function Rules

```cpp
class Base {
public:
    virtual void display() {  // Virtual function
        cout << "Base";
    }
};

class Derived : public Base {
public:
    void display() override {  // Override keyword (C++11)
        cout << "Derived";
    }
};
```

### Key Points

1. **Virtual keyword** in base class enables dynamic binding
2. **Override keyword** (optional but recommended) in derived class
3. **Virtual destructor** needed when deleting through base pointer
4. **Pure virtual function** `= 0` makes class abstract

### Virtual vs Non-Virtual

```cpp
Base *ptr = new Derived();

// With virtual
ptr->display();  // Calls Derived::display()

// Without virtual
ptr->display();  // Calls Base::display()
```

---

## Object Creation Methods

### Stack Allocation
```cpp
MyClass obj;           // Default constructor
MyClass obj(10);       // Parameterized constructor
MyClass obj2 = obj;    // Copy constructor

// Automatic cleanup when goes out of scope
```

### Heap Allocation
```cpp
MyClass *ptr = new MyClass();      // Default
MyClass *ptr = new MyClass(10);    // Parameterized
MyClass *ptr = new MyClass(*obj);  // Copy

delete ptr;  // Manual cleanup required
```

### When to Use Which?
- **Stack:** Small objects, automatic cleanup, known lifetime
- **Heap:** Large objects, dynamic lifetime, need to return from function

---

## Common OOP Patterns

### Getter/Setter Pattern
```cpp
class Person {
private:
    string name;
    int age;
public:
    void setName(string n) { name = n; }
    string getName() { return name; }
    
    void setAge(int a) {
        if(a >= 0 && a <= 150)  // Validation
            age = a;
    }
    int getAge() { return age; }
};
```

### Constructor Initialization List
```cpp
class Rectangle {
private:
    int length, breadth;
public:
    Rectangle(int l, int b) : length(l), breadth(b) {
        // Members already initialized
    }
};
```

### Copy Constructor Pattern
```cpp
class MyClass {
private:
    int *ptr;
public:
    // Deep copy
    MyClass(const MyClass &obj) {
        ptr = new int;
        *ptr = *(obj.ptr);
    }
};
```

---

## Important Concepts

### this Pointer
- Points to the object that called the member function
- Implicit parameter to all non-static member functions

```cpp
class MyClass {
    int x;
public:
    void setX(int x) {
        this->x = x;  // Distinguish parameter from member
    }
};
```

### Static Members
- Shared by all objects of class
- Accessed using class name
- Only one copy exists

```cpp
class Counter {
    static int count;  // Declaration
public:
    Counter() { count++; }
    static int getCount() { return count; }
};

int Counter::count = 0;  // Definition outside class
```

### Const Member Functions
- Cannot modify member variables
- Can be called on const objects

```cpp
class MyClass {
    int x;
public:
    int getX() const {  // Const member function
        return x;
    }
};
```
---
**Happy Coding! 🚀**