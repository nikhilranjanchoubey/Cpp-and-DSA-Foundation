/*Write a program to display transpose of matrix entered by the user.*/

#include<iostream>
using namespace std;

int main(){

    int n,m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    int array[n][m];

    //Elements Input in Matrix 
    cout<<"Enter elements of the Matrix: "<<endl;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>array[i][j];
        }
    }
    // Original Matrix
    cout<<"The given Matrix is:\n";
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<" "<<array[i][j];
        }
        cout<<endl;
    }
    // Transpose Matrix
    cout << "Transpose of the Matrix:\n";
    for (int i = 0; i < m; i++) {         
    for (int j = 0; j < n; j++) {    
        cout << array[j][i] << " ";
    }
    cout << endl;
}
    
    return 0;
}