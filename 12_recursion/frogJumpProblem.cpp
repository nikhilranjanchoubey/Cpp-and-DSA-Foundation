/*There are N stones, numbered 1, 2, ..., N. For each i (1 ≤ i ≤ N), the height of Stone i is hᵢ.
There is a frog who is initially on Stone 1.
He will repeat the following action some number of times to reach Stone N:

If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2.
Here, a cost of |hᵢ - hⱼ| is incurred, where j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone N.

Input: n = 4
arr[] = {10, 30, 40, 20}
Output: 30*/

#include <iostream>
#include <cmath> // for abs()
using namespace std;

// Recursive function to calculate minimum cost from stone i to stone n-1
int minCost(int *h, int n, int i) {
    // Base case: if frog is already at the last stone
    if (i == n - 1) return 0;

    // If only one jump possible (i+1)
    if (i == n - 2) return abs(h[i] - h[i + 1]);

    // Recursive case: choose min cost between jumping to i+1 or i+2
    int jumpOne = minCost(h, n, i + 1) + abs(h[i] - h[i + 1]);
    int jumpTwo = minCost(h, n, i + 2) + abs(h[i] - h[i + 2]);

    return min(jumpOne, jumpTwo);
}

int main() {
    int arr[] = {10, 30, 40, 20};
    int n = 4;

    // Start from stone 0
    cout << minCost(arr, n, 0) << endl;

    return 0;
}
