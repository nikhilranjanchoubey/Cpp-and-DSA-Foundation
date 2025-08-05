// Find the sum of digits in a given number n.

#include<iostream>
using namespace std;

int main(){

    int n,m;
    cout<<"Enter a number: ";
    cin>>n; 

    int digits=0;
    int sum=0;
    while(n>0){
        digits++;
        m=n%10; // m is used to store remainder.
        n=n/10; 
        sum+=m;
    }

    cout<<"Numbers of digits: "<<digits<<endl;
    cout<<"Sum of digits: "<<sum<<endl;

    return 0;
}