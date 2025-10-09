#include<iostream>
using namespace std;

int main(){

    int a, b, c;

    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    // First level: compare a with b
    if(a > b){
        // Second level: compare a with c
        if(a > c){
            cout << a << " is largest";
        }
        else{
            cout << c << " is largest";
        }
    }
    else{
        // Second level: compare b with c
        if(b > c){
            cout << b << " is largest";
        }
        else{
            cout << c << " is largest";
        }
    }

    return 0;
}