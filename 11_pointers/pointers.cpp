#include<iostream> 
using namespace std;

int main() {

    int x, y; // Declare two integer variables 'x' and 'y'. Initially, they hold garbage values.

    cout << "Enter two numbers: " << endl;
    cin >> x >> y; // Take input from the user and store values in 'x' and 'y'

    // Create pointers that store the addresses of 'x' and 'y'
    int *ptrx = &x; // 'ptrx' points to the memory location of 'x'
    int *ptry = &y; // 'ptry' points to the memory location of 'y'

    int result; // Declare an integer variable 'result'. Initially holds garbage value.

    // Create a pointer to 'result'
    int *ptr_result = &result;

    // Let's say user inputs: x = 10, y = 20
    // *ptrx = 10 (value at address of x)
    // *ptry = 20 (value at address of y)
    // *ptrx + *ptry = 30
    // *ptr_result = 30 → stores the sum at the memory location of 'result'

    *ptr_result = *ptrx + *ptry; // Add values pointed by 'ptrx' and 'ptry', store in 'result'

    // Output the result using both direct variable and pointer dereferencing
    cout << "Result stored in variable: " << result <<endl;
    cout<< "Result accessed via pointer: " << *ptr_result << endl;

    return 0; 
}

// #include<iostream>
// using namespace std;

// int main(){

//     int x, y; // declare x and y, so x, y has garbage value

//     cout<<"Enter two numbers: "<<endl;
//     cin>>x>>y; // taking input of x and y

//     int *ptrx = &x; // &x fetches address of x and then store it in ptrx
//     int *ptry = &y; // &y fetches address of y and then store it in ptry

//     int result; // declare result so it has garbage value
    
//     int *ptr_result = &result;

//     // *ptrx -- 10
//     // *ptry -- 20
//     // *ptrx+*ptry -- 30
//     // *ptr_result = 30; we store 30 on the address stored in *ptr_result
//     // result -- 30
//     *ptr_result = *ptrx + *ptry;


//     cout<<result<<" "<<*ptr_result<<endl;

//     return 0;
// }