// Find maximum of three numbers using nested if else statements.

#include<iostream>
using namespace std;
int main(){

    int num1,num2,num3;
    cout<<"Enter three numbers: ";
    cin>>num1>>num2>>num3;
     
    if(num1>num2){
        if(num1>num3){
            cout<<"Maximum number is: "<<num1<<endl;
        }
    }
    else{
        if(num2>num3){
            cout<<"Maximum number is: "<<num2<<endl;
        }
        else{
            cout<<"Maximum number is: "<<num3<<endl;
        }
    }

    return 0;
}