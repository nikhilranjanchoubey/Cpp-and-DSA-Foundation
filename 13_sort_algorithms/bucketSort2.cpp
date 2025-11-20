#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

// Bucket Sort for floating-point numbers across any range
void bucketSort(float arr[], int size) {
    // Step 1: Create empty buckets
    vector<vector<float>> buckets(size);

    // Step 2: Find the minimum and maximum elements
    float max_ele = arr[0], min_ele = arr[0];
    for (int i = 1; i < size; i++) {
        max_ele = max(max_ele, arr[i]);
        min_ele = min(min_ele, arr[i]);
    }

    // Step 3: Calculate the range of each bucket
    float range = (max_ele - min_ele) / size;

    // Step 4: Distribute elements into buckets
    for (int i = 0; i < size; i++) {
        int index = (arr[i] - min_ele) / range;

        // Handle boundary case where element equals max_ele
        if (index == size) index--;

        buckets[index].push_back(arr[i]);
    }

    // Step 5: Sort individual buckets
    for (int i = 0; i < size; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Step 6: Concatenate buckets into original array
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (float val : buckets[i]) {
            arr[k++] = val;
        }
    }
}

int main() {
    float arr[] = { 6.13, 8.45, 0.12, 1.89, 4.75, 2.63, 7.85, 10.39 };
    int size = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}