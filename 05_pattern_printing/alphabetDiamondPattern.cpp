// WAP to print alphabet diamond pattern
//     A
//    ABC
//   ABCDE
//  ABCDEFG
// ABCDEFGHI
//  ABCDEFG
//   ABCDE
//    ABC
//     A

#include <iostream> 
using namespace std;

int main() {
    
    int n=5; // Number of rows for the top half of the diamond 

    // Top half of the diamond (includes the middle line)
    for(int line = 1; line <= n; line++){
                
    // Calculate and print leading spaces for alignment
        int no_of_spaces = (n-line);
        for (int k = 0; k < no_of_spaces; k++){
            cout<<" ";
        }

    // Print increasing alphabet characters starting from 'A'

        int no_of_chars = 2*line -1;
        for(int j=0; j<no_of_chars; j++){
            char ch = (char)('A' + j);
            cout<<ch;
        }
        cout<<"\n";
    }
       
    // Bottom half of the diamond (excluding the middle line)
    for(int line = n+1; line <= 2*n-1; line++){
    // Print leading spaces which increase as we move downward
        int no_of_spaces = (line-n);
        for(int k=0; k < no_of_spaces; k++){
            cout<<" ";
        }
    // Print decreasing characters forming an inverted triangle

        int no_of_chars = 2*(2*n-line)-1;
        for(int j=0; j < no_of_chars; j++){
            cout<<(char)('A'+j);
        }
        cout<<"\n";
    }
    return 0; 
}