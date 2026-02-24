#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> pge(vector<int> &arr)
{
    int n = arr.size();
    reverse(arr.begin(), arr.end());
    vector<int> output(n, -1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() and arr[i] > arr[st.top()])
        {
            output[st.top()] = n-i-1;
            st.pop();
        }
        st.push(i);
    }

    while (not st.empty())
    { // not mandatory while loop
        output[st.top()] = -1;
        st.pop();
    }
    reverse(output.begin(),output.end());
    reverse(arr.begin(), arr.end());
    return output;
}

int main()
{
    int n;
    cout << "Enter total no. of elements: ";
    cin >> n;
    vector<int> v;
    cout << "Enter Elements: " << endl;
    while (n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << "Stock Span: " << endl;
    vector<int> res = pge(v);
    for (int i = 0; i < res.size(); i++)
    {
        cout << (i-res[i]) << " ";
    }

    return 0;
}