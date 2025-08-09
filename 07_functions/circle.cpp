// Given radius of a circle.
// Write a function to print the area and circumference of the circle.

#include<iostream>
using namespace std;


float area(float r){
    return 3.14 * r * r;
}

float circumference(float r){
    return 2 * 3.14 * r;
}

int main(){
     
    float r;
    cout<<"Enter radius of circle: ";
    cin>>r;
    cout<<"Area: "<<area(r)<<endl;
    cout<<"Circumference: "<<circumference(r)<<endl;

    return 0;
}