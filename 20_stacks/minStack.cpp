/* Design a stack that supports push, pop, top, and retrieving the minimum
element in constant time.

Implement the MinStack class:

- MinStack() initializes the stack object.
- void push(int val) pushes the element val onto the stack.
- void pop() removes the element on the top of the stack.
- int top() gets the top element of the stack.
- int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

Assumption: Methods pop, top and getMin operations will always be called on
non-empty stacks. */

#include<iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        
        if(minSt.empty())
            minSt.push(val);
        else
            minSt.push(min(val, minSt.top()));
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack obj;

    obj.push(5);
    cout << "Pushed: 5\n";
    cout << "Current Min: " << obj.getMin() << "\n\n";

    obj.push(3);
    cout << "Pushed: 3\n";
    cout << "Current Min: " << obj.getMin() << "\n\n";

    obj.push(7);
    cout << "Pushed: 7\n";
    cout << "Current Min: " << obj.getMin() << "\n\n";

    obj.push(2);
    cout << "Pushed: 2\n";
    cout << "Current Min: " << obj.getMin() << "\n\n";

    cout << "Top Element: " << obj.top() << "\n\n";

    obj.pop();
    cout << "After Pop\n";
    cout << "Top Element: " << obj.top() << "\n";
    cout << "Current Min: " << obj.getMin() << "\n";

    return 0;
}