#include<iostream>
using namespace std;

int main(){

    int n;
    int reverse = 0;

    cout<<"Enter a number: ";
    cin>>n;

    while(n>0){
      reverse = reverse*10;
      reverse = reverse + (n%10);
      n = n/10;
   }
   
   cout<<"The reversed number is "<<reverse;

    return 0;
}