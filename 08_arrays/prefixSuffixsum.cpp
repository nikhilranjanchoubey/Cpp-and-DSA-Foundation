/*Check if we can partition the array into two subarrays with equal sum.
More formally, check that the prefix sum of a part of the array 
is equal to the suffix sum of rest of the array.*/

#include <iostream>
#include <vector>
using namespace std;

bool checkPrefixSuffixSum(vector<int> &v) {
    int total_sum = 0;

    //Calculate the total sum of the array
    for (int i = 0; i < v.size(); i++) {
        total_sum += v[i];
    }

    int prefix_sum = 0;

    //Traverse and check for a valid partition point
    for (int i = 0; i < v.size() - 1; i++) {
        prefix_sum += v[i]; // Accumulate prefix sum
        int suffix_sum = total_sum - prefix_sum; // Remaining sum

        //Compare prefix and suffix sums
        if (prefix_sum == suffix_sum) {
            return true; // Partition found
        }
    }

    return false; 
}

int main() {
    int n;

  
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> v;

    //Enter array elements
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }

    //Check for partition and display result
    if (checkPrefixSuffixSum(v)) {
        cout << "Yes, the array can be partitioned into two equal-sum subarrays." << endl;
    } else {
        cout << "No, such a partition is not possible." << endl;
    }

    return 0;
}
