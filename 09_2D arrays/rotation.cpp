/*Given a square matrix, turn it by 90 degrees in a clockwise direction
without using any extra space.*/

#include<iostream>
#include<vector>
#include<algorithm> // for reverse()
using namespace std;

// Function to rotate the matrix 90 degrees clockwise
void rotateArray(vector<vector<int> > &vec){

    int n = vec.size();

   // Step 1: Transpose the matrix
    // Swap elements across the diagonal
     for(int i=0;i<n;i++){
        for(int j=0; j<i; j++){
            swap(vec[i][j],vec[j][i]);
        }
    }

    // Step 2: Reverse each row
    // This gives the rotated matrix
    for(int i=0;i<n;i++){
        reverse(vec[i].begin(),vec[i].end());
    }
    return;
}
int main(){

    int n;
    // Input size of the matrix
    cout << "Enter the size of the square matrix: ";
    cin>>n;

    vector<vector<int> > vec(n, vector<int> (n));

    //Elements Input in Matrix 
    cout<<"Enter elements of the Matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cin>>vec[i][j];
        }
    }

    rotateArray(vec);

    // Rotation Matrix
    cout << "Rotated Matrix:\n";
     for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}