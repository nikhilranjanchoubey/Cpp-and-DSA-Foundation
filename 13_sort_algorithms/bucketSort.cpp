#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

// Bucket Sort for floating-point numbers in range [0, 1)
void bucketSort(float arr[], int size) {
    // Step 1: Create 'size' empty buckets (each bucket is a vector)
    vector<vector<float>> buckets(size);

    // Step 2: Distribute array elements into appropriate buckets
    for (int i = 0; i < size; i++) {
        int index = arr[i] * size; // Index calculation based on value
        buckets[index].push_back(arr[i]);
    }

    // Step 3: Sort individual buckets
    for (int i = 0; i < size; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Step 4: Concatenate all buckets into original array
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

int main() {
    // Sample input: floating-point numbers in [0, 1)
    float arr[] = { 0.13, 0.45, 0.12, 0.89, 0.75, 0.63, 0.85, 0.39 };
    int size = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}