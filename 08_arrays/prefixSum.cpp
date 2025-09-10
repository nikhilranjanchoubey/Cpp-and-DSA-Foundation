// Given an integers array 'a', return the prefix sum/running sum
// in the same array without creating a new array.

#include<iostream>
#include<vector>
using namespace std;

// Function to compute the running/prefix sum in-place
void runningSum(vector<int> &v){
    // Start from index 1 and add the previous element's value to the current
    for(int i = 1; i < v.size(); i++){
        v[i] += v[i - 1]; // Accumulate the sum
    }
    return; 
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> v;

    // Input 'n' elements into the vector
    cout << "Enter " << n << " integers: ";
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        v.push_back(ele); // Add element to the vector
    }

    // Call the function to compute the running sum
    runningSum(v);

    // Output the modified array with prefix sums
    cout << "Prefix sum array: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0; 
}