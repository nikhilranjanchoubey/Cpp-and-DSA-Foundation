#include<iostream>
using namespace std;

bool isPresentInRange(int *arr, int size, int currentIndex, int target) {
    // Base case: if we've reached the end of the array
    if (currentIndex == size) {
        return false;
    }

    // Check current element or recurse for the rest of the array
    return (arr[currentIndex] == target) || isPresentInRange(arr, size, currentIndex + 1, target);
}

int main() {
    int arr[] = {5, 4, 1, 8, 6, -9, 8, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);  
    int target = 8;

    // Check if target is present in the array
    bool found = isPresentInRange(arr, size, 0, target);

    // Output result
    if (found)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}