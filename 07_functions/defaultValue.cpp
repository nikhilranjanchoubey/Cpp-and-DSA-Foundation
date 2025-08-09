#include<iostream>
using namespace std;

void fun(int x, int y = 100, int z = 30){
    cout<<x<<" "<<y<<" "<<z;
}

int main(){

    fun(10);

    return 0;
}