// Given two numbers a and b, 
// WAP using functions to print all the odd numbers between them.

#include<iostream>
using namespace std;

bool isodd(int num){
    // number is even
    if (num % 2 == 0){
    return false;
    }
    else {
    // number is odd
    return true;
    }      
}

int main(){
    int a = 1, b = 10;
    for(int i = a; i<= b; i++){
        if (isodd(i)){
            cout<<i<<" ";
        }
    }

    return 0;
}


