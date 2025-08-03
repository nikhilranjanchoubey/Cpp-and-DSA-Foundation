// Print the first multiple of 5 which is also a multiple of 7.

#include<iostream>
using namespace std;

int main(){
    cout<<"Using While Loop\n";
    int i=5;

    while(true){

        if(i%7==0){
            cout<<i<<endl;
            break;
        }
        i+=5;
    }
    cout<<"Using For Loop\n";

    for(int i=5;;i+=5){
        if(i%7==0){
            cout<<i<<endl;
            break;
        }
    }
    return 0;    
}