/* Given an array of integer heights representing the histogram's bar height where the width of each bar is 1,
return the area of the largest rectangle in the histogram. */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int histogram(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;      // stores indexes
    int ans = 0;

    st.push(0);

    for (int i = 1; i < n; i++) {

        while (!st.empty() && arr[i] < arr[st.top()]) {

            int el = arr[st.top()];   // element to calculate area
            st.pop();

            int nsi = i;   // next smaller index
            int psi = (st.empty()) ? (-1) : st.top();  // previous smaller index

            ans = max(ans, el * (nsi - psi - 1));
        }

        st.push(i);
    }

    // Remaining elements in stack
    while (!st.empty()) {

        int el = arr[st.top()];
        st.pop();

        int nsi = n;   // next smaller index is n (end of array)
        int psi = (st.empty()) ? (-1) : st.top();

        ans = max(ans, el * (nsi - psi - 1));
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> v;
    while (n--) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int ans = histogram(v);
    cout << ans << "\n";

    return 0;
}