// write a function to print square of first 5 natural numbers.
// Sample Output: 1 4 9 16 25

#include<iostream>
using namespace std;

int square(int n){
    return n * n;
}

int main(){

    for (int i=1;i<=5;i++){
        cout<<square(i)<<" ";
    } 

    return 0;
}