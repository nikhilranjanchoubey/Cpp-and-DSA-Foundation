// Print the sum of the first n natural numbers,where n is the input.

#include<iostream>
using namespace std;

int main (){

    int num,sum=0;
    cout<<"Enter a number: ";
    cin>>num;

    int i=1; // Loop variable
    while(i<=num){
        sum+=i;
        i++;
    }

    cout<<"Sum is: "<<sum<<endl;

    return 0;
}