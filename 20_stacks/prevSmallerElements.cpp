#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmaller(vector<int> &arr)
{
    int n = arr.size();
    vector<int> output(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
            output[i] = arr[st.top()];
        else
            output[i] = -1;

        st.push(i);
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

    vector<int> res = prevSmaller(v);

    cout << "Previous Smaller Elements: " << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}