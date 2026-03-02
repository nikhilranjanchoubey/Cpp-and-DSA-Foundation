#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int calculate(int v1, int v2, char op)
{
    if (op == '^')
        return pow(v1, v2);
    if (op == '+')
        return v1 + v2;
    if (op == '-')
        return v1 - v2;
    if (op == '/')
        return v1 / v2;
    if (op == '*')
        return v1 * v2;

    return 0; 
}

int evaluate(string &str)
{
    stack<int> st;

    // Traverse from RIGHT to LEFT
    for (int i = str.size() - 1; i >= 0; i--)
    {
        char ch = str[i];

        if (isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();

            st.push(calculate(v1, v2, ch));
        }
    }

    return st.top();
}

int main()
{
    string str = "-+2*319"; 
    cout << evaluate(str);

    return 0;
}