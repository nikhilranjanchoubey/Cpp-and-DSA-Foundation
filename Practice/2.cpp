#include<iostream>
using namespace std;

int main(){

    double p,r,t;

    cout<<"Enter Principal Amount(in rupees): "<<endl;
    cin>>p;

    cout<<"Enter Rate of Interest(in %): "<<endl;
    cin>>r;

    cout<<"Enter Time(in months): "<<endl;
    cin>>t;

    double si = (p * r * t) / 100;

    cout<<"Simple Interest is: "<<si<<endl;

    return 0;
}