#include <iostream>
using namespace std;

int main() {
    int *ptr;  // Declared but not initialized — wild pointer

    cout<<ptr<<" "<<*ptr<<endl; // May crash or print garbage

    return 0;
}