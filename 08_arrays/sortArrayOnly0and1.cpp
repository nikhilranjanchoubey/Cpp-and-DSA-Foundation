// Sort an Array cosisting of only 0s and 1s.

#include<iostream>
#include<vector>
using namespace std;

// Function to sort the array containing only 0s and 1s
void sortZerosAndOnes(vector<int> &v) {
    int Zeros_count = 0;

    //Count the number of 0s in the array
    for(int ele : v) {
        if(ele == 0) {
            Zeros_count++;
        }
    }

    //Overwrite the array
    // Fill the first 'Zeros_count' elements with 0
    // Fill the remaining elements with 1
    for(int i = 0; i < v.size(); i++) {
        if(i < Zeros_count) {
            v[i] = 0;
        } else {
            v[i] = 1;
        }
    }
}

int main() {
    int n;

    // Input: Size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> v;

    // Input: Array elements (only 0s and 1s)
    cout << "Enter " << n << " elements (only 0s and 1s): ";
    for(int i = 0; i < n; i++) {
        int ele;
        cin >> ele;

        v.push_back(ele);
    }

    // Display array before sorting
    cout << "Before sorting: ";
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Call the sorting function
    sortZerosAndOnes(v);

    // Display array after sorting
    cout << "After sorting: ";
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}