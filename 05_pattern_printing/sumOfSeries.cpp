// Find the sum of the following series
// s= 1-2+3-4.....n

#include<iostream>
using namespace std;

int main(){

    int n,sum=0;
    cout<<"Enter a number: ";
    cin>>n;

    for(int i=1;i<=n;i++){
        if(i%2==0){
            sum -= i;
        }
        else{
            sum += i;
        }
        cout<<endl;
    }

    cout<<"Sum of series is: "<<sum;

    return 0;
}

