#include<iostream>
using namespace std;

// Function to merge two sorted subarrays into a single sorted array
void merge(int arr[], int l, int mid, int r){

    // Calculate sizes of two subarrays to be merged
    int a_n = mid - l + 1;     // Size of left subarray
    int b_n = r - mid;         // Size of right subarray

    // Create temporary arrays to hold the values
    int a[a_n];                // Left subarray
    int b[b_n];                // Right subarray

    // Copy data to temporary arrays a[] and b[]
    for(int i = 0; i < a_n; i++){
        a[i] = arr[l + i];
    }

    for(int j = 0; j < b_n; j++){
        b[j] = arr[mid + 1 + j];
    }

    // Initial indexes for subarrays and merged array
    int i = 0;  // Index for a[]
    int j = 0;  // Index for b[]
    int k = l;  // Index for merged array arr[]

    // Merge the temp arrays back into arr[l..r]
    while(i < a_n && j < b_n){
        if(a[i] < b[j]){
            arr[k++] = a[i++];  // Copy smaller element from a[]
        }
        else{
            arr[k++] = b[j++];  // Copy smaller element from b[]
        }
    }

    // Copy any remaining elements of a[], if any
    while(i < a_n){
        arr[k++] = a[i++];
    }

    // Copy any remaining elements of b[], if any
    while(j < b_n){
        arr[k++] = b[j++];
    }
}

// Recursive function to implement merge sort
void mergeSort(int arr[], int l, int r){

    // Base case: if the array has one or no elements, it's already sorted
    if(l >= r){
        return;
    }

    // Find the middle point to divide the array into two halves
    int mid = (l + r) / 2;

    // Recursively sort the first and second halves
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    // Merge the sorted halves
    merge(arr, l, mid, r);
}

int main(){

    // Sample array to be sorted
    int arr[] = {10, 28, 24, 6, 34, 18, 38, 44};
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate array size

    // Call mergeSort on the entire array
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}