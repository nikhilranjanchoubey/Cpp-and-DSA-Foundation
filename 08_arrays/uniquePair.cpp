/*Given a vector[] sorted in increasing order of n size and an integer x,
find the number of unique pairs that exists in the array whose absolute sum is exactly x.*/

#include<iostream>
using namespace std;

int main() {
    int arr[] = {-2, -1, 0, 3, 6, 8, 11, 12};
    int x = 14;
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    int j = n - 1;
    int count = 0;

    while (i < j) {
        int sum = arr[i] + arr[j];
        int absSum = abs(sum);

        if (absSum == x) {
            count++;

            // Skip duplicates to ensure uniqueness
            int left = arr[i], right = arr[j];
            while (i < j && arr[i] == left) i++;
            while (i < j && arr[j] == right) j--;
        }
        else if (absSum < x) {
            i++;
        }
        else {
            j--;
        }
    }

    cout << "Number of unique pairs with absolute sum " << x << " is: " << count << endl;

    return 0;
}