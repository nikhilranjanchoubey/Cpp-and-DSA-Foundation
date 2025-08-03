// Print the sum of the stream of N integers in the input using do-while-loop.

#include<iostream>
using namespace std;

int main (){
     
    int n,sum=0;
    cout<<"Enter a number: ";
    cin>>n;

    do {
        int num;
        cin>>num;
        sum+=num;
        n--;
    }while(n>0);

    cout<<"Sum is: "<<sum<<endl;;

    return 0;
}