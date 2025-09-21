/*Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maximumOnesRow(vector<vector<int> >V){


int maxOnes = INT_MIN;
int maxOnesRow = -1;
int columns = V[0].size();

for(int i=0;i<V.size();i++){
    for(int j=0;j<V[i].size();j++){

        if(V[i][j]==1){
            int numberOfOnes = columns - j;
            if(numberOfOnes > maxOnes){
                maxOnes = numberOfOnes;
                maxOnesRow = i;
            }
        }
    }
}

    return maxOnesRow;
}

int main(){
    
    int n,m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int> > vec(n,vector<int> (m));

     cout<<"Enter elements of the array: "<<endl;
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }

    int res = maximumOnesRow(vec);
    cout << "Row with maximum 1s: " << res << endl;

    return 0;
}