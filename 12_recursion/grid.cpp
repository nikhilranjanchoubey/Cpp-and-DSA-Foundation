/*The problem is to count all the possible paths on an m x n grid,
from top left (grid[0][0]) to bottom right (grid[m-1][n-1]).

Having constraints that from each cell,
you can either move only to right or down.

Input: m = 2, n = 3
Output: 3*/

#include<iostream>
using namespace std;

// Recursive function to count all possible paths from (i, j) to (m-1, n-1)
int f(int i, int j, int m, int n){
    // Base case: reached bottom-right cell
    if(i == m - 1 && j == n - 1) return 1;

    // Out of bounds: invalid path
    if(i >= m || j >= n) return 0;

    // Move right and down, and sum the number of paths
    return f(i, j + 1, m, n) + f(i + 1, j, m, n);
}

int main(){
 
    cout << f(0, 0, 2, 3);
    
    return 0;
}