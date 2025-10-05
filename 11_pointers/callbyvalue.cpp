#include<iostream>
using namespace std;

// This function attempts to swap two integers
// But it uses pass-by-value, so it won't affect the original variables in main
void swap(int x, int y){
    // x and y are copies of the original arguments
    int temp = x;
    x = y;
    y = temp;
    // The swap happens only within this function's scope
}

int main(){
    int x = 10;
    int y = 20;

    // Passing x and y by value — copies are sent to the function
    swap(x, y);

    // Output will still be 10 20 because the original x and y were not modified
    cout <<"Pass By Value" << endl;
    cout <<"Value Of X: "<< x << endl;
    cout <<"Value Of Y: " << y << endl;
}