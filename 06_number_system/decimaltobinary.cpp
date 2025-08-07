#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;

    int ans=0;
    int power=1;

    while (n>0){
        int paritydigits = n%2;
        ans += paritydigits*power;
        power*=10;
        n/=2;
    }
    cout<<"The numbe in binary number system is " <<ans<<endl;

    return 0;
}