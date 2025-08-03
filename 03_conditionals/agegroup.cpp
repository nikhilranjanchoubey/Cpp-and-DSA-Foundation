// WAP to divide people into 3 age groups depending upon there age.
// Below 12 -->> Child
// Between 12 and 18 -->> Teenager
// Above 18 -->> adult

#include<iostream>
using namespace std;

int main (){
    
    int age;
    cout<<"Enter Your Age(in years): ";
    cin>>age;

    if (age<12){
        cout<<"Child";
    }
    else if (age>18){
        cout<<"Adult";
    }
    else{
        cout<<"Teenager";
    }

    return 0;
}