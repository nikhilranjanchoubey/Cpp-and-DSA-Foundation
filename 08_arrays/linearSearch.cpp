// Search if a given element is present in the array or not.
// If it is not present then return -1 else return the index.
#include<iostream>
using namespace std;

int main() {
    // int arr[] = {3, 9, 18, 11, 7};
    // int find = 11;
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int index = -1;

    // for (int i = 0; i < size; i++) {
    //     if (arr[i] == find) {
    //         index = i;
    //         break;
    //     }
    // }

    // if (index != -1) {
    //     cout << index;
    // } else {
    //     cout << "1";
    // }

    int array[] = {3, 9, 18, 11, 7};
    int key = 11;

    int ans = -1;

    for (int i = 0; i < 5; i++){
        if(array[i]==key){
            ans=i;
            break;
        }
    }

    cout<<ans<<endl;

    return 0;
}