#include<iostream>
using namespace std;

// Function to swap two integers using pointers
void swap(int *x, int *y) {
    // Dereference the pointers to access and swap the actual values
    int temp = *x;  // Store the value pointed to by x
    *x = *y;        // Assign the value pointed to by y to the location pointed to by x
    *y = temp;      // Assign the stored value to the location pointed to by y
}

int main() {
    int x = 10;
    int y = 20;

    // Create pointers to x and y
    int *p1 = &x;   // p1 holds the address of x
    int *p2 = &y;   // p2 holds the address of y

    // Call swap function with pointers
    swap(p1, p2);   // This swaps the actual values of x and y

    // Print the swapped values
    cout << "Pass By Reference" << endl;
    cout << "Value Of X: " << x << endl;
    cout << "Value Of Y: " << y << endl;

    return 0;
}

// #include<iostream>
// using namespace std;

// // This function swaps two integers using pass-by-reference
// // Changes made here will affect the original variables in main
// void swap(int &x, int &y){ // & means reference to original variables
//     int temp = x;
//     x = y;
//     y = temp;
//     // Now the swap affects x and y in main()
// }

// int main(){
//     int x = 10;
//     int y = 20;

//     // Passing x and y by reference — original variables are modified
//     swap(x, y);

//     // Output will now be 20 10 because the swap was successful
//     cout << "Pass By Reference" << endl;
//     cout << "Value Of X: " << x << endl;
//     cout << "Value Of Y: " << y << endl;
// }