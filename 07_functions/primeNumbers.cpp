// Given two numbers a and b,
// WAP to print all the prime numbers present between a and b

#include<iostream>
using namespace std;

bool isPrime(int num){
    for (int i=2; i<= (num-1); i++){
        if(num %i == 0)
        return false;
    }    
    return true;
}

bool isPrimeBtr(int num){
    for(int i = 2; i*i <= num; i++){
        // i^2 <= num  -->> i <= sqrt(num)
        if(num % i == 0) return false;
    }
    return true;
}

int main(){
    int a = 2, b = 40;
    for(int i = a; i<= b; i++){
        if (isPrimeBtr(i)){
            cout<<i<<" ";
        }
    }

    return 0;
}