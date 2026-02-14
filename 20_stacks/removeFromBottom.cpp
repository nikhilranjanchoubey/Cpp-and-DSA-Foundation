#include <iostream>
#include <stack>
using namespace std;


void removeFromBottom(stack<int> &st)
{
    // Base case: if only one element left, remove it
    if (st.size() == 1)
    {
        st.pop();   // remove bottom element
        return;
    }

    int curr = st.top();
    st.pop();

    // Recursive call
    removeFromBottom(st);

    // Push back other elements
    st.push(curr);
}

int main()
{
    stack<int> st;
    st.push(1); // bottom
    st.push(2);
    st.push(3);
    st.push(4);  // top

    removeFromBottom(st);   
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
