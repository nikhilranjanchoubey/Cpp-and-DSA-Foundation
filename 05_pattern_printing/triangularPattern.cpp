#include<iostream>
using namespace std;

int main(){

     int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    

    for (int i=1; i<=n;i++){ // no of lines/rows -> i
        for (int j=1;j<=i;j++){ // no of colums -> j
        cout<<"*";
        }
       cout<<endl; 
    }



    return 0;
}