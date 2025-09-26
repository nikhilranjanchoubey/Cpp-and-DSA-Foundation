// Pattern: Prefix Sums in 2D Arrays.

// Method 1: Brute Force

/*Given a matrix 'a' of dimension nxm
and 2 coordinates (l1,r1) and (l2,r2).
Return the sum of the rectangle from (l1,r1) to (l2,r2).*/

#include<iostream>
#include<vector>
using namespace std;

// Function to calculate the sum of a submatrix from (l1,r1) to (l2,r2)
int rectangleSum(vector<vector<int> >&matrix, int l1, int r1, int l2, int r2){
    int sum = 0;

    // Traverse the submatrix and accumulate the sum
    for(int i = l1; i <= l2; i++){
        for(int j = r1; j <= r2; j++){
            sum += matrix[i][j];            
        }
    }

    return sum;
}

int main(){
    int n, m;

    // Input for matrix dimensions
    cout << "Enter number of rows (n): ";
    cin >> n;
    cout << "Enter number of columns (m): ";
    cin >> m;

    vector<vector<int> > matrix(n, vector<int>(m));

    // Inputfor matrix elements
    cout << "Enter matrix elements :\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    int l1, r1, l2, r2;

    // Input for rectangle coordinates
    cout << "Enter top-left coordinates (l1 r1): ";
    cin >> l1 >> r1;
    cout << "Enter bottom-right coordinates (l2 r2): ";
    cin >> l2 >> r2;

    // Display the matrix
    cout << "\nMatrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Display the rectangle sum
    int sum = rectangleSum(matrix, l1, r1, l2, r2);
    cout << "\nSum of rectangle from (" << l1 << "," << r1 << ") to (" << l2 << "," << r2 << ") is: " << sum << endl;

    return 0;
}