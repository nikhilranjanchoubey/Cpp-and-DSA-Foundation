// Calculate the sum of all the elements in the give array.
#include<iostream>
using namespace std;

int main() {
    // int size;
    // cout << "Total elements of array: ";
    // cin >> size;

    // int arr[size]; 

    // cout << "Enter elements of array: " << endl;
    // for (int idx = 0; idx < size; idx++) {
    //     cin >> arr[idx];
    // }

    // int sum = 0;
    // for (int idx = 0; idx < size; idx++) {
    //     sum += arr[idx];
    // }

    // cout << "Sum of all elements: " << sum << endl;

    int array[]={3, 4, 10, 11};
    int size = sizeof(array)/sizeof(array[0]);

    int sum = 0;
    for(int i = 0; i<size; i++){
        sum+=array[i];
    }
    cout<<sum<<endl;

    return 0;
}