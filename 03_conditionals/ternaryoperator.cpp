#include<iostream>
using namespace std;

int main (){

    int marks;
    cout<<"Enter Your Marks: ";
    cin>>marks;

    // Using if-else
    cout<<"Using if-else Statement\n";
    if (marks>33){
        cout<<"Pass"<<endl;
    }
    else{
        cout<<"Fail"<<endl;
    }

    // Using Ternary Operator
    cout<<"Using Ternary Operator\n";
    marks>33 ? cout<<"Pass"<<endl : cout<<"Fail"<<endl;





    return 0;
}