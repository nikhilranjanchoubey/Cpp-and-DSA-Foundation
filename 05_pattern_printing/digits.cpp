// Count the number of digits for a given number n.

#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n; 

    int digits=0;
    while(n>0){
        digits++;
        n=n/10;
    }

    cout<<"Numbers of digits: "<<digits<<endl;

    return 0;
}