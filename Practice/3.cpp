#include<iostream>
using namespace std;

int main(){

    int a,b;

    cout<<"Enter two numbers: ";
    cin>>a>>b;

    cout<<endl;

    cout<<"Numbers Before Swaping: "<<endl;
    cout<<"A: "<<a<<" B: "<<b<<endl;
    
    a = a + b;
    b = a - b;
    a = a - b;

    cout<<endl;

    cout<<"Numbers After Swaping: "<<endl;
    cout<<"A: "<<a<<" B: "<<b<<endl;

    return 0;
}