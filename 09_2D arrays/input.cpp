#include<iostream>
using namespace std;

int main(){

    int n,m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    int array[n][m];

    cout<<"Enter elements of array: "<<endl;
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>array[i][j];
        }
    }

    cout<<"The given array is: "<<endl;
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<" "<<array[i][j];
        }
        cout<<endl;
    }

    return 0;
}