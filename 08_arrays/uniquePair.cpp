/*Given a vector[] sorted in increasing order of n size and an integer x,
find the number of unique pairs that exists in the array whose absolute sum is exactly x.*/


#include<iostream>
using namespace std;

int main() {
    int arr[] = {-2, -1, 0, 1, 6, 8, 11, 12};
    int x = 12;
    int n = sizeof(arr) / sizeof(arr[0]); // n -->> 8
    int i = 0;
    int j = n - 1;
    int count = 0;

    while (i < j) {
        int sum = arr[i] + arr[j];

        if (sum == x) {
        
          count += 1;
          i++;
          j--;
        } else if (sum < x) {
            i++; 
        } else {
            j--; 
        }
    }

    cout<<count;

    return 0;
}