#include<iostream>         
using namespace std;  

int main(){        

    int *ptr = NULL; // Initializes pointer to NULL — traditional way (value is 0)

    int *p1 = 0; // Also initializes pointer to null — 0 is treated as null in pointer context

    int *p2 = '\0'; // '\0' is the null character (ASCII 0), also treated as null pointer

    cout<<ptr<<" "<<p1<<" "<<p2<<" "<<"\n";

    // Pointer is null. Cannot dereference.

    return 0;
}