// Reverse the digits of a number.

#include<iostream>
using namespace std;

int main(){

    int n,m;
    cout<<"Enter a number: ";
    cin>>n; 

    int reverse=0;
    while(n>0){
          int lastdigit = n%10;
          reverse = reverse * 10+  lastdigit;
          n/=10;       
        
    }

    cout<<"Reverse of number is: "<<reverse<<endl;    

    return 0;
}