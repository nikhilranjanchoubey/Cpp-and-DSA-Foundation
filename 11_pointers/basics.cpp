#include<iostream>
using namespace std;

int main(){

   int n = 10; // Declare an integer variable 'n' and initialize it with 10

    // Print the value stored in 'n'
    cout << "Value: " << n << endl; // Output: Value: 10

    // Print the memory address of variable 'n'
    cout << "Address: " << &n << endl; // Output: Address: (some hexadecimal address)

    // Declare a pointer 'ptr' that stores the address of 'n'
    int *ptr = &n; // Can also be written as int* ptr = &n ;; int * ptr = &n

    // Print the value of the pointer (i.e., the address it holds)
    cout << "Address stored inside ptr: " << ptr << endl; // Output: Pointer: (same address as &n)

    // Dereference the pointer to access the value stored at that address
    cout << "Value present at the address stored in ptr: " << *ptr << endl; // Output: Pointer: 10

    cout<<"------------------------------------------------------------------------------"<<endl;

    n = 23; // the bucket n is updated the value from 10 to 23
    // but ptr is still pointing to same bucket
    // now if we dereference ptr, we will get 23

    cout<<"New updated value of n: "<<n<<endl;
    cout<<"Ptr still pointing to same memory which has 23 instead of 18: "<<*ptr<<endl;

    // updating n with pointer

    *ptr = 50;
    cout<<"New value of n: "<<n<<endl;
    cout<<"New value pointed by ptr: "<<*ptr<<endl;

    int N = *ptr;
    cout<<N<<endl;

    return 0; 
}

