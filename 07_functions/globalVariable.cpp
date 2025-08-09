#include<iostream>
using namespace std;

string name = "Nikhil"; // global scope

void fun() {

    cout<<name<<"\n";
}

int main(){
    cout<<name<<"\n";
    name = "Ranjan";
    fun();

    return 0;
}