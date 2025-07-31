#include<iostream>
using namespace std;

int main (){

    int a=4;
    cout<<sizeof(a)<<endl; //4

    char name='a';
    cout<<sizeof(name)<<endl; //1

    bool flag;
    a==name? flag=true : flag=false; //ternary operator
    cout<<flag<<endl; //0

    cout<<(&a)<<endl;

   int c = 6;
   cout << (c++) << endl;  // Post-increment: prints 6, then c becomes 7
   cout << c << endl;      // Prints updated value of c: 7

   int b = 5;
   cout << (--b) << endl;  // Pre-decrement: b becomes 4, then prints 4

    return 0;
}