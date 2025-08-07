// WAP to print a rectangle out of '*'.
#include<iostream>
using namespace std;

int main(){

    int starRows,starCols;
    cout<<"Please Enter the number of StarRows: ";
    cin>>starRows;
    cout<<"Please Enter the number of StarColumns: ";
    cin>>starCols;

    for(int i=1;i<=starRows;i++){
        for(int j=1;j<=starCols;j++){
        cout<<"*";
        }
       cout<<endl; 
    }

    return 0;
}

 