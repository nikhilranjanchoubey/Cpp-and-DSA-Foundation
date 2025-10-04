#include<iostream>
using namespace std;

int main(){

    int x = 9;
    int y = 2;
    int *ptr = &x;

    // ptr = 5; we can't do this as ptr only stores address nothing else

    // *ptr = &y; this wont work as we cannot store address in an int bucket
    
    cout<<"Address of x: "<<&x<<endl;
    cout<<"Address stored inside ptr: "<<ptr<<endl;
    cout<<"Address of ptr itself: "<<&ptr<<endl; // prints the address of the ptr bucket not the address stored in ptr

    return 0;
}


/*
int main() {

    int x = 9; // Declare and initialize integer variable 'x'
    int y = 2; // Declare and initialize integer variable 'y'

    int *ptr = &x; // Declare a pointer 'ptr' and assign it the address of 'x'

    // ❌ Mistake: ptr = 5;
    // This is invalid because 'ptr' is a pointer and should store a memory address, not a literal integer.
    // Correct usage: ptr = &y; // if you want ptr to point to y instead

    // ❌ Mistake: *ptr = &y;
    // This is invalid because '*ptr' accesses the value at the memory location ptr points to (which is an int),
    // and you're trying to assign an address (&y) to an int — type mismatch.
    // Correct usage: ptr = &y; // change the pointer to point to y

    // ✅ Let's print some useful pointer-related info:
    cout << "Address of x: " << &x << endl; // Prints the memory address of variable 'x'
    cout << "Address stored inside ptr: " << ptr << endl; // Prints the address that 'ptr' is pointing to (same as &x)
    cout << "Address of ptr itself: " << &ptr << endl; // Prints the memory address of the pointer variable 'ptr' itself

    return 0;
}
*/