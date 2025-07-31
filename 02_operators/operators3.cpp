#include<iostream>
using namespace std;

int main(){

    int num1=5; //0101 = 5

    cout<<(num1<<1)<<endl; //10 '<<' left shift by1 then multiply by 2
    cout<<(num1>>1)<<endl; //2 '>>' right shift by1 then divide by 2

    int num2=8; //1000 = 8

    cout<<(num1&num2)<<endl; //0
    cout<<(num1|num2)<<endl; //1101 = 13

    return 0;
}