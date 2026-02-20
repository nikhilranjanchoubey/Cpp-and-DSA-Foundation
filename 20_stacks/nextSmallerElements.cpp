#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nse(vector<int> &arr)
{
    int n = arr.size();
    vector<int> output(n, -1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() and arr[i] < arr[st.top()])
        {
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    while (not st.empty())
    { // not mandatory while loop
        output[st.top()] = -1;
        st.pop();
    }

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
    cout << "Next Smaller Elements: " << endl;
    vector<int> res = nse(v);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}