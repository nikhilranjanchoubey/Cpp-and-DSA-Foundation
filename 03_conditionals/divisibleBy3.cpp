// WAP to print the value if it is even and divisible by 3.
// Use Of AND(&&) operator.
#include<iostream>
using namespace std;

int main (){

    int num;
    cout<<"Enter a number: ";
    cin>>num;

    if ((num%2==0) && (num%3==0)){
        cout<<num<<endl;
    }
    return 0;
}