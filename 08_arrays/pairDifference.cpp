/*Given a vector arr[] sorted in increasing order of n size and an integer x,
find if there exists a pair in the array whose absolute difference is exactly x.*/

#include<iostream>
using namespace std;

int main() {
    int arr[] = {5,10,15,20,26};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]); // n -->> 5
    int i = 0;
    int j = 1;
    bool found = false;

    while (i < n and j < n) {
        int diff = abs(arr[i] - arr[j]);
        // What abs does:
        //abs(-10) → 10  
        //abs(10)  → 10  
        //abs(0)   → 0
        if (diff == x) {
        
            found = true;
            break;
        } else if (diff < x) {
            j++; // increase difference
        } else {
            i++; // decrease difference     
    }
}

    if (found == true)
        cout<<"YES";

    else cout <<"NO";

    return 0;
}