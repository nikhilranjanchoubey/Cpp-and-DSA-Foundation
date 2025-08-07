//  WAP to print + pattern given below
//    *
//    *
//  *****
//    *
//    *

#include<iostream>
using namespace std;

int main (){
    int n = 5; // Size of the pattern (must be odd to form a symmetric '+')

    // Loop to iterate through each line of the pattern
    for(int line = 0; line < n; line++){

        // Loop to iterate through each character in the current line
        for(int i = 0; i < n; i++){
            
            // Print '*' at the center column (vertical line of '+')
            if(i == n / 2) 
                cout << "*";
            
            // Print '*' across the center row (horizontal line of '+')
            else if(line == n / 2) 
                cout << "*";
            
            // Print space elsewhere
            else 
                cout << " ";
        }

        // Move to the next line after printing all characters in the current line
        cout << endl;
    }

    return 0;
}