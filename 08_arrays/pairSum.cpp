/*Given a vector arr[] sorted in increasing order of n size and an integer x,
find if there exists a pair in the array whose sum is exactly x.*/

#include<iostream>
using namespace std;

int main() {
    int arr[] = {-2, -1, 0, 3, 6, 8, 11, 12};
    int x = 14;
    int n = sizeof(arr) / sizeof(arr[0]); // n -->> 8
    int i = 0;
    int j = n - 1;
    bool found = false;

    while (i < j) {
        int sum = arr[i] + arr[j];

        if (sum == x) {
        
            found = true;
            break;
        } else if (sum < x) {
            i++; // move left pointer to increase sum
        } else {
            j--; // move right pointer to decrease sum
        }
    }

    if (found == true)
        cout<<"YES";

    else cout <<"NO";

    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// bool hasPairWithSum(const vector<int>& arr, int x) {
//     int i = 0;              // Start pointer
//     int j = arr.size() - 1; // End pointer

//     while (i < j) {
//         int sum = arr[i] + arr[j];

//         if (sum == x) {
//             cout << "Pair found: " << arr[i] << " + " << arr[j] << " = " << x << endl;
//             return true;
//         } else if (sum < x) {
//             i++; // Move left pointer to increase sum
//         } else {
//             j--; // Move right pointer to decrease sum
//         }
//     }

//     cout << "No pair found with sum " << x << endl;
//     return false;
// }

// int main() {
//     vector<int> arr = {-2, -1, 3, 6, 8, 11, 12};
//     int x = 14;

//     hasPairWithSum(arr, x);

//     return 0;
// }