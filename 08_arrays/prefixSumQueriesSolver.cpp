/*Given an array of integers of size n.
Answer q queries where you need to print the sum of values
in a given range of indices from l to r(both included)

Note: The values of l and r in queries follow 1-based indexing.*/

#include<iostream>
#include<vector>
using namespace std;

// index -->> 0 1 2 3 4 5 6 ...
// vector -->> 0 x1 x2 ...

// 0 based indexing -->> 0 ...... n-1
// 1 based indexing -->> 1 ...... n

int main() {
    int n;

    //Input array size
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Initialize vector with n+1 elements (1-based indexing)
    vector<int> v(n + 1, 0);

    //Input array elements starting from index 1
    cout << "Enter " << n << " integers: ";
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    //Build prefix sum array
    for (int i = 1; i <= n; i++) {
        v[i] += v[i - 1]; // Each element becomes sum of all previous elements
    }

    int q;

    //Input number of queries
    cout << "Enter number of queries: ";
    cin >> q;

    //Process each query
    while (q--) {
        int l, r;
        cout << "Enter range (l to r): ";
        cin >> l >> r;

        //Compute range sum using prefix sum
        int ans = v[r] - v[l - 1];

        //Output the result
        cout << "Sum from index " << l << " to " << r << " is: " << ans << endl;
    }

    return 0;
}
