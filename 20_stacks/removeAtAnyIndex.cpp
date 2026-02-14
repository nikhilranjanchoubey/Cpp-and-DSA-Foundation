#include <iostream>
#include <stack>
using namespace std;

void removeAtAnyIndex(stack<int> &st, int idx)
{
    stack<int> temp;
    int n = st.size();
    int count = 0;

    // Move elements until we reach the element to remove
    while (count < n - idx - 1)
    {
        int curr = st.top();
        st.pop();
        temp.push(curr);
        count++;
    }

    // Remove the required element
    st.pop();

    // Push back remaining elements
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);  // top

    removeAtAnyIndex(st, 1);  // Remove element at index 1 (from bottom)

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
