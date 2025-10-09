#include<iostream>
using namespace std;

int main(){

    int n;

    cout<<"Enter a Year: ";
    cin>>n;

    // Leap year logic:
    // - Divisible by 4 AND not divisible by 100
    // - OR divisible by 400

    if((n%4 == 0) && (n%100 != 0) || (n%400 == 0)){
        cout<<n<<" is a leap year";
    }

    else{
        cout<<n<<" is not a leap year";
    }

    return 0;
}