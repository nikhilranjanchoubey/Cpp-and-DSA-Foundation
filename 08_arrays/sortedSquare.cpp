/*Given a vector arr[] sorted in increasing order.
Return an array of squares of each number sorted in increasing order.
Where size of vector 1<size<101.*/

#include<iostream>
using namespace std;

int main(){

    int arr[] = {0,1,2,3};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]); // n -->> 4
    int square[n];

    for(int i=0;i<n;i++){
         square[i] = arr[i]*arr[i];
    }
    for(int i=0;i<n;i++){
       cout<< " " << square[i];
    }


    return 0;
}