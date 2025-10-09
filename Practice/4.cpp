#include<iostream>
using namespace std;

int main(){

    int a = 5;  // '=' assigns the value 5 to variable 'a'

    // '==' checks if the value of 'a' is equal to 1
    if(a == 1){
        cout << a;  // This won't run because a is 5, not 1
    }
    else
        cout << "a is 5";  // This will run and print: a is 5

    return 0;
}